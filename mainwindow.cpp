#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Board.h"
#include "Sudoku.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	Board *tmp = new Board();
	scene = tmp;
    ui->graphicsView->setScene(scene);

	scene->update();
	//connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(genetateButtonAction()));

	Sudoku *generatedSudoku = new Sudoku;
	generatedSudoku->generateSudokuPuzzle(7);
	//tmp->fillBoard(generatedSudoku->sudokuTable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::genetateButtonAction() {
//	QMessageBox msgBox;
//	msgBox.setText("asd");
//	msgBox.exec();
//
//	//Sudoku *generatedSudoku = new Sudoku;
//	//generatedSudoku->generateSudokuPuzzle(7);
//	//scene->fillBoard(generatedSudoku->sudokuTable);
//
//}