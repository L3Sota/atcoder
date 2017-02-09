#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	const int n = 4;
	char** grid = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		grid[i] = new char[n];
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = n-1; j; --j)
		{
			cout << grid[i][j] << " ";
		}
		cout << grid[i][0] << endl;
	}

	return 0;
}
