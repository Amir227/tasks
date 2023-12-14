#include <cstdio>
#include <iostream>

using namespace std;


int countSort(int* arr, int size, int q)
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
    for (int i = 0; i <= max-1; i++){
        if (q < count[i]){
            return i;
        }
        q-=count[i];
    }

    delete[] count;
    delete[] output;
    return 0;
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
    int q = 0;
    cout << "Введите размер массива: ";
    cin >> size;
    int* array;
    array = new int[size];
    cout << "Введите номер статистики: " << endl;
    cin >> q;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    print_arr(array, size);
    cout << "\n";
    int y = countSort(array, size, q);
    //print_arr(array, size);
    cout << y;
    delete[] array;
    return 0;
}