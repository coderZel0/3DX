#ifndef ASSERT_H
#define ASSERT_H
#include <iostream>

#if ASSERT_ENABLED
#define debugBreak() asm("int3")

#define ASSERT(expr)                                                           \
  if (expr) {                                                                  \
  } else {                                                                     \
    std::cout << "Assertion failed: " << #expr << __FILE__ << __LINE__         \
              << std::endl;                                                    \
    debugBreak();                                                              \
  }

#else
#define ASSERT(exp)
#endif

#endif
