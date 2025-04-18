#include "../includes/characterlistitem.hpp"

CharacterListItem::CharacterListItem(Character* character, QWidget* parent)
	: _character(character), QGroupBox(parent)
{
	_viewButton = new QPushButton("View", this);
	_editButton = new QPushButton("Edit", this);

	_layout = new QHBoxLayout(this);
	_layout->addWidget(_viewButton);
	_layout->addWidget(_editButton);
	setLayout(_layout);
	setTitle(character->getName());
}

CharacterListItem::~CharacterListItem() {}

Character* CharacterListItem::getCharacter() const
{
	return _character;
}

QPushButton* CharacterListItem::getViewButton() const
{
	return _viewButton;
}

QPushButton* CharacterListItem::getEditButton() const
{
	return _editButton;
}