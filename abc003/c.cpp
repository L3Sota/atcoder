#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iomanip>//setfill/setw
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

typedef unsigned int ui;

int main(void) {
	int n,k;
	cin >> n >> k;
	double sum = 0.0;

	//array loading
	vector<ui> r;
	for (int i = 0; i < n; ++i)
	{
		ui in;
		cin >> in;
		r.push_back(in);
	}

	sort(r.begin(), r.end());

	for (int i = n-k; i < n; ++i)
	{
		sum += r[i];
		sum /= 2.0;
	}

	cout << setprecision(8) << sum << endl;
	return 0;
}
