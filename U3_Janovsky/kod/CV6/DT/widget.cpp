#include "widget.h"
#include "ui_widget.h"
#include "generatepoints.h"
#include <vector>
#include <fstream>
#include <QtGui>
#include "edge.h"
#include "algorithms.h"
#include "triangle.h"
#include "draw.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget){ui->setupUi(this);}

Widget::~Widget(){delete ui;}

void Widget::on_Points_clicked()
{
int num = ui->points_count->text().toInt();

//Generate                                                  // description is all the same, only think that changes is method used
if ((ui->comboBox->currentIndex())==0){
    ui->Canvas->clearDT();
    QSize s = ui->Canvas->size();                           // this gives size of canvas so we can fill the whole space on any monitor (any resizing)
    ui->Canvas->setPoints(GeneratePoints::generateGrid(num,s));
    ui->Canvas->repaint();                                  // set points and paint them
}

if (ui->comboBox->currentIndex()==1){
    ui->Canvas->clearDT();
    QSize s = ui->Canvas->size();
    ui->Canvas->setPoints(GeneratePoints::generateKupa(num,s));
    ui->Canvas->repaint();
}

if (ui->comboBox->currentIndex()==2){
    ui->Canvas->clearDT();
    QSize s = ui->Canvas->size();
    ui->Canvas->setPoints(GeneratePoints::generateSpocinek(num,s));
    ui->Canvas->repaint();
}

if (ui->comboBox->currentIndex()==3){
    ui->Canvas->clearDT();
    QSize s = ui->Canvas->size();
    ui->Canvas->setPoints(GeneratePoints::generateUdoli(num,s));
    ui->Canvas->repaint();
}

if (ui->comboBox->currentIndex()==4){
    ui->Canvas->clearDT();
    QSize s = ui->Canvas->size();
    ui->Canvas->setPoints(GeneratePoints::generateHrbet(num,s));
    ui->Canvas->repaint();
}

}

void Widget::on_Delaunay_clicked()
{
    std::vector<QPoint3D> points = ui->Canvas->getPoints();
    std::vector<Edge> dt = Algorithms::DT(points);
    ui->Canvas->setDT(dt);
    repaint();
}


void Widget::on_Contours_clicked()
{
    //Create contour lines
    int dz = ui->DZ->text().toInt();
    std::vector<Edge> dt = ui->Canvas->getDT();
    std::vector<double> contour_heights;
    std::vector<Edge> contours = Algorithms::createContours(dt, 0.0, 9999.9, dz, contour_heights);
    //std::vector<Edge> contours5 = Algorithms::createContours(dt, 0, 9999, dz*5);
    ui->Canvas->setContours(contours,contour_heights,dz);
    //ui->Canvas->setContours5(contours5);
    repaint();
}

void Widget::on_Clear_clicked()
{
    //Clear and repaint
    ui->Canvas->clearDT();
    repaint();
}

void Widget::on_Analyze_clicked()
{
    bool slope = FALSE;
    bool aspect = FALSE;

    //Analyze slope and aspect
    std::vector<Edge> dt = ui->Canvas->getDT();
    std::vector<Triangle> dtm = Algorithms::analyzeDTM(dt);
    ui->Canvas->setDTM(dtm);

    if (ui->comboBox_2->currentIndex()==0){
        slope = TRUE;
        aspect = FALSE;
    }
    else if (ui->comboBox_2->currentIndex()==1){
        slope = FALSE;
        aspect = TRUE;
    }

    ui->Canvas->setAspect(aspect);
    ui->Canvas->setSlope(slope);
    repaint();
}
