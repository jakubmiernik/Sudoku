#include "Sudoku.h"

Sudoku::Sudoku(){
	std::fill(sudokuTable[0] + 0, sudokuTable[8] + 9, 0);
	/*int tmp[9][9] =	  { { 0,0,0,0,0,0,0,0,0 },
						{ 0,3,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,0,0,0,0,0 },
						{ 1,2,3,4,5,6,7,8,9 } };
	for (int xx = 0; xx < 9; xx++) {
		for (int yy = 0; yy < 9; yy++) {
			sudokuTable[xx][yy] = tmp[xx][yy];
		}
	}*/
}

Sudoku::Sudoku(int sSudokuTable[9][9]) {
	for (int xx = 0; xx < 9; xx++) {
		for (int yy = 0; yy < 9; yy++) {
			sudokuTable[xx][yy] = sSudokuTable[xx][yy];
		}
	}
}

Sudoku::~Sudoku(){
}

void Sudoku::generateSudokuPuzzle(int difficultLevel) {
	// function to generate sudoku puzzle from full solved sudoku
	// generating take place by diging hols in full solved sudoku

	// first generate full solved sudoku
	this->generateSudoku();

	int cellsToClear = 0;
	int numberOfEmpty = 0;
	srand(time(NULL));

	int watchdog = 0;
	// next dig the holes
	while (cellsToClear > numberOfEmpty) {
		watchdog++;
		// select random cell to clear;
		int x = rand() % 9;
		int y = rand() % 9;

		// clear this cell but remember this value
		int selectedValue = sudokuTable[y][x];
		sudokuTable[y][x] = 0;

		//check if sudoku can be solved without this value
		Sudoku *tmpSudoku = new Sudoku(sudokuTable);
		if (tmpSudoku->solveSudoku()) {
			numberOfEmpty++;
		}
		else {
			sudokuTable[y][x] = selectedValue;
		}
		if (watchdog > 10000) {
			break;
			OutputDebugStringA("Loop killed by watchdog");
		}
			
	}
}

bool Sudoku::solveSudoku() {
	// function to solve sudoku if it is not solved
	// this function using recursion to solve sudoku

	int row, col;
	//finding empty cell
	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (sudokuTable[row][col] == EMPTY_VALUE) {
				// goto use to exit both loop same time 
				// and by the way jump over return
				goto end_loops;
			}			
		}
	}
	// return true if there is no empty cells
	return true;

	// enter here if find empty cell
end_loops:

	// loop over possible numbers
	for(int ii=1; ii<10; ii++){
		// for each number check if it fit in empty place
		if ((this->checkNumber(col, row, ii)) == true) {
			// if fits place it in sudoku and try solve sudoku with this number
			sudokuTable[row][col] = ii;
			if (solveSudoku())
				// if sudoku solved with this number return true
				return true;
			else
				//else make this number 0
				sudokuTable[row][col] = EMPTY_VALUE;
		}
	}
	return false;
}

void Sudoku::generateSudoku(){
	//function to generate new full complit sudoku
	// this algorythm generate sudoku in time about 0.0035s

	std::vector <int> possibleNumbers;
	srand(time(NULL));
	//watchdog to kill generating and start new one if it take to much time
	int watchdogCounter = 0; 
	for (int yy = 0; yy < 9; yy++) {
		watchdogCounter++;
		if (watchdogCounter > 1000) {
			watchdogCounter = 0;
			yy = 0;
			this->clear();
		}
		//filling the vector of possible numbers for yy row
		possibleNumbers.clear();
		for (int jj = 1; jj < 10; jj++) {
			possibleNumbers.push_back(jj);
		}
		for (int xx = 0; xx < 9; xx++) {
			int number = 0;
			int random = 0;
			int counter = 0;
			// loop which rendom number from posible for this row 
			// and check if it fit to other numbers in sudoku
			// if not, rerandom number
			do {
				random = rand() % possibleNumbers.size();
				number = possibleNumbers[random];
				counter++;
			} while (checkNumber(xx, yy, number) == false && counter < 20);
			// if 10 times program cant fit number  
			// remove this row and redo this row
			if (counter >= 20) {
				for (int iitmp = 0; iitmp < 9; iitmp++) {
					sudokuTable[yy][iitmp] = 0;
				}
				for (int ii = 0; ii < 9; ii++) {
					sudokuTable[yy][ii] = 0;
				}
				yy--;
				break;
			}
			// if number fit to sudoku this number is insert to it
			// and this number is remove from vector of possible numbers for this row
			sudokuTable[yy][xx] = number;
			possibleNumbers.erase(possibleNumbers.begin() + random);
		}
	}
	this->debugPrintSudoku();
}

bool Sudoku::checkNumber(int xCoordinate, int yCoordinate, int value) {
	//function check if number witch 'value' vaule can be on position (xCoordinate, yCoordinate)
	// in our Sudoku table 
	// if return true - this number can be on this position

	//checking rows and columns
	for (int ii = 0; ii < 9; ii++) {
		if (sudokuTable[yCoordinate][ii] == value && yCoordinate != ii) {
			return false;
		}
		if (sudokuTable[ii][xCoordinate] == value && xCoordinate != ii) {
			return false;
		}
	}
	//checking 3x3 group
	int* groupNumber = this->squareCoordinatesToGroupCoordinates(xCoordinate, yCoordinate);
	for (int yy = 0; yy < 3; yy++) {
		for (int xx = 0; xx < 3; xx++) {
			int squareX = (groupNumber[0] - 1) * 3 + xx;
			int squareY = (groupNumber[1] - 1) * 3 + yy;
			if (sudokuTable[squareY][squareX] == value) {
				return false;
			}
		}
	}
	return true;
}

bool Sudoku::checkSudoku() {
	//function check if sudoku in sudokuTable[] is correct
	bool correct = true;
	for (int xx = 0; xx < 9; xx++) {
		for (int yy = 0; yy < 9; yy++) {
			if (!(this->checkNumber(xx, yy, sudokuTable[yy][xx]))) {
				correct = false;
				break;
			}
		}
	}
	return correct;
}

int* Sudoku::squareCoordinatesToGroupCoordinates(int x, int y) {
	// TO DO: zamiast zwracac tablice lepiej podawac ja do wypelnienai przez referencje 
	// function to get number of sudoku group (3x3) for given number on position (x,y)

	int groupX = 0;
	int groupY = 0;
	if (x >= 0 && x < 3) groupX = 1;
	else if (x >= 3 && x < 6) groupX = 2;
	else if (x >= 6 && x < 9) groupX = 3;

	if (y >= 0 && y < 3) groupY = 1;
	else if (y >= 3 && y < 6) groupY = 2;
	else if (y >= 6 && y < 9) groupY = 3;

	int groupCoordinates[2] = { groupX , groupY};
	return groupCoordinates;
}

void Sudoku::debugPrintSudoku() {
	// simple function to draw on screen sudoku puzzle

	for (int yy = 0; yy < 9; yy++) {
		for (int xx = 0; xx < 9; xx++) {
			OutputDebugStringA(std::to_string(sudokuTable[yy][xx]).c_str());
			OutputDebugStringA(" ");
		}
		OutputDebugStringA("\n");
	}
	OutputDebugStringA("\n");
}

void Sudoku::clear() {
	std::fill(sudokuTable[0] + 0, sudokuTable[8] + 9, 0);
}