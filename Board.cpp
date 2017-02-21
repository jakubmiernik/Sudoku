#include "Board.h"

Board::Board(){
	thickPen = QPen(Qt::black, THICK_PEN_THICKNESS);

	Square *squares[81];
	for (int ii = 0; ii < 81; ii++) {
		squares[ii] = new Square(ii);
		this->addItem(squares[ii]);
	}
	this->drawBoard();
}

Board::~Board(){
}

void Board::drawBoard(){
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
	for (int yy = 0; yy < 9; yy++) {
		for (int xx = 0; xx < 9; xx++) {
			int squareNumber = Square::squareGlobalCoordinatesToGlobalNumber(xx, yy);
			squares[squareNumber].setConstantValue(table[yy][xx]);
		}
	}
}