#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Config.h"
#include "Square.h"
//#include "Board.h"


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
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
//private slots:
	//void genetateButtonAction();
};

#endif // MAINWINDOW_H
