#include "AB\common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
#include <limits>
WF_MSW_RESTORE()

#include "AB\logger.hpp"


struct TestStruct
{
  int x;
  double y;
};

template <typename T>
void func(T* pArray, size_t pSize)
{
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << pArray[i]);
  }
}

// full specialization
template <>
void func(TestStruct* pArray, size_t pSize)
{
  for (size_t i = 0; i < pSize; ++i)
  {
    AB_WARN(i << " " << pArray[i].x << ", " << pArray[i].y);
  }
}

std::ostream& operator<<(std::ostream& pOut, TestStruct& pValue)
{
  pOut << pValue.x << ", " << pValue.y;
  return pOut;
}

// template struct
template <typename S>
struct AuxStruct 
{
  typedef S type;
};


template <typename S>
struct AuxStructConst
{
  typedef const S type;
};


// Remove const
template <typename T>
struct AuxRemoveConst {
  typedef T type;
};

template <typename T>
struct AuxRemoveConst<const T> {
  typedef T type;
};

// Pointer functions
template <typename T>
struct ABTypeOf
{
  typedef T type;
};

int dummy(char)
{
  AB_WARN("Called 1");
  return 0;
}

void dummy(int, int)
{
  AB_WARN("Called 2");
}

int main(int argc, char* argv[])
{
  AB_UNSED(argc);
  AB_UNSED(argv);

  // template functions
  int arrInt[3] = {};
  short arrShort[3] = {};
  char arrChar[3] = {};

  TestStruct arrStruct[3] = {};

  func(arrStruct, 3);

  // Struct template
  AuxStruct<int>::type i;
  AuxStructConst<int>::type j = 0;

  AuxStructConst<int>::type k = 0;

  AuxRemoveConst<const int>::type m = 0;

  // function pointer
  ABTypeOf<int(char)>::type* fcPtr = dummy;
  ABTypeOf<void(int, int)>::type* fcPtr2 = dummy;
  fcPtr('X');
  fcPtr2(0, 0);

  return 0;
}