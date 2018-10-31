/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *zobrazeni;
    QSplitter *splitter;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(754, 506);
        zobrazeni = new QWidget(Widget);
        zobrazeni->setObjectName(QStringLiteral("zobrazeni"));
        zobrazeni->setGeometry(QRect(9, 9, 611, 481));
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(630, 50, 82, 249));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);
        splitter->addWidget(label);
        comboBox = new QComboBox(splitter);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setAutoFillBackground(false);
        splitter->addWidget(comboBox);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAutoFillBackground(false);
        splitter->addWidget(label_2);
        spinBox = new QSpinBox(splitter);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setAutoFillBackground(false);
        spinBox->setMinimum(1000);
        spinBox->setMaximum(1000000);
        spinBox->setSingleStep(1000);
        spinBox->setValue(1000000);
        splitter->addWidget(spinBox);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoFillBackground(false);
        splitter->addWidget(pushButton);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "Points Placement", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Circle", 0)
         << QApplication::translate("Widget", "Random", 0)
         << QApplication::translate("Widget", "Raster", 0)
        );
        label_2->setText(QApplication::translate("Widget", "Number of points", 0));
        pushButton->setText(QApplication::translate("Widget", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
