#include <cstdio>
#include <iostream>

using namespace std;
class Decimal
{
    public:
        int* digits;
        int count;
        Decimal() : digits(nullptr), count(0) {};

        Decimal(int* digits_1, int count_1){
            count = count_1;
            digits = new int[count];
            for (int i = 0; i < count;i++){
                digits[i] = digits_1[i];
            }
        }
        Decimal(const Decimal& other){
            count = other.count;
            digits = new int[count];
            for (int i = 0; i < count;i++){
                digits[i] = other.digits[i];
            }
        }
        Decimal& operator=(const Decimal& other){
            if (digits){
                delete[] digits;
            }
            count = other.count;
            digits = new int[count];
            for (int i = 0; i < count;i++){
                digits[i] = other.digits[i];
            }
            return *this;
        }
        Decimal operator+(const Decimal& other){ // сложение
            int new_count = 0;
            int* new_decimal = nullptr;
            if (count > other.count){
                new_count = count;
                new_decimal = new int[new_count];
                for(int i = other.count - 1; i >= 0; i--){
                    new_decimal[i] = other.digits[i] + digits[i];
                }
                for (int i = other.count; i < new_count; i++){
                    new_decimal[i]  = digits[i];
                }
            }
            else{
                new_count = other.count;
                new_decimal = new int[new_count];
                for(int i = 0; i < count; i++){
                    new_decimal[i] = other.digits[i] + digits[i];
                }
                for (int i = count; i < new_count; i++){
                    new_decimal[i]  = other.digits[i];
                }
            }
            // объявить новый массив здесь.
            for (int i = new_count - 1; i >=0; i--){
                if (new_decimal[i] > 9){
                    if (i == 0){
                        // перезаписать новый массив добавить туда 1 слева при переходе через десяток
                    }
                    new_decimal[i] = new_decimal[i] % 10;
                    new_decimal[i - 1] ++;
                }
            }
            Decimal c = Decimal(new_decimal, new_count);
            delete[] new_decimal;
            return c;
        }
        ~Decimal(){
            if (digits){
                delete[] digits;
            }
        };
};


int main()
{
    Decimal arr_1;
    Decimal arr_2;
    int arr_3[10] = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9};
    int count = 10;
    Decimal arr_4 = Decimal(arr_3, count);

    Decimal arr_5(arr_4);
    arr_1 = arr_4;
    arr_2 = arr_1 + arr_4;
    for (int i = 0; i < count; i++)
    {
        cout << arr_1.digits[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr_2.digits[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr_4.digits[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i < count; i++)
    // {
    //     cout << arr_5.digits[i] << " ";
    // }
    cout << endl;
    return 0;
}
