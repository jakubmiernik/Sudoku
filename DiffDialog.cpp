#include "DiffDialog.h"

DiffDialog::DiffDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.generateButton, SIGNAL(clicked()), this, SLOT(close()));
}

DiffDialog::~DiffDialog()
{
}

int DiffDialog::getDiffValue(){
	
	int diffValue = ui.horizontalSlider->value();
	return diffValue;
}