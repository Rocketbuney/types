#include <types/types.h>
#include <cstddef>

types::stack::stack(const int &stack_length) {
  this->stack_length = stack_length;
  if (this->stack_length > 0)
    this->data = new int[this->stack_length];
  else
    this->data = NULL;
  
  this->top = 0;
}

types::stack::~stack() {
  if (this->data)
    delete []this->data;
  
  this->top = 0;
  this->stack_length = 0;
}

bool types::stack::push(const int &to_add) {
  return true;
}

bool types::stack::pop() {
  return true;
}

bool types::stack::peak(int &result) {
  return true;
}

bool types::stack::isempty(void) {
  if (!data || this->top == 0)
    return true;
  
  return false;
}