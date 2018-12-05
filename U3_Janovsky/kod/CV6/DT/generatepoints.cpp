#include "generatepoints.h"

GeneratePoints::GeneratePoints(){}


std::vector<QPoint3D> GeneratePoints::generateGrid(int &n, QSize &size){
    int h = size.height()-10;                                               //window size to fit the generated stuff inside
    int w = size.width()-10;
                                                                            //distance betwen points
    std::vector<QPoint3D> pts;
    double gapX = h/ceil(std::sqrt(n));
    double gapY = w/ceil(std::sqrt(n));


        for(double x=10;x<w;x+=gapX){                                            //creating points
            x = x + rand()%40;
            for(double y=10;y<h;y+=gapY){
                y = y + rand()%40;
                double z=rand()%100;
                pts.push_back(QPoint3D(x,y,z));
            }
        }

    return pts;
}


std::vector<QPoint3D> GeneratePoints::generateKupa(int &n, QSize &size){
    std::vector<QPoint3D> pts;
    QPoint3D p;
    int w = size.width();
    int h = size.height();                                                  //window size to fit the generated stuff inside
    QPoint3D center(w/2,h/2,90+rand()%5);                                                 //centre of circle, its fixed position because fitting to display problems
    pts.push_back(center);
    double fi = (2*M_PI)/n*4;

    for(int i = 0;i<n/4;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (50+rand()%5)*cos(i*(fi+rand()%1)));
        p.setY(center.y() + (50+rand()%5)*sin(i*(fi+rand()%1)));
        p.setZ(75+rand()%5);
        pts.push_back(p);
    }

    for(int i = 0;i<n/4;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (100+rand()%15)*cos(i*(fi+rand()%1)));
        p.setY(center.y() + (100+rand()%15)*sin(i*(fi+rand()%1)));
        p.setZ(50+rand()%5);
        pts.push_back(p);
    }

    for(int i = 0;i<n/4;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (150+rand()%25)*cos(i*(fi+rand()%1)));
        p.setY(center.y() + (150+rand()%25)*sin(i*(fi+rand()%1)));
        p.setZ(25+rand()%5);
        pts.push_back(p);
    }

    for(int i = 0;i<n/4;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (350+rand()%25)*cos(i*(fi+rand()%1)));
        p.setY(center.y() + (350+rand()%25)*sin(i*(fi+rand()%1)));
        p.setZ(0+rand()%5);
        pts.push_back(p);
    }


    return pts;
}

std::vector<QPoint3D> GeneratePoints::generateHrbet(int &n, QSize &size){
    std::vector<QPoint3D> pts;
    QPoint3D p;
    int w = size.width();
    int h = size.height();                                                  //window size to fit the generated stuff inside

    QPoint3D center(w/2,0,n+rand()%5);
    pts.push_back(center);

    // hrbet
    for(int i = 0;i<n/5;i++)
    {
        p.setX(center.x() + ((rand()%5)-rand()%5));
        p.setY(center.y() + (i*15)+rand()%15);
        p.setZ(n-i-rand()%1);
        pts.push_back(p);
    }

    // R 1
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 2*i +((rand()%10)-rand()%10));
        p.setY(center.y() + (i*15)+rand()%20);
        p.setZ(n-2*i-rand()%3);
        pts.push_back(p);
    }

    // L 1
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 2*i  -((rand()%10)-rand()%10));
        p.setY(center.y() + (i*15)+rand()%20);
        p.setZ(n-2*i-rand()%3);
        pts.push_back(p);
    }

    // R 2
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 10*i +((rand()%20)-rand()%20));
        p.setY(center.y() + (i*25)+rand()%20);
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // L 2
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 10*i -((rand()%20)-rand()%20));
        p.setY(center.y() + (i*25)+rand()%20);
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // R 3
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 8*i +((rand()%20)-rand()%20));
        p.setY(center.y() + (i*8)+rand()%20);
        p.setZ(n-3*i-rand()%3);
        pts.push_back(p);
    }

    // L 3
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 8*i -((rand()%20)-rand()%20));
        p.setY(center.y() + (i*8)+rand()%20);
        p.setZ(n-3*i-rand()%3);
        pts.push_back(p);
    }

    // R 4
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 10*i +((rand()%20)-rand()%20));
        p.setY(center.y());
        p.setZ(n-3*i-rand()%3);
        pts.push_back(p);
    }

    // L 4
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 10*i -((rand()%20)-rand()%20));
        p.setY(center.y());
        p.setZ(n-3*i-rand()%3);
        pts.push_back(p);
    }
return pts;
}


std::vector<QPoint3D> GeneratePoints::generateSpocinek(int &n, QSize &size){

}

std::vector<QPoint3D> GeneratePoints::generateUdoli(int &n, QSize &size){

}
