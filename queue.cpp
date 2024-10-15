#include <iostream>
using namespace std;

#define SIZE 5  

int queue[SIZE]; 
int front = -1;   
int rear = -1;  


bool isFull() {
    return rear == SIZE - 1;
}


bool isEmpty() {
    return front == -1 || front > rear;
}


void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue " << value << endl;
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;           
    queue[rear] = value; 
    cout << value << " enqueued to the queue.\n";
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue.\n";
        return;
    }
    cout << queue[front] << " dequeued from the queue.\n";
    front++; 


    if (front > rear) {
        front = rear = -1;
    }
}


void peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element is: " << queue[front] << endl;
}

int main() {
  
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

  
    enqueue(60);

    peek();  

    dequeue();
    dequeue();

    peek();  

    return 0;
}
