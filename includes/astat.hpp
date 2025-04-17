#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <QString>

class AStat
{
protected:
  class AbilityScoreOutOfRangeException : std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return "Ability Score out of range\n\
              Must be between 1 and 30.";
    }
  };

  class AbilityModifierOutOfRangeException : std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return "Ability Modifier out of range\n\
              Must be between -5 and +10";
    }
  };

  class SkillModifierOutOfRangeException : std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return "Skill Modifier out of range\n\
              Must be between -5 and +10";
    }
  };

  class SavingThrowModifierOutOfRangeException : std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return "Saving Throw Modifier out of range\n\
              Must be between -5 and +10";
    }
  };

  const QString _name;
  short             _value;

public:
  AStat(QString name);
  virtual ~AStat();

  const QString     getName() const;
  short             getValue();
  virtual void      setValue(short value);
  virtual QString   toString() const;

};
