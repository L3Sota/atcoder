#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	string s;
	int n;
	cin >> s >> n;
	--n;
	cout << s[n/5] << s[n%5] << endl;
	return 0;
}
