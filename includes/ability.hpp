#pragma once

#include "astat.hpp"

class Ability : public AStat
{
public:
  Ability(QString name, short value);
  ~Ability();

  short getModifier() const;

  void setValue(short value);
  QString toString() const;

private:
  short _modifier;
};
