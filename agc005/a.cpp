#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <vector>

using namespace std;

typedef unsigned long ul;

int main(void) {
	string x;
	cin >> x;
	ul n = x.size();
	vector<bool> b;
	b.push_back(x[0] == 'S');

	for (int i = 1; i < n; ++i)
	{
		if (x[i] == 'T') {
			if(b.back()) b.erase(b.end() - 1);
			else b.push_back(false);
		} else {
			b.push_back(true);
		}
	}

    cout << b.size() << endl;
    return 0;
}
