#include<cmath>
#include<vector>
#include "algorithms.h"
#include "sortbyxasc.h"
#include "sortbyyasc.h"


Algorithms::Algorithms(){}

double Algorithms::distance(QPoint a, QPoint b){                                    // calculates distance betwen 2 points
    double dx = b.x() - a.x();
    double dy = b.y() - a.y();
    return sqrt(dx*dx + dy*dy);
}

TPosition Algorithms::getPointLinePosition(QPoint &q, QPoint &a, QPoint &b)
{
    //Point and line position
    double eps = 1.0e-15;

    double ux = b.x() - a.x();
    double uy = b.y() - a.y();
    double vx = q.x() - a.x();
    double vy = q.y() - a.y();

    //Determinant
    double t = (ux * vy - uy * vx);

    //Point in the left half plane
    if(t > eps)
        return LEFT;

    //Point in the right half plane
    if(t < -eps)
        return RIGHT;

    //Point on the line
    return ON;
}

double Algorithms::getPointLineDistance(QPoint &q, QPoint &a, QPoint &b)
{
    //Point and line distance
    double x12 = b.x()-a.x();
    double y12 = b.y()-a.y();

    double y1a = q.y()-a.y();
    double y2a = b.y()-q.y();

    double numerator = -q.x()*y12 + a.x()*y2a + b.x()*y1a;
    double denominator = sqrt(x12*x12 + y12*y12);

    return fabs(numerator)/denominator;

}

double Algorithms::get2LinesAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4)
{
    //Angle between two lines
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Dot product
    double dot = ux * vx + uy * vy;

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    return fabs(acos(dot/(nu * nv)))*(180/M_PI);
}

bool Algorithms::compareAngle(QPoint &a, QPoint &b){
   //function compare angles between 2 points
   const double eps = 1.0e-20;
   double anga = get2LinesAngle(pvt, pvt_orient, pvt, a);
   double angb = get2LinesAngle(pvt, pvt_orient, pvt, b);

   if(std::abs(anga - angb)>=eps){
        return anga>angb;
   }
   else{
        bool c = compareDistance(a,b);
        return c;
   }
}

bool Algorithms::compareDistance(QPoint &a, QPoint &b){
   //function compare distances between 2 points
   double d1 = distance(pvt, a);
   double d2 = distance(pvt, b);
   return d1<d2;
}

QPolygon Algorithms::CHJarvis (vector<QPoint> &points)
{
    //Create convex hull using the Jarvis Scan procedure
    QPolygon ch;

    //Find pivot q
    std::sort(points.begin(), points.end(), sortByYAsc());
    QPoint q = points[0];

    std::sort(points.begin(), points.end(), SortByXAsc());
    QPoint s = points[0];

    //Create Pjj
    QPoint pjj (s.x()-1,q.y());
    QPoint pj = q;

    //Add pivot to CH
    ch.push_back(q);

    //Add all points to CH
    do
    {
        int i_max = -1;
        double fi_max = 0;

        //Find pi = arg max angle(pi, pj, pjj)
        for(unsigned int i = 0; i<points.size();i++)
        {
            //Get angle betwwen 2 segments
            double fi = get2LinesAngle(pj,points[i], pj, pjj  );

            //Find maximum
            if (fi>fi_max)
            {
                i_max=i;
                fi_max=fi;
            }
        }

        //Add the next point to CH
        ch.push_back(points[i_max]);

        //Assign CH verticess
        pjj = pj;
        pj = points[i_max];
    }

    while (pj != q);

    //Delete points on the same line
    for(int i=0; i<(ch.size()-2); i++){                                 //again, points are sorted, so we test only 2 points next to each other on the list
        if(getPointLinePosition(ch[i+2],ch[i],ch[i+1])==ON){            // if 3 points are in line , remove the midle one, j+2 becomes j+1 and test again
            ch.remove(i+1);
            i--;
        }
    }

    return ch;
}

QPolygon Algorithms::QHull (vector<QPoint> &points)
{
    //Create convex hull using the qhull procedure
    QPolygon ch;
    int size = points.size();
    std::vector<QPoint> su, sl;

    //Find q1, q3
    std::sort(points.begin(), points.end(), SortByXAsc());
    QPoint q1 = points[0];
    QPoint q3 = points[points.size()-1];

    // Add to SU,SL
    su.push_back(q1);
    su.push_back(q3);
    sl.push_back(q1);
    sl.push_back(q3);

    //Splite to SU or SL
    for(int i =0;i<size;i++)
    {
        // Add to SU
        if(getPointLinePosition(points[i],q1,q3)==LEFT)
        {
            su.push_back(points[i]);
        }

        // Add to SL
        if(getPointLinePosition(points[i],q1,q3)==RIGHT)
        {
            sl.push_back(points[i]);
        }
    }

    //Add q3 to ch
    ch.push_back(q3);

    //Process SU
    qh(1, 0, su, ch);

    //Add q1 to ch
    ch.push_back(q1);

    //Process SL
    qh(0, 1, sl, ch);

    //Delete points on the same line
    for(int i=0; i<(ch.size()-2); i++){                                 //again, points are sorted, so we test only 2 points next to each other on the list
        if(getPointLinePosition(ch[i+2],ch[i],ch[i+1])==ON){            // if 3 points are in line , remove the midle one, j+2 becomes j+1 and test again
            ch.remove(i+1);
            i--;
        }
    }


    return ch;
}

