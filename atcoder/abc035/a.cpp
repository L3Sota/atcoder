#include <iostream>

int main(void)
{
	int w, h;
	std::cin >> w >> h;
	if(((double)w) / h < 1.5)
	{
		std::cout << "4:3" << std::endl;
	} else {
		std::cout << "16:9" << std::endl;
	}
}
