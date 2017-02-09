#include <array>
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

array<char, 5> v = {'a', 'e', 'i', 'o', 'u'};

int main(void) {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (s[i] == v[j])
			{
				s = s.erase(i, 1);
				--i;
				break;
			}
		}
	}

	cout << s << endl;
	return 0;
}
