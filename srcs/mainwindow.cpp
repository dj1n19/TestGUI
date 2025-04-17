#include "../includes/mainwindow.hpp"
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    // setFixedSize(800, 600);

    createMenus();

    // _characterInfoWidget = new CharacterInfoWidget(this);
	_characterInfoArea = new QMdiArea(this);
    _characterListWidget = new CharacterListWidget(this);
    _characterListDockWidget = new QDockWidget("Character List", this);
    _characterListDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
	_characterListDockWidget->setWidget(_characterListWidget);
	
	setCentralWidget(_characterInfoArea);
	addDockWidget(Qt::LeftDockWidgetArea, _characterListDockWidget);

    connect(_exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(_characterBuilderAction, SIGNAL(triggered(bool)), this, SLOT(openCharacterBuilder()));
    
	connect(this, SIGNAL(showCharacterSignal(CharacterInfoWidget *)), this, SLOT(showCharacter(CharacterInfoWidget *)));
}

void MainWindow::openCharacterBuilder()
{
  CharacterBuilderForm  characterBuilderForm(this);

  if (characterBuilderForm.exec() == QDialog::Accepted)
  {
    Character*  c;

    c = characterBuilderForm.createCharacter(CharacterBuilderForm::EType::PLAYER);
    _characterListWidget->addCharacter(c);

	connect(_characterListWidget->last()->getButton(), SIGNAL(clicked()), this, SLOT(createCharacterSheet()));
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

void MainWindow::createCharacterSheet()
{
	emit showCharacterSignal(static_cast<CharacterInfoWidget *>(sender()->parent()));
}

void MainWindow::showCharacter(CharacterInfoWidget *c)
{
	_characterInfoArea->addSubWindow(c);
	std::cout << "SubWindow added " << _characterInfoArea->subWindowList().size() << std::endl;
}