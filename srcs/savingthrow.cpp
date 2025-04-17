#include "../includes/savingthrow.hpp"

SavingThrow::SavingThrow(QString name, short value): AStat(name)
{
  try
  {
    if ((value < -5) || (value > 10))
    {
      throw SavingThrowModifierOutOfRangeException();
    }
    _value = value;
  }
  catch (SkillModifierOutOfRangeException &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

SavingThrow::~SavingThrow()
{

}

void SavingThrow::setValue (short value)
{
  if ((value < -5) || (value > 10))
  {
    throw SavingThrowModifierOutOfRangeException();
  }
  _value = value;
}

QString SavingThrow::toString () const
{
  return _name + " => " + _value;
}
