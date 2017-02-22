#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QtCore>

#include "Config.h"
#include "Square.h"

class Board : public QGraphicsScene
{
private:
	Square *squares[81];
	QPen thickPen;
public:
	Board();
	~Board();
	void clear();
	void drawBoard();
	void fillBoard(int table[9][9]);
};

#endif //BOARD_H