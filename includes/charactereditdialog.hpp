#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "character.hpp"
#include "lists.hpp"

class CharacterEditDialog : public QDialog
{
	Q_OBJECT
public:
	CharacterEditDialog(Character* character, QWidget *parent = nullptr);
	~CharacterEditDialog();

	void applyChanges();

public slots:
	void verify();

private:
	Character* _character;

	QGridLayout* _layout;
	QDialogButtonBox* _buttons;

	QLabel* _nameLabel;
	QLabel* _raceLabel;
	QLabel* _classLabel;
	QLabel* _levelLabel;

	QLineEdit* _nameEdit;
	QComboBox* _raceEdit;
	QComboBox* _classEdit;
	QLineEdit* _levelEdit;
};