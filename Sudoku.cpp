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
	this->generateSudoku();
}

Sudoku::~Sudoku(){
}

void Sudoku::generateSudoku(){
	//function to generate new full complit sudoku
	// this algorythm generate sudoku in time about 0.0035s

	std::vector <int> possibleNumbers;
	srand(time(NULL));
	for (int yy = 0; yy < 9; yy++) {
		//filling the vector of possible numbers for yy row
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
			} while (checkNumber(xx, yy, number) == false && counter < 10);
			// if 10 times program cant fit number  
			// remove this row and redo this row
			if (counter >= 10) {
				for (int iitmp = 0; iitmp < 9; iitmp++) {
					sudokuTable[yy][iitmp] = 0;
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
}

bool Sudoku::checkNumber(int xCoordinate, int yCoordinate, int value) {
	//function check if number witch 'value' vaule can be on position (xCoordinate, yCoordinate)
	// in our Sudoku table 
	// if return true - this number can be on this position
	bool answer = true;
	//checking rows and columns
	for (int ii = 0; ii < 9; ii++) {
		if (sudokuTable[yCoordinate][ii] == value) {
			answer = false;
			break;
		}
		if (sudokuTable[ii][xCoordinate] == value) {
			answer = false;
			break;
		}
	}
	//checking 3x3 group
	int* groupNumber = this->squareCoordinatesToGroupCoordinates(xCoordinate, yCoordinate);
	for (int yy = 0; yy < 3; yy++) {
		for (int xx = 0; xx < 3; xx++) {
			int squareX = (groupNumber[0] - 1) * 3 + xx;
			int squareY = (groupNumber[1] - 1) * 3 + yy;
			if (sudokuTable[squareY][squareX] == value) {
				answer = false;
				break;
			}
		}
	}
	return answer;
}

int* Sudoku::squareCoordinatesToGroupCoordinates(int x, int y) {
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
	for (int yy = 0; yy < 9; yy++) {
		for (int xx = 0; xx < 9; xx++) {
			OutputDebugStringA(std::to_string(sudokuTable[yy][xx]).c_str());
			OutputDebugStringA(" ");
		}
		OutputDebugStringA("\n");
	}
}