#include "Algorithms.h"

#include <QCoreApplication>
#include <QTime>
#include <QPointF>
Algorithms::Algorithms(int el,QSlider* slider){

    this->el=el;
    this->slider=slider;
}

Algorithms::~Algorithms(){

}



void Algorithms::delay()
{
    if(slider->value()==0)
    {
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    else
    if(slider->value()==1)
    {
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    else
    if(slider->value()==2)
    {
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    else
    if(slider->value()==3)
    {
        QTime dieTime= QTime::currentTime().addMSecs(10);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    else
    if(slider->value()==4)
    {
        QTime dieTime= QTime::currentTime().addMSecs(100);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
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




/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int Algorithms::partition (std::vector<Rectangle1 *> list, int low, int high)
{
    list[high]->setColor(Qt::blue);
    int pivot = list[high]->getHeight(); // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        list[j]->setColor(Qt::blue);
        delay();
        if (list[j]->getHeight() < pivot)
        {
            i++; // increment index of smaller element
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
    delay();
    list[high]->setColor(Qt::red);
    int aux = list[i+1]->getHeight();
    QPointF p=list[i+1]->pos();
    list[i+1]->setHeight(list[high]->getHeight());
    list[i+1]->setPos(list[i+1]->x(),list[high]->y());
    list[high]->setHeight(aux);
    list[high]->setPos(list[high]->x(),p.y());
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void Algorithms::quickSort(std::vector<Rectangle1 *> list, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(list, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}





// A utility function to get maximum value in arr[]
int Algorithms::getMax(std::vector<Rectangle1 *> list, int n)
{
    int mx = list[0]->getHeight();
    for (int i = 1; i < n; i++)
        if (list[i]->getHeight() > mx)
            mx = list[i]->getHeight();
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void Algorithms::countSort(std::vector<Rectangle1 *> list, int n, int exp)
{
    int output[100]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(list[i]->getHeight() / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(list[i]->getHeight() / exp) % 10] - 1] = list[i]->getHeight();
        count[(list[i]->getHeight() / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
    {
        list[i]->setColor(Qt::blue);
        list[i]->setHeight(output[i]);
        delay();
        list[i]->setColor(Qt::red);
    }

}

// The main function to that sorts arr[] of size n using
// Radix Sort
void Algorithms::radixsort(std::vector<Rectangle1 *> list, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(list, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(list, n, exp);
}
