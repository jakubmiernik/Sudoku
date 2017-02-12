#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include "mainwindow.h"

class Sudoku
{
private:
	

public:
	// zmieniec tabele na prywatna po debugu 
	int sudokuTable[9][9];		//name convention: sudokuTable[yy][xx]
	Sudoku();
	~Sudoku();
	void generateSudoku();
	bool checkNumber(int xCoordinate, int yCoordinate, int value);
	int* squareCoordinatesToGroupCoordinates(int x, int y);
	void debugPrintSudoku();
};