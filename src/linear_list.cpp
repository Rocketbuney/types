/*
 * @Author: Jack Thake 
 * @Date: 2020-10-29 14:22:55 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-29 17:06:04
*/

#include <types/types.h>
#include <cstddef>

namespace types {
  linear_list::linear_list() {
    this->head = NULL;
  }


  linear_list::~linear_list() {
    while (this->head) { /* traverse through, destroying list. */
      node *temp = this->head;

      this->head = this->head->next;
      delete temp;
    }
  }


  /* push to the front of the list */
  bool linear_list::push_front(const int &to_push) {
    /* grab previous head */
    node *temp = this->head;

    /* attempt to allocate */
    this->head = new node;
    if (!this->head) { /* if allocation failed, revert to old head */
      this->head = temp;
      return false;
    }

    /* copy over data */
    this->head->data = to_push;
    this->head->next = temp;

    return true;
  }


  /* push to the rear of the list */
  bool linear_list::push_back(const int &to_push) {
    node *current = this->head;

    while (current->next) /* traverse to the last item */
      current = current->next;
    
    /* attempt to allocate a new node */
    current->next = new node;
    if (!current->next) { /* if allocation failed, revert */
      current->next = NULL;
      return false;
    }
    
    /* copy over data */
    current->next->data = to_push;
    current->next->next = NULL;

    return true;
  }


  /* remove all matching items */
  bool linear_list::remove_item(const int &to_remove) {
    node *current = this->head, *previous = NULL;
    bool has_removed = false;

    while (current) { /* loop through list, checking if we should remove */
      if (current->data == to_remove) {
        has_removed = true;
        previous->next = current->next;
        delete current;
      }

      /* advance to next iteration */
      previous = current;
      current = current->next;
    }

    if (has_removed)
      return true;
    
    return false;
  }


  /* clear list */
  void linear_list::clear(void) {
    /* just call the destructor as it already deallocates the list. */
    this->~linear_list();
  }


  /* remove duplicates */
  bool linear_list::unique(void) {
    /* TODO: Implement me! */
    return true;
  }
};