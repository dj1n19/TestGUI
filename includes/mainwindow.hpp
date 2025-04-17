#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QVector>
#include <QMdiArea>

#include "characterbuilderform.hpp"
#include "characterinfowidget.hpp"
#include "characterlistwidget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow() {};

//   CharacterInfoWidget* getCharacterInfoWidget();

public slots:
  void  openCharacterBuilder();

private:
	QMenuBar*	_menuBar;
	QMenu*      _fileMenu;
    QAction*    _exitAction;
    QAction*    _characterBuilderAction;

	QMdiArea*						_characterInfoArea;
    QDockWidget*          			_characterListDockWidget;
    CharacterListWidget*  			_characterListWidget;
    QVector<CharacterInfoWidget *>  _characterInfoWidgets;

    // QGridLayout*  _layout;

    void  createMenus();
    void  createActions();

public slots:
	void showCharacter(CharacterInfoWidget *c);
	void createCharacterSheet();

signals:
	void showCharacterSignal(CharacterInfoWidget *c);
};

