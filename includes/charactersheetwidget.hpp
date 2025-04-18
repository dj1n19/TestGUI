#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>

#include "character.hpp"

class CharacterSheetWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CharacterSheetWidget(Character* character, QWidget *parent = nullptr);
	~CharacterSheetWidget();

private:

	QTabWidget* 	_tabWidget;
	
	Character* _character;
	
	// Main Tab
	QWidget*  		_mainTab;
	QGridLayout* 	_mainLayout;

	QLabel* _nameLabel;
	QLabel* _raceLabel;
	QLabel* _classLabel;
	QLabel* _levelLabel;

	void createMainTab();
};