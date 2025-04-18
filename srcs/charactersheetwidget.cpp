#include "../includes/charactersheetwidget.hpp"

CharacterSheetWidget::CharacterSheetWidget(Character* character, QWidget* parent)
	: QWidget(parent), _character(character)
{
	QVBoxLayout* layout = new QVBoxLayout(this);

	_tabWidget = new QTabWidget(this);
	layout->addWidget(_tabWidget);

	createMainTab();

	setLayout(layout);
	setWindowTitle(character->getName());
}

CharacterSheetWidget::~CharacterSheetWidget() {}

void CharacterSheetWidget::createMainTab()
{
	_mainTab = new QWidget(this);
	_mainLayout = new QGridLayout(_mainTab);
	_nameLabel = new QLabel("Name: " + _character->getName(), _mainTab);
	_raceLabel = new QLabel("Race: " + _character->getRace(), _mainTab);
	_classLabel = new QLabel("Class: " + _character->getClass(), _mainTab);
	_levelLabel = new QLabel("Level: " + QString::number(_character->getLevel()), _mainTab);

	_mainLayout->addWidget(_nameLabel, 0, 0);
	_mainLayout->addWidget(_raceLabel, 1, 0);
	_mainLayout->addWidget(_classLabel, 2, 0);
	_mainLayout->addWidget(_levelLabel, 3, 0);

	_mainLayout->setColumnStretch(1, 1);
	_mainLayout->setRowStretch(4, 1);

	_mainTab->setLayout(_mainLayout);
	_tabWidget->addTab(_mainTab, "Character Info");
}