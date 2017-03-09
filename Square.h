#ifndef SQUARE_H
#define SQUARE_H

#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "Config.h"


class Square : public QGraphicsItem
{
private:
	int sSquareNumber;			//number of square (0-81) 
	int sValue;					//value set on this square
	double sStartLocationX;		//start locatins of square on board
	double sStartLocationY;
	int sXCoordinate;			//coordinates of square (1-9) x (1-9)
	int sYCoordinate;
	bool sSelectedNumbers[9];	//list of selected square which could by on this square
	bool sIsMarged;				//flag if square should be marged or not
	bool sIsConstant;			//flag to diable ability to change value 
	QPen* numbersPen;				//pen to drow number

	int checkWhichMiniSquare(QPointF mousePos) const;
	void miniSquareNumberToCoordinates(int numer, int coordinates[2]) const;
	int miniSquareCoordinatesToNumber(int xCoordinate, int yCoordinate) const;
	QRectF boundingRect() const;
	void setSquateCoordinations();
	void setSquareLocation();
	

public:
	Square();
	explicit Square(int squareNumber);
	~Square();
	void setConstantValue(int value);
	void clear();
	void paint(QPainter * painter, const QStyleOptionGraphicsItem* , QWidget * widget);
	void adaptFontSize(QPainter * painter, int flags, QRectF drawRect, QString text);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
	static int squareGlobalCoordinatesToGlobalNumber(int xCoordinate, int yCoordinate);
	static void squareGlobalNumberToGlobalCoordinates(int globalNumber, int globalCoordinates[2]);
	void changeColor(const QColor color);
	int getValue() const;
};

#endif //SQUARE_H
