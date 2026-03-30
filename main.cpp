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
};

void ListTraverse(List list);
void ListAdd(List& list, int value);
void ListRemove(List& list, int value);

int main()
{
	List list;
	ListAdd(list, 1);
	ListAdd(list, 2);
	ListAdd(list, 3);

	ListTraverse(list);

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

void ListTraverse(List list)
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

void ListRemove(List & list, int value)
{

}
