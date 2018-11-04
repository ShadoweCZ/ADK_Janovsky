#include "draw.h"
#include <QtGui>
using namespace std;

Draw::Draw(QWidget *parent) : QWidget(parent){
    //Set the initial values
    draw_point = true;
    q.setX(200); // to test Q on polygon point
    q.setY(250);
}

QPoint Draw::getPoint(){
    return q;
}

vector<vector<QPoint>> Draw::getList(){
    return poly_list;
}

void Draw::setResultPolygons(vector<int> res){
    result_polygons = res;
}

void Draw::import (const char* path, std::ifstream &file){      //taken from internet with some (many) edits
    file.open(path);                                            //loading polygons from *.txt file
    int count;                                                  //number of polygons
    vector<double> tmp_x;                                       //vector for storing x coordinates
    double tmp_y;                                               //object for storing y coordinate
    int p = 0;                                                  //number of polygon being processed

    file >> count;
    vector<vector<QPoint> > tmp(count, vector<QPoint>(0));      //create the same ammount of vectors as in the file
    std::swap(poly_list, tmp);                                  //swap the temporary vector with the class vector

    while (file.good()){                                        //Returns true if a file open for reading has reached the end
        unsigned int pt_count;                                  //number of points in one polygon
        file >> pt_count;

        if(tmp_x.capacity()<pt_count){                          //if the capacity of the vector is less than i need, reserve more space
            tmp_x.reserve(pt_count);
        }

        poly_list[p].reserve(pt_count);                         //reserve space in the final vector

        for(unsigned int i=0; i<pt_count;i++){                  //load x coordinates of a polygon
            file>>tmp_x[i];
        }

        for(unsigned int i=0; i<pt_count; i++){                 //load each y coordinate and store the QPoint
            file>>tmp_y;
            poly_list[p].push_back(QPoint(tmp_x[i],tmp_y));
        }
        p++;
        if(p==count){
            break;
        }
    }
    file.close();                                               // close the file, needs to be done
}

void Draw::paintEvent(QPaintEvent *e){                          //i dont know how to remove warning about unused e :(    so much work to remake this from 1 polygon to multi polygon ...
    QPainter painter(this);                                     //draw the polygon and the point
    QBrush brush(Qt::blue,Qt::DiagCrossPattern);                //paint settings //color and design

    for (unsigned int j=0; j<poly_list.size();j++){             //iterate over all the polygons (finaly found i can use "unsigned"  :D )
        QPolygon polygon;                                       //create the polygon

        for(unsigned int i=0; i < poly_list[j].size(); i++){
            polygon.append(poly_list[j].at(i));                 //add points to the polygon
            painter.drawEllipse(poly_list[j].at(i).x() - 2.5, poly_list[j].at(i).y() -2.5, 5, 5); //draw circle around points
        }

        auto in = std::find(result_polygons.begin(),result_polygons.end(),j); // finds if the polygon is the one containing Q // auto because idk what to use here

        if(in != result_polygons.end()){
            QPainterPath path;                                  //enables painting, filling, etc
            path.addPolygon(polygon);                           //select the polygon to be filled, painted,..
            painter.fillPath(path,brush);                       // fills the polygon by predefined by QBrush
        }

        painter.drawPolygon(polygon);                           //draw the polygon
    }

    painter.drawEllipse(q.x()-5 ,q.y()-5, 10, 10);              //draw circle around point Q

    result_polygons.clear();                                    //just to empty it, not needed anymore
    painter.end();                                              //stop drawing
}

void Draw::mousePressEvent(QMouseEvent *e){
    //Set point q
    if(draw_point){
        q.setX(e->x());
        q.setY(e->y());
    }
    repaint();
}

void Draw::clearCanvas(){
    //Clear the Canvas
    q.setX(-5);
    q.setY(-5);

    poly_list.clear();
    result_polygons.clear();
    repaint();
}




