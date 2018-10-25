#include "algorithms.h"
using namespace std;

Algorithms::Algorithms(){}

int Algorithms::getPointLinePosition(QPoint &q, QPoint &a, QPoint &b){
    double eps = 10e-6;                     //beow is absolute 0
    double ux = b.x() - a.x();              //Point and line position
    double uy = b.y() - a.y();
    double vx = q.x() - a.x();
    double vy = q.y() - a.y();
    double wx = q.x() - b.x();
    double wy = q.y() - b.y();
    double dist_qb = sqrt(wx * wx + wy * wy);             //distances
    double dist_qa = sqrt(vx * vx + vy * vy);
    double dist_ab = sqrt(ux * ux + uy * uy);
    double sum = dist_qa + dist_qb;
    double t = (ux * vy - uy * vx);         //Determinant
    if(t >= eps)                             //Point in the left half plane
        return 1;
    if(t <= -eps)                            //Point in the right half plane
        return 0;
    if(t <= eps && t >= -eps){                            // when point Q is the same as point B or A
        if((sum-dist_ab)<=eps && (sum - dist_ab)>= -eps)
            return 2;
    }
    return -1;
}

double Algorithms::get2LinesAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4){
    double ux = p2.x() - p1.x();                                    //members of vector
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();
    double dot = ux * vx + uy * vy;                                 //Dot product
    double nu = sqrt(ux * ux + uy * uy);                            //Norms
    double nv = sqrt(vx * vx + vy * vy);
    return fabs(acos(dot/(nu * nv)))*(180/M_PI);                    //angle
}

int Algorithms::getPositionRay(QPoint q, vector<QPoint> pol){
    int k = 0;                                      //Analyze point and polygon position
    int n = pol.size();                             //number of vector points
    double xir = pol[0].x() - q.x();                //Initialize the coordinates
    double yir = pol[0].y() - q.y();
    int size=pol.size();
    for(int i=1;i<size + 1; i++){                   //number of vector points
        if(getPointLinePosition(q, pol[i-1], pol[i])==2) return 1;      //if point is on the line
        double xiir = pol[i%n].x() - q.x();
        double yiir = pol[i%n].y() - q.y();
        if(((yiir > 0)&&(yir <= 0))||((yir > 0)&&(yiir <= 0))){         //Upper halfplane?
            double xm = (xiir * yir - xir * yiir) / (yiir - yir);       //Right half plane?
            if(xm >0)                               //Increment intersection
                k++;
        }
        xir = xiir;                                 //Assign coordinates
        yir = yiir;
    }
     int end = k%2;
     if (end == 0)
         return 0;
     else
         return 1;
}

// because i have more than 1 vector, i need to iterate for each vector
vector<int> Algorithms::itRay(QPoint &q, vector<vector<QPoint>> pol_list){
    vector<int> res;
    int sizeR = pol_list.size();
    for(int i=0;i<sizeR;i++)
    {if(getPositionRay(q,pol_list[i])==1) res.push_back(i);} //returns index of polygon that contains point Q
    return res;}

int Algorithms::getPositionWinding(QPoint q, std::vector<QPoint> pol){
       int n = pol.size();
       double sum_fi=0.0;
       double eps = 1.0e-10;
       for (int i=0; i < n; i++){                                           //Process all polygon segments
           if(getPointLinePosition(q, pol[i], pol[i+1])==2) return 1;       // if the point is on the line
           double fi = get2LinesAngle(pol[i], q, pol[(i+1)%n], q);          //Get angle
           int t = getPointLinePosition(q, pol[i], pol[(i+1)%n]);           //Get position
           if(t > 0)                                                        //Point q in the left halfplane
               sum_fi += fi;
           else
               sum_fi -= fi;                                                //Point in the right halfplane
           if(t == 2)
               return 1;                                                    //Point  on the line // as done before // bonus
       }
       if (fabs(fabs(sum_fi)-360)< eps)                                     //Point q inside P
           return 1;
       if (fabs(sum_fi) < eps)                                              //Point q outside P
           return 0;
       else
           return -1;                                                       //Point q on the boundary
}

// because i have more than 1 vector, i need to iterate for each vector
vector<int> Algorithms::itWinding(QPoint &q, vector<vector<QPoint>> pol_list){
    vector<int> res;
    int sizeW = pol_list.size();
    for(int i=0;i<sizeW;i++)
    {if(getPositionWinding(q,pol_list[i])==1) res.push_back(i);} //returns index of polygon that contains point Q
    return res;}


