#include <algorithm>
#include <cmath>
#include <cstdlib>//atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort, abs
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define PRIME 1000000007

using namespace std;

int main(void){
	string n;

	cin >> n;
	if (n[n.size() - 1] == 'T')
	{
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