void Algorithms::qh(int s, int e, vector<QPoint> &p, QPolygon &h)
{
    //Local recursive procedure of qhull
    int i_max = -1;
    double d_max = 0;
    int size = p.size();

    //Browse all points
    for(int i = 2; i<size; i++)
    {
        //Is the point in the right half-plane?
        if(getPointLinePosition(p[i], p[s], p[e])==RIGHT)
        {
            //Compute the distance between point and the given segment
            double d =  getPointLineDistance(p[i], p[s], p[e]);

            //Remember the furthest point and its index
            if (d>d_max)
            {
                d_max = d;
                i_max = i;
            }
        }
    }

    //Point in the right half plain exists
    if(i_max >1)
    {
        //Process the first interval
        qh(s,i_max,p,h);

        //Add to CH
        h.push_back(p[i_max]);

        //Process the second interval
        qh(i_max,e,p,h);
    }
}

QPolygon Algorithms::CHSweep (vector<QPoint> &points)
{
    //Create convex hull using the sweepline procedure
    QPolygon ch;

    int size = points.size();

    //sort by X
    std::sort(points.begin(), points.end(), SortByXAsc());

    //Create list of predecessors
    std::vector<int> p(points.size());

    //Create list of successors
    std::vector<int> n(points.size());

    //Create an initial biangle (0, 1)
    //Change i to 2 in the next for loop
    n[0]=1;
    n[1]=0;

    p[0]=1;
    p[1]=0;

    for (int i = 2; i < size; i++)
    {
        //Point in the upper halfplane
        //Link i with predecessor/successor
        if(points[i].y() > points[i-1].y())
        {
            p[i]=i-1;
            n[i]=n[i-1];
        }

        //Point in the lower halfplane
        else
        {
            n[i]=i-1;
            p[i]=p[i-1];

        }

        //Link predecessor/successor with i-th point
        n[p[i]] = i;
        p[n[i]] = i;

        //Fix the upper tangent
        while(getPointLinePosition(points[n[n[i]]], points[i], points[n[i]])==RIGHT)
        {
            p[n[n[i]]] = i;
            n[i] = n[n[i]];
        }

        //Fix the lower tangent
        while(getPointLinePosition(points[p[p[i]]], points[i], points[p[i]])==LEFT)
        {
            n[p[p[i]]] = i;
            p[i] = p[p[i]];
        }
    }

    // Convert to the polygon
    ch.push_back(points[0]);
    int i = n[0];

    while (i != 0)
    {
       ch.push_back(points[i]);
       i = n[i];
    }

    //Delete points on the same line
    for(int i=0; i<(ch.size()-2); i++){                                 //again, points are sorted, so we test only 2 points next to each other on the list
        if(getPointLinePosition(ch[i+2],ch[i],ch[i+1])==ON){            // if 3 points are in line , remove the midle one, j+2 becomes j+1 and test again
            ch.remove(i+1);
            i--;
        }
    }
    return ch;
}

QPoint Algorithms::pvt;
QPoint Algorithms::pvt_orient;
QPolygon Algorithms::CHGraham (vector<QPoint> &points){
    QPoint p_0(0, 0);
    QPolygon ch;
    QPolygon sec_ch;

   // sort all points by Y
   std::sort(points.begin(), points.end(), sortByYAsc());

   // put pivot to the second slot
   ch.push_back(points[0]);
   sec_ch.push_back(points[0]);

   // create pivot
   pvt=points[0];

   //orientation of pivot
   pvt_orient.setX(-1000);
   pvt_orient.setY(pvt.y());

   //sort by angle
   std::sort(points.begin(), points.end(), compareAngle);

   // skip points on the same line
   for(unsigned int i=0; i<=points.size()-1;i++){
        while (getPointLinePosition(points[i],points[0],points[i+1])==ON){
           i++;
        }
   ch.push_back(points[i]);
   }
   sec_ch.push_back(ch[1]);

    //Find convextible points
   for(int i = 2; i <= ch.size()-1; i++)
   {
      QPoint t1=sec_ch[sec_ch.size()-1];
      sec_ch.pop_back();

      QPoint t2 = sec_ch[sec_ch.size()-1];
      sec_ch.push_back(t1);

      while(getPointLinePosition(ch[i], t2, sec_ch[sec_ch.size()-1])!=LEFT){
           sec_ch.pop_back();
           t1=sec_ch[sec_ch.size()-1];

           sec_ch.pop_back();
           t2 = sec_ch[sec_ch.size()-1];
           sec_ch.push_back(t1);
       }
       sec_ch.push_back(ch[i]);
   }

   for(int i = 0 ; i < sec_ch.size() - 2 ; i++ ){
        if( getPointLineDistance( sec_ch[i] , sec_ch[i+1] , sec_ch[i+2] ) == -1 ){       //again, points are sorted, so we test only 2 points next to each other on the list
            sec_ch.erase(sec_ch.begin()+(i+1));                                         // if 3 points are in line , remove the midle one, j+2 becomes j+1 and test again
            i=i-1;
        }
    }
   return  sec_ch;
}


