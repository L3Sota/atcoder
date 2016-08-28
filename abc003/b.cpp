#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

bool valid(char c)
{
	switch(c) {
		case '@':case 'a':case 't':case 'c':case 'o':case 'd':case 'e':case 'r': return true;
		default: return false;
	}
}

int main(void){
	string s,t;
	cin >> s >> t;
	bool winnable = true;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == t[i] || (t[i] == '@' && valid(s[i])) || (s[i]=='@' && valid(t[i]))) {
			continue;
		} else {
			winnable = false;
			break;
		}
	}
	cout << (winnable ? "You can win" : "You will lose") << endl;
	return 0;
}
