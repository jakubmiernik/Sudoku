#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include "mainwindow.h"
#include "Config.h"

class Sudoku
{
private:

public:
	int sudokuTable[9][9];		//name convention: sudokuTable[yy][xx]
	Sudoku();
	Sudoku(int sSudokuTable[9][9]);
	~Sudoku();
	void generateSudokuPuzzle(int difficultLevel);
	bool solveSudoku();
	void generateSudoku(); // TO DO: move it to private
	bool checkNumber(int xCoordinate, int yCoordinate, int value);
	int* squareCoordinatesToGroupCoordinates(int x, int y);
	void debugPrintSudoku();
};

#endif //SUDOKU_H