#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int s[3], e[3];
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> s[i] >> e[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		sum += s[i]*e[i]/10;
	}
	cout << sum << endl;

	return 0;
}
