#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
 
using namespace std;
 
int main(void) {
	int a[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
	int five = 0;
	int seven = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] == 5)
		{
			++five;
		}
		if (a[i] == 7)
		{
			++seven;
		}
	}
	cout << (five == 2 && seven == 1 ? "YES" : "NO") << endl;
	return 0;
}
