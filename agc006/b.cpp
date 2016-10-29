#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
    size_t m, n, x;
    cin >> m >> x;
    n = 2*m-1;
    if (x != 1 && x != n)
    {
        cout << "Yes\n";
        size_t *row = new size_t[n];
        size_t pos = m-1;
        row[pos] = x;
        //pos+pos = 2*(m-1) = 2*m-2 = n-1
        for (size_t i = 1; i <= pos; ++i)
        {
            size_t next_up = x+i>n ? x+i-n : x+i;
            size_t next_down = i>=x ? n-i+x : x-i;
            row[pos+i] = (i%2 ? next_up : next_down);
            row[pos-i] = (i%2 ? next_down : next_up);
        }
        for (size_t i = 0; i < n; ++i) cout << row[i] << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
