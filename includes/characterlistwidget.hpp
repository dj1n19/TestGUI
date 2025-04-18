#pragma once

#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include <QPushButton>

#include "character.hpp"
#include "characterlistitem.hpp"

class CharacterListWidget : public QGroupBox
{
  Q_OBJECT
public:
  explicit CharacterListWidget(QWidget *parent = nullptr);

  void addCharacter(Character* c);

  CharacterListItem* last();
  CharacterListItem* itemAt(unsigned int index);

  int count() const;

private:
  QVBoxLayout*  _layout;
  QVector<CharacterListItem *> _items;

public slots:

signals:

};

