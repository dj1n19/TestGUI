#include "../includes/characterlistwidget.hpp"

CharacterListWidget::CharacterListWidget(QWidget *parent)
  : QGroupBox(parent)
{
  _layout = new QVBoxLayout(this);
  _layout->setDirection (QBoxLayout::TopToBottom);
  _layout->setAlignment(Qt::AlignTop);

  setLayout(_layout);
  setTitle("Characters");
}

void CharacterListWidget::addCharacter(Character *c)
{
  	if (!c)
		return ;
	CharacterListItem* item = new CharacterListItem(c, this);
	_items.push_back(item);
  	_layout->addWidget(item->getButton());

  	// connect(_characters.last(), SIGNAL(released()), _characters.last(), SLOT(showCharacter()));
}

CharacterListItem* CharacterListWidget::last()
{
	return _items.isEmpty() ? nullptr : _items.last();
}

CharacterListItem* CharacterListWidget::itemAt(unsigned int index)
{
	return (index >= 0 && index < _items.size()) ? _items.at(index) : nullptr;
}

int CharacterListWidget::count() const
{
	return _items.size();
}