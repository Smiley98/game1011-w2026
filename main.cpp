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

int main()
{
	List* list = new List;
	ListAdd(*list, 1);
	ListAdd(*list, 2);
	ListAdd(*list, 3);

	ListTraverse(*list);
	// This will call the destructor which will call our Clear function!
	delete list;

	return 0;
}

void Traverse(Node* node)
{
	if (node != nullptr)
	{
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
