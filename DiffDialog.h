#pragma once

#include <QDialog>
#include "ui_DiffDialog.h"

class DiffDialog : public QDialog
{
	Q_OBJECT

public:
	DiffDialog(QWidget *parent = Q_NULLPTR);
	~DiffDialog();

	int getDiffValue();

private:
	Ui::DiffDialog ui;

};
