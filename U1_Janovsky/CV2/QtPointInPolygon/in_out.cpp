#include "in_out.h"


in_out::in_out()
{

}

void in_out::write(QString filename)
{
    QFile file(filename);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }

    // To write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out << "QFile Tutorial";
    file.flush();
    file.close();
}

void in_out::read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    qDebug() << myText;

    file.close();
}

void in_out::loadData (const char* path, std::ifstream &file, QString &status){
        file.open(path);
        if(!file.is_open()){
            status = "Error: Failed to open polygon file.";
            file.close();
        }

        //how many polygons?
        int poly_count;
        file >> poly_count;

        //initialize the right number of vectors in the main vector
        std::vector<std::vector<QPoint> > tmp(poly_count, std::vector<QPoint>(0));

        //swap the temporary vector with the class vector
        std::swap(poly_list, tmp);

        int p = 0; //number of polygon being processed

        //temporary vector for storing polygon's x coordinates
        std::vector<double> tmp_x;

        while (file.good()){
            //number of points in one polygon
            unsigned int pt_count;
            file >> pt_count;

            //if the capacity of the vector is less than what we need, reserve more space
            if(tmp_x.capacity()<pt_count){
                tmp_x.reserve(pt_count);
            }
            //reserve space in the final vector
            poly_list[p].reserve(pt_count);

            //load x coordinates of a polygon
            for(unsigned int i=0; i<pt_count;i++){
                file>>tmp_x[i];
            }

            //load each y coordinate and store the QPoint
            double tmp_y;
            for(unsigned int i=0; i<pt_count; i++){
                file>>tmp_y;
                poly_list[p].push_back(QPoint(tmp_x[i],tmp_y));
            }
            p++;
            if(p==poly_count){
                break;
            }
        }
        file.close();
}
