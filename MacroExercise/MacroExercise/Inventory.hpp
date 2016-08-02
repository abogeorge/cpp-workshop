#ifndef  _AB_INVENTORY_HPP_
#define _AB_INVENTORY_HPP_

//#include "Pokemon.hpp"
#include "AB\common.hpp"
#include <memory>

class Pokemon;

class Inventory 
{
  // TYPES

  // MEMBERS
private:
  size_t mBackpackSize;
  size_t mPokemonCount;
  std::unique_ptr<Pokemon[]> mBackpack;
  // METHODS
private:
  AB_DISABLE_COPY(Inventory);
public:
  Inventory();  
  void addPokemon(const Pokemon&);
};

#endif // ! _AB_INVENTORY_HPP_
