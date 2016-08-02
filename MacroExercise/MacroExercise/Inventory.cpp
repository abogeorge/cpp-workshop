#include "Inventory.hpp"
#include "Pokemon.hpp"
#include "AB\logger.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE();

Inventory::Inventory() :
  mBackpackSize(2),
  mPokemonCount(0),
  mBackpack(new Pokemon[mBackpackSize])
{

}

void Inventory::addPokemon(const Pokemon& pPokemon)
{
  if (mPokemonCount == mBackpackSize) {
    Pokemon* lnewBackpack = new Pokemon[2 * mBackpackSize];
    for (size_t i = 0; i < mBackpackSize; ++i)
    {
      lnewBackpack[i] = mBackpack[i];
    }
    mBackpack.reset(lnewBackpack);
    mBackpackSize *= 2;
    AB_WARN("Backback size inscreased to: " << mBackpackSize);
  }
    
  mBackpack.get()[mPokemonCount] = pPokemon;
  mPokemonCount++;


}