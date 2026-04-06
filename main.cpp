#include <iostream>
#include <vector>

template<typename T>
struct Node
{
	T value = 0;
	Node<T>* next = nullptr;
};

template<typename T>
struct List
{
	Node<T>* head = nullptr;
	~List();
};

template<typename T>
using NodeFunc = void(Node<T>* node);

//template<typename T>
//void ListTraverse(const List<T>& list, NodeFunc<T> func);
//
//template<typename T>
//void ListAdd(List<T>& list, int value);
//
//template<typename T>
//void ListRemove(List<T>& list, int value);
//
//template<typename T>
//void ListClear(List<T>& list);

void FunctionPointerExample();

template<typename T>
void NodePrint(Node<T>* node)
{
	std::cout << "Value: " << node->value << std::endl;
}

template<typename T>
void NodeDouble(Node<T>* node)
{
	node->value *= 2;
}

template<typename T>
void NodeTriple(Node<T>* node)
{
	node->value *= 3;
}

template<typename T>
void NodeTraverse(Node<T>* node, NodeFunc<T> func)
{
	if (node != nullptr)
	{
		func(node);
		NodeTraverse(node->next, func);
	}
}

template<typename T>
void ListTraverse(const List<T>& list, NodeFunc<T> func)
{
	NodeTraverse(list.head, func);
}

template<typename T>
void ListAdd(List<T>& list, int value)
{
	if (list.head == nullptr)
	{
		list.head = new Node<T>;
		list.head->value = value;
	}
	else
	{
		// 1. Iterate until we reach the next pointer of the element in the list (nullptr)
		Node<T>* temp = list.head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		// 2. Allocate memory for the node we want to add, then point to it!
		temp->next = new Node<T>;
		temp->next->value = value;
	}
}

template<typename T>
void ListRemove(List<T>& list, int value)
{
	// Case 0 - List is empty, therefore there's nothing to remove
	if (list.head == nullptr)
		return;

	// Case 1 - Head is the node we want to remove. Perform same logic as ListClear (store curr, point to next, delete curr)
	if (list.head->value == value)
	{
		Node<T>* curr = list.head;
		list.head = list.head->next;
		delete curr;
	}
	else
	{
		Node<T>* curr = list.head, *prev = nullptr;
		
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

template<typename T>
void ListClear(List<T>& list)
{
	std::cout << "Clear called" << std::endl;

	Node<T>* temp = list.head;
	while (temp != nullptr)
	{
		// Store additional garbage pointer so we can advance temp while still keeping track of the previous node to delete!
		Node<T>* garbage = temp;
		temp = temp->next;
		delete garbage;
	}

	// Must nullify head otherwise calling subsequent operations such as Add & Remove will break!!!
	// (Deleting a pointer does not nullify said pointer)
	list.head = nullptr;
}

template<typename T>
List<T>::~List()
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

int main()
{
	List<int> list;
	ListAdd(list, 1);
	ListAdd(list, 2);
	ListAdd(list, 3);
	//ListRemove(list, 2);

	std::cout << "Values x1:\n";
	ListTraverse<int>(list, NodePrint);

	std::cout << "Values x2:\n";
	ListTraverse(list, NodeDouble);
	ListTraverse(list, NodePrint);

	std::cout << "Values x6:\n";
	ListTraverse(list, NodeTriple);
	ListTraverse(list, NodePrint);

	FunctionPointerExample();
	return 0;
}