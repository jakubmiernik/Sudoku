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
	connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearButtonAction()));
	connect(ui->checkButton, SIGNAL(clicked()), this, SLOT(checkButtonAction()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::genetateButtonAction() {
	QMessageBox msgBox;
	msgBox.setWindowTitle("New sudoku");
	msgBox.setIcon(QMessageBox::Question);
	msgBox.setText(trUtf8("Are you sure?"));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::No);
	
	int answer = msgBox.exec();
	if (answer == QMessageBox::Yes) {
		sceneBoard->clear();
		Sudoku *generatedSudoku = new Sudoku();
		generatedSudoku->generateSudokuPuzzle(7);
		sceneBoard->fillBoard(generatedSudoku->sudokuTable);
	}
}

void MainWindow::clearButtonAction() {
	QMessageBox msgBox;
	msgBox.setWindowTitle("Clear sudoku");
	msgBox.setIcon(QMessageBox::Question);
	msgBox.setText(trUtf8("Are you sure?"));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::No);

	int answer = msgBox.exec();
	if (answer == QMessageBox::Yes) {
		sceneBoard->clear();
	}
}

void MainWindow::checkButtonAction() {
	QMessageBox msgBox;
	
	Sudoku sudoku = sceneBoard->getSudoku();
	int bedCell[2];
	std::vector <int> bedCellsCoordinates;	//pair of x,y one pair after another
	bool correct = sudoku.checkSudoku(bedCellsCoordinates);
	if (correct)
		msgBox.setText("Congratulation");
	else {
		msgBox.setText("Try again");
		for (int ii = 0; ii < bedCellsCoordinates.size(); ii = ii + 2) {
			Square* bedSquare = sceneBoard->getSquare(bedCellsCoordinates[ii], bedCellsCoordinates[ii+1]);
			bedSquare->changeColor(Qt::red);
		}
	}
	msgBox.exec();
}