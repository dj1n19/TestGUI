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
	connect(this, SIGNAL(characterUpdatedSignal(Character *)), this, SLOT(refreshCharacterSheet(Character *)));
}

void MainWindow::openCharacterBuilder()
{
  	CharacterBuilderForm  characterBuilderForm(this);

  	if (characterBuilderForm.exec() == QDialog::Accepted)
  	{
    	Character*  c;

    	c = characterBuilderForm.createCharacter(CharacterBuilderForm::EType::PLAYER);
    	_characterListWidget->addCharacter(c);

		connect(_characterListWidget->last()->getViewButton(), SIGNAL(clicked()), this, SLOT(handleViewCharacterButton()));
		connect(_characterListWidget->last()->getEditButton(), SIGNAL(clicked()), this, SLOT(handleEditCharacterButton()));
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

	if (_openCharacterSheets.contains(c))
	{
		_characterSheetArea->setActiveSubWindow(_openCharacterSheets[c]);
		return ;
	}

	CharacterSheetWidget* characterSheet = new CharacterSheetWidget(c, this);
	
	QMdiSubWindow* subWindow = _characterSheetArea->addSubWindow(characterSheet);
	subWindow->setWindowTitle(c->getName());
	subWindow->show();

	_openCharacterSheets[c] = subWindow;

	connect(subWindow, &QMdiSubWindow::destroyed, [this, c]() {
		_openCharacterSheets.remove(c);
	});
}

void MainWindow::handleViewCharacterButton()
{
	QPushButton* button = qobject_cast<QPushButton *>(sender());
	if (!button)
		return;

	Character* character = nullptr;
	for (int i = 0; i < _characterListWidget->count(); ++i)
	{
		if (_characterListWidget->itemAt(i)->getViewButton() == button)
		{
			character = _characterListWidget->itemAt(i)->getCharacter();
			break;
		}
	}

	if (character)
		emit showCharacterSheetSignal(character);	
}

void MainWindow::handleEditCharacterButton()
{
	QPushButton* button = qobject_cast<QPushButton *>(sender());
	if (!button)
		return;

	Character* character = nullptr;
	for (int i = 0; i < _characterListWidget->count(); ++i)
	{
		if (_characterListWidget->itemAt(i)->getEditButton() == button)
		{
			character = _characterListWidget->itemAt(i)->getCharacter();
			break;
		}
	}

	if (character)
	{
		CharacterEditDialog editDialog(character, this);
		if (editDialog.exec() == QDialog::Accepted)
			emit characterUpdatedSignal(character);
	}
}

void MainWindow::refreshCharacterSheet(Character* character)
{
	if (_openCharacterSheets.contains(character))
	{
		QMdiSubWindow* oldWindow = _openCharacterSheets[character];
		_openCharacterSheets.remove(character);
		_characterSheetArea->removeSubWindow(oldWindow);
		delete oldWindow;

		showCharacterSheet(character);
	}

	for (int i = 0; i < _characterListWidget->count(); ++i)
	{
		CharacterListItem* item = _characterListWidget->itemAt(i);

		if (item->getCharacter() == character)
		{
			item->setTitle(character->getName());
			break;
		}
	}
}