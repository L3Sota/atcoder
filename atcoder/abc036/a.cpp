#include <iostream>

int main(void)
{
	int a, b;
	std::cin >> a >> b;
	std::cout << b/a + (b%a==0?0:1) << std::endl;
	return 0;
}
