#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int data[6] = {1, 2, 3, 4, 5, 6};
	n %= 30;
	for (int i = 0; i < n; ++i)
	{
		int index = i%5;
		int temp = data[index];
		data[index] = data[index + 1];
		data[index + 1] = temp;
	}
	for (int i = 0; i < 6; ++i)
	{
		cout << data[i];
	}
	cout << endl;
	
	return 0;
}
