#include "AB\common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
#include <limits>
#include <memory>
WF_MSW_RESTORE()

#include "AB\logger.hpp"

union Test {
  int mInt;
  char mChar[sizeof(int)];
  float mFloat;
};


int main(int argc, char* argv[])
{
  AB_UNSED(argc);
  AB_UNSED(argv);
  //AB_WARN("Variable is NULL");
  
  // type conversion
  unsigned int x = 4000000000;
  long long y;
  y = x;
  AB_WARN(y);

  // numeric limits
  AB_WARN(std::numeric_limits<int>::min());
  AB_WARN(std::numeric_limits<unsigned int>::min());
  AB_WARN(std::numeric_limits<long>::max());
  AB_WARN(std::numeric_limits<unsigned long long>::max());
  AB_WARN(std::numeric_limits<unsigned short>::max());

  // Unions
  std::cout << std::endl;
  Test testUnion;
  //memset(&testUnion, 0, sizeof testUnion);
  //testUnion.mInt = std::numeric_limits<unsigned short>::max();
 // testUnion.mChar[sizeof(int)] = 0;
  testUnion.mFloat = 1.0;
  AB_WARN(testUnion.mInt);
  AB_WARN((int)testUnion.mChar[0] << (int)testUnion.mChar[1] << (int)testUnion.mChar[2] << (int)testUnion.mChar[0]);
  AB_WARN(testUnion.mFloat);
  AB_WARN(sizeof testUnion);

  // Smart Pointers
  std::cout << std::endl;
  std::unique_ptr<int[]> z(new int[3]);
  z.get()[0] = 1;
  AB_WARN(z.get()[0]);

  // Pointers
  std::cout << std::endl;
  int lSrc = 5, lVal = 6;
  const int* lSrb = &lSrc;
  AB_WARN(*lSrb);

  // Typedefs
  std::cout << std::endl;
  AB_WARN(std::numeric_limits<ab_i>::min());
  AB_WARN(std::numeric_limits<ab_ui>::min());
  AB_WARN(std::numeric_limits<ab_l>::max());
  AB_WARN(std::numeric_limits<ab::ull>::max());
  AB_WARN(std::numeric_limits<ab::us>::max());

  std::cout << std::endl;
  using namespace ab;
  for (i i = 0; i < 3; ++i)
  {
    AB_WARN(i);
    {
      ab::i i = 42;
      AB_ERROR(i);
    }
  }

  AB_WARN(++ab::x);
  int xc = ab::x;
  AB_WARN(xc);
  AB_WARN(++xc);
  AB_WARN(ab::x);

  return 0;
}