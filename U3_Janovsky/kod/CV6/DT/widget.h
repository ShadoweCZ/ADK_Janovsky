#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void on_Points_clicked();

    void on_Delaunay_clicked();

    void on_Contours_clicked();

    void on_Clear_clicked();

    void on_Analyze_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
