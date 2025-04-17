#include "../includes/character.hpp"

Character::Character()
{

}

Character::~Character () {}

void Character::setName(QString n)
{
    _name = n;
}

void Character::setClass(QString c)
{
  _class = c;
}

void Character::setRace (QString r)
{
  _race = r;
}

void Character::setLevel(unsigned char l)
{
    _level = l;
}

void Character::setPoficiencyBonus (unsigned char p)
{
    _proficiencyBonus = p;
}

void Character::setInitiative (unsigned char i)
{
    _initiative = i;
}

void Character::setArmorClass (unsigned char a)
{
    _armorClass = a;
}

void Character::setMaxHP (unsigned int h)
{
    _maxHP = h;
}

void Character::setCurrentHP (unsigned int h)
{
    _currentHP = h;
}

void Character::setTempHP (unsigned int h)
{
    _tempHP = h;
}

void Character::setPortrait(QPixmap& p)
{
  _portrait = &p;
}

QString Character::getName () const
{
    return _name;
}

QString Character::getClass() const
{
  return _class;
}

QString Character::getRace () const
{
  return _race;
}

unsigned char Character::getLevel () const
{
    return _level;
}
unsigned char Character::getProficiencyBonus () const
{
    return _proficiencyBonus;
}

unsigned char Character::getInitiative () const
{
    return _initiative;
}

unsigned char Character::getArmorClass () const
{
    return _armorClass;
}

unsigned int Character::getMaxHP () const
{
    return _maxHP;
}

unsigned int Character::getCurrentHP () const
{
    return _currentHP;
}

unsigned int Character::getTempHP () const
{
    return _tempHP;
}

QPixmap Character::getPortrait() const
{
  return *_portrait;
}

//unsigned char Character::getAbility (QString a) const
//{

//}

//unsigned char Character::getProficiency (QString p) const
//{

//}

//unsigned char Character::getSavingThrow (QString s) const
//{

//}

//unsigned char Character::getSkill (QString s) const
//{

//}
