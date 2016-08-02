#include "AB/common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
#include <limits>
WF_MSW_RESTORE()

#include "AB/logger.hpp"
#include "Pokemon.hpp"
#include "Inventory.hpp"

int main()
{
  Pokemon arr[3] = {};
  Pokemon test(10, 20, 30, 40, Pokemon::ptFire);

  AB_WARN(arr[1].getName());
  AB_WARN(test.getName() << " " << test.getHealth());

  Inventory inv;
  inv.addPokemon(test);
  inv.addPokemon(test);
  inv.addPokemon(test);
  inv.addPokemon(test);
  inv.addPokemon(test);
  inv.addPokemon(test);
  inv.addPokemon(test);

  Pokemon test2 = Pokemon::ptFire;
  AB_WARN(test2.getName());

  AB_WARN(std::boolalpha << (test2 == test));
  AB_WARN(std::boolalpha << (Pokemon::ptFire == test2));


  std::cin.get();
}