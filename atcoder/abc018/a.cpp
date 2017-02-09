#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int score[3], rank[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> score[i];
		rank[i] = 0;
	}
	for (int i = 0; i < 3; ++i)
	{
		int j = (i + 1)%3;
		if (score[i] > score[j])
		{
			++rank[i];
		} else {
			++rank[j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		switch (rank[i]) {
			case 0: {cout << 3 << endl; break;}
			case 1: {cout << 2 << endl; break;}
			case 2: {cout << 1 << endl; break;}
		}
	}
	return 0;
}
