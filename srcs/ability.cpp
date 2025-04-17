#include "../includes/ability.hpp"

Ability::Ability(QString name, short value): AStat(name)
{
  try
  {
    if (value <= 0 || value > 30)
      throw AbilityScoreOutOfRangeException();
    else
      _value = value;
    _modifier = value / 2 - 5;
    if ((_modifier < -5) || (_modifier > 10))
      throw AbilityModifierOutOfRangeException();
  }
  catch (AbilityScoreOutOfRangeException &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
  catch (AbilityModifierOutOfRangeException &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

Ability::~Ability()
{

}

short Ability::getModifier () const
{
  return _modifier;
}

void Ability::setValue (short value)
{
  if (value <= 0 || value > 30)
  {
    throw AbilityScoreOutOfRangeException();
  }
  _value = value;
  _modifier = value / 2 - 5;
  if ((_modifier < -5) || (_modifier > 10))
  {
    throw AbilityModifierOutOfRangeException();
  }
}

QString Ability::toString () const
{
  return _name
        + " => "
        + _value
        + "("
        + _modifier
        + ")";
}
