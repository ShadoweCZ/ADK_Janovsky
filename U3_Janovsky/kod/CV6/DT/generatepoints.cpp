#include "generatepoints.h"
#include "qpoint3d.h"

GeneratePoints::GeneratePoints(){}

// generate modifed grid (aka random points) just for test
std::vector<QPoint3D> GeneratePoints::generateGrid(int &n, QSize &size){
    int h = size.height()-10;                                               //window size to fit the generated stuff inside
    int w = size.width()-10;
                                                                            //distance betwen points
    std::vector<QPoint3D> pts;
    double gapX = h/ceil(std::sqrt(n));
    double gapY = w/ceil(std::sqrt(n));

        //standard grid creation + RAND ,RAND heights
        for(double x=10;x<w;x+=gapX){                                            //creating points
            for(double y=10;y<h;y+=gapY){
                double z=rand()%100;
                pts.push_back(QPoint3D(x+ rand()%10 - rand()%10,y + rand()%10 - rand()%10,z));
            }
        }

    return pts;
}

// generate pile
std::vector<QPoint3D> GeneratePoints::generatePile(int &n, QSize &size){
    std::vector<QPoint3D> pts;
    QPoint3D p;
    int w = size.width();
    int h = size.height();                                                  //window size to fit the generated stuff inside
    QPoint3D center(w/2,h/2,430+rand()%5);                                  //centre of circle, its fixed position because fitting to display problems
    pts.push_back(center);
    double fi = (2*M_PI)/n*5;

    // generate multiple circles with constanly lowering height to create Pile
//    for(int i = 0;i<n/5;i++)                                                  //generating points on circle of random radius
//    {
//        p.setX(center.x() + (50+rand()%2)*cos(i*(fi+rand()%1)));
//        p.setY(center.y() + (50+rand()%2)*sin(i*(fi+rand()%1)));
//        p.setZ(425+rand()%3);
//        pts.push_back(p);
//    }

//    for(int i = 0;i<n/5;i++)                                                  //generating points on circle of random radius
//    {
//        p.setX(center.x() + (100+rand()%2)*cos(i*(fi+rand()%1)));
//        p.setY(center.y() + (100+rand()%2)*sin(i*(fi+rand()%1)));
//        p.setZ(420+rand()%1);
//        pts.push_back(p);
//    }

    for(int i = 0;i<n/5;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (150+rand()%3)*cos(i*(fi+rand()%1)));
        p.setY(center.y() + (150+rand()%3)*sin(i*(fi+rand()%1)));
        p.setZ(415+rand()%2);
        pts.push_back(p);
    }

    for(int i = 0;i<n/5;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (330+rand()%5)*cos(i*(fi)));
        p.setY(center.y() + (370+rand()%5)*sin(i*(fi)));
        p.setZ(400+rand()%2);
        pts.push_back(p);
    }

    for(int i = 0;i<n/5;i++)                                                  //generating points on circle of random radius
    {
        p.setX(center.x() + (1000+rand()%5)*cos(i*(fi)));
        p.setY(center.y() + (1000+rand()%5)*sin(i*(fi)));
        p.setZ(300+rand()%2);
        pts.push_back(p);
    }


    return pts;
}

//generate ridge
std::vector<QPoint3D> GeneratePoints::generateRidge(int &n, QSize &size){
    std::vector<QPoint3D> pts;
    QPoint3D p;
    int w = size.width();                                                  //window size to fit the generated stuff inside

    QPoint3D center(w/2,0,n+rand()%5);  //point in the top centre, its the highest point
    pts.push_back(center);

    //ridge itself, slowly decreasing height
    for(int i = 0;i<n/5;i++)
    {
        p.setX(center.x() + ((rand()%5)-rand()%5));
        p.setY(center.y() + (i*15)+rand()%15);
        p.setZ(n-i-rand()%1);
        pts.push_back(p);
    }

    // now we didnt use circle (angle,distance) to generate, instaed we use additions to the coordinates from center point
    // we created multiple lines that are from centre point but are aimed away frim ridge
    // height of those "lines" is decreasing faster, creating ridge

    // R 1
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 2*i );
        p.setY(center.y() + (i*15));
        p.setZ(n-2*i-rand()%3);
        pts.push_back(p);
    }

    // L 1
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 2*i  );
        p.setY(center.y() + (i*15));
        p.setZ(n-2*i-rand()%3);
        pts.push_back(p);
    }

    // R 2
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 10*i );
        p.setY(center.y() + (i*25));
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // L 2
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 10*i);
        p.setY(center.y() + (i*25));
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // R 3
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 15*i );
        p.setY(center.y() + (i*15));
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // L 3
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 15*i);
        p.setY(center.y() + (i*15));
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // R 4
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() + 30*i +((rand()%20)-rand()%20));
        p.setY(center.y());
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }

    // L 4
    for(int i = 0;i<n/7;i++)
    {
        p.setX(center.x() - 30*i -((rand()%20)-rand()%20));
        p.setY(center.y());
        p.setZ(n-6*i-rand()%3);
        pts.push_back(p);
    }
return pts;
}

//generate rest
std::vector<QPoint3D> GeneratePoints::generateRest(int &n, QSize &size){
    int h = size.height()-10;                                               //window size to fit the generated stuff inside
    int w = size.width()-10;
                                                                            //distance betwen points
    std::vector<QPoint3D> pts;
    double gapX = h/ceil(std::sqrt(n));
    double gapY = w/ceil(std::sqrt(n));

    //again we use the modifed raster from beginning, and we edit that

        for(double x=10;x<w;x+=gapX){                                            //creating points

            for(double y=10;y<h;y+=gapY){
                double z;

                // create 3 sectors, upper, middle and lower
                // upper and lower have around constant slope
                // the middle one if flat, creating rest
                if (y < h/3) //upper
                    z = (h-y - rand()%20 + rand()%20-75);

                else if (y > 2*h/3) //lower
                    z = (h-y + rand()%20 - rand()%20+75);

                else    //middle
                    z = (h/2 - rand()%20 + rand()%20);


                pts.push_back(QPoint3D(x+ rand()%10 - rand()%10,y+ rand()%10 - rand()%10,z));
            }
        }

    return pts;
}

//generate valey
std::vector<QPoint3D> GeneratePoints::generateValey(int &n, QSize &size){
    int h = size.height()-10;                                               //window size to fit the generated stuff inside
    int w = size.width()-10;
                                                                            //distance betwen points
    std::vector<QPoint3D> pts;
    double gapX = h/ceil(std::sqrt(n));
    double gapY = w/ceil(std::sqrt(n));

    //again we use the modifed raster from beginning, and we edit that

        for(double x=10;x<w;x+=gapX){                                            //creating points

            for(double y=10;y<h;y+=gapY){

                double z;

                // area split onto 2 parts, 1 is decreasing, 1 is increasing in height
                if (y < h/2) //uper half
                    z = round(h-y - rand()%20 + rand()%20);

                else    //lower half
                    z = round(y + rand()%20 - rand()%20);


                pts.push_back(QPoint3D(x+ rand()%10 - rand()%10,y+ rand()%10 - rand()%10,z));
            }
        }

    return pts;
}
