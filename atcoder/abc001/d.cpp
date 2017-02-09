#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool debug = false;

int main(void) {
	int n;
	cin >> n;
	list<pii> t;

	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		string s;
		cin >> s;
		a = stoi(s.substr(0, 2));//input format:
		b = stoi(s.substr(2, 2));//HHMM-HHMM
		c = stoi(s.substr(5, 2));//012345678
		d = stoi(s.substr(7, 2));//aabb ccdd
		if (d > 55) {
			++c;
		}
		b = (b/5)*5;
		d = (((d+4)/5)%12)*5;
		t.push_back(pii(a*100+b, c*100+d));
	}

	t.sort();

	if (debug)
	{
		for (list<pii>::iterator i = t.begin(); i != t.end(); ++i)
		{
			pii now = *i;
			cout << setfill('0') << right
			<< setw(4) << now.first << "-" 
			<< setw(4) << now.second << endl;
		}
	}

	for (list<pii>::iterator i = t.begin(); i != --t.end(); ++i)
	{
		pii current = *i;
		++i;
		pii next = *i;
		--i;
		int startC = current.first;
		int startN = next.first;
		int endC = current.second;
		int endN = next.second;
		if (endC >= startN)
		{
			pii merge;
			if (endN >= endC) {
				merge = pii(startC, endN);
			} else {
				merge = pii(startC, endC);
			}
			i = t.insert(i, merge);
			++i;
			i = t.erase(i);
			i = t.erase(i);
			--i;
			--i;
		}
	}

	for (list<pii>::iterator i = t.begin(); i != t.end(); ++i)
	{
		pii now = *i;
		cout << setfill('0') << right
		<< setw(4) << now.first << "-" 
		<< setw(4) << now.second << endl;
	}

	return 0;
}
