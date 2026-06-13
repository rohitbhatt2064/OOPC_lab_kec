#include <iostream>

//void logr(const char* text);

void log(const char* text);

static int Multiply(int a, int b)

{
	int result = a * b;
	log("Multlipy");
	return result;
}

int main()
{
	//std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();
}