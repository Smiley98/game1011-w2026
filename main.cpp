#include <iostream>
#include <vector>

struct Node
{
	int value = 0;
	Node* next = nullptr;
};

int main()
{
	Node* head = nullptr;

	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;

	a->value = 1;
	b->value = 2;
	c->value = 3;

	a->next = b;
	b->next = c;
	c->next = nullptr;

	head = a;

	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "Value: " << temp->value << std::endl;
		temp = temp->next;
	}

	return 0;
}
