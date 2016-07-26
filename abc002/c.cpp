#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
#include <iomanip>//setfill/setw
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <valarray>

using namespace std;

int main(void) {
	valarray<int> pts[3];
	for (int i = 0; i < 3; ++i)
	{
		int a[2];
		cin >> a[0] >> a[1];
		pts[i] = valarray<int>(a, 2);
	}

	pts[1] -= pts[0];
	pts[2] -= pts[0];
	int iarea = abs(pts[1][0]*pts[2][1] - pts[2][0]*pts[1][1]);
	double area = 0.5 * iarea;
	cout << setprecision(8) << area << endl;
	return 0;
}
