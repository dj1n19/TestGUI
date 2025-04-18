#include "../includes/charactersheetwidget.hpp"

CharacterSheetWidget::CharacterSheetWidget(Character* character, QWidget* parent)
	: QWidget(parent), _character(character)
{
	_tabWidget = new QTabWidget(this);
}

CharacterSheetWidget::~CharacterSheetWidget() {}

void CharacterSheetWidget::createMainTab()
{
	_mainTab = new QWidget(this);
	_mainLayout = new QGridLayout(_mainTab);
	_nameLabel = new QLabel("Name: " + _character->getName(), _mainTab);
	_raceLabel = new QLabel("Name: " + _character->getRace(), _mainTab);
	_classLabel = new QLabel("Name: " + _character->getClass(), _mainTab);
	_levelLabel = new QLabel("Name: " + _character->getLevel(), _mainTab);

	_mainLayout->addWidget(_nameLabel, 0, 0);
	_mainLayout->addWidget(_raceLabel, 1, 0);
	_mainLayout->addWidget(_classLabel, 2, 0);
	_mainLayout->addWidget(_levelLabel, 3, 0);
	_mainTab->setLayout(_mainLayout);
	_tabWidget->addTab(_mainTab, "Character Info");
}