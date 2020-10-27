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
  if (this->top >= stack_length || !this->data)
    return false;
  
  this->data[this->top] = to_add;
  ++this->top;

  return true;
}

bool types::stack::pop() {
  if (!this->data || this->top == 0)
    return false;
  
  this->data[this->top - 1] = NULL;
  --this->top;

  return true;
}

bool types::stack::peak(int &result) {
  if (!this->data || this->top == 0)
    return false;
  
  result = this->data[this->top - 1];
  return true;
}

bool types::stack::isempty(void) {
  if (!data || this->top == 0)
    return true;
  
  return false;
}