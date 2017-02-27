#include "mainwindow.h"
#include <QApplication>
#include <ctime>
#include <string>
#include "Sudoku.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	/*for (int ii = 0; ii < 10; ii++) {
		clock_t begin = clock();
		sudoku->generateSudoku();
		clock_t end = clock();
		sudoku->debugPrintSudoku();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		OutputDebugStringA(std::to_string(elapsed_secs).c_str());
		OutputDebugStringA("\n \n");
	}*/

    return a.exec();
}
