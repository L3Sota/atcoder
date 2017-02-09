#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int m;
	cin >> m;
	if (m < 100)
	{
		cout << "00" << endl;
		return 0;
	}
	if (m > 70000)
	{
		cout << "89" << endl;
		return 0;
	}
	if (m <= 5000)
	{
		m /= 100;
		cout << setfill('0') << right << setw(2) << m << endl;
		return 0;
	}
	if (m >= 35000)
	{
		cout << ((m - 30000) / 5000 + 80) << endl;
		return 0;
	}
	if (m <= 30000)
	{
		cout << (m/1000 + 50) << endl;
		return 0;
	}
}
