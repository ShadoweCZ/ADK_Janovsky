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
    QPoint getPoint() {return q;}               //returns coordinates of clicked point
    explicit Draw(QWidget *parent = nullptr);
    void import(const char* path, std::ifstream &file);             // used to load polygon from txt file
    vector<vector<QPoint>> getList(){return poly_list;}             //access to polygon list
    void setResultPolygons(vector<int> res){result_polygons = res;} //sets the private variable containing the indexes of polygons with Q point in them





signals:

public slots:
};

#endif // DRAW_H
