#ifndef DRAW_H
#define DRAW_H
#include <QWidget>
#include <QPoint>
#include <QtGui>
#include <QString>
#include <fstream>
#include <vector>
using namespace std;
class Draw : public QWidget
{
    Q_OBJECT

private:
    bool draw_point;                            //Switch, whether to draw a point or a polygon
    QPoint q;                                   //The analyzed point q
    vector<vector<QPoint>> poly_list;           //polygon of polygons because i have multiple polygons and want them in 1 place
    vector<int> result_polygons;                //polygons to be colored

public:
    void paintEvent(QPaintEvent *e);            //paints the polygon
    void mousePressEvent(QMouseEvent *e);       //creates point Q on click
    void clearCanvas();                         //deletes all from the window
    QPoint getPoint();                          //returns coordinates of clicked point
    vector<vector<QPoint>> getList();           //access to polygon list
    explicit Draw(QWidget *parent = nullptr);
    void import(const char* path, std::ifstream &file);             // used to load polygon from txt file
    void setResultPolygons(vector<int> res);    //sets the private variable containing the indexes of polygons with Q point in them





signals:

public slots:
};

#endif // DRAW_H
