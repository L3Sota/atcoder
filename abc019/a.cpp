#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int age[3], rank[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> age[i];
		rank[i] = 0;
	}
	for (int i = 0; i < 3; ++i)
	{
		int j = (i + 1)%3;
		if (age[i] > age[j])
		{
			++rank[i];
		} else if (age[i] < age[j]) {
			++rank[j];
		} else {
			cout << age[i] << endl;
			return 0;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (rank[i] == 1)
		{
			cout << age[i] << endl;
			return 0;
		}
	}
	return 0;
}
