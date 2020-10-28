/*
 * @Author: Jack Thake 
 * @Date: 2020-10-22 15:28:13 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-28 09:52:46
*/

#ifndef __STACK_H__
#define __STACK_H__

namespace types {
  /* a simple stack */
  class stack {
  public:
    stack(const int &stack_length = 0);
    ~stack();

    bool push(const int &to_add);
    bool pop();
    bool peak(int &result) const;
    bool isempty(void) const;
  private:
    int *data;
    int stack_length, top;
  };
};

#endif