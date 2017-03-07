#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <Windows.h>

#include "Config.h"
#include "Square.h"


class Sudoku
{
private:
	int sudokuTable[9][9];		// name convention: sudokuTable[yy][xx]
	void generateSudoku();
	bool solveSudoku();
public:
	Sudoku();
	explicit Sudoku(int sSudokuTable[9][9]);
	~Sudoku();
	void generateSudokuPuzzle(int difficultLevel);
	bool checkNumber(int xCoordinate, int yCoordinate, int value);
	bool checkSudoku(std::vector <int>& bedCellsCoordinates);
	void squareCoordinatesToGroupCoordinates(int x, int y, int groupCoordinates[2]);
	void debugPrintSudoku();
	void clear();
	void getSudokuTable(int sSudokuTable[9][9]) const;
};

#endif //SUDOKU_H