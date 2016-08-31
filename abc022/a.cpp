#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int n, s, t, w;
	cin >> n >> s >> t >> w;
	int days = 0;
	if (w >= s && w <= t)
	{
		++days;
	}
	for (int i = 0; i < n-1; ++i)
	{
		int diff;
		cin >> diff;
		w += diff;
		if (w >= s && w <= t)
		{
			++days;
		}
	}
	cout << days << endl;
	return 0;
}
