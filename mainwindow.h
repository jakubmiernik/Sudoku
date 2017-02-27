#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMessageBox>
#include <algorithm>
#include <vector>

#include "Square.h"
#include "Board.h"
#include "Sudoku.h"
#include "Config.h"
#include "ui_mainwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
	Board *sceneBoard;
private slots:
	void genetateButtonAction();
	void clearButtonAction();
	void checkButtonAction();
};

#endif // MAINWINDOW_H
