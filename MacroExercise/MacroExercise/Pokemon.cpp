#include "Pokemon.hpp"
#include "AB/logger.hpp"



WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE();

const char* Pokemon::IVYSAUR = "Ivysaur";
const char* Pokemon::CHARIZARD = "Charizard";
const char* Pokemon::WAORTORTLE = "Wartortle";

const char* Pokemon::getName(Type pType) {

  const char* result = NULL;

  switch (pType) {
  case ptWater:
    result = WAORTORTLE;
    break;
  case ptFire:
    result = CHARIZARD;
    break;
  case ptEarth:
    result = IVYSAUR;
    break;
  default:
    AB_ERROR("Unknown type: " << pType);
    break;
  }

  return result;
}

Pokemon::Pokemon(Type pType) :
  mType(pType),
  mNameRef(getName(mType)),
  mHealth(10),
  mAttack(10),
  mDefence(10),
  mSpeed(10) {

}

Pokemon::Pokemon(uint pHealth, uint pAttack,
  uint pDefence, uint pSpeed, Type pType) :
  mType(pType),
  mNameRef(getName(mType)),
  mHealth(pHealth),
  mAttack(pAttack),
  mDefence(pDefence),
  mSpeed(pSpeed) {

}

Pokemon::uint Pokemon::getAttack() const {
  return mAttack;
}

const char* Pokemon::getName() const {
  return mNameRef;
}

bool operator==(const Pokemon& pVal1, const Pokemon& pVal2)
{
  bool result = (
    (pVal1.mType == pVal2.mType) &&
    (pVal1.mNameRef == pVal2.mNameRef) &&
    (pVal1.mHealth == pVal2.mHealth) &&
    (pVal1.mAttack == pVal2.mAttack) &&
    (pVal1.mDefence == pVal2.mDefence) &&
    (pVal1.mSpeed == pVal2.mSpeed)
    );
  return result;
}