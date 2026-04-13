#include <iostream>
#include <cassert>

template<typename T>
struct Stack
{
	T values[8];
	const int capacity = 8;
	int top = -1;
};

template<typename T>
using StackFunc = void(T value);

template<typename T>
void StackForEach(Stack<T>& stack, StackFunc<T> func);

template<typename T>
void StackPush(Stack<T>& stack, T value);

template<typename T>
void StackPop(Stack<T>& stack);

template<typename T>
T& StackTop(Stack<T>& stack);

template<typename T>
bool StackIsEmpty(const Stack<T>& stack);

template<typename T>
bool StackIsFull(const Stack<T>& stack);

template<typename T>
void FuncPrint(T value)
{
	std::cout << "Value: " << value << std::endl;
}

int main()
{
	Stack<int> stack;

	StackPush(stack, 2);
	StackPush(stack, 4);
	StackPush(stack, 6);
	StackPush(stack, 8);

	StackTop(stack) = 69420;

	StackPush(stack, 10);
	StackPush(stack, 12);
	StackPush(stack, 14);
	StackPush(stack, 16);

	// Test stack-full assert
	//StackPush(stack, 18);
	StackForEach(stack, FuncPrint);

	StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);

	StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);

	// Test stack-empty assert
	//StackPop(stack);
	StackForEach(stack, FuncPrint);

	StackPush(stack, 2);
	StackPush(stack, 4);
	StackPush(stack, 6);
	StackPush(stack, 8);
	StackForEach(stack, FuncPrint);

	StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);

	return 0;
}

template<typename T>
void StackForEach(Stack<T>& stack, StackFunc<T> func)
{
	for (int i = 0; i <= stack.top; i++)
		func(stack.values[i]);
}

template<typename T>
void StackPush(Stack<T>& stack, T value)
{
	assert(!StackIsFull(stack));
	stack.top++;
	stack.values[stack.top] = value;
}

template<typename T>
void StackPop(Stack<T>& stack)
{
	assert(!StackIsEmpty(stack));
	stack.top--;
}

template<typename T>
T& StackTop(Stack<T>& stack)
{
	assert(!StackIsEmpty(stack));
	assert(!StackIsFull(stack));
	return stack.values[stack.top];
}

template<typename T>
bool StackIsEmpty(const Stack<T>& stack)
{
	return stack.top < 0;
}

template<typename T>
bool StackIsFull(const Stack<T>& stack)
{
	return stack.top >= stack.capacity - 1;
}
