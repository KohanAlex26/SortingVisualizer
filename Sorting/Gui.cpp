#include <windows.h>
#include <QGraphicsView>
#include <QHBoxLayout>
#include "Gui.h"
#include "Rectangle1.h"
#include "Algorithms.h"
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QTime>
#include <QComboBox>
#include <QSlider>

Gui::Gui(int el,QWidget* parent): QGraphicsView{parent}
{
    this->initGui(el);
    this->connectSignalsAndSlots();
    slider = new QSlider(Qt::Horizontal);
    slider->setValue(0);
    algorithm=new Algorithms(el,slider);
    this->el=el;
}

Gui::~Gui(){}

void Gui::initGui(int el)
{
    this->setWindowTitle("Sorting Algorithms");

    finalLayout = new QVBoxLayout{this};
    layout = new QHBoxLayout();

    this->sortButton = new QPushButton("Sort!");
    this->refreshButton =new QPushButton("Refresh!");

    scene = new QGraphicsScene(this);
//    graphicsView = new QGraphicsView();

//    graphicsView->setScene(scene);
    setScene(scene);
    comboBox = new QComboBox();
//    comboBox->addItem(" ");
    comboBox->addItem("Bubble Sort");
    comboBox->addItem("Insertion Sort");
    comboBox->addItem("Merge Sort");
    comboBox->addItem("Quick Sort");
    comboBox->addItem("Radix Sort");

    SHIFT = 10;
    for(int i = 0; i < el; i ++)
    {
        int height = rand() % 300 + 1; // values between 1 and 100
        Rectangle1 *rect = new Rectangle1(height);
        rect->setColumn(i);
//        rect->setPos(SHIFT * i,100-height);
        rect->setPos(SHIFT * i,0);
        scene->addItem(rect);
        list.push_back(rect);
    }

//    QSlider *slider = new QSlider();
//    slider->move(1600,1500);
//    finalLayout->addWidget(slider);

//    layout->addWidget(graphicsView);
//    layout->addWidget(this);
    layout->addWidget(sortButton);
    layout->addWidget(refreshButton);



    finalLayout->addWidget(comboBox);
    finalLayout->addLayout(layout);

    QHBoxLayout* LayoutSlider = new QHBoxLayout{this};

    LayoutSlider->addWidget(slider);
    finalLayout->addLayout(LayoutSlider);


}

void Gui::connectSignalsAndSlots(){
    QObject::connect(this->sortButton,SIGNAL(released()),this,SLOT(sort()));
    QObject::connect(this->refreshButton,SIGNAL(released()),this,SLOT(refresh()));
}

void Gui::sort()
{
    QString text = comboBox->currentText();
    if(text == "Bubble Sort")
       this->algorithm->bubbleSort(list);
    else if(text == "Insertion Sort")
        this->algorithm->insertionSort(list);
    else if(text == "Merge Sort")
        this->algorithm->mergeSort(list,0,el-1);
    else if(text == "Quick Sort")
        this->algorithm->quickSort(list, 0, el - 1);
    else if(text == "Radix Sort")
        this->algorithm->radixsort(list, el);
}

void Gui::refresh()
{
    for(int i = 0; i < el; i++)
    {
        int height=list[i]->setRandomHeight();
//        list[i]->setPos(SHIFT * i,100-height);
        list[i]->setPos(SHIFT * i,0);
    }
}

