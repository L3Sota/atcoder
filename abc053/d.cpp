#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> elements;
    int max_element = numeric_limits<int>::min();
    for (size_t i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        elements.push_back(temp);
        if (temp > max_element)
            max_element = temp;
    }

    vector<int> counter(max_element+1, 0);

    for (size_t i = 0; i < n; ++i)
        ++counter[elements[i]];

    int totalcount = 0;
    for (size_t i = 0; i <= max_element; ++i) {
        if (counter[i] > 1)
            totalcount += counter[i] - 1;
    }
    if (totalcount % 2)
        ++totalcount;

    cout << (n - totalcount) << endl;

    return 0;
}
