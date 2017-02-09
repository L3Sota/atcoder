#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
 
using namespace std;
 
int main(void) {
	int n;
	cin >> n;
	int min = 100;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		if (min > t)
		{
			min = t;
		}
	}
	cout << min << endl;
 
	return 0;
}
