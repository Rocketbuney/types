#ifndef __STACK_H__
#define __STACK_H__

namespace types {
  class stack {
  public:
    stack(const int &stack_length = 0);
    ~stack();

    bool push(const int &to_add);
    bool pop();
    bool peak(int &result);
    bool isempty(void);
  private:
    int *data;
    int stack_length, top;
  };
};

#endif