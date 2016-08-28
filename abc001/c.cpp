#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

//add 112.5 for rounding correction, div 225, round %16
string directions[16] = {
	"N", "NNE", "NE", "ENE",
	"E", "ESE", "SE", "SSE",
	"S", "SSW", "SW", "WSW",
	"W", "WNW", "NW", "NNW"
};

//mult 60, add 3 for rounding error correction
pii speed[14] = {
	pii(0, 0), pii(1, 18), pii(2, 96), pii(3, 204),
	pii(4, 330), pii(5, 480), pii(6, 648), pii(7, 834),
	pii(8, 1032), pii(9, 1248), pii(10, 1470), pii(11, 1710),
	pii(12, 1962), pii(12, 12003)
};

int main(void) {
	int deg, wind, i;
	cin >> deg >> wind;
	i = 0;
	wind += 3;
	while (wind >= speed[i].second) {
		++i;
	}
	--i;
	if (i == 0)
	{
		cout << "C 0" << endl;
	} else {
		cout << directions[((deg*10+1125)/2250)%16] + " " << speed[i].first << endl;
	}
	return 0;
}
