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

void Traverse(Node* node)
{
	if (node != nullptr)
	{
		std::cout << "Value: " << node->value << std::endl;
		Traverse(node->next);
	}
}

// Iterative traversal. Using recursive traversal to review recursion
void Travere2(List list);

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

	Traverse(list.head);

	return 0;
}

void Travere2(List list)
{
	Node* temp = list.head;
	while (temp != nullptr)
	{
		std::cout << "Value: " << temp->value << std::endl;
		temp = temp->next;
	}
}
