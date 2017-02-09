#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
	int l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	if (l1 == l2) {
		cout << l3 << endl;
	} else if (l2 == l3)
	{
		cout << l1 << endl;
	} else {
		cout << l2 << endl;
	}
	return 0;
}
