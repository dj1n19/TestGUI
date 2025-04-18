#include "../includes/mainwindow.hpp"
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    // setFixedSize(800, 600);

    createMenus();

    // _characterInfoWidget = new CharacterInfoWidget(this);
	_characterSheetArea = new QMdiArea(this);
    _characterListWidget = new CharacterListWidget(this);
    _characterListDockWidget = new QDockWidget("Character List", this);
    _characterListDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
	_characterListDockWidget->setWidget(_characterListWidget);
	
	setCentralWidget(_characterSheetArea);
	addDockWidget(Qt::LeftDockWidgetArea, _characterListDockWidget);

    connect(_exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(_characterBuilderAction, SIGNAL(triggered(bool)), this, SLOT(openCharacterBuilder()));
    
	connect(this, SIGNAL(showCharacterSheetSignal(Character *)), this, SLOT(showCharacterSheet(Character *)));
}

void MainWindow::openCharacterBuilder()
{
  CharacterBuilderForm  characterBuilderForm(this);

  if (characterBuilderForm.exec() == QDialog::Accepted)
  {
    Character*  c;

    c = characterBuilderForm.createCharacter(CharacterBuilderForm::EType::PLAYER);
    _characterListWidget->addCharacter(c);

	connect(_characterListWidget->last()->getButton(), SIGNAL(clicked()), this, SLOT(handleCharacterButton()));
  }
}

void MainWindow::createActions()
{
  _characterBuilderAction = new QAction("Character Builder", _fileMenu);
  _exitAction = new QAction("Exit", _fileMenu);
}

void MainWindow::createMenus()
{
	_menuBar = new QMenuBar(this);
	_fileMenu = new QMenu("&File", _menuBar);
	_menuBar->addMenu(_fileMenu);

    createActions();
  	_fileMenu->addAction(_characterBuilderAction);
  	_fileMenu->addAction(_exitAction);

	setMenuBar(_menuBar);
}

void MainWindow::showCharacterSheet(Character* c)
{
	if (!c)
		return;

	CharacterSheetWidget* characterSheet = new CharacterSheetWidget(c, this);
	
	QMdiSubWindow* subWindow = _characterSheetArea->addSubWindow(characterSheet);
	subWindow->setWindowTitle(c->getName());
	subWindow->show();
}

void MainWindow::handleCharacterButton()
{
	QPushButton* button = qobject_cast<QPushButton *>(sender());
	if (!button)
		return;

	Character* character = nullptr;
	for (int i = 0; i < _characterListWidget->count(); ++i)
	{
		if (_characterListWidget->itemAt(i)->getButton() == button)
		{
			character = _characterListWidget->itemAt(i)->getCharacter();
			break;
		}
	}

	if (character)
		emit showCharacterSheetSignal(character);	
}