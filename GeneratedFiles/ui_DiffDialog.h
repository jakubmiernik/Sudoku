/********************************************************************************
** Form generated from reading UI file 'DiffDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFDIALOG_H
#define UI_DIFFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DiffDialog
{
public:
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *generateButton;

    void setupUi(QDialog *DiffDialog)
    {
        if (DiffDialog->objectName().isEmpty())
            DiffDialog->setObjectName(QStringLiteral("DiffDialog"));
        DiffDialog->resize(315, 246);
        label = new QLabel(DiffDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 159, 33));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        horizontalSlider = new QSlider(DiffDialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 110, 241, 22));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(45);
        horizontalSlider->setValue(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        label_2 = new QLabel(DiffDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 80, 71, 16));
        label_3 = new QLabel(DiffDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 80, 71, 16));
        generateButton = new QPushButton(DiffDialog);
        generateButton->setObjectName(QStringLiteral("generateButton"));
        generateButton->setGeometry(QRect(110, 180, 93, 28));

        retranslateUi(DiffDialog);

        QMetaObject::connectSlotsByName(DiffDialog);
    } // setupUi

    void retranslateUi(QDialog *DiffDialog)
    {
        DiffDialog->setWindowTitle(QApplication::translate("DiffDialog", "DiffClass", 0));
        label->setText(QApplication::translate("DiffDialog", "Select Dificult", 0));
        label_2->setText(QApplication::translate("DiffDialog", "Super Easy", 0));
        label_3->setText(QApplication::translate("DiffDialog", "Super Hard", 0));
        generateButton->setText(QApplication::translate("DiffDialog", "Generate!", 0));
    } // retranslateUi

};

namespace Ui {
    class DiffDialog: public Ui_DiffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFDIALOG_H
