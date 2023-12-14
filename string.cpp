#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class String
{
    public:
        char* data;
        int size;
        String() : data(nullptr), size(0) {};
        String(const char* str) : data(nullptr), size(strlen(str)) 
        {
            data = new char[size+1];
            strncpy(data, str, size+1);
        };
        String& operator=(const String& other){
            if (data){
                delete[] data;
            }
            data = nullptr;
            size = other.size;
            if (other.data){
                data = new char[size + 1];
                strncpy(data, other.data, size + 1);
            }
            return *this;
        }
        String& operator+=(const String& other)
        {
            int new_size = size + other.size;
            char* new_data = new char[new_size+1];
            for (int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            for (int i = 0; i < other.size; i++){
                new_data[size + i] = other.data[i];
            }
            new_data[new_size] = 0;
            size = new_size;
            data = new_data;
            return *this;
            
        }
        String operator+(const String& other){
            int new_size = size + other.size;
            char* new_data = new char[new_size + 1];
            for (int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            for (int i = 0; i < other.size; i++){
                new_data[size + i] = other.data[i];
            }
            new_data[new_size] = 0;
            String str_sum(new_data); 
            delete[] new_data;
            return str_sum;
        }
        void add(char x){
            char* new_data = new char[size+2];
            for (int i = 0; i < size; i++){
                new_data[i] = data[i];
            }

            new_data[size] = x;
            new_data[size+1] = 0;
            size ++;
            delete[] data;
            data = new_data;
        }

        char operator[](int i) const{
                if (i >= size) {
                    cout << "Ошибка";
                    return data[0];
                } else {
                    return data[i];
                }
        }
        char& operator()(int i)
        {
            if (i >= size) {
                cout << "Ошибка";
                return data[0];
            } else {
                return data[i];
            }
        }
        ~String(){
            if (data){
               delete[] data;
            }
        }
};


ostream& operator<<(ostream& out, const String& strok)
{
    for (int i = 0; i < strok.size - 1; i++){
        out << strok.data[i];
    }
    return out << strok.data[strok.size - 1];
}

istream &operator>>(istream &in, String& strok)
{
    char a;
    while (true)
    {
        a = in.get();
        if (a == '\n'){
            break;
        }
        else{
            strok.add(a);
        }
    }
    return in;
}

int main()
{
    char *x = new char[6];
    x[0] = '1';
    x[1] = '2';
    x[2] = '3';
    x[3] = '4';
    x[4] = '5';
    x[5] = 0;

    String str3(x);
    String str2;
    String str1;

    cin >> str1 >> str2;
    String str4 = str1 + str2;
    String str5(str4);
    str5 += str3;

    cout << "string #1: " << str1 << endl;
    cout << "string #2: " << str2 << endl;
    cout << "string #3: " << str3 << endl;
    cout << "string #4: " << str4 << endl;
    cout << "string #5: " << str5 << endl;
    char a = str5[7];
    str5(0) = 'A';
    cout << "string #5 UPD: " << str5 << endl;
    delete[] x;
    return 0;
}


//                                all operators
// void String::add(char x)
// {

//     char *new_str = new char[len + 2];

//     for (int i = 0; i < len; i++) {
//         new_str[i] = str[i];
//     }

//     new_str[len] = x;
//     new_str[len + 1] = 0;

//     len = len + 1;
//     delete[] str;
//     str = new_str;
// }

// int String::min_len(const String &other) const
// {
//     if (len <= other.len) {
//         return len;
//     } else {
//         return other.len;
//     }
// }

// String::String()
// {

//     len = 0;
//     str = new char[1];
//     str[0] = 0;
// }

// String::String(const String &other)
// {

//     len = other.len;
//     str = new char[len + 1];

//     for (int i = 0; i < len; i++) {
//         str[i] = other.str[i];
//     }

//     str[len] = 0;
// }

// String::String(char *xArg)
// {

//     int len_arg = 0;
//     while (xArg[len_arg] != 0) {
//         len_arg++;
//     }

//     len = len_arg;

//     str = new char[len + 1];

//     for (int i = 0; i < len; i++) {
//         str[i] = xArg[i];
//     }

//     str[len] = 0;
// }

// String::~String()
// {
//     delete[] str;
// }

// //контактенация строк
// String String::operator+(const String &other) const
// {

//     int new_len = len + other.len;
//     char *new_str = new char[new_len + 1];

//     for (int i = 0; i < len; i++) {
//         new_str[i] = str[i];
//     }
//     for (int i = 0; i < other.len; i++) {
//         new_str[len + i] = other.str[i];
//     }

//     new_str[new_len] = 0;
//     String str_sum(new_str);
//     delete[] new_str;

//     return str_sum;
// }

// String &String::operator+=(const String &right)
// {

//     int new_len = len + right.len;

//     char *new_str = new char[new_len + 1];

//     for (int i = 0; i < len; i++) {
//         new_str[i] = str[i];
//     }
//     for (int i = 0; i < right.len; i++) {
//         new_str[len + i] = right.str[i];
//     }

//     new_str[new_len] = 0;

//     len = new_len;
//     delete[] str;

//     str = new_str;

//     return *this;
// }

// //чтение и запись символа
// char String::operator[](int i) const
// {
//     if (i >= len) {
//         throw "Ошибка";
//     } else {
//         return str[i];
//     }
// }

// char &String::operator()(int i)
// {
//     if (i >= len) {
//         throw "Ошибка";
//     } else {
//         return str[i];
//     }
// }

// //операции сравнения
// bool String::operator==(const String &other) const
// {
//     if (len != other.len) {
//         return false;
//     } else {

//         int i = 0;
//         while ((str[i] == other.str[i]) && (i < len)) {
//             i++;
//         }

//         if (i == len) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// }

// bool String::operator!=(const String &other) const
// {
//     if (len != other.len) {
//         return true;
//     } else {

//         int i = 0;
//         while ((str[i] == other.str[i]) && (i < len)) {
//             i++;
//         }

//         if (i == len) {
//             return false;
//         } else {
//             return true;
//         }
//     }
// }

// bool String::operator<(const String &other) const
// {

//     if (*this == other) {
//         return false;
//     }

//     int i = 0;

//     while ((int)(str[i]) == (int)(other.str[i]) && (i < min_len(other))) {
//         i++;
//     }

//     if (i == len) {
//         return true;
//     }
//     if (i == other.len) {
//         return false;
//     }

//     if ((int)(str[i]) < (int)(other.str[i])) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool String::operator>(const String &other) const
// {

//     if (*this == other) {
//         return false;
//     }

//     int i = 0;

//     while ((int)(str[i]) == (int)(other.str[i]) && (i < min_len(other))) {
//         i++;
//     }

//     if (i == len) {
//         return true;
//     }
//     if (i == other.len) {
//         return false;
//     }

//     if ((int)(str[i]) > (int)(other.str[i])) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool String::operator<=(const String &other) const
// {

//     if ((*this < other) || (*this == other)) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool String::operator>=(const String &other) const
// {

//     if ((*this > other) || (*this == other)) {
//         return true;
//     } else {
//         return false;
//     }
// }

// std::ostream &operator<<(std::ostream &out, String &str)
// {
//     for (int i = 0; i < (str.len) - 1; i++) {
//         out << str.str[i];
//     }

//     return out << str.str[str.len - 1];
// };

// std::istream &operator>>(std::istream &in, String &str)
// {

//     char a;

//     while (true) {
//         a = in.get();
//         if (a == '\n') {
//             break;
//         } else {
//             str.add(a);
//         }
//     }
//     return in;
// };






//