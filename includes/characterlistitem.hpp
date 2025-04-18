#pragma once

#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>

#include "character.hpp"

// Helper class to hold character and button together
class CharacterListItem : public QGroupBox
{
	Q_OBJECT
public:
	CharacterListItem(Character* character, QWidget *parent = nullptr);
	~CharacterListItem();

	Character* getCharacter() const;
	QPushButton* getViewButton() const;
	QPushButton* getEditButton() const;

private:
	Character*		_character;
	QPushButton* 	_viewButton;
	QPushButton* 	_editButton;
	QHBoxLayout* 	_layout;
};