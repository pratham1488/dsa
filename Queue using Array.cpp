#include <iostream>
#define MAX 5 

class Queue {
private:
    int front;
    int rear;
    int arr[MAX]; 

public:
   
    Queue() {
        front = -1;
        rear = -1;
    }

    
    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue " << value << std::endl;
            return;
        }
        if (front == -1) front = 0; // If inserting first element, update front
        arr[++rear] = value; 
        std::cout << "Enqueued: " << value << std::endl;
    }

    
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue." << std::endl;
            return;
        }
        std::cout << "Dequeued: " << arr[front] << std::endl;
        front++; // Move front to the next element
        if (front > rear) { 
            front = rear = -1;
        }
    }

    
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return arr[front];
    }


    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    std::cout << "Front element: " << q.peek() << std::endl;

    q.enqueue(60);

    return 0;
}
