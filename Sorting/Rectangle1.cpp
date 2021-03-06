#include "Rectangle1.h"

Rectangle1::Rectangle1(int height,QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    this->height = height;
    setRect(0,0,10,height);
    brush.setStyle(Qt::SolidPattern);
    this->setColor(color);
}

Rectangle1::~Rectangle1(){

}

void Rectangle1::setHeight(int height){
    this->height = height;
    setRect(0,0,10,height);
}

void Rectangle1::setColumn(int column){
    this->column = column;
}

void Rectangle1::setColor(QColor color){
    brush.setColor(color);
    setBrush(color);
}

int Rectangle1::getHeight(){
    return this->height;
}

int Rectangle1::getColumn(){
    return this->column;
}

int Rectangle1::setRandomHeight(){
     height=rand() % 300 + 1;
     setRect(0,0,10,height);
     return height;
}
