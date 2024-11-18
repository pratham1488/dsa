#include <iostream>
#define SIZE 5

class SimpleQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is Full\n";
            return;
        }
        if (front == -1) // First element to be inserted
            front = 0;
        arr[++rear] = value;
        std::cout << "Enqueued: " << value << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        int value = arr[front++];
        if (front > rear) // Reset queue after last element is dequeued
            front = rear = -1;
        return value;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return;
        }

        std::cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    SimpleQueue sq;

    sq.enqueue(10);
    sq.enqueue(20);
    sq.enqueue(30);
    sq.enqueue(40);
    sq.enqueue(50);

    sq.display();

    std::cout << "Dequeued: " << sq.dequeue() << "\n";
    std::cout << "Dequeued: " << sq.dequeue() << "\n";

    sq.display();

    sq.enqueue(60);
    sq.enqueue(70);

    sq.display();

    return 0;
}
