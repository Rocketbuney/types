//
//  main.cpp
//  types-test
//
//  Created by Jack Thake on 4/15/21.
//

#include <iostream>
#include <types/types.h>
#include "test_assert.h"

bool compfn(const void *a, const void *b) {
  int _a = *((int*)a), _b = *((int*)b);
  if (_a == _b)
    return true;
  
  return false;
}

int linear_list_test() {
  types::linear_list list;
  int *test_vals = new int[5];
  int tester = 2;
  
  test_vals[0] = 1;
  test_vals[1] = 2;
  test_vals[2] = 2;
  test_vals[3] = 4;
  test_vals[4] = 2;
  
  test_assert(list.is_empty());
  test_assert(!list.clear());
  
  test_assert(list.push_back((void *)&test_vals[4])); // push 5 to the back of the list
  test_assert(list.push_back((void *)&test_vals[3])); // push 4 to the back of the list
  test_assert(list.push_back((void *)&test_vals[2])); // push 3 to the back of the list
  test_assert(list.push_back((void *)&test_vals[1])); // push 2 to the back of the list
  test_assert(list.push_back((void *)&test_vals[0])); // push 1 to the back of the list
  
  delete []test_vals;
  
  /* list should now contain 2 -> 4 -> 2 -> 2 -> 1 */
  test_assert(!list.is_empty());
  
  for (auto val : list) {
    std::cout << *((int*)val) << std::endl;
  }
  
  list.remove((void*)&tester, compfn);
  
  /* list should now contain 4 -> 1 */
  for (auto val : list) {
    std::cout << *((int*)val) << std::endl;
  }
  
  test_assert(list.clear());
  test_assert(list.is_empty());
  
  return 1;
}

int main(int argc, const char * argv[]) {
  int ret = linear_list_test();
  
  return ret;
}
