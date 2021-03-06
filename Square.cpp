#include "Square.h"


Square::Square(){
	sSquareNumber = 0;
	sValue = 0;
	numbersPen = new QPen(Qt::black, THIN_PEN_THICKNESS);
	sIsMarged = false;
	sIsConstant = false;
	for (int ii = 0; ii < 9; ii++) 
		sSelectedNumbers[ii] = false;

	this->setSquareLocation();
}

Square::Square(int squareNumber) {
	sSquareNumber = squareNumber;
	sValue = 0;
	numbersPen = new QPen(Qt::black, THIN_PEN_THICKNESS);
	sIsMarged = false;
	sIsConstant = false;
	for (int ii = 0; ii < 9; ii++) 
		sSelectedNumbers[ii] = false;

	this->setSquareLocation();
}

Square::~Square()
{
	delete numbersPen;
}

void Square::setConstantValue(int value)
{
	sValue = value;
	sIsConstant = true;
	sIsMarged = true;

	this->update();
}

void Square::clear() {
	sValue = 0;
	sIsMarged = false;
	numbersPen = new QPen(Qt::black, THIN_PEN_THICKNESS);
	sIsConstant = false;
	for (int ii = 0; ii < 9; ii++)
		sSelectedNumbers[ii] = false;
	this->update();
}

QRectF Square::boundingRect() const
{
	// outer most edges
	return QRectF(sStartLocationX, sStartLocationY, SQUARE_SIZE, SQUARE_SIZE);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	QRectF rect = boundingRect();

	//drawing edges of square
	QPen normalPen(Qt::black, NORMAL_PEN_THICKNESS);
	//QPen thinPen(Qt::black, THIN_PEN_THICKNESS);
	painter->setPen(normalPen);
	painter->drawRect(rect);

	painter->setPen(*numbersPen);
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
	else if (sIsMarged == true) {
		if (sIsConstant) {
			numbersPen->setColor(Qt::gray);
			painter->setPen(*numbersPen);
		}
		this->adaptFontSize(painter, Qt::AlignCenter, rect, QString::number(sValue));
		painter->drawText(rect, Qt::AlignCenter, QString::number(sValue));
	}


}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	int miniSquareClicked = this->checkWhichMiniSquare(event->pos());
	numbersPen->setColor(Qt::black);
	sSelectedNumbers[miniSquareClicked] = !sSelectedNumbers[miniSquareClicked];
	this->update();
}

void Square::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) {
	numbersPen->setColor(Qt::black);
	if (!sIsConstant) {
		sIsMarged = !sIsMarged;
		sValue = this->checkWhichMiniSquare(event->pos()) + 1;	//+1 because squareNumber is (0-8)
		this->update();
	}
}

int Square::checkWhichMiniSquare(QPointF mousePos) const
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

void Square::miniSquareNumberToCoordinates(int numer, int coordinates[2]) const {
	// function to change miniSquareNumber (0-8) on coordinates x,y (1-3)
	coordinates[0] = (numer % 3) + 1;
	coordinates[1] = numer / 3 + 1;
}

int Square::miniSquareCoordinatesToNumber(int xCoordinate, int yCoordinate) const {
	// function to change miniSquareCoordinates (1-3) on squareNumber (0-8)
	return (xCoordinate + 3 * (yCoordinate - 1)) - 1;
}

int Square::squareGlobalCoordinatesToGlobalNumber(int xCoordinate, int yCoordinate) {
	// function to change squareCoordinations in sudoku (1-9) on squareNumber (0-80)
	return (xCoordinate + 9 * (yCoordinate - 1)) - 1;
}

void Square::squareGlobalNumberToGlobalCoordinates(int globalNumber, int globalCoordinates[2]) {
	//function to change Global Number of Square (0-80) to global coordinates of square (1-9)x(1-9)
	globalCoordinates[0] = (globalNumber % 9) + 1;  //x
	globalCoordinates[1] = globalNumber / 9 + 1;	//y
}



int Square::getValue() const {
	return sValue;
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

void Square::adaptFontSize(QPainter * painter, int flags, QRectF drawRect, QString text) {
	QRect fontBoundRect =
		painter->fontMetrics().boundingRect(drawRect.toRect(), flags, text);
	float xFactor = drawRect.width() / fontBoundRect.width();
	float yFactor = drawRect.height() / fontBoundRect.height();
	float factor = xFactor < yFactor ? xFactor : yFactor;
	QFont f = painter->font();
	f.setPointSizeF(f.pointSizeF()*factor);
	painter->setFont(f);
}

void Square::changeColor(const QColor color) {
	// function to change color of numbers in square
	numbersPen->setColor(color);
	this->update();
}