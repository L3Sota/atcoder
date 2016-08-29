#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << (b - a%b)%b << endl;
	
	return 0;
}
