#include <string>
#include <iostream>
#include <tuple>
#include <vector>

class ElementA
{
public:
	ElementA(const int i) : integer(i)
	{
	}
	ElementA() : integer(-1)
	{
	}
	
	int integer;
};

std::vector<std::tuple<ElementA&>> vector;

void pushA(const ElementA &e)
{
	ElementA a;
	ElementA &r_a = a;
	std::tuple<ElementA&> tup = std::forward_as_tuple(r_a);

	std::get<0>(tup) = e;
	vector.push_back(tup);
}

int main(void)
{
	ElementA myA(777);
	pushA(myA);
	std::cout << std::get<0>(vector.at(0)).integer << std::endl;	// garbage value here, not 777

	return 0;
}