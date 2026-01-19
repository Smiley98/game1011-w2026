#include <iostream>
#include <cmath>

void Example1();
void Example2();
void Example3();

int main()
{
	//Example1();
	//Example2();
	Example3();
	return 0;
}

struct Pixel
{
	float r;
	float g;
	float b;
	float a;
};

constexpr int TEXTURE_WIDTH = 1024;
constexpr int TEXTURE_HEIGHT = 1024;

struct Texture
{
	Pixel pixels[TEXTURE_WIDTH][TEXTURE_HEIGHT];
};

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

void Example1()
{
	Circle circle;
	//circle.radius = -1.0f; <-- compiler error because radius is private (inaccessible)
	circle.SetRadius(-1.0f);
}

void Example2()
{
	// Declare a "pointer to an integer" named ptr, which initially points to nothing (nullptr = "nothing")
	int* ptr = nullptr;
	int a = 5;
	int b = 10;

	// Assign ptr to the address of a ('&' = "address-of")
	ptr = &a;
	std::cout << "Pointer address at a: " << ptr << std::endl;
	std::cout << "Pointer value at a: " << *ptr << std::endl;
	// *ptr means "dereference", which looks up the value in the address stored by the pointer
	// In this case, we get the value 5 because ptr stores the address of a

	ptr = &b;
	std::cout << "Pointer address at b: " << ptr << std::endl;
	std::cout << "Pointer value at b: " << *ptr << std::endl;
	// Change the address of ptr to be that of b.
	// Now we see b's address in the console when we output the pointer itself,
	// and we see the value of b (10) when we dereference our pointer!
}

void Example3()
{
	int sz_pixel = sizeof(Pixel);
	int sz_texture = sizeof(Texture);// sz_pixel* TEXTURE_WIDTH* TEXTURE_HEIGHT;
	int sz_texture_kb = sz_texture / 1024;		// 1024 bytes in 1 kilobyte
	int sz_texture_mb = sz_texture_kb / 1024;	// 1024 kilobytes in 1 megabyte
	//Texture texture;
	// The above line of code allocates our texture on the "stack" (and crashes our program)
	// Stack memory is managed by the compiler. Its size must be known at compile-time
	// Generally, its only about 1 megabyte (but we need 16 megabytes to allocate a texture)!!!

	// By using the "new operator", we allocate our texture's memory on the "heap".
	// The heap allows us to use as much memory as our computer has (16 gigabytes in my case)!
	// However, we must now manage this memory ourselves.
	Texture* texture = new Texture;
	delete texture;

	// If we allocate an array of textures, we use scalar-new "new[]"
	// and we must call the corresponding scalar-delete "delete[]"
	// (delete only deletes 1 element, we need to delete all 16 elements with delete[])
	Texture* textures = new Texture[16];
	delete[] textures;
}
