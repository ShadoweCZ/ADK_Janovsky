#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QtGui>

class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint> points;
    QPolygon ch;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void setCH( QPolygon ch_) {ch = ch_;}
    void setPoints(std::vector<QPoint> pts){points = pts;}
    std::vector<QPoint> getPoints(){return points;}
    void clearAll();
    void clearHull();


signals:

public slots:
};

#endif // DRAW_H
