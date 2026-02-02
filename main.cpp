#include <iostream>

struct Vector2
{
	float x;
	float y;
};

Vector2 operator+(Vector2 a, Vector2 b)
{
	Vector2 v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return v;
}

Vector2 operator-(Vector2 a, Vector2 b)
{
	Vector2 v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
}

Vector2 operator*(Vector2 v, float s)
{
	Vector2 r;
	r.x = v.x * s;
	r.y = v.y * s;
	return r;
}

Vector2 operator/(Vector2 v, float s)
{
	Vector2 r;
	r.x = v.x / s;
	r.y = v.y / s;
	return r;
}

// https://www.geeksforgeeks.org/cpp/overloading-stream-insertion-operators-c/
std::ostream& operator<<(std::ostream& out, Vector2 v)
{
	out << "X: " << v.x << " Y: " << v.y << std::endl;
	return out;
}

// https://www.geeksforgeeks.org/cpp/overloading-stream-insertion-operators-c/
std::istream& operator>>(std::istream& in, Vector2& v)
{
	in >> v.x >> v.y;
	return in;
}

int main()
{
	// The compiler knows how to do + - * / for primitive (built-in) types
	float a = 5.0f;
	float b = 10.0f;
	float c = a + b;
	//float d = 0.0f;
	//std::cout << "Please enter a decimal number" << std::endl;
	//std::cin >> d;
	//std::cout << "You entered " << d << std::endl;

	// However, for user-defined types, we must overload said operators to tell the compiler what to do!
	Vector2 v1{ 1.0f, 2.0f };
	Vector2 v2{ 3.0f, 4.0f };
	Vector2 v3 = v1 + v2;
	Vector2 v4 = v1 - v2;

	Vector2 v5 = v1 * 10.0f;
	Vector2 v6 = v1 / 10.0f;

	//std::cout << "X: " << v5.x << " Y: " << v5.y << std::endl;
	// Much more convenient to output with an overloaded stream-insertion (<<) operator!
	std::cout << v1;
	std::cout << v2;
	std::cout << v3;
	std::cout << v4;
	std::cout << v5;

	// Test overloaded stream insertion and stream extraction operators
	// (See https://www.geeksforgeeks.org/cpp/overloading-stream-insertion-operators-c/ for more information)
	std::cout << "Please enter two decimal values for x & y" << std::endl;
	std::cin >> v6;
	std::cout << "You entered "<< v6;

	return 0;
}
