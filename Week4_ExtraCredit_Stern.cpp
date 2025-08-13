#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
private:
    int data[MAX_SIZE];
    int front; // some books define this as H or head
    int rear; // some books define this as T or tail
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear == -1;
    }

    bool isFull() {
        return front == MAX_SIZE - 1;
    }
    // Rear needs to be changed to front in the above line of code, otherwise when the queue is full,
    // the wrong value from the queue, the rear, is being returned instead of the frontmost item from the queue

    void push(int x) {
        if (isFull()) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        data[++rear] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        int x = data[front];
// front++ needs to be removed from this line of code. Queues work differently from stacks, and there is no need
// to add a value to the front of the queue when the pop function is called. Otherwise, this function ends up
// adding 1 to the frontmost item in the queue, which in turn will return the wrong value
        if (front > rear) {
            front = 0;
            rear = -1;
        }
// After looking up various information about queues using arrays online, I realized that the queue also never
// adjusts the values within the array once they are removed. Using a for loop resolves this by moving each value
// within the queue up one
        for (int i = 0; i < rear; i++) {
            data[i] = data[i + 1];
        }
// After the values within the queue are relocated to the appropriate places within the array, the last value within
// the queue needs to be removed, as it is no longer in use
        rear--;
        return x;
    }
};

int main() {
    Queue queue;

    queue.push(1);
    queue.push(2);
    queue.push(2);
    queue.push(2);
    queue.push(6);
    cout << queue.pop() << endl;
    queue. push (2);
    cout << queue.pop() << endl;
    queue. push (3);
    cout << queue.pop() << endl;
    queue. push (3);
    cout << queue.pop() << endl;
    queue. push (3);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    return 0;

    // With this given code for main, while it does still technically work when the code is ran the
    // last four values that are pushed into the queue never get printed because the pop function
    // being called is only called enough times to print the initial five values from the queue.
    // In order for all of the values to be printed without overfilling the queue, the pop function
    // simply needs to be called on 4 more times for all of the values to be printed
}