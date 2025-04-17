#include "../includes/astat.hpp"

AStat::AStat(QString name): _name(name) { }

AStat::~AStat () { }

const QString AStat::getName () const
{
  return _name;
}

short AStat::getValue ()
{
  return _value;
}

void  AStat::setValue(short value)
{
  _value = value;
}

QString AStat::toString() const
{
  return _name + " => " + _value;
}
