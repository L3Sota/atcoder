#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;
	cout << (a*s + b*t + (s + t >= k ? -(s+t)*c : 0)) << endl;
	return 0;
}
