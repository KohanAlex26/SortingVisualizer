#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QDrag>
#include <string>

class Rectangle1: public QGraphicsRectItem
{
public:
    Rectangle1(int height,QGraphicsItem *parent=0);
    ~Rectangle1();

    //setter
    void setHeight(int height);
    void setColumn(int column);
    void setColor(QColor color);
    int setRandomHeight();

    //getter
    int getHeight();
    int getColumn();
private:
    int height;
    int column;

    QBrush brush;
    QColor color = Qt::red;
};

#endif // RECTANGLE1_H
