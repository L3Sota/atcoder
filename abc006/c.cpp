#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int ad = 0;
	int sr = 0;
	int in = 0;
	if (m % 2)
	{
		++sr;
		--n;
		m -= 3;
	}
	if (m < 2*n || m > 4*n)
	{
		cout << "-1 -1 -1" << endl;
		return 0;
	}
	if (m < 3*n) {
		ad = n;
		n = 0;
		m -= 2*ad;
	} else {
		in = n;
		n = 0;
		m -= 4*in;
	}
	if ((m > 0 && ad >= m/2) || (m < 0 && in >= -m/2)) {
		cout << ad - m/2 << " " << sr << " " << in + m/2 << endl;
	} else {
		cout << "-1 -1 -1" << endl;
	}

	return 0;
}
