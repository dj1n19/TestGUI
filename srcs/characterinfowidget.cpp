#include "../includes/characterinfowidget.hpp"

CharacterInfoWidget::CharacterInfoWidget(QWidget *parent)
  : QGroupBox{parent} {}

CharacterInfoWidget::CharacterInfoWidget(Character* character, QWidget *parent)
  : QGroupBox{parent}, _character(character)
{
  _button = new QPushButton(_character->getName(), parent);

  _layout = new QGridLayout(this);
  // _layout->setDirection (QBoxLayout::TopToBottom);
  _layout->setAlignment(Qt::AlignTop);

  _nameLabel = new QLabel(this);
  _raceLabel = new QLabel(this);
  _classLabel = new QLabel(this);
  _levelLabel = new QLabel(this);

  _layout->addWidget(_nameLabel, 0, 0);
  _layout->addWidget(_raceLabel, 1, 0);
  _layout->addWidget(_classLabel, 2, 0);
  _layout->addWidget(_levelLabel, 3, 0);

  setLayout (_layout);

  _nameLabel->setText ("Name: " + _character->getName ());
  _raceLabel->setText ("Race: " + _character->getRace ());
  _classLabel->setText ("Class: " + _character->getClass ());
  _levelLabel->setText ("Level: " + QString::number(_character->getLevel ()));
}

QPushButton* CharacterInfoWidget::getButton()
{
  return _button;
}