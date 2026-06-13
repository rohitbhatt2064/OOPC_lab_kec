
#include <iostream>

void log(const char* text)
{
	std::cout << text << std::endl;
}

static int Multiply(int a, int b)

{
	int result = a * b;
	log("Multlipy");
	return result;
}