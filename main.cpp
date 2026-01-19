#include <iostream>
#include <cmath>

class Circle
{
public:
	float GetRadius() { return radius; }
	void SetRadius(float r)
	{
		// Setters only make sense if they do some form of validation.
		// In this case, we ensure that our circle's radius cannot be negative!
		r = std::max(r, 0.0f);
		radius = r;
	}

private:
	float radius;
};

int main()
{
	return 0;
}
