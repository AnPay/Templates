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
	while(temp->next!=nullptr && temp->next->cgpa> (*head)->cgpa)
	{
		temp=temp->next;
	}
	new_student->next=temp->next;
	temp->next = new_student;
	return;
}
