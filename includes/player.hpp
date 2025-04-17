#pragma once

#include "character.hpp"

class Player : public Character
{
public:
  Player();
  ~Player();

  void attack(Character &target) const;
};

