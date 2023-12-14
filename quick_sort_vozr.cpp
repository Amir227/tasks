#include <cstdio>
#include <iostream>


using namespace std;

void printArray(int* array, int n)
{
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}


void quickSort(int*array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot =  array[(i+j) / 2];
    int temp = 0;

    while ( i <= j)
    {
        while (array[i] < pivot){
            i++;
        }
        while (array[j] > pivot){
            j--;
        }
        if (i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (j > low){
        quickSort(array, low, j);
    }
    if (i < high){
        quickSort(array, i, high);
    }    
}

int main()
{
    int size = 0;
    cout << "Введите размер массива";
    cin >> size;
    int* array;
    array = new int[size];
    cout << "Введите элементы массива" << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    printArray(array,size);
    quickSort(array, 0, size);
    cout << endl;
    printArray(array, size);
    delete[] array;
    return 0;
}



