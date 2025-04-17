#pragma once

#include "astat.hpp"

class Skill : public AStat
{
public:
  Skill(QString name, short value);
  ~Skill();

  void      setValue (short value);
  QString   toString () const;
private:

};

