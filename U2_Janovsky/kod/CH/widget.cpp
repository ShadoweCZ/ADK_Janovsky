#include <ctime>
#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "generatepoints.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_5->setText(QString::number(1000));                // default value of label, that shows default value of slider
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QPolygon ch;
    std::vector<QPoint> points = ui->Canvas->getPoints();

    clock_t s1 = std::clock();                       //Start time 1
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e1 = std::clock();                       //End time 1

    clock_t s2 = std::clock();                       //Start time 2
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e2 = std::clock();                       //End time 2

    clock_t s3 = std::clock();                       //Start time 3
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e3 = std::clock();                       //End time 3

    clock_t s4 = std::clock();                       //Start time 4
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e4 = std::clock();                       //End time 4

    clock_t s5 = std::clock();                       //Start time 5
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e5 = std::clock();                       //End time 5

    clock_t s6 = std::clock();                       //Start time 6
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e6 = std::clock();                       //End time 6

    clock_t s7 = std::clock();                       //Start time 7
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e7 = std::clock();                       //End time 7

    clock_t s8 = std::clock();                       //Start time 8
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e8 = std::clock();                       //End time 8

    clock_t s9 = std::clock();                       //Start time 9
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e9 = std::clock();                       //End time 9

    clock_t s10 = std::clock();                       //Start time 10
    if (ui->comboBox->currentIndex()==0)            //Construct CH using diferent methods
        ch = Algorithms::CHJarvis(points);
    else if (ui->comboBox->currentIndex()==1)
        ch = Algorithms::CHGraham(points);
    else if (ui->comboBox->currentIndex()==2)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);
    clock_t e10 = std::clock();                       //End time 10


    //Time difference in miliseconds
    clock_t time1 = e1 - s1;
    clock_t time2 = e2 - s2;
    clock_t time3 = e3 - s3;
    clock_t time4 = e4 - s4;
    clock_t time5 = e5 - s5;
    clock_t time6 = e6 - s6;
    clock_t time7 = e7 - s7;
    clock_t time8 = e8 - s8;
    clock_t time9 = e9 - s9;
    clock_t time10 = e10 - s10;

    ui->label_2->setText(QString::number(time1) + " ms");
    ui->label_7->setText(QString::number(time2) + " ms");
    ui->label_8->setText(QString::number(time3) + " ms");
    ui->label_9->setText(QString::number(time4) + " ms");
    ui->label_10->setText(QString::number(time5) + " ms");
    ui->label_11->setText(QString::number(time6) + " ms");
    ui->label_12->setText(QString::number(time7) + " ms");
    ui->label_13->setText(QString::number(time8) + " ms");
    ui->label_14->setText(QString::number(time9) + " ms");
    ui->label_15->setText(QString::number(time10) + " ms");

    //Set and repaint
    ui->Canvas->setCH(ch);
    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearAll();
    repaint();

    ui->label_2->setText("time1");
    ui->label_7->setText("time2");
    ui->label_8->setText("time3");
    ui->label_9->setText("time4");
    ui->label_10->setText("time5");
    ui->label_11->setText("time6");
    ui->label_12->setText("time7");
    ui->label_13->setText("time8");
    ui->label_14->setText("time9");
    ui->label_15->setText("time10");

    ui->label_5->setText(QString::number(1000));                // default value of label, that shows default value of slider
}

void Widget::on_points_clicked()
{
    std::vector<QPoint> points;
    int num = ui->label_5->text().toInt();

    //Generate                                                  // description is all the same, only think that changes is method used
    if ((ui->comboBox_2->currentIndex())==0){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();                           // this gives size of canvas so we can fill the whole space on any monitor (any resizing)
        points = GeneratePoints::generateCluster(num,s);        // generating method
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();                                  // set points and paint them
    }

    if (ui->comboBox_2->currentIndex()==1){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateRandom(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    if (ui->comboBox_2->currentIndex()==2){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateGrid(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    if (ui->comboBox_2->currentIndex()==3){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateCircle(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    if (ui->comboBox_2->currentIndex()==4){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateEllipse(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    if (ui->comboBox_2->currentIndex()==5){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateStarShape(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    if (ui->comboBox_2->currentIndex()==6){
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        points = GeneratePoints::generateSquare(num,s);
        ui->Canvas->setPoints(points);
        ui->Canvas->repaint();
    }

    ui->Canvas->setPoints(points);
    ui->Canvas->repaint();
}

void Widget::on_horizontalSlider_sliderMoved(int position)          // (plain) text edit widget was doing some wierd stuff so i used slider
{
    int &count = position;
    ui->label_5->setText(QString::number(count));                   // this shows number under the slider
}
