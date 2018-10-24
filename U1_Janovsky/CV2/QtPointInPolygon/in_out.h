#ifndef IN_OUT_H
#define IN_OUT_H

#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

class in_out
{
public:
    in_out();
    void write(QString filename);
    void read(QString filename);
    void loadData(const char* path, std::ifstream &file);
};

#endif // IN_OUT_H
