#include <iostream>
#include <vector>

struct Node
{
	int value = 0;
	Node* next = nullptr;
};

struct List
{
	Node* head = nullptr;
	~List();
};

void ListTraverse(const List& list);
void ListAdd(List& list, int value);
void ListRemove(List& list, int value);
void ListClear(List& list);

void FunctionPointerExample();

// TODO next class -- implement sorted add, and cover STL list
// (Also upgrade traverse to use funciton pointers, and make list generic)!
int main()
{
	List list;
	ListAdd(list, 1);
	ListAdd(list, 2);
	ListAdd(list, 3);
	ListRemove(list, 2);
	ListTraverse(list);

	FunctionPointerExample();
	return 0;
}

void Traverse(Node* node)
{
	if (node != nullptr)
	{
		node->value *= 2;
		std::cout << "Value: " << node->value << std::endl;
		Traverse(node->next);
	}
}

void ListTraverse(const List& list)
{
	Traverse(list.head);
}

void ListAdd(List& list, int value)
{
	if (list.head == nullptr)
	{
		list.head = new Node;
		list.head->value = value;
	}
	else
	{
		// 1. Iterate until we reach the next pointer of the element in the list (nullptr)
		Node* temp = list.head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		// 2. Allocate memory for the node we want to add, then point to it!
		temp->next = new Node;
		temp->next->value = value;
	}
}

void ListRemove(List& list, int value)
{
	// Case 0 - List is empty, therefore there's nothing to remove
	if (list.head == nullptr)
		return;

	// Case 1 - Head is the node we want to remove. Perform same logic as ListClear (store curr, point to next, delete curr)
	if (list.head->value == value)
	{
		Node* curr = list.head;
		list.head = list.head->next;
		delete curr;
	}
	else
	{
		Node* curr = list.head, *prev = nullptr;
		
		// Search until we're pointing to the element we want to remove
		while (curr != nullptr && curr->value != value)
		{
			prev = curr;
			curr = curr->next;
		}

		// If our search was successful, delete the node and update the pointer chain
		if (curr != nullptr)
		{
			prev->next = curr->next;
			delete curr;
		}
	}
}

void ListClear(List& list)
{
	std::cout << "Clear called" << std::endl;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		// Store additional garbage pointer so we can advance temp while still keeping track of the previous node to delete!
		Node* garbage = temp;
		temp = temp->next;
		delete garbage;
	}

	// Must nullify head otherwise calling subsequent operations such as Add & Remove will break!!!
	// (Deleting a pointer does not nullify said pointer)
	list.head = nullptr;
}

List::~List()
{
	ListClear(*this);
}

using MathOp = int(*)(int a, int b);

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

void FunctionPointerExample()
{
	MathOp op = nullptr;

	op = Add;
	int a = op(1, 2);

	op = Sub;
	int b = op(1, 2);

	op = Mul;
	int c = op(1, 2);

	op = Div;
	int d = op(1, 2);

	op = nullptr;
}
