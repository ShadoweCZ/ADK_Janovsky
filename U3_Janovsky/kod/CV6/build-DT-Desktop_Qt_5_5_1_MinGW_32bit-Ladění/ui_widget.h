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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *points_count;
    QComboBox *comboBox;
    QPushButton *Points;
    QSpacerItem *verticalSpacer_8;
    QPushButton *Delaunay;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QLineEdit *DZ;
    QPushButton *Contours;
    QSpacerItem *verticalSpacer_7;
    QComboBox *comboBox_2;
    QPushButton *Analyze;
    QSpacerItem *verticalSpacer_6;
    QPushButton *Clear;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(746, 467);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        points_count = new QLineEdit(Widget);
        points_count->setObjectName(QStringLiteral("points_count"));

        verticalLayout->addWidget(points_count);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        Points = new QPushButton(Widget);
        Points->setObjectName(QStringLiteral("Points"));

        verticalLayout->addWidget(Points);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        Delaunay = new QPushButton(Widget);
        Delaunay->setObjectName(QStringLiteral("Delaunay"));

        verticalLayout->addWidget(Delaunay);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        DZ = new QLineEdit(Widget);
        DZ->setObjectName(QStringLiteral("DZ"));

        verticalLayout->addWidget(DZ);

        Contours = new QPushButton(Widget);
        Contours->setObjectName(QStringLiteral("Contours"));

        verticalLayout->addWidget(Contours);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        comboBox_2 = new QComboBox(Widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        Analyze = new QPushButton(Widget);
        Analyze->setObjectName(QStringLiteral("Analyze"));

        verticalLayout->addWidget(Analyze);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        Clear = new QPushButton(Widget);
        Clear->setObjectName(QStringLiteral("Clear"));

        verticalLayout->addWidget(Clear);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "DTM", 0));
        label->setText(QApplication::translate("Widget", "Generate points", 0));
        points_count->setText(QApplication::translate("Widget", "600", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Randomised Grid", 0)
         << QApplication::translate("Widget", "Pile", 0)
         << QApplication::translate("Widget", "Rest", 0)
         << QApplication::translate("Widget", "Valley", 0)
         << QApplication::translate("Widget", "Ridge", 0)
        );
        Points->setText(QApplication::translate("Widget", "Points", 0));
        Delaunay->setText(QApplication::translate("Widget", "Delaunay", 0));
        label_2->setText(QApplication::translate("Widget", "Interval of contours", 0));
        DZ->setText(QApplication::translate("Widget", "15", 0));
        Contours->setText(QApplication::translate("Widget", "Contours", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Slope", 0)
         << QApplication::translate("Widget", "Aspect", 0)
        );
        Analyze->setText(QApplication::translate("Widget", "Analyze", 0));
        Clear->setText(QApplication::translate("Widget", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
