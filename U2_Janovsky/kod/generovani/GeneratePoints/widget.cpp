#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget){ui->setupUi(this);}

Widget::~Widget(){delete ui;}

void Widget::on_spinBox_valueChanged(int arg1)
{
    int n = arg1;
}

void Widget::on_pushButton_clicked()
{

}
