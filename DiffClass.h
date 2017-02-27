#pragma once

#include <QDialog>
#include "ui_DiffClass.h"

class DiffClass : public QDialog
{
	Q_OBJECT

public:
	DiffClass(QWidget *parent = Q_NULLPTR);
	~DiffClass();

private:
	Ui::DiffClass ui;
};
