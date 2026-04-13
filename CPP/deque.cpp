#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

// Deque class
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert at front
    void insertFront(int val) {
        Node* nn = new Node(val);

        if (front == nullptr) {
            front = rear = nn;
        } else {
            nn->next = front;
            front->prev = nn;
            front = nn;
        }
    }

    // Insert at rear
    void insertRear(int val) {
        Node* nn = new Node(val);

        if (rear == nullptr) {
            front = rear = nn;
        } else {
            nn->prev = rear;
            rear->next = nn;
            rear = nn;
        }
    }

    // Delete from front
    int deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty\n";
            return -1;
        }

        Node* temp = front;
        int val = temp->val;

        front = front->next;

        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr;

        delete temp;
        return val;
    }

    // Delete from rear
    int deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty\n";
            return -1;
        }

        Node* temp = rear;
        int val = temp->val;

        rear = rear->prev;

        if (rear != nullptr)
            rear->next = nullptr;
        else
            front = nullptr;

        delete temp;
        return val;
    }

    // Get front
    int getFront() {
        if (front == nullptr) return -1;
        return front->val;
    }

    // Get rear
    int getRear() {
        if (rear == nullptr) return -1;
        return rear->val;
    }

    // Display deque
    void display() {
        Node* temp = front;
        cout << "Deque: ";
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Deque() {
        Node* temp = front;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main function
int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    cout << "Deleted Front: " << dq.deleteFront() << endl;
    dq.display();

    cout << "Deleted Rear: " << dq.deleteRear() << endl;
    dq.display();

    cout << "Deleted Rear: " << dq.deleteRear() << endl;
    cout << "Deleted Rear: " << dq.deleteRear() << endl;
    cout << "Deleted Rear (empty): " << dq.deleteRear() << endl;

    dq.display();

    return 0;
}
