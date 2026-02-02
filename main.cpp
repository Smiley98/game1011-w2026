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

int main()
{
	// The compiler knows how to do + - * / for primitive (built-in) types
	//float a = 5.0f;
	//float b = 10.0f;
	//float c = a + b;

	// However, for user-defined types, we must overload said operators to tell the compiler what to do!
	Vector2 v1{ 1.0f, 2.0f };
	Vector2 v2{ 3.0f, 4.0f };
	Vector2 v3 = v1 + v2;
	Vector2 v4 = v1 - v2;

	Vector2 v5 = v1 * 10.0f;
	Vector2 v6 = v1 / 10.0f;

	return 0;
}
