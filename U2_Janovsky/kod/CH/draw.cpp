#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent){}

void Draw::paintEvent(QPaintEvent *e)
{
   QPainter painter(this);
   painter.begin(this);
   painter.setPen(Qt::red);

   //Draw points
   int size = points.size();
   for(int i = 0; i < size; i++)
   {
       painter.drawEllipse(points[i].x()-2, points[i].y()-2, 4, 4);
       //painter.drawText(points[i].x()+10, points[i].y()+10, QString::number(i));      // only good for testing with "clicking" points
   }

   //Draw convex hull
   painter.setPen(Qt::blue);
   painter.drawPolygon(ch);
   for(int i = 0; i < ch.size(); i++){
       painter.drawEllipse(ch[i].x()-4, ch[i].y()-4, 8, 8);
   }
   painter.end();

}



void Draw::mousePressEvent(QMouseEvent *e)
{
    QPoint p(e->x(), e->y());

    points.push_back(p);

    repaint();

}

void Draw::clearAll()
{
    points.clear();
    ch.clear();
}

void Draw::clearHull()
{
    ch.clear();
    repaint();
}
