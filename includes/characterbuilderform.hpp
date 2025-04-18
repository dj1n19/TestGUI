#pragma once

#include <QLabel>
#include <QDialog>
#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QDialogButtonBox>

#include "character.hpp"
#include "player.hpp"
#include "lists.hpp"

class CharacterBuilderForm : public QDialog
{
  Q_OBJECT
public:

  enum class EType
  {
    PLAYER,
    PNJ,
    MONSTER
  };

  explicit CharacterBuilderForm(QWidget *parent = nullptr);

  Character* createCharacter(EType type);

public slots:
  void verify();

private:
  QGridLayout*      _layout;
  QDialogButtonBox* _buttons;

  QLabel*  _nameLabel;
  QLabel*  _classLabel;
  QLabel*  _raceLabel;
  QLabel*  _levelLabel;

  QLineEdit* _nameInput;
  QComboBox* _classInput;
  QComboBox* _raceInput;
  QLineEdit* _levelInput;

  Character* createPlayer();

signals:

};

