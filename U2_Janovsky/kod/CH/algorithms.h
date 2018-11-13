#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>
using namespace std;
typedef enum{
    LEFT = 0,
    RIGHT,
    ON
} TPosition;

class Algorithms
{
public:
    Algorithms();
    static TPosition getPointLinePosition(QPoint &q, QPoint &a, QPoint &b);
    static double get2LinesAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4);   
    static double getPointLineDistance(QPoint &q, QPoint &a, QPoint &b);
    static void qh (int s, int e, vector<QPoint> &p, QPolygon &h);
    static QPolygon CHJarvis (vector<QPoint> &points);
    static QPolygon CHGraham (vector<QPoint> &points);
    static QPolygon QHull (vector<QPoint> &points);
    static QPolygon CHSweep (vector<QPoint> &points);
    static double distance(QPoint a, QPoint b);

    static QPoint pvt;
    static QPoint pvt_orient;
    static bool compareAngle(QPoint &a, QPoint &b);
    static bool compareDistance(QPoint &a, QPoint &b);

};

#endif // ALGORITHMS_H
