#include "../includes/charactereditdialog.hpp"

CharacterEditDialog::CharacterEditDialog(Character* character, QWidget *parent)
	: QDialog(parent), _character(character)
{
	setWindowTitle("Edit Character " + character->getName());

	_nameLabel = new QLabel("Name: ", this);
	_raceLabel = new QLabel("Race: ", this);
	_classLabel = new QLabel("Class: ", this);
	_levelLabel = new QLabel("Level: ", this);

	_nameEdit = new QLineEdit(character->getName(), this);
	_raceEdit = new QComboBox(this);
	_classEdit = new QComboBox(this);
	_levelEdit = new QLineEdit(QString::number(character->getLevel()), this);

	_raceEdit->insertItems(0, RACES);
	_classEdit->insertItems(0, CLASSES);

	int raceIndex = RACES.indexOf(character->getRace());
	int classIndex = CLASSES.indexOf(character->getClass());
	if (raceIndex >= 0)
		_raceEdit->setCurrentIndex(raceIndex);
	if (classIndex >= 0)
		_classEdit->setCurrentIndex(classIndex);
	
	_buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

	_layout = new QGridLayout(this);
	_layout->addWidget(_nameLabel, 0, 0);
	_layout->addWidget(_raceLabel, 1, 0);
	_layout->addWidget(_classLabel, 2, 0);
	_layout->addWidget(_levelLabel, 3, 0);

	_layout->addWidget(_nameEdit, 0, 1);
	_layout->addWidget(_raceEdit, 1, 1);
	_layout->addWidget(_classEdit, 2, 1);
	_layout->addWidget(_levelEdit, 3, 1);

	_layout->addWidget(_buttons, 4, 0, 1, 2);

	setLayout(_layout);

	connect(_buttons, SIGNAL(accepted()), this, SLOT(verify()));
	connect(_buttons, SIGNAL(rejected()), this, SLOT(reject()));
}

CharacterEditDialog::~CharacterEditDialog() {}

void CharacterEditDialog::verify()
{
	if (_nameEdit->text().isEmpty() || _levelEdit->text().isEmpty())
	{
		QMessageBox incompleteForm;
		incompleteForm.setText("Do not leave any fields empty.");
		incompleteForm.setStandardButtons(QMessageBox::Ok);
		incompleteForm.exec();
	}
	else if (_levelEdit->text().toInt() <= 0)
	{
		QMessageBox invalidLevel;
		invalidLevel.setText("Level cannot be less than 1.");
		invalidLevel.setStandardButtons(QMessageBox::Ok);
		invalidLevel.exec();
	}
	else
	{
		applyChanges();
		accept();
	}
}

void CharacterEditDialog::applyChanges()
{
	_character->setName(_nameEdit->text());
	_character->setRace(_raceEdit->currentText());
	_character->setClass(_classEdit->currentText());
	_character->setLevel(_levelEdit->text().toUInt());
}