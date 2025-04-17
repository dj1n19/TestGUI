#pragma once

#include <string>
#include <QPixmap>

class Character
{
public:
    Character();
    virtual ~Character();

    // setters
    void setName(QString n);
    void setClass(QString c);
    void setRace(QString r);
    void setLevel(unsigned char l);
    void setPoficiencyBonus(unsigned char p);
    void setInitiative(unsigned char i);
    void setArmorClass(unsigned char a);
    void setMaxHP(unsigned int h);
    void setCurrentHP(unsigned int h);
    void setTempHP(unsigned int h);
    void setPortrait(QPixmap& p);

    // getters
    QString     getName() const;
    QString     getClass() const;
    QString     getRace() const;
    unsigned char   getLevel() const;
    unsigned char   getProficiencyBonus() const;
    unsigned char   getInitiative() const;
    unsigned char   getArmorClass() const;
    unsigned int    getMaxHP() const;
    unsigned int    getCurrentHP() const;
    unsigned int    getTempHP() const;
    QPixmap         getPortrait() const;

//    unsigned char   getAbility(QString a) const;
//    unsigned char   getProficiency(QString p) const;
//    unsigned char   getSavingThrow(QString s) const;
//    unsigned char   getSkill(QString s) const;

    virtual void attack(Character &target) const = 0;


protected:
    QString         _name;
    QString         _class;
    QString         _race;
    unsigned char       _level;
    unsigned char       _proficiencyBonus;
    unsigned char       _initiative;
    unsigned char       _armorClass;
    unsigned char       _speed;
    unsigned int        _maxHP;
    unsigned int        _currentHP;
    unsigned int        _tempHP;

    QPixmap*  _portrait;

//    Abilities           _abilities;
//    Proficiencies       _proficiencies;
//    SavingThrows        _SavingThrows;
//    Skills              _skills;
};

