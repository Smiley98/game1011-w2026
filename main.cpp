#include <iostream>

struct Queue
{
	const int capacity = 8;
	int values[8]{};
	int front = 0;
	int back = 0;
};

using QueueFunc = void(*)(int& value);
void QueueForEach(Queue& queue, QueueFunc func)
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
void QueuePush(Queue& queue, int value)
{
	queue.values[queue.back] = value;
	++queue.back %= queue.capacity;
}

// Remove from the front of our queue
void QueuePop(Queue& queue)
{
	++queue.front %= queue.capacity;
}

int& QueueFront(Queue& queue)
{
	return queue.values[queue.front];
}

int& QueueBack(Queue& queue)
{
	return queue.values[queue.back];
}

void Print(int& value)
{
	std::cout << "Value: " << value << std::endl;
}

int main()
{
	Queue queue;

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
	QueueForEach(queue, Print);

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
