#include "../includes/characterlistwidget.hpp"

CharacterListWidget::CharacterListWidget(QWidget *parent)
  : QGroupBox{parent}
{
  _layout = new QVBoxLayout(this);
  _layout->setDirection (QBoxLayout::TopToBottom);
  _layout->setAlignment(Qt::AlignTop);

  setLayout(_layout);
}

void CharacterListWidget::addCharacter(Character *c)
{
  	if (!c)
		return ;
	_characters.push_back(new CharacterInfoWidget(c, this));
  	_layout->addWidget(_characters.last()->getButton());

  	// connect(_characters.last(), SIGNAL(released()), _characters.last(), SLOT(showCharacter()));
}

CharacterInfoWidget* CharacterListWidget::last()
{
	return _characters.last();
}