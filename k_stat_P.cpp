#include <cstdio>
#include <iostream>


using namespace std;

void printArray(int* array, int n)
{
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}


int quickSort(int*array, int low, int high, int k)
{
    while(low < high){
        int i = low;
        int j = high;
        int pivot =  array[k];
        int temp = 0;

        while ( i < j)
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

        if (j < k){
            low = i;
        }
        if (k < i){
            high = j;
        }
    }

    return array[k-1];  
}

int main()
{
    int size = 0;
    int k = 0;
    cout << "Введите размер массива ";
    cin >> size;
    cout << "Введите порядковую статистику ";
    cin >> k;
    int* array;
    array = new int[size];
    cout << "Введите элементы массива " << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    printArray(array, size);
    int d = quickSort(array, 0, size, k);
    cout << endl;
    //printArray(array, size);
    cout << endl;
    cout << d << endl;
    delete[] array;
    return 0;
}



