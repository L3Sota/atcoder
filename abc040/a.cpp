#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
 
using namespace std;
 
int main(void) {
	int n, x;
	cin >> n >> x;
	int front = x - 1;
	int back = n - x;
	cout << (front < back ? front : back) << endl;
	return 0;
}
