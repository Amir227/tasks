#include <cstdio>
#include <iostream>

using namespace std;
class List
{
  public:
    List();
    ~List();
    void push_back(int data); // добавление элемента в конец списка
    void pop_front(); // удаление первого элемента из списка
    int getSize() { return size; } // определение текущего размера списка
    void clear(); //удаление данных списка
    int &operator[](const int index); //определение значения по индексу
    void removeCom(int index);
    void pop_back();
    void bubble_sort(); //сортировка пузырьком
  private:
    class Node
    {
      public:
        Node *pNext; //указатель на след узел
        int data; // значение в текущем узле
        Node(int data = 0, Node *pNext = nullptr) // конструктор класса Node
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *head;
    int size;
};

int main()
{
    setlocale(LC_ALL, "ru");
    List lst;
    cout << "Пожалуйста, введите элементы которые хотите записать в список, "
            "нажмите на 'ENTER' чтобы прекратить ввод:"
         << endl;
    int value;
    int index;
    for (int i = 0; cin >> value; i++) {
        lst.push_back(value);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << "Пожалуйста, введите индекс с конца элемента, который хотите "
            "удалить:"
         << endl;
    cin >> index;

    cout << "Элементы списка до удаления: " << endl;
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    cout << "Размер списка:" << lst.getSize() << endl;

    cout << "Элементы списка после удаления: " << endl;
    lst.removeCom(index);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    cout << "Размер списка:" << lst.getSize() << endl;
    cout << endl;
    cout << "Сортировка пузырьком: " << endl;
    lst.bubble_sort();
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    return 0;
}

List ::~List()
{
    clear();
}


void List ::bubble_sort()
{
    Node *left = this->head; // указатель на голову
    Node *right = left->pNext; // следующий элемент после головы
    Node *tmp = new Node; // временный указатель
    while (
        left->pNext != nullptr) { // обход по всем боксам за исключением последнего правого
        while (right != nullptr) // обход уже по всем боксам
        {
            if ((left->data) > (right->data)) { // Сам алгоритм сортировки,
                                                // сравниваем значения в боксах
                tmp->data = left->data;
                left->data = right->data;
                right->data = tmp->data;
            }
            right =
                right->pNext; // направляем указатель на следующий элемент чтобы
                              // не было зацикливания для внутреннего while
        }
        left = left->pNext; // направляем указатель на следующий элемент чтобы
                            // не было зацикливания для внешнего while
        right = left->pNext; // возвращаем указатель назад
    }
    delete tmp; // чтобы не было утечек памяти, удаляем временную переменную.
}