#ifndef _AB_POKEMON_HPP_
#define _AB_POKEMON_HPP_

#include "AB\common.hpp"

class Pokemon {
  //TYPES
  typedef unsigned int uint;
public:
  enum Type {
    ptWater = 100,
    ptFire = 200,
    ptEarth = 300
  };

  //MEMBERS
private:
  Type mType;
  const char* mNameRef;

  uint mHealth;
  uint mAttack;
  uint mDefence;
  uint mSpeed;

  static const char* IVYSAUR;
  static const char* CHARIZARD;
  static const char* WAORTORTLE;

  //METHODS
private:
  static const char* getName(Type);
  //AB_DISABLE_COPY(Pokemon);
 
public:
  Pokemon(Type = ptWater);
  Pokemon(uint, uint, uint, uint, Type = ptWater);

  inline uint getHealth() const {
    return mHealth;
  }

  uint getAttack() const;

  const char* getName() const;

  friend bool operator==(const Pokemon&, const Pokemon&);

};


#endif