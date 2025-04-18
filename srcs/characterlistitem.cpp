#include "../includes/characterlistitem.hpp"

CharacterListItem::CharacterListItem(Character* character, QWidget* parent)
	: _character(character), QWidget(parent)
{
	_button = new QPushButton(character->getName(), parent);
}

CharacterListItem::~CharacterListItem() {}

Character* CharacterListItem::getCharacter() const
{
	return _character;
}

QPushButton* CharacterListItem::getButton() const
{
	return _button;
}