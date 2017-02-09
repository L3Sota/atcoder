#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	if (n > k) {
		cout << (x*k + (n-k)*y) << endl;
	} else {
		cout << (x*n) << endl;
	}
	return 0;
}
