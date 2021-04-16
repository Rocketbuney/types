/*
 * @Author: Jack Thake 
 * @Date: 2020-10-29 14:22:55 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-29 17:06:04
*/

#include <types/types.h>
#include <cstddef>

namespace types {

/* create empty list */
linear_list::linear_list() {
  this->head = NULL;
}


/* deallocate list */
linear_list::~linear_list() {
  node *tmp = NULL;
  while (this->head) {
    tmp = this->head->next;
    delete this->head;
    this->head = tmp;
  }
}


/* push item to front of list */
bool linear_list::push_front(void *to_add) {
  node *prev_head = this->head;
  
  /* set head to a new node, push the old head behind it */
  this->head = new node;
  if (!head) {
    this->head = prev_head;
    return false;
  }
  
  this->head->data = to_add;
  this->head->next = prev_head;
  
  return true;
}


/* push item to back of the list */
bool linear_list::push_back(void *to_add) {
  if (!this->head) /* empty list */
    return this->push_front(to_add);
  
  /* traverse to end*/
  node *tmp = this->head;
  while(tmp->next)
    tmp = tmp->next;
  
  /* allocate new node */
  tmp->next = new node;
  if (!tmp->next)
    return false;
  
  tmp->next->data = to_add;
  tmp->next->next = NULL;
  
  return true;
}


/* remove matching list items recursively using c++ pass by reference */
int linear_list::remove_recurs(node * &current, void *comp, bool (*compfn)(const void *, const void *)) {
  if (!current) return 0;
  
  if (compfn(current->data, comp)) {
    current = current->next;
    
    return 1 + remove_recurs(current, comp, compfn);
  } else {
    return remove_recurs(current->next, comp, compfn);
  }
}


/* remove all matching entries, if the compfn returns true - delete. */
/* recursive wrapper function */
bool linear_list::remove(void *comp, bool (*compfn)(const void *, const void *)) {
  return remove_recurs(this->head, comp, compfn);
}


/* only keep unique data */
bool linear_list::unique() {
  return true;
}


/* clear list */
bool linear_list::clear(void) {
  if (!head) /* if no list exists, fail */
    return false;
  
  this->~linear_list();
  
  return true;
}


/* iterator begin*/
linear_list::iterator linear_list::begin() {
  return linear_list::iterator(this->head);
}


/* iterator end */
linear_list::iterator linear_list::end() {
  return linear_list::iterator(NULL);
}


//----------------------------//
/* linear list iterator class */
//----------------------------//


/* construct the iterator */
linear_list::iterator::iterator(const node *p_node) : current_node(p_node) {}


/* assignment operator for iterator */
linear_list::iterator &linear_list::iterator::operator=(const node * p_node) {
  this->current_node = p_node;
  return *this;
}


/* prefix increment operator overload*/
linear_list::iterator &linear_list::iterator::operator++() {
  if (this->current_node)
    current_node = current_node->next;
  
  return *this;
}


/* postfix operator overload */
linear_list::iterator &linear_list::iterator::operator++(int) {
  if (this->current_node)
    current_node = current_node->next;
  
  return *this;
}


/* inequality operator overload */
bool linear_list::iterator::operator!=(const linear_list::iterator &it) {
  return current_node != it.current_node;
}


/* dereference operator */
void *linear_list::iterator::operator*() {
  return current_node->data;
}

}
