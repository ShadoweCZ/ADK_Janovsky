#ifndef GENERATEPOINTS_H
#define GENERATEPOINTS_H
#include <vector>
#include <QPoint>
#include <QSize>
#include <QtMath>
#include "qpoint3d.h"

class GeneratePoints
{
public:
    GeneratePoints();
    static std::vector<QPoint3D> generateGrid(int &n,QSize &size);
    static std::vector<QPoint3D> generatePile(int &n,QSize &size);
    static std::vector<QPoint3D> generateValey(int &n,QSize &size);
    static std::vector<QPoint3D> generateRest(int &n,QSize &size);
    static std::vector<QPoint3D> generateRidge(int &n,QSize &size);
};

#endif // GENERATEPOINTS_H
