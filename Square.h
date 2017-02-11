#pragma once
#include "mainwindow.h"
#include "Config.h"
#include <QGraphicsSceneMouseEvent>

class Square : public QGraphicsItem
{
private:
	int sSquareNumber;			//number of square (0-81) 
	double sStartLocationX;		//start locatins of square on board
	double sStartLocationY;
	int sXCoordinate;			//coordinates of square (1-9) x (1-9)
	int sYCoordinate;
	int sValue;					//value set on this square
	bool sSelectedNumbers[9];	//list of selected square which could by on this square
	bool sIsMarged;				//flag if square should be marged or not

	int checkWhichMiniSquare(QPointF mousePos);
	int * miniSquareNumberToCoordinates(int numer);
	int miniSquareCoordinatesToNumber(int xCoordinate, int yCoordinate);
	void setSquateCoordinations();
	void setSquareLocation();
	QRectF boundingRect() const;

public:
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	Square();
	Square(int squareNumber);
	~Square();
};

