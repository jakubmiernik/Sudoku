#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QtCore>

#include "Config.h"
#include "Square.h"
#include "Sudoku.h"

class Board : public QGraphicsScene
{
private:
	Square *squares[81];
	QPen thickPen;
public:
	Board();
	~Board();
	void clear();
	void fillBoard(int table[9][9]);
	void drawBoard();
	Sudoku getSudoku() const;
	Square* getSquare(int xSquare, int ySquare) const;
};

#endif //BOARD_H