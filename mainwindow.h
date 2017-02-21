#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMessageBox>

#include "Config.h"
#include "ui_mainwindow.h"
#include "Square.h"


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
	//Board *sceneBoard;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
private slots:
	void genetateButtonAction();
};

#endif // MAINWINDOW_H
