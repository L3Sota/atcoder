#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define REP(i,n) for(int i = 0; i < n; ++i)

int main(void) {
    std::ifstream result("result.txt");
    std::vector<std::string> v;
    REP(i,75) {
        std::string s;
        std::getline(result, s, '\n');
        v.push_back(s);
    }
    std::sort(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << '\n';
    }
}
