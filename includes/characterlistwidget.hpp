#pragma once

#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include <QPushButton>

#include "characterinfowidget.hpp"

class CharacterListWidget : public QGroupBox
{
  Q_OBJECT
public:
  explicit CharacterListWidget(QWidget *parent = nullptr);

  void addCharacter(Character* c);

  CharacterInfoWidget* last();

private:
  QVBoxLayout*  _layout;
  QVector<CharacterInfoWidget *> _characters;

public slots:

signals:

};

