#include "generatepoints.h"
#include "sortbyxasc.h"
#include "sortbyyasc.h"
#include <QtMath>

GeneratePoints::GeneratePoints(){}

std::vector<QPoint> GeneratePoints::generateCluster(int &n, QSize &size){
    int num_clusters = n/100;                                               // clusters of points
    int w = size.width()-30;
    int h = size.height()-30;                                               //window size to fit the generated stuff inside
    std::vector<QPoint> pts;
                                                                            //generate the starting point in each cluster
    for (int i = 0; i<num_clusters;i++){
        QPoint master_pt(rand()%w,rand()%h);
        pts.push_back(master_pt);
                                                                            //generate points around the starting point
        for (unsigned j=0; j<(10-1);j++){
            double new_x = master_pt.x()+rand()%(w/20);
            double new_y = master_pt.y()+rand()%(h/20);
            pts.push_back(QPoint(new_x,new_y));
        }
    }
                                                                            //Delete duplicit points, because Jarvis
    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for(unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
            pts.erase(pts.begin()+j);
            j--;
        }
    }
    return pts;
}
std::vector<QPoint> GeneratePoints::generateRandom(int &n, QSize &size){
    int w = size.width()-30;
    int h = size.height()-30;                                               //window size to fit the generated stuff inside
    std::vector<QPoint> pts;

    for (int i = 0; i<n;i++){                                               // random points generation
        pts.push_back({rand()%w,rand()%h});
    }
                                                                            //Delete duplicit points, because Jarvis
    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for(unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
            pts.erase(pts.begin()+j);
            j--;
        }
    }
    return pts;

}

std::vector<QPoint> GeneratePoints::generateGrid(int &n, QSize &size){
    int h = size.height()-10;                                               //window size to fit the generated stuff inside
    int w = size.width()-10;
                                                                            //distance betwen points
    std::vector<QPoint> pts;
    double gap = h/ceil(std::sqrt(n));

    for(double x=10;x<w;x+=gap){                                            //creating points
        for(double y=10;y<h;y+=gap){
            pts.push_back(QPoint(x,y));
        }
    }
    return pts;
}



std::vector<QPoint> GeneratePoints::generateCircle(int &n, QSize &size){
    std::vector<QPoint> pts;
    QPoint p;
    int w = size.width();
    int h = size.height();                                                  //window size to fit the generated stuff inside
    QPoint center(w/2,h/2);                                                 //centre of circle, its fixed position because fitting to display problems
    double radius = rand()%(h/2);
    double fi = (2*M_PI)/n;

    for(int i = 0;i<n;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + radius*cos(i*fi));
        p.setY(center.y() + radius*sin(i*fi));
        pts.push_back(p);
    }
                                                                            //Delete duplicit points, because Jarvis
    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for(unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
        pts.erase(pts.begin()+j);
        j--;
        }
    }
    return pts;
}

std::vector<QPoint> GeneratePoints::generateEllipse(int &n, QSize &size){
    std::vector<QPoint> pts;
    QPoint p;

    int w = size.width()/2;
    int h = size.height()/2;                                                //window size to fit the generated stuff inside
    double a = rand()%(w);                                                  // a,b parameters of ellipse
    double b = rand()%(h);

    QPoint center(w,h);                                                     //centre of circle, its fixed position because fitting to display problems

    double fi = (2*M_PI)/n;

    for(int i = 0;i<n;i++)                                                  //generating ellipse of random a,b parameters
    {
        p.setX(center.x() + a*cos(i*fi));
        p.setY(center.y() + b*sin(i*fi));
        pts.push_back(p);
    }

    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for( unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
        pts.erase(pts.begin()+j);
        j--;
        }
    }
    return pts;
}

std::vector<QPoint> GeneratePoints::generateStarShape(int &n, QSize &size){
    std::vector<QPoint> pts;
    n/=2;
    int a = size.width()/2;                                                 //window size to fit the generated stuff inside
    int b = size.height()/2;

    QPoint p;
    QPoint center(a,b);                                                     //point, from where all other points are visible (star shape polygon)

    double fi = (2*M_PI)/n;

    for(int i = 0;i<n;i++)                                                  //basicly generating circle where each point has diferent radius
    {
        p.setX(center.x() + rand()%(b)*cos(i*fi));
        p.setY(center.y() + rand()%(b)*sin(i*fi));
        pts.push_back(p);
    }

    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for(unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
        pts.erase(pts.begin()+j);
        j--;
        }
    }
    return pts;
}

std::vector<QPoint> GeneratePoints::generateSquare(int &n, QSize &size)
{
    std::vector<QPoint> pts;

    int h = size.height()/2;                                                //window size to fit the generated stuff inside

    QPoint p(30,30);                                                        //fixed one point of square because fitting to display problems
    double length = rand()%(2*h);                                           //lenght of square side, random for each generating

    QPoint p1(p.x()+length,p.y());                                          // create the main 4(3) corner points
    QPoint p2(p.x()+length,p.y()+length);
    QPoint p3(p.x(),p.y()+length);
    pts.push_back(p);
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);

    double length_small = length/(n/4);
    for(int i = 0;i < n/4;i++)                                              // fill the space betwen square corners with points
    {
        pts.push_back(QPoint(p.x()+(i*length_small),p.y()));
        pts.push_back(QPoint(p.x()+length,p.y()+(i*length_small)));
        pts.push_back(QPoint(p.x()+(i*length_small),p.y()+length));
        pts.push_back(QPoint(p.x(),p.y()+(i*length_small)));
    }

    std::sort(pts.begin(), pts.end(), SortByXAsc());
    for(unsigned int j = 0; j<(pts.size()-1); j++){
        if((pts[j].x() == pts[j+1].x())&&(pts[j].y() == pts[j+1].y())){
        pts.erase(pts.begin()+j);
        j--;
        }
    }
    return pts;
}

