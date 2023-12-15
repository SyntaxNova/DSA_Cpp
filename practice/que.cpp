#include<iostream>

using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int *queue;

public:
    // Constructor to initialize the circular queue
    CircularQueue(int size) {
        maxSize = size;
        front = rear = -1;
        queue = new int[maxSize];
    }

    // Destructor to free the dynamically allocated memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    // Function to enqueue (insert) an element
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        queue[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Function to dequeue (delete) an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << queue[front] << endl;

        if (front == rear) {
            // If the queue has only one element, reset front and rear
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);

        cout << endl;
    }
};

int main() {
    // Create a circular queue with a fixed size (e.g., 5)
    CircularQueue cq(5);

    // Perform operations on the circular queue
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();

    cq.enqueue(6); // This will display a message indicating the queue is full

    return 0;
}

