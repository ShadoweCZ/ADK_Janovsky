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
    static std::vector<QPoint3D> generateKupa(int &n,QSize &size);
    static std::vector<QPoint3D> generateUdoli(int &n,QSize &size);
    static std::vector<QPoint3D> generateSpocinek(int &n,QSize &size);
    static std::vector<QPoint3D> generateHrbet(int &n,QSize &size);
};

#endif // GENERATEPOINTS_H
