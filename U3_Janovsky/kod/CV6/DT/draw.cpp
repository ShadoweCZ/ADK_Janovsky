#include "draw.h"
#include <QtGui>
#include "widget.h"
#include "ui_widget.h"
#include "generatepoints.h"
#include <vector>
#include <fstream>
#include "edge.h"
#include "algorithms.h"
#include "triangle.h"

Draw::Draw(QWidget *parent) : QWidget(parent){}

void Draw::setContours(std::vector<Edge> &contours_, std::vector<double> &contour_heights_,int dz_){
    contours = contours_;
    contour_heights = contour_heights_;
    dz = dz_;
   }

void Draw::paintEvent(QPaintEvent *e)
{
   QPainter painter(this);
   painter.begin(this);
   painter.setPen(Qt::red);
   //Draw points
   for(unsigned int i = 0; i < points.size(); i++)
   {
       painter.drawEllipse(points[i].x() - 2, points[i].y() - 2, 4, 4);
       //painter.drawText(points[i].x() + 5, points[i].y() + 5, QString::number(points[i].getZ()));
   }

   //Draw Delaunay edges
   for(unsigned int i = 0; i < dt.size(); i++)
   {
       painter.setPen(QPen(QColor(220,220,220),1));
       painter.drawLine(dt[i].getS(), dt[i].getE());
   }

   //Draw contour lines
     for(unsigned int i = 0; i < contours.size(); i++)
   {
            painter.setPen(QPen(QColor(139,69,19),1));
            painter.drawLine(contours[i].getS(), contours[i].getE());
   }

     //Draw contour lines
for(unsigned int i = 0; i < contours.size(); i++)
{

    int h = contour_heights[i];
    int hl = 5*dz;

    //diferenciate betwen main contur and normal contur lines
    if(!(h%(hl)))
       {
        painter.setPen(QPen(QColor(139,69,19),2));
        if(!(i%(8))){ // describe main contur lines with thier heights
            double text_x = (contours[i].getS().x() + contours[i].getE().x())/2;
            double text_y = (contours[i].getS().y() + contours[i].getE().y())/2;
            painter.drawText(text_x, text_y, QString::number(h));
        }
    }
    else
    {
         painter.setPen(QPen(QColor(139,69,19),1));
    }
    painter.drawLine(contours[i].getS(), contours[i].getE());
}



   if(slope == TRUE)
   {
       //Draw slope
       double c = 255.0/180;
       for(unsigned int i = 0; i < dtm.size(); i++)
       {
           //Get triangle and its vertices
           Triangle t = dtm[i];
           QPoint3D p1 = t.getP1();
           QPoint3D p2 = t.getP2();
           QPoint3D p3 = t.getP3();

           //Get slope and set the brush
           int c_slope = c * t.getSlope();
           painter.setBrush(QColor(c_slope,c_slope,c_slope));

           //Create and draw the polygon
           QPolygon triangle;
           triangle.append(QPoint(p1.x(), p1.y()));
           triangle.append(QPoint(p2.x(), p2.y()));
           triangle.append(QPoint(p3.x(), p3.y()));

           painter.drawPolygon(triangle);
       }
   }

   if(aspect == TRUE)
   {
       //Draw aspect
       for(unsigned int i =0; i<dtm.size(); i++)
       {
           //Get triangle and its vertices
           Triangle t = dtm[i];
           QPoint3D p1 = t.getP1();
           QPoint3D p2 = t.getP2();
           QPoint3D p3 = t.getP3();

           int count_aspect = t.getAspect();

           if((count_aspect>=0) && (count_aspect<22.5)){
               painter.setBrush(Qt::red);
           }
           else if((count_aspect>=22.5) && (count_aspect<67.5)){
               painter.setBrush(QColor(255,165,0));
           }
           else if((count_aspect>=67.5) && (count_aspect<112.5)){
               painter.setBrush(Qt::yellow);
           }
           else if((count_aspect>=112.5) && (count_aspect<157.5)){
              painter.setBrush(Qt::green);
           }
           else if((count_aspect>=157.5) && (count_aspect<202.5)){
               painter.setBrush(QColor(173,216,230));
           }
           else if((count_aspect>=202.5) && (count_aspect<247.5)){
               painter.setBrush(QColor(30,144,255));
           }
           else if((count_aspect>=247.5) && (count_aspect<292.5)){
                painter.setBrush(Qt::blue);
           }
           else if((count_aspect>=292.5) && (count_aspect<337.5)){
               painter.setBrush(QColor(255,20,147));
           }
           else if((count_aspect>=337.5) && (count_aspect<360)){
               painter.setBrush(Qt::red);
           }


           //Create and draw the polygon
           QPolygon triangle;
           triangle.append(QPoint(p1.x(), p1.y()));
           triangle.append(QPoint(p2.x(), p2.y()));
           triangle.append(QPoint(p3.x(), p3.y()));

           painter.drawPolygon(triangle);

       }

   }

   painter.end();
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Add new point
    int z = (rand()%101);
    QPoint3D p(e->x(), e->y(), z);
    points.push_back(p);
    repaint();
}

void Draw::clearDT()
{
    //Clear all
    points.clear();
    dt.clear();
    dtm.clear();
    contours.clear();
    //contours5.clear();

}

