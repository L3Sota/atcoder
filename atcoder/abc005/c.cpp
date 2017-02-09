#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

void rar(int n, int* a);

int main(void) {
	int t, n, m;
	cin >> t >> n;
	int* a = new int[n];
	rar(n, a);
	cin >> m;
	if (n < m)
	{
		cout << "no" << endl;
		return 0;
	}
	int* b = new int[m];
	rar(m, b);
	int margin = n - m;
	int i = 0;
	int j = 0;
	int misses = 0;
	while (misses <= margin && i < n && j < m)
	{
		while(b[j] - a[i] > t) {
			++i;
			++misses;
		}
		if (a[i] > b[j])
		{
			cout << "no" << endl;
			return 0;
		}
		++i;
		++j;
	}

	cout << (misses <= margin ? "yes" : "no") << endl;

	return 0;
}

void rar(int n, int* a)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	return;
}
