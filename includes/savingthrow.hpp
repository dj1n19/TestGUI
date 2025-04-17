#pragma once

#include "astat.hpp"

class SavingThrow : public AStat
{
public:
  SavingThrow(QString name, short value);
  ~SavingThrow();

  void    setValue(short value);
  QString toString() const;
};

