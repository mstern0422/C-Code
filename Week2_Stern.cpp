#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Node
{
public:
    char c;
    Node* next;
    Node* prev;
    // constructor
    Node() { 
        next = prev = nullptr; 
        c = ' '; 
    }
    // parametrized constructor
    Node(char value) { 
        c = value; 
        next = prev = nullptr; 
    }
};

int main()
{
    std::ifstream file("TextInput.txt");
    char action;
    char space, data;
    int temp = 0;
    Node* head = new Node(); 
    Node* tail = nullptr; 
    Node* current = nullptr;

    while (file.get(action)){
        if (action == 'A'){
            file.get(space);
            file.get(data);
            Node* newNode = new Node(data);
            if (temp == 0){
                head = newNode;
                newNode -> next = nullptr;
                newNode -> prev = nullptr;
                tail = newNode;
                current = newNode;
                temp = 1;
            } 
            else {
                tail -> next = newNode;
                newNode -> prev = tail;
                newNode -> next = nullptr;
                tail = newNode;
                current = newNode;
                temp = 2;               
            }
        } 
        else if (action == 'B'){
            if (tail != nullptr){
            current = tail -> prev;
                if (tail != nullptr) {
                    tail -> next = nullptr;
                }
                else {
                    head -> next = nullptr;
                }
            }
        }
        else if (action == 'D'){
            if (temp == 1){
                Node *start = head;
                Node* ptr = start;
                start = start -> next;
                delete ptr;
            }
            else if (temp == 2){
                Node* start = head;
                Node *ptr = start;
                while (ptr -> c != current -> c){
                    ptr = ptr -> next;
                }
                Node * ptr1 = start;
                while (ptr1 -> next != ptr){
                    ptr1 = ptr1 -> next;
                }
                Node* ptr2 = ptr -> next;
                ptr1 -> next = ptr2;
                delete ptr;
            }
        }
    }

    Node* start = head;
    while (start != nullptr)
        {
            cout << start -> c << "  ";
            start = start -> next;
        }
    return 0;
}