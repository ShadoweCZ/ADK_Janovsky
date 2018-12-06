#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

#include "edge.h"
#include "qpoint3d.h"
#include "triangle.h"

class Draw : public QWidget
{
    Q_OBJECT
    private:
        std::vector<QPoint3D> points;     //List of points
        std::vector<Edge> dt;             //List of Delaunay edges
        std::vector<Edge> contours;       //List of contours
        std::vector<Triangle> dtm;
        bool slope, aspect;
        std::vector<double> contour_heights; //List of contour heights
        int dz;

    public:
        explicit Draw(QWidget *parent = nullptr);
        void paintEvent(QPaintEvent *e);
        void mousePressEvent(QMouseEvent *e);
        void clearPoints() {points.clear();}
        void clearDT();
        std::vector<QPoint3D> & getPoints(){return points;}
        std::vector<Edge> & getDT(){return dt;}
        void setDT(std::vector<Edge> &dt_){dt = dt_;}
        void setContours(std::vector<Edge> &contours_,std::vector<double> &contour_heights_,int dz_);
        void setDTM(std::vector<Triangle> &dtm_){dtm = dtm_;}
        void setPoints(std::vector<QPoint3D> pts){points = pts;}
        void setSlope(bool slope_){slope = slope_;}
        void setAspect(bool aspect_){aspect = aspect_;}

    signals:

    public slots:

};

#endif // DRAW_H
