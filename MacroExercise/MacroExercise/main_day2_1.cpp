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

struct TestStruct
{
  int x;
  double y;
};

const TestStruct CONSTANTS[3] = {};

// cea mai buna varianta de return
static const TestStruct& getConstant()
{
  return CONSTANTS[2];
}

// C-mode
static bool createObject(size_t pValue, int** pContainer)
{
  //*pContainer = new int[pValue]; // one way 
  *pContainer = (int*) malloc(pValue * sizeof(**pContainer));
  return true;
}

int main(int argc, char* argv[])
{
  int* arr = NULL;
  bool succes = createObject(5U, &arr);

  return 0;
}