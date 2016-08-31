#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int a, d;
	cin >> a >> d;
	if (a < d) {
		cout << ++a*d << endl;
	} else {
		cout << ++d*a << endl;
	}
	return 0;
}
