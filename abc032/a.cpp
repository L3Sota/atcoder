#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
 
using namespace std;
 
int main(void) {
	int a, b, n;
	cin >> a >> b >> n;
	while(n%a || n%b) {
		++n;
	}
	cout << n << endl;
	return 0;
}
