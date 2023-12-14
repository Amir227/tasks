#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;



struct ListNode
{
    ListNode* next;
    int value;
    ListNode() : value(0), next(nullptr) {};
    ListNode(int new_value, ListNode* next){
        next = nullptr;
        value = new_value;
    }


};

ListNode* Process(ListNode* headA, ListNode* headB)
{
    int sizeA = 1;
    int sizeB = 1;
    ListNode* currentB = headB;
    ListNode* currentA = headA;
    while(currentA->next){
        sizeA++;
        currentA=currentA->next;
    }
    while(currentB->next){
        sizeB++;
        currentB=currentB->next;
    }
    cout << sizeA << "  " << sizeB << endl;
    currentA = headA;
    currentB = headB;
    if (sizeA > sizeB){
        while(currentB){
            currentA->value += currentB->value;
            int i = 0;
            if (currentA->value > 9){
                currentA->value = currentA->value % 10;
                i = 1;
            }
            currentA = currentA->next;
            currentB = currentB->next;
            if (i == 1){
                currentA->value ++;
            }
        }
        return headA;
    }
    else{
        while(currentA){
            currentB->value += currentA->value;
            int i = 0;
            if (currentB->value > 9){
                currentB->value = currentB->value % 10;
                i = 1;
            }
            currentB = currentB->next;
            currentA = currentA->next;
            if (i == 1){
                currentB->value ++;
            }
        }
        return headB;
    }
}

void clear(ListNode* list)
{
    while(list){
        ListNode* ptr = list->next;
        delete list;
        clear(ptr);
    }
}

ListNode *read_list(istream &in)
{
    int value;
    map <string, ListNode*> nodes;
    cout << "Пожалуйста, введите голову списка" << endl;
    cin >> value;
    nodes["head"] = new ListNode();
    nodes["head"]->value = value;

    while(cin.get() != '\n'){
        string a;
        string parent;
        int value;
        string name;
        in >> parent >> value >> name;
        if (name.empty()){
            break;
        }
        ListNode *parentNode = nodes.at(parent);
        ListNode *newNode = new ListNode();
        newNode->value = value;
        parentNode->next = newNode;
        if (nodes.find(name) != nodes.end()) {
            cout << "Ошибка имя не уникально" << endl;
        }
        nodes[name] = newNode;
    }
    return nodes["head"];
}

int main()
{
    ListNode* listA = read_list(cin);
    ListNode* listB = read_list(cin);
    ListNode* listC = Process(listA, listB);
    while (listC){
        cout << listC->value << " ";
        listC = listC->next;
    }
    clear(listB);
    clear(listA);
    cout << endl;
    return 0;
}