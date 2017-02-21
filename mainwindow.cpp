#include "mainwindow.h"
#include "Board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	Board *sceneBoard = new Board(); //pointer to scene which is Board class
	scene = sceneBoard;
	// sceneBoard and scene point to the same adress 
	// because it cant be execute from scene function from Board which is not in QGraphicsScene
	// by doing it we execute function by Board sceneBoard and it work on scene too

    ui->graphicsView->setScene(scene);
	scene->update();

	connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(genetateButtonAction()));

	int sudokuToSolve[9][9] = { { 0,0,0,8,4,9,1,2,7 },
								{ 9,2,4,1,6,7,8,3,5 },
								{ 7,8,1,3,2,5,4,9,6 },
								{ 6,1,9,7,0,4,2,5,3 },
								{ 4,5,0,2,9,1,6,7,8 },
								{ 8,7,2,5,3,6,9,4,1 },
								{ 2,6,8,9,5,3,0,0,4 },
								{ 3,9,7,4,1,8,0,6,2 },
								{ 1,4,5,6,7,2,3,8,9 } };


	sceneBoard->fillBoard(sudokuToSolve);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::genetateButtonAction() {
	QMessageBox msgBox;
	msgBox.setText("asd");
	msgBox.exec();

	//Sudoku *generatedSudoku = new Sudoku();
	//generatedSudoku->generateSudokuPuzzle(7);
	//scene->fillBoard(generatedSudoku->sudokuTable);

}