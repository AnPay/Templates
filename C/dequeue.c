#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque definition
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Create node
Node* createNode(int val) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = val;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

// Initialize deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

// Insert at front
void insertFront(Deque* dq, int val) {
    Node* nn = createNode(val);

    if (dq->front == NULL) {
        dq->front = dq->rear = nn;
    } else {
        nn->next = dq->front;
        dq->front->prev = nn;
        dq->front = nn;
    }
}

// Insert at rear
void insertRear(Deque* dq, int val) {
    Node* nn = createNode(val);

    if (dq->rear == NULL) {
        dq->front = dq->rear = nn;
    } else {
        nn->prev = dq->rear;
        dq->rear->next = nn;
        dq->rear = nn;
    }
}

// Delete from front
int deleteFront(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = dq->front;
    int val = temp->val;

    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    return val;
}

// Delete from rear
int deleteRear(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = dq->rear;
    int val = temp->val;

    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    return val;
}

// Get front
int getFront(Deque* dq) {
    if (dq->front == NULL) return -1;
    return dq->front->val;
}

// Get rear
int getRear(Deque* dq) {
    if (dq->rear == NULL) return -1;
    return dq->rear->val;
}

// Display deque
void display(Deque* dq) {
    Node* temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Free entire deque
void freeDeque(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(dq);
}

// Main function to test
int main() {
    Deque* dq = createDeque();

    insertRear(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertFront(dq, 1);

    display(dq);

    printf("Front: %d\n", getFront(dq));
    printf("Rear: %d\n", getRear(dq));

    printf("Deleted Front: %d\n", deleteFront(dq));
    display(dq);

    printf("Deleted Rear: %d\n", deleteRear(dq));
    display(dq);

    printf("Deleted Rear: %d\n", deleteRear(dq));
    printf("Deleted Rear: %d\n", deleteRear(dq));
    printf("Deleted Rear (empty): %d\n", deleteRear(dq));

    display(dq);

    freeDeque(dq);
    return 0;
}
