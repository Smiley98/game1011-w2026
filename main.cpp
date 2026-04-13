struct Queue
{
	const int capacity = 8;
	int values[8]{};
	int front = 0;
	int back = 0;
};

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

int main()
{
	Queue queue;

	QueuePush(queue, 3);
	QueuePush(queue, 6);
	QueuePush(queue, 9);

	int a = QueueFront(queue);
	QueuePop(queue);

	int b = QueueFront(queue);
	QueuePop(queue);

	int c = QueueFront(queue);
	QueuePop(queue);

	return 0;
}
