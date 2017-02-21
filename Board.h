#include "ui_mainwindow.h"
#include "Square.h"
#include "Config.h"

class Board : public QGraphicsScene
{
private:
	Square squares[81];
	QPen thickPen;
public:
	Board();
	~Board();
	void drawBoard();
	void fillBoard(int table[9][9]);
};