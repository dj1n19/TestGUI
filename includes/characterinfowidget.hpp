#pragma once

#include <QPushButton>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QString>

#include "character.hpp"

class CharacterInfoWidget : public QGroupBox
{
  Q_OBJECT
public:
  explicit CharacterInfoWidget(QWidget *parent = nullptr);
  CharacterInfoWidget(Character* character, QWidget *parent = nullptr);

  QPushButton*  getButton();

public slots:

signals:

private:
  QPushButton*  _button;
  QGridLayout*  _layout;

  QLabel*  _nameLabel;
  QLabel*  _raceLabel;
  QLabel*  _classLabel;
  QLabel*  _levelLabel;

  Character*  _character;

};

