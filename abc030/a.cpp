#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a*d > b*c) {
		cout << "AOKI" << endl;
	} else if (a*d < b*c) {
		cout << "TAKAHASHI" << endl;
	} else {
		cout << "DRAW" << endl;
	}
	return 0;
}
