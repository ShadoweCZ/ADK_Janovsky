#ifndef GENERATEPOINTS_H
#define GENERATEPOINTS_H
#include <vector>
#include <QPoint>
#include <QSize>
#include <QtMath>

class GeneratePoints
{
public:
    GeneratePoints();
    static std::vector<QPoint> generateCluster(int &n,QSize &size);
    static std::vector<QPoint> generateRandom(int &n,QSize &size);
    static std::vector<QPoint> generateGrid(int &n,QSize &size);
    static std::vector<QPoint> generateCircle(int &n, QSize &size);
    static std::vector<QPoint> generateEllipse(int &n, QSize &size);
    static std::vector<QPoint> generateStarShape(int &n, QSize &size);
    static std::vector<QPoint> generateSquare(int &n, QSize &size);
};

#endif // GENERATEPOINTS_H
