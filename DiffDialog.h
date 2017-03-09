#pragma once

#include <QDialog>
#include "ui_DiffDialog.h"

class DiffDialog : public QDialog
{
	Q_OBJECT

public:
	int getDiffValue() const;

	DiffDialog(QWidget *parent = Q_NULLPTR);
	~DiffDialog();

private:
	Ui::DiffDialog ui;
};
