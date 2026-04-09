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
