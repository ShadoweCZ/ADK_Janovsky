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
    void on_clear_clicked();
    void on_anal_clicked();
    void on_Import_clicked();
    void on_repaint_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
