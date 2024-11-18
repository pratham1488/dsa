#include <iostream>
#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is Full\n";
            return;
        }

        if (front == -1) // First element to be inserted
            front = rear = 0;
        else if (rear == SIZE - 1 && front != 0) // Wrap around
            rear = 0;
        else
            rear++;

        arr[rear] = value;
        std::cout << "Enqueued: " << value << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }

        int value = arr[front];
        arr[front] = -1; // Optional, to clear dequeued value

        if (front == rear) // Queue becomes empty
            front = rear = -1;
        else if (front == SIZE - 1) // Wrap around
            front = 0;
        else
            front++;

        return value;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return;
        }

        std::cout << "Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                std::cout << arr[i] << " ";
        } else {
            for (int i = front; i < SIZE; i++)
                std::cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    return 0;
}
