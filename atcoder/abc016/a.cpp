#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int m, d;
	cin >> m >> d;
	cout << (m%d ? "NO" : "YES") << endl;
	return 0;
}
