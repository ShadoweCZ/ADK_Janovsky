#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include <QtGui>
using namespace std;
class Algorithms
{
public:
    Algorithms();
    static int getPositionRay(QPoint q, vector<QPoint> pol);                        // finds if the point is inside polygon
    static int getPositionWinding(QPoint q, vector<QPoint> pol);                    // finds if the point is inside polygon
    static int getPointLinePosition(QPoint &q, QPoint &a, QPoint &b);               //finds if the point is on left, right or directly at line
    static double get2LinesAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4);     // calculates angle betwen 2 lines
    static vector<int> itWinding(QPoint &q, vector<vector<QPoint>> pol_list);  //iterates winding for multiple polygons and returns indexes of the ones containing q
    static vector<int> itRay(QPoint &q, vector<vector<QPoint>> pol_list);      //iterates Ray for multiple polygons and returns indexes of the ones containing q
};

#endif // ALGORITHMS_H
