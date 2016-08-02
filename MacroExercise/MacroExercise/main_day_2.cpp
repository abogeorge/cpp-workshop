#include "AB\common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
#include <limits>
WF_MSW_RESTORE()

#include "AB\logger.hpp"

void func(int* pInt, size_t pSize)
{
  AB_WARN(sizeof(int&));
  AB_WARN(sizeof(pInt));
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << pInt[i]);
  }
}

void func(short* pInt, size_t pSize)
{
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << pInt[i]);
  }
}

struct TestStruct
{
  int x;
  double y;
};

void func(TestStruct* pInt, size_t pSize)
{
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << std::hex << pInt[i].x << " " 
      <<  std::dec << pInt[i].x << ", " << pInt[i].y);
  }
}

void func(char* pInt, size_t pSize)
{
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << pInt[i]);
  }
}

int main(int argc, char* argv[])
{
  //AB_UNSED(argc);
  AB_UNSED(argv);

  //int* intPtr = NULL;
  //int* intPtr2 = new int(42);
  ////*intPtr2 = 42;

  //int& y = *intPtr2;
  //y = 43;

  //AB_WARN(intPtr2 << " " << &intPtr2 << " " <<*intPtr2);

  int* intPtr2 = new int[7];

  int& y = *intPtr2;
  y = 43;

  AB_WARN(intPtr2 << " " << &intPtr2 << " " <<*intPtr2 << " " << intPtr2[1]);

  func(intPtr2, 7);

  // array-uri
  std::cout << std::endl;
  short arr[10] = { 1,2,3,4 };
  size_t numElem = sizeof(arr) / sizeof(*arr);
  AB_WARN(numElem);
  func(arr, numElem);

  std::cout << std::endl;
  short* arr2 = new short[static_cast<size_t>(argc)] {1,2,3,4};
  func(arr2, argc);
  delete[] arr2;

  // struct
  std::cout << std::endl;
  TestStruct* arr3 = new TestStruct[3]{ };
  func(arr3, 3);

  delete[] arr3;

  // chars
  char* str = "abc";
  func(str, strlen(str));

  return 0;
}