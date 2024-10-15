#include <iostream>
#define SIZE 5 

class Queue {
private:
    int arr[SIZE]; 
    int front, rear;

public:
   
    Queue() {
        front = -1;
        rear = -1;
    }

   
    bool isEmpty() {
        return front == -1;
    }

   
    bool isFull() {
        return rear == SIZE - 1;
    }

   
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        if (front == -1) front = 0; 
        arr[++rear] = value; 
        std::cout << "Enqueued: " << value << std::endl;
    }

   
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Dequeued: " << arr[front] << std::endl;
        front++;
        if (front > rear) { // Reset queue if it becomes empty
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

    q.display();

    q.dequeue();
    q.display();

    std::cout << "Front element: " << q.peek() << std::endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will show that the queue is full

    q.display();

    return 0;
}
