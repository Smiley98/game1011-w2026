#include <iostream>
#include <cassert>

struct Stack
{
	const int capacity = 8;
	int values[8];
	int top = -1;
};

using StackFunc = void(int value);
void StackForEach(Stack& stack, StackFunc func);

void StackPush(Stack& stack, int value);
int StackPop(Stack& stack);

bool StackIsEmpty(const Stack& stack);
bool StackIsFull(const Stack& stack);

void FuncPrint(int value)
{
	std::cout << "Value: " << value << std::endl;
}

int main()
{
	Stack stack;

	StackPush(stack, 2);
	StackPush(stack, 4);
	StackPush(stack, 6);
	StackPush(stack, 8);

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

	return 0;
}

void StackForEach(Stack& stack, StackFunc func)
{
	for (int i = 0; i <= stack.top; i++)
		func(stack.values[i]);
}

void StackPush(Stack& stack, int value)
{
	assert(!StackIsFull(stack));
	stack.top++;
	stack.values[stack.top] = value;
}

int StackPop(Stack& stack)
{
	assert(!StackIsEmpty(stack));
	int top = stack.values[stack.top];
	stack.top--;
	return top;
}

bool StackIsEmpty(const Stack& stack)
{
	return stack.top < 0;
}

bool StackIsFull(const Stack& stack)
{
	return stack.top >= stack.capacity - 1;
}
