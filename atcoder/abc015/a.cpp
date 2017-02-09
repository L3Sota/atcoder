#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	cout << (a.size() > b.size() ? a : b) << endl;
	
	return 0;
}
