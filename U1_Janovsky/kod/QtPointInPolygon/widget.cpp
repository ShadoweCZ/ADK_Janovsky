#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include <QFileDialog>
#include <fstream>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_clear_clicked()
{
    ui->Canvas->clearCanvas();
}

void Widget::on_anal_clicked(){
    vector<int> res;
    QPoint q = ui->Canvas->getPoint();
    vector<vector<QPoint>> poly_list;
    poly_list = ui->Canvas->getList();
    if(ui->method->currentIndex() == 0)                                         //check which algorithm is selected and find point
        res = Algorithms::itWinding(q, poly_list);
    else
        res = Algorithms::itRay(q, poly_list);

    QString status = QString::number(res.size())+" polygons contain point q";   // returns in how many polygon Q is
    ui->label_2->setText(status);
    ui->Canvas->setResultPolygons(res);
    ui->Canvas->repaint();
}

void Widget::on_Import_clicked(){
    QString chosen_file = QFileDialog::getOpenFileName(this,tr("Load polygons"),"C:\\","Text File (*.txt)");
    const char* path = chosen_file.toLatin1().data();
    ifstream file;
    QString status;
    ui->Canvas->import(path,file); //call file loading function
    ui->Canvas->repaint();
}

void Widget::on_repaint_clicked(){
    ui->Canvas->repaint();          // repaint, removes color etc
}

