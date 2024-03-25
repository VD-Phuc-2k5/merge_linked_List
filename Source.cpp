#include <iostream>
#include <stdlib.h>

struct Node
{
	int data;
	Node* next;
};
struct List
{
	Node* head, * tail;
};

void initialize(List &l);
Node* createNode(int value);
void createLinkedList(List &l, int len);

bool isEmpty(List l);
void printLinkedList(Node *head);

void merge(List l1, List l2);
int deleteAfter(List &l, Node* current);
void insertTail(List &l, int value);
void insertAfter(List &l, Node* current, int value);
void swap(int &a, int &b);
void sort(List l, char type);

int main()
{
	List list1, list2;
	// nhap danh sach thu nhat
	initialize(list1);
	createLinkedList(list1, 5);
	// nhap danh sach thu hai
	initialize(list2);
	createLinkedList(list2, 5);
	// xu ly
	merge(list1, list2);
	system("pause>0");
	return 0;
}
bool isEmpty(List l)
{
	return l.head == NULL;
}
void initialize(List &l)
{
	l.head = l.tail = NULL;
}
Node* createNode(int value)
{
	Node* node = new Node;
	node->data = value;
	node->next = NULL;
	return node;
}
void createLinkedList(List &l, int len)
{
	while (len--)
	{
		int temp;
		std::cin >> temp;
		insertTail(l, temp);
	}
}
void printLinkedList(Node *head)
{
	while (head)
	{
		std::cout << head->data << ' ';
		head = head->next;
	}
	std::cout << '\n';
}
void merge(List l1, List l2)
{
	if (isEmpty(l1) && isEmpty(l2)) return;
	if (isEmpty(l1))
		l1.head = l2.head;
	else
		l1.tail->next = l2.head;
	initialize(l2);
	Node* head = l1.head;
	while (head && head->next)
	{
		insertTail(l2, deleteAfter(l1, head));
		head = head->next;
	}
	sort(l1, 'd'); sort(l2, 'a');

	Node* p = l1.head, *q = l2.head;
	while (q)
	{
		insertAfter(l1, p, q->data);
		p = p->next->next;
		q = q->next;
	}
	printLinkedList(l1.head);
}
int deleteAfter(List &l, Node* current)
{
	if (isEmpty(l) || current == NULL) return NULL;
	Node* next_next = current->next->next;
	int value = current->next->data;
	delete current->next;
	current->next = next_next;
	return value;
}
void insertTail(List &l, int value)
{
	Node* node = createNode(value);
	if (isEmpty(l)) 
		l.head = node;
	else
		l.tail->next = node;
	l.tail = node;
}
void insertAfter(List &l, Node* current, int value)
{
	Node* node = createNode(value);
	node->next = current->next;
	current->next = node;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sort(List l, char type)
{
	bool sorted = false, compare;
	if(isEmpty(l)) return;
	while (!sorted)
	{
		sorted = true;
		Node* current = l.head;
		while (current->next)
		{
			if (type == 'a')
				compare = current->data > current->next->data;
			else if (type == 'd')
				compare = current->data < current->next->data;
			else return;

			if (compare)
			{
				sorted = false;
				swap(current->data, current->next->data);
			}
			current = current->next;
		}
	}
}
