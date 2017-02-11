#include "Square.h"


Square::Square(){
	sSquareNumber = 0;
	sValue = 0;
	sIsMarged = false;
	for (int ii = 0; ii < 9; ii++) sSelectedNumbers[ii] = false;

	this->setSquareLocation();
}

Square::Square(int squareNumber) {
	sSquareNumber = squareNumber;
	sValue = 0;
	sIsMarged = false;
	for (int ii = 0; ii < 9; ii++) sSelectedNumbers[ii] = false;

	this->setSquareLocation();
}

Square::~Square()
{
}

QRectF Square::boundingRect() const
{
	// outer most edges
	return QRectF(sStartLocationX, sStartLocationY, SQUARE_SIZE, SQUARE_SIZE);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QRectF rect = boundingRect();

	//drawing edges of square
	QPen normalPen(Qt::black, NORMAL_PEN_THICKNESS);
	QPen thinPen(Qt::black, THIN_PEN_THICKNESS);
	painter->setPen(normalPen);
	painter->drawRect(rect);

	painter->setPen(thinPen);
	//drawing mini squares
	if (sIsMarged == false) {
		for (int yy = 1; yy<4; yy++) {
			for (int xx = 1; xx<4; xx++) {
				int miniSquareNumber = miniSquareCoordinatesToNumber(xx, yy);
				int boardStartX = sStartLocationX + (xx-1)*MINI_SQUARE_SIZE;
				int boardStartY = sStartLocationY + (yy-1)*MINI_SQUARE_SIZE;
				QRectF miniSquare = QRect(boardStartX, boardStartY, MINI_SQUARE_SIZE, MINI_SQUARE_SIZE);
				painter->drawRect(miniSquare);
				// draw number in miniSquare if number is selected
				if (sSelectedNumbers[miniSquareNumber]) {
					painter->drawText(miniSquare, Qt::AlignCenter, QString::number(miniSquareNumber+1));
				}
			}
		}
	}


}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	//sIsMarged = !sIsMarged;
	int miniSquareClicked = this->checkWhichMiniSquare(event->pos());
	sSelectedNumbers[miniSquareClicked] = !sSelectedNumbers[miniSquareClicked];
	this->update();
}

int Square::checkWhichMiniSquare(QPointF mousePos) 
{
	//function to check on which mini suare clicked mouse
	double x = mousePos.x();
	double y = mousePos.y();
	int miniSquareNumber = 0;
	int xMiniSquareNumber = 0;
	int yMiniSquareNumber = 0;

	if (x >= sStartLocationX && x < sStartLocationX + MINI_SQUARE_SIZE) xMiniSquareNumber = 1;
	else if(x >= sStartLocationX + MINI_SQUARE_SIZE && x < sStartLocationX + 2* MINI_SQUARE_SIZE) xMiniSquareNumber = 2;
	else if (x >= sStartLocationX + 2 * MINI_SQUARE_SIZE && x < sStartLocationX + 3 * MINI_SQUARE_SIZE) xMiniSquareNumber = 3;
	else xMiniSquareNumber = 0;

	if (y >= sStartLocationY && y < sStartLocationY + MINI_SQUARE_SIZE) yMiniSquareNumber = 1;
	else if (y >= sStartLocationY + MINI_SQUARE_SIZE && y < sStartLocationY + 2 * MINI_SQUARE_SIZE) yMiniSquareNumber = 2;
	else if (y >= sStartLocationY + 2 * MINI_SQUARE_SIZE && y < sStartLocationY + 3 * MINI_SQUARE_SIZE) yMiniSquareNumber = 3;
	else yMiniSquareNumber = 0;

	miniSquareNumber = miniSquareCoordinatesToNumber(xMiniSquareNumber, yMiniSquareNumber);
	
	return miniSquareNumber;
}

int* Square::miniSquareNumberToCoordinates(int numer) {
	// function to change miniSquareNumber (0-8) on coordinates x,y (1-3)
	int coordinates[2];
	coordinates[0] = (numer % 3) + 1;
	coordinates[1] = numer / 3 + 1;
	return coordinates;
}

int Square::miniSquareCoordinatesToNumber(int xCoordinate, int yCoordinate) {
	// function to change miniSquareCoordinates (1-3) on squareNumber (0-8)
	return (xCoordinate + 3 * (yCoordinate - 1)) - 1;
}

void Square::setSquateCoordinations() {
	sXCoordinate = (sSquareNumber % 9) + 1;
	sYCoordinate = sSquareNumber / 9 + 1;
}

void Square::setSquareLocation() {
	// function to set location of this square
	this->setSquateCoordinations();
	int xOffset = 0;
	int yOffset = 0;
	if (sXCoordinate > 3 && sXCoordinate <= 6) xOffset = OFFSET_BETWEEN_BOARDS;
	else if (sXCoordinate > 6) xOffset = 2 * OFFSET_BETWEEN_BOARDS;

	if (sYCoordinate > 3 && sYCoordinate <= 6) yOffset = OFFSET_BETWEEN_BOARDS;
	else if (sYCoordinate > 6) yOffset = 2 * OFFSET_BETWEEN_BOARDS;

	sStartLocationX = BOARD_START_POINT + (sXCoordinate-1) * SQUARE_SIZE +xOffset;
	sStartLocationY = BOARD_START_POINT + (sYCoordinate-1) * SQUARE_SIZE +yOffset;
}