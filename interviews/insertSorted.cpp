#include<stdlib.h>
#include<stdio.h>
struct student{
	const char* name;
	float cgpa;
	struct student* next;
};

void insertSorted(student** head, student* new_student)
{
	if(*head==nullptr || new_student->cgpa>(*head)->cgpa)
	{
		new_student->next = *head;
		*head = new_student;
		return;
	}
	
	
	struct student * temp = *head;
	student* prev = nullptr;
	while(temp->next!=nullptr && temp->next->cgpa> new_student->cgpa)
	{
		temp=temp->next;
	}
	new_student->next=temp->next;
	temp->next = new_student;
	return;
}


int main()
{
	student* head = nullptr;
	student* s1 = (student*)malloc(sizeof(student));
	s1->name = "Payal";
	s1->cgpa=3.0;
	insertSorted(&head,s1);
	
	student* s2 = (student*)malloc(sizeof(student));
	s2->name = "Anand";
	s2->cgpa=4.0;
	insertSorted(&head,s2);
	
	student* s3 = (student*)malloc(sizeof(student));
	s3->name = "Rahul";
	s3->cgpa=1.0;
	insertSorted(&head,s3);
	printf("added");
	student* t = head;
	while(t)
	{
	    printf("%f\n",t->cgpa);
	    t=t->next;
	}
	    
	

}


LL in C
#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// LinkedList definition
typedef struct {
    ListNode* head;
    ListNode* tail;
} LinkedList;

// Create new node
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Initialize LinkedList
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = createNode(-1); // dummy head
    list->tail = list->head;
    return list;
}

// Get value at index
int get(LinkedList* list, int index) {
    int t = 0;
    ListNode* temp = list->head->next;

    while (temp != NULL) {
        if (t == index)
            return temp->val;
        t++;
        temp = temp->next;
    }
    return -1;
}

// Insert at head
void insertHead(LinkedList* list, int val) {
    ListNode* nn = createNode(val);
    nn->next = list->head->next;
    list->head->next = nn;

    if (nn->next == NULL)
        list->tail = nn;
}

// Insert at tail
void insertTail(LinkedList* list, int val) {
    ListNode* nn = createNode(val);
    list->tail->next = nn;
    list->tail = nn;
}

// Remove at index
int removeNode(LinkedList* list, int index) {
    int t = 0;
    ListNode* temp = list->head;

    while (temp != NULL && t < index) {
        temp = temp->next;
        t++;
    }

    if (temp != NULL && temp->next != NULL) {
        if (temp->next == list->tail)
            list->tail = temp;

        ListNode* todel = temp->next;
        temp->next = temp->next->next;
        free(todel);
        return 1; // true
    }

    return 0; // false
}

// Get all values
int* getValues(LinkedList* list, int* returnSize) {
    int capacity = 10;
    int* res = (int*)malloc(capacity * sizeof(int));
    int size = 0;

    ListNode* temp = list->head->next;

    while (temp != NULL) {
        if (size == capacity) {
            capacity *= 2;
            res = (int*)realloc(res, capacity * sizeof(int));
        }
        res[size++] = temp->val;
        temp = temp->next;
    }

    *returnSize = size;
    return res;
}
