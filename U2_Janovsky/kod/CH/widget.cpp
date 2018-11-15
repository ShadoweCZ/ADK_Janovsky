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


void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearAll();
    repaint();

    ui->label_2->setText("time1");

    ui->label_5->setText(QString::number(1000));                // default value of label, that shows default value of slider
}

void Widget::on_points_clicked()
{
    std::vector<QPoint> points;
    int num = ui->label_5->text().toInt();
    ui->label_2->setText("time1");

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

void Widget::on_pushButton_3_clicked()
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

    clock_t e1 = std::clock();                      //end time 1
    clock_t time1 = e1 - s1;                        //computes duration in ms

    ui->label_2->setText(QString::number(time1) + " ms");       //show duration in label
    ui->Canvas->setCH(ch);
    repaint();
}

