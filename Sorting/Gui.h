#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "Rectangle1.h"
#include "Algorithms.h"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include <QGraphicsView>

class Gui : public QGraphicsView
{
    Q_OBJECT
public:
    QSlider *slider;
    Gui(int el,QWidget* parent = 0);
    ~Gui();
private:
//    Algorithms* algorithm = new Algorithms(el);
    Algorithms* algorithm;
    int SHIFT;
    int el;

    std::vector<Rectangle1*> list;
//    QGraphicsView* graphicsView;
    QGraphicsScene* scene;
    QComboBox* comboBox;
    QPushButton* sortButton;
    QPushButton* refreshButton;
    QVBoxLayout* finalLayout;
    QHBoxLayout* layout;

    void delay();
    void initGui(int el);
    void connectSignalsAndSlots();
    //void populateView();

public slots:
    void sort();
    void refresh();
};

#endif // GUI_H
