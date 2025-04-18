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
#include "charactereditdialog.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
  	virtual ~MainWindow() {};

  
private:
  	QMenuBar*	_menuBar;
  	QMenu*      _fileMenu;
  	QAction*    _exitAction;
  	QAction*    _characterBuilderAction;
  
	QMdiArea*				_characterSheetArea;
    QDockWidget*          	_characterListDockWidget;
    CharacterListWidget*	_characterListWidget;
    QVector<Character *>  	_characters;

	QMap<Character *, QMdiSubWindow *> _openCharacterSheets;

    void  createMenus();
    void  createActions();
	
	
	public slots:
	void  openCharacterBuilder();
	void showCharacterSheet(Character* c);
	void refreshCharacterSheet(Character* character);
	void handleViewCharacterButton();
	void handleEditCharacterButton();

signals:
	void showCharacterSheetSignal(Character* c);
	void characterUpdatedSignal(Character* c);
};

