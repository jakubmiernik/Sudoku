#include "Board.h"

Board::Board() : thickPen(QPen(Qt::black, THICK_PEN_THICKNESS)){
	//thickPen = QPen(Qt::black, THICK_PEN_THICKNESS);

	for (int ii = 0; ii < 81; ii++) {
		squares[ii] = new Square(ii);
		this->addItem(squares[ii]);
	}
	this->drawBoard();
}

Board::~Board(){
	for (int ii = 0; ii < 81; ii++) {
		delete squares[ii];
	}
}

void Board::clear() {
	//function to clear all squares on board
	for (int ii = 0; ii < 81; ii++) {
		squares[ii]->clear();
	}
}
void Board::drawBoard(){
	//function frow board (only board without squares)
	for (int ii = 0; ii<3; ii++) {
		for (int jj = 0; jj<3; jj++) {
			//int nBoard = ii * 3 + jj;
			int boardStartX = BOARD_START_POINT + jj*(SINGLE_BOARD_SIZE + OFFSET_BETWEEN_BOARDS);
			int boardStartY = BOARD_START_POINT + ii*(SINGLE_BOARD_SIZE + OFFSET_BETWEEN_BOARDS);
			this->addRect(boardStartX, boardStartY, SINGLE_BOARD_SIZE, SINGLE_BOARD_SIZE, thickPen);
		}
	}
}

void Board::fillBoard(int table[9][9]) {
	//function fill squares with values from table[][]
	this->clear();
	for (int yy = 0; yy < 9; yy++) {
		for (int xx = 0; xx < 9; xx++) {
			int squareNumber = Square::squareGlobalCoordinatesToGlobalNumber(xx+1, yy+1);
			if(table[yy][xx]!= 0)
				squares[squareNumber]->setConstantValue(table[yy][xx]);
		}
	}

}

Sudoku Board::getSudoku() const {
	//function return sudoku which is on board 
	
	int table[9][9];
	for (int yy = 0; yy < 9; yy++) {
		for (int xx = 0; xx < 9; xx++) {
			int squareNumber = Square::squareGlobalCoordinatesToGlobalNumber(xx + 1, yy + 1);
			table[yy][xx] = squares[squareNumber]->getValue();
		}
	}
	Sudoku sudoku = Sudoku(table);
	return sudoku;
}

Square* Board::getSquare(int xSquare, int ySquare) const {
	int number = Square::squareGlobalCoordinatesToGlobalNumber(xSquare + 1, ySquare + 1);
	return squares[number];
}
