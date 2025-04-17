#include "../includes/skill.hpp"

Skill::Skill(QString name, short value): AStat(name)
{
  try
  {
    if ((value < -5) || (value > 10))
      throw SkillModifierOutOfRangeException();
    _value = value;
  }
  catch(SkillModifierOutOfRangeException &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

Skill::~Skill ()
{

}

void Skill::setValue(short value)
{
  if ((value < -5) || (value > 10))
      throw SkillModifierOutOfRangeException();
  _value = value;
}

QString Skill::toString () const
{
  return _name + " => " + _value;
}
