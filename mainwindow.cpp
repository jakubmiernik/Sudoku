#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	sceneBoard = new Board(); //pointer to scene which is Board class
	scene = sceneBoard;
	// sceneBoard and scene point to the same adress 
	// because it cant be execute from scene function from Board which is not in QGraphicsScene
	// by doing it we execute function by Board sceneBoard and it work on scene too

    ui->graphicsView->setScene(scene);
	scene->update();

	connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(genetateButtonAction()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::genetateButtonAction() {

	//TO DO: add widnow which ask for aprove
	Sudoku *generatedSudoku = new Sudoku();
	generatedSudoku->generateSudokuPuzzle(7);
	sceneBoard->fillBoard(generatedSudoku->sudokuTable);

}