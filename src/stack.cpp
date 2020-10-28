/*
 * @Author: Jack Thake 
 * @Date: 2020-10-27 15:27:08 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-28 09:53:12
*/

#include <types/types.h>
#include <cstddef>

types::stack::stack(const int &stack_length) {
  this->stack_length = stack_length;
  if (this->stack_length > 0) // only allocate if necessray
    this->data = new int[this->stack_length];
  else
    this->data = NULL;
  
  this->top = 0;
}


types::stack::~stack() {
  if (this->data) // only deallocate if necessary
    delete []this->data;
  
  this->top = 0;
  this->stack_length = 0;
}


bool types::stack::push(const int &to_add) {
  if (this->top >= stack_length || !this->data) // only add if stack exists
    return false;
  
  this->data[this->top] = to_add; 
  ++this->top;

  return true;
}


bool types::stack::pop() {
  if (!this->data || this->top == 0) // only pop if possible
    return false;
  
  this->data[this->top - 1] = NULL;
  --this->top;

  return true;
}


bool types::stack::peak(int &result) const {
  if (!this->data || this->top == 0) // only peak if possible
    return false;
  
  result = this->data[this->top - 1];
  return true;
}


bool types::stack::isempty(void) const { // returns weather the stack hasn't been allocated or if the stack is empty
  if (!data || this->top == 0)
    return true;
  
  return false;
}
