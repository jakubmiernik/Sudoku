#include "mainwindow.h"
#include <QApplication>
#include <ctime>
#include <string>
#include "Sudoku.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	/*for (int ii = 0; ii < 10; ii++) {
		clock_t begin = clock();
		sudoku->generateSudoku();
		clock_t end = clock();
		sudoku->debugPrintSudoku();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		OutputDebugStringA(std::to_string(elapsed_secs).c_str());
		OutputDebugStringA("\n \n");
	}*/

	int sudokuToSolve[9][9] = { { 0,0,0,8,4,9,1,2,7 },
								{ 9,2,4,1,6,7,8,3,5 },
								{ 7,8,1,3,2,5,4,9,6 },
							    { 6,1,9,7,0,4,2,5,3 },
								{ 4,5,0,2,9,1,6,7,8 },
								{ 8,7,2,5,3,6,9,4,1 },
							    { 2,6,8,9,5,3,0,0,4 },
								{ 3,9,7,4,1,8,0,6,2 },
								{ 1,4,5,6,7,2,3,8,9 }};
	/*  {{5,3,6,8,4,9,1,2,7},
		{ 9,2,4,1,6,7,8,3,5 },
		{ 7,8,1,3,2,5,4,9,6 },
		{ 6,1,9,7,8,4,2,5,3 },
		{ 4,5,3,2,9,1,6,7,8 },
		{ 8,7,2,5,3,6,9,4,1 },
		{ 2,6,8,9,5,3,7,1,4 },
		{ 3,9,7,4,1,8,5,6,2 },
		{ 1,4,5,6,7,2,3,8,9 }
		};*/

	//Sudoku *sudoku2 = new Sudoku(sudokuToSolve);
	//sudoku2->debugPrintSudoku();
	//sudoku2->solveSudoku();
	//sudoku2->debugPrintSudoku();
	
	//Sudoku *sudoku3 = new Sudoku(sudokuToSolve);
	//sudoku3->debugPrintSudoku();

	//Sudoku *sudoku = new Sudoku();
	//sudoku->generateSudokuPuzzle(7);
	//sudoku->debugPrintSudoku();

    return a.exec();
}
