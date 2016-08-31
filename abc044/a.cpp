#include <algorithm>//min/max/sort(rand-access it)/merge
#include <array>
#include <bitset>
#include <climits>//INT_MAX/INT_MIN/ULLONG_MAX
#include <cmath>//fmin/fmax/fabs/sin(h)/cos(h)/tan(h)/exp/log/pow/sqrt/cbrt/ceil/floor/round/trunc
#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
#include <iomanip>//setfill/setw
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>
#include <list>
#include <queue>
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <tuple>
#include <utility>//pair
#include <valarray>
#include <vector>

#define PRIME 1000000007

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<ull, int> puli;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pllll;
typedef pair<ull, ull> pulul;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

const bool debug = false;

int main(void) {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	if (n > k)
	{
		cout << (x*k + (n-k)*y) << endl;
	} else {
		cout << (x*n) << endl;
	}
	return 0;
}
