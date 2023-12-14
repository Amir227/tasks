#include <cstdio>
#include <iostream>

using namespace std;


void countSort(int* arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    int* output = new int[max + 1];
    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++){
        count[i] = 0;
    }

    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++){
        count[i] += count[i-1];
    }
    for (int i = size - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
    delete[] count;
    delete[] output;
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
    cout << "\n";
    countSort(array, size);
    print_arr(array, size);
    delete[] array;
    return 0;
}