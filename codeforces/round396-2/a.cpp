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

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << ((a.compare(b) == 0) ? -1 : (int)max(a.size(), b.size())) << endl;
    return 0;
}
