#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "Rectangle1.h"
#include "QSlider"

class Algorithms
{
public:
    Algorithms(int el,QSlider* slider);
    ~Algorithms();

    //bubble sort
    void bubbleSort(std::vector<Rectangle1*> list);

    //insertion sort
    void insertionSort(std::vector<Rectangle1*> list);

    //merge sort
    void mergeSort(std::vector<Rectangle1 *> list,int l, int r);
    void merge(std::vector<Rectangle1 *> list,int l, int m, int r);

    //quick sort
    void swap(Rectangle1 *a, Rectangle1 *b);
    int partition (std::vector<Rectangle1 *> list, int low, int high);
    void quickSort(std::vector<Rectangle1 *> list, int low, int high);

    //radix sort
    int getMax(std::vector<Rectangle1 *> list, int n);
    void countSort(std::vector<Rectangle1 *> list, int n, int exp);
    void radixsort(std::vector<Rectangle1 *> list, int n);



private:
    void delay();
    int el;
    QSlider *slider;
};

#endif // ALGORITHMS_H
