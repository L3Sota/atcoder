#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
 
using namespace std;
 
int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	cout << 2*(a*b + b*c + c*a) << endl;
	return 0;
}
