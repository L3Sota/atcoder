#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <new>
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

std::string next_name(std::string name) {
    char head = name.front();
    char tail = name.back();
    if (tail != head && tail != 'z') {
        return name.substr(0, name.size()-1) + static_cast<char>(tail+1);
    } else if (head != 'Z') {
        return static_cast<char>(head+1) + name.substr(1, name.size()-1);
    } else {
        size_t newsize = name.size() + 2;
        char* newname = new char[newsize];
        newname[0] = 'A';
        for (size_t i = 1; i < newsize-1; ++i) {
            newname[i] = 'a';
        }
        newname[newsize-1] = '\0';
        std::string result = std::string(newname);
        delete[] newname;
        return result;
    }
}

using namespace std;

int main(void)
{
    size_t n, k;
    cin >> n >> k;

    string* ss = new string[n];
    bool* yn = new bool[n-k+1];
    size_t first_y = n;

    for (size_t i = 0; i < n-k+1; ++i) {
        string temp; cin >> temp;
        yn[i] = (temp == "YES");
    }
    for (size_t i = 0; i < n-k+1; ++i) {
        if (yn[i]) { first_y = i; break; }
    }
    if (first_y == n) {
        for (size_t i = 0; i < n; ++i) {
            ss[i] = "Noob";
        }
    } else {
        string name = "Poo";
        string latest_name = name;
        for (size_t i = first_y; i < first_y+k; ++i) {
            ss[i] = name;
            name = next_name(latest_name);
            latest_name = name;
        }
        for (size_t i = first_y+k; i < n; ++i) {
            if (yn[i-k+1]) {
                ss[i] = next_name(latest_name);
                latest_name = ss[i];
            } else {
                ss[i] = ss[i-k+1];
            }
        }
        for (size_t i = first_y-1; i < n; --i) {
            if (yn[i]) {
                ss[i] = next_name(latest_name);
                latest_name = ss[i];
            } else {
                ss[i] = ss[i+k-1];
            }
        }
    }

    for (size_t i = 0; i < n-1; ++i) {
        cout << ss[i] << ' ';
    }
    cout << ss[n-1] << '\n';

    return 0;
}
