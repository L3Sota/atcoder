#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int x;
	cin >> x;
	cout << (x / 10 + x % 10) << endl;
	return 0;
}
