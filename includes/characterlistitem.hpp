#pragma once

#include <QWidget>
#include <QPushButton>

#include "character.hpp"

// Helper class to hold character and button together
class CharacterListItem : public QWidget
{
	Q_OBJECT
public:
	CharacterListItem(Character* character, QWidget *parent = nullptr);
	~CharacterListItem();

	Character* getCharacter() const;
	QPushButton* getButton() const;

private:
	Character* _character;
	QPushButton* _button;
};