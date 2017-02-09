#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#define PRIME_SHORT 10007

using namespace std;

typedef unsigned int ui;

void rar(int n, int* a);

int main(void) {
	ui* data = new ui[1000000];
	data[0] = 0U;
	data[1] = 0U;
	data[2] = 1U;
	size_t n;
	cin >> n;
	--n;
	for (size_t i = 3; i <= n; ++i)
	{
		data[i] = (data[i-1] + data[i-2] + data[i-3]) % PRIME_SHORT;
	}
	cout << data[n] << endl;
	return 0;
}
