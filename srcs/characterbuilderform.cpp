#include "../includes/characterbuilderform.hpp"

CharacterBuilderForm::CharacterBuilderForm(QWidget *parent)
  : QDialog(parent)
{
  _nameLabel = new QLabel("Name", this);
  _classLabel = new QLabel("Class", this);
  _raceLabel = new QLabel("Race", this);
  _levelLabel = new QLabel("Level", this);

  _nameInput = new QLineEdit(this);
  _classInput = new QComboBox(this);
  _raceInput = new QComboBox(this);
  _levelInput = new QLineEdit(this);

  _raceInput->insertItems (0, RACES);
  _classInput->insertItems (0, CLASSES);

  _buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

  _layout = new QGridLayout(this);
  _layout->addWidget(_nameLabel, 0, 0);
  _layout->addWidget(_classLabel, 1, 0);
  _layout->addWidget(_raceLabel, 2, 0);
  _layout->addWidget(_levelLabel, 3, 0);

  _layout->addWidget(_nameInput, 0, 1);
  _layout->addWidget(_classInput, 1, 1);
  _layout->addWidget(_raceInput, 2, 1);
  _layout->addWidget(_levelInput, 3, 1);

  _layout->addWidget (_buttons, 4, 1);

  setLayout (_layout);

  connect(_buttons, SIGNAL(accepted()), this, SLOT(verify()));
  connect(_buttons, SIGNAL(rejected ()), this, SLOT(reject()));
}

void CharacterBuilderForm::verify()
{
  if (!_nameInput->text().isEmpty() && !_levelInput->text().isEmpty())
    accept();
  else
  {
    QMessageBox incompleteForm;
    incompleteForm.setText("Some fields were left empty.");
    incompleteForm.setStandardButtons(QMessageBox::Ok);
    incompleteForm.exec();
  }
}

Character* CharacterBuilderForm::createPlayer ()
{
  Character* c = new Player();

  c->setName(_nameInput->text());
  c->setClass(_classInput->currentText());
  c->setRace(_raceInput->currentText());
  c->setLevel(static_cast<unsigned char>(_levelInput->text().toUInt()));

  return c;
}

Character* CharacterBuilderForm::createCharacter (EType type)
{
  switch (type)
  {
    case EType::PLAYER :
      return createPlayer();
      break;
    case EType::PNJ :
      break;
    case EType::MONSTER :
      break;
  }

  return nullptr;
}
