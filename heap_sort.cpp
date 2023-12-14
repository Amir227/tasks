#include <cstdio>
#include <iostream>

using namespace std;

void heapify(int* array, int size, int i)
{
    int tmp;
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && array[left] > array[largest]){ // array[left] < array[largest]
        largest = left;
    }
    if (right < size && array[right] > array[largest]){ // array[right] < array[largest]
        largest = right;
    }
    if (largest != i){
        tmp = array[i];
        array[i] = array[largest];
        array[largest] = tmp;
        heapify(array, size, largest);
    }
}


void heapSort(int* array, int size)
{
    int tmp;
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(array, size, i);
    }
    for (int i = size - 1; i >= 0; i--){
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heapify(array, i, 0);
    }
}

void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    } 
}

int main()
{
    int size = 0;
    cout << "Введите размер массива: ";
    cin >> size;
    int* array;
    array = new int[size];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    print_arr(array, size);
    heapSort(array, size);
    cout << "\n";
    print_arr(array, size);
    delete[] array;
    return 0;
}