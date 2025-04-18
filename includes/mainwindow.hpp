#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QVector>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "characterbuilderform.hpp"
#include "characterlistwidget.hpp"
#include "charactersheetwidget.hpp"

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

	QMdiArea*				_characterSheetArea;
    QDockWidget*          	_characterListDockWidget;
    CharacterListWidget*	_characterListWidget;
    QVector<Character *>  	_characters;

    // QGridLayout*  _layout;

    void  createMenus();
    void  createActions();

public slots:
	void showCharacterSheet(Character* c);
	void handleCharacterButton();

signals:
	void showCharacterSheetSignal(Character* c);
};

