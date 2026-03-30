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
void ListAdd(List list, int value);

int main()
{
	List list;

	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;

	a->value = 1;
	b->value = 2;
	c->value = 3;

	a->next = b;
	b->next = c;
	c->next = nullptr;

	list.head = a;

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

void ListAdd(List list, int value)
{

}
