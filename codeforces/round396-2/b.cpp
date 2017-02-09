#include <algorithm>//min/max/sort(rand-access it)/merge
#include <array>
#include <bitset>
// #include <chrono>//std::chrono::/system_clock/steady_clock/high_resolution_clock/duration
#include <climits>//INT_MAX/INT_MIN/ULLONG_MAX
#include <cmath>//fmin/fmax/fabs/sin(h)/cos(h)/tan(h)/exp/log/pow/sqrt/cbrt/ceil/floor/round/trunc
// #include <cstdio>//printf/scanf/fopen/fclose/fprintf/fscanf/snprintf/putc/puts/getc/gets
#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
// #include <fstream>//ifstream/ofstream
#include <iomanip>//setfill/setw/setprecision/fixed/scientific
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN
#include <list>
#include <new>
#include <queue>
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <tuple>
#include <utility>//pair
#include <valarray>
#include <vector>

using namespace std;

const bool debug = false;

int main(void)
{
    int n;
    cin >> n;


    vector<int> a;
    for (size_t i = 0; i < n; ++i) {
        int temp; cin >> temp;
        a.push_back(temp);
    }

    //debug output
    if (debug)
    {
        //1D
        cout << "a" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << "\t";
        }
    }

    sort(a.begin(), a.end());

    int x;
    int y = a[0];
    int z = a[1];
    for (size_t i = 2; i < n; ++i) {
        x = y;
        y = z;
        z = a[i];
        if ((x + y) > z) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
