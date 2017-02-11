#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(this);
	scene = new Board();
    ui->graphicsView->setScene(scene);
	
	Square *squares[81];
	for (int ii = 0; ii < 81; ii++) {
		squares[ii] = new Square(ii);
		scene->addItem(squares[ii]);
	}
	scene->update();
	/*Square* square = new Square(0);
	scene->addItem(square);
	scene->update();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
