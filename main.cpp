#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template<typename T>
T Square(T n);

template<typename T>
void Swap(T& a, T& b);

template<typename A, typename B, typename C>
void Print3Types(A a, B b, C c);

void Example1();
void Example2();
void Example3();
void Example4();

template<typename T>
class Array
{
public:

	Array()
	{
		size = 0;
		capacity = 4;
		data = new T[capacity];
	}

	~Array()
	{
		assert(data != nullptr);
		delete[] data;
		data = nullptr;
	}

	// Adds an element to the end of the array
	void Push(T value)
	{
		if (size == capacity)
		{
			// 1) Double capacity
			capacity *= 2;
			T* new_data = new T[capacity];

			// 2) Copy old elements to new memory
			for (int i = 0; i < size; i++)
				new_data[i] = data[i];

			// 3) Delete old memory, reassign internal pointer to new memory
			delete[] data;
			data = new_data;
		}

		data[size] = value;
		size++;
	}

	// Removes the last element from the array
	void Pop()
	{
		if (size > 0)
		{
			size--;
		}
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
			std::cout << "Value " << i + 1 << ": " << data[i] << std::endl;
	}

	T& operator[](int index)
	{
		assert(index >= 0);
		assert(index < size);
		return data[index];
	}

private:
	T* data = nullptr;
	int size = 0;
	int capacity = 0;
};

// You can inheret from templated classes the same way you can inherit from regular classes!

class IntArray : public Array<int>
{
public:

};

class FloatArray : public Array<float>
{
public:

};

int main()
{
	//Example1();
	//Example2();
	//Example3();
	Example4();
	return 0;
}

void Example1()
{
	int a = Square(2);
	float b = Square(2.5f);
}

void Example2()
{
	int a = 5;
	int b = 10;
	std::string first = "Connor";
	std::string last = "Smiley";
	Swap(a, b);
	Swap(first, last);
}

void Example3()
{
	Print3Types(1, 69.420f, "Hello <generic> world!");
	Print3Types("Hello <generic> world!", 69.420f, 1);
}

void Example4()
{
	{
		//Array<int> arr;
		IntArray arr;

		arr.Push(1);
		arr.Push(2);
		arr.Push(3);
		arr.Push(4);
		arr.Push(5);
		arr[-1] = 300;

		// Should print 1, 2, 3, 4, 5
		arr.Print();

		arr.Pop();
		arr.Pop();

		// Should print 1, 2, 3
		arr.Print();
	}

	{
		//Array<float> arr;
		FloatArray arr;

		arr.Push(1.1f);
		arr.Push(2.2f);
		arr.Push(3.3f);

		arr.Print();
		arr.Pop();
		arr.Print();
	}
}

template<typename T>
T Square(T n)
{
	return n * n;
}

template<typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename A, typename B, typename C>
void Print3Types(A a, B b, C c)
{
	std::cout << "Value 1: " << a << "\nValue 2: " << b << "\nValue 3: " << c << std::endl;
}
