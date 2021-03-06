#include "Algorithms.h"

#include <QCoreApplication>
#include <QTime>
#include <QPointF>
Algorithms::Algorithms(int el){

    this->el=el;
}

Algorithms::~Algorithms(){

}

void Algorithms::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Algorithms::bubbleSort(std::vector<Rectangle1*> list)
{
    for(int i = 0; i < el; i++)
    {
        list[i]->setColor(Qt::blue);
        for(int j = i + 1; j < el; j++)
        {
            list[j]->setColor(Qt::blue);
            if(list[j]->getHeight() < list[i]->getHeight())
            {
                int aux = list[i]->getHeight();
                QPointF p=list[i]->pos();
                list[i]->setHeight(list[j]->getHeight());
                list[i]->setPos(list[i]->x(),list[j]->y());
                list[j]->setHeight(aux);
                list[j]->setPos(list[j]->x(),p.y());
            }
            delay();
            list[j]->setColor(Qt::red);
         }
        list[i]->setColor(Qt::red);
     }
}

void Algorithms::insertionSort(std::vector<Rectangle1*> list)
{
    int i,j,aux;
    for (i = 0; i < el; i++)
    {
        list[i]->setColor(Qt::blue);
        aux = list[i]->getHeight();
        QPointF p=list[i]->pos();
        j = i - 1;

        while (j >= 0 && list[j]->getHeight() > aux)
        {
            list[j]->setColor(Qt::blue);
            list[j + 1]->setHeight(list[j]->getHeight());
            list[j + 1]->setPos(list[j+1]->x(),list[j]->y());
            j = j - 1;
            delay();
//            for(int i=0;i<=100000000;i++)
//            {

//            }
            QCoreApplication::processEvents();
            list[j+1]->setColor(Qt::red);
        }
        list[j + 1]->setHeight(aux);
        list[j + 1]->setPos(list[j+1]->x(),p.y());
        list[i]->setColor(Qt::red);
    }
}

void Algorithms::merge(std::vector<Rectangle1 *> list,int l, int m, int r)
{

    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[100], R[100],P1[100],P2[100];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = list[l + i]->getHeight();
        P1[i] = list[l + i]->y();
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = list[m + 1 + j]->getHeight();
        P2[j] = list[m+1+j]->y();
    }
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            list[k]->setColor(Qt::blue);
            list[k]->setHeight(L[i]);
//            list[k]->setPos(list[k]->x(),P1[i]);
            delay();
            i++;
            list[k]->setColor(Qt::red);
        }
        else {
            list[k]->setColor(Qt::blue);
            list[k]->setHeight(R[j]);
//            list[k]->setPos(list[k]->x(),P2[j]);
            delay();
            j++;
            list[k]->setColor(Qt::red);
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        list[k]->setColor(Qt::blue);
        list[k]->setHeight(L[i]);
//        list[k]->setPos(list[k]->x(),P1[i]);
        delay();
        i++;
        list[k]->setColor(Qt::red);
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        list[k]->setColor(Qt::blue);
        list[k]->setHeight(R[j]);
//        list[k]->setPos(list[k]->x(),P1[j]);
        delay();
        j++;
        list[k]->setColor(Qt::red);
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void Algorithms::mergeSort(std::vector<Rectangle1 *> list,int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(list,l,m);
    mergeSort(list,m+1,r);
    merge(list,l,m,r);
}
