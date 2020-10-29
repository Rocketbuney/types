/*
 * @Author: Jack Thake 
 * @Date: 2020-10-29 14:22:55 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-29 14:36:14
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
    /* TODO: Implement me! */
    return true;
  }


  /* remove all matching items */
  bool linear_list::remove_item(const int &to_remove) {
    /* TODO: Implement me! */
    return true;
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