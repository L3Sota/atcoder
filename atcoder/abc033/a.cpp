#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << (n % 1111 ? "DIFFERENT" : "SAME") << endl;
	return 0;
}
