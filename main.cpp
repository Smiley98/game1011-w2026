#include <iostream>

template<typename T>
struct Queue
{
	T values[8]{};
	const int capacity = 8;
	int front = 0;
	int back = 0;
};

template<typename T>
using QueueFunc = void(*)(T& value);

template<typename T>
void QueueForEach(Queue<T>& queue, QueueFunc<T> func)
{
	// Copy front so we don't change queue's actual front-index
	int front = queue.front;
	while (front != queue.back)
	{
		func(queue.values[front]);
		++front %= queue.capacity;
	}
}

// Add to the back of the queue
template<typename T>
void QueuePush(Queue<T>& queue, T value)
{
	queue.values[queue.back] = value;
	++queue.back %= queue.capacity;
}

// Remove from the front of our queue
template<typename T>
void QueuePop(Queue<T>& queue)
{
	++queue.front %= queue.capacity;
}

template<typename T>
int& QueueFront(Queue<T>& queue)
{
	return queue.values[queue.front];
}

template<typename T>
int& QueueBack(Queue<T>& queue)
{
	return queue.values[queue.back];
}

template<typename T>
void FuncPrint(T value)
{
	std::cout << "Value: " << value << std::endl;
}

template<typename T>
void FuncDouble(T& value)
{
	value *= 2;
}

int main()
{
	Queue<int> queue;

	QueuePush(queue, 5);
	QueuePush(queue, 10);
	QueuePush(queue, 15);
	QueuePush(queue, 20);
	QueuePush(queue, 25);
	// front = 0, back = 5

	QueuePop(queue);
	// front = 1, back = 5

	QueuePush(queue, 3);
	QueuePush(queue, 6);
	QueuePush(queue, 9);
	// front = 1, back = 0

	QueueFront(queue) = 69420;
	QueueForEach(queue, FuncDouble);
	QueueForEach(queue, FuncPrint);

	QueuePop(queue);
	QueuePop(queue);
	QueuePop(queue);
	// front = 4, back = 0

	QueuePush(queue, 2);
	QueuePush(queue, 4);
	QueuePush(queue, 6);
	// front = 4, back = 3

	return 0;
}
