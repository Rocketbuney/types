//
//  test_assert.h
//  types-test
//
//  Created by Jack Thake on 4/15/21.
//

#include <cstdio>
#include <cstdlib>

#ifndef test_assert
#define test_assert(x) if (!(x)) { printf("Test assertion failed: (%s), file %s, line %d.\n", #x, __FILE__, __LINE__); abort(); }
#endif
