#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	scene = new Board();
    ui->graphicsView->setScene(scene);

	scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
