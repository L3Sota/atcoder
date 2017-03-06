#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> ti3;

int main(void)
{
    int n;
    cin >> n;
    int** a = new int*[n-1];
    for (size_t i = 1; i < n; ++i)
    {
        a[i-1] = new int[n-1];

        for (size_t j = 1; j < n; ++j)
        {
            int ans = 114514;
            if (i == j)
                { ans = ((n-1)%i) ? -1 : ((n-1)/i); }
            else if (i > j)
                { ans = a[j-1][i-1]; }
            else // i < j
            {
                ans = -1;

                int** grid = new int*[n];
                for (size_t k = 0; k < n; ++k) {
                    grid[k] = new int[n];
                    for (size_t l = 0; l < n; ++l) {
                        grid[k][l] = 114514;
                    }
                }
                grid[0][0] = 0;
                queue<ti3> q;
                q.emplace(0, 0, 0);
                while(!q.empty())
                {
                    ti3 t = q.front();
                    int first = get<0>(t);
                    int second = get<1>(t);
                    int third = get<2>(t);
                    if (first == n-1 && second == n-1) {
                        ans = third;
                        break;
                    }

                    bool lef_i = first >= i;
                    bool lef_j = first >= j;
                    bool rit_i = first+i < n;
                    bool rit_j = first+j < n;
                    bool top_i = second >= i;
                    bool top_j = second >= j;
                    bool bot_i = second+i < n;
                    bool bot_j = second+j < n;

                    if (rit_i && bot_j && third+1 < grid[first+i][second+j]) {
                        q.emplace(first+i, second+j, third+1);
                        grid[first+i][second+j] = third+1;
                    }
                    if (lef_i && bot_j && third+1 < grid[first-i][second+j]) {
                        q.emplace(first-i, second+j, third+1);
                        grid[first-i][second+j] = third+1;
                    }
                    if (rit_i && top_j && third+1 < grid[first+i][second-j]) {
                        q.emplace(first+i, second-j, third+1);
                        grid[first+i][second-j] = third+1;
                    }
                    if (lef_i && top_j && third+1 < grid[first-i][second-j]) {
                        q.emplace(first-i, second-j, third+1);
                        grid[first-i][second-j] = third+1;
                    }
                    if (rit_j && bot_i && third+1 < grid[first+j][second+i]) {
                        q.emplace(first+j, second+i, third+1);
                        grid[first+j][second+i] = third+1;
                    }
                    if (lef_j && bot_i && third+1 < grid[first-j][second+i]) {
                        q.emplace(first-j, second+i, third+1);
                        grid[first-j][second+i] = third+1;
                    }
                    if (rit_j && top_i && third+1 < grid[first+j][second-i]) {
                        q.emplace(first+j, second-i, third+1);
                        grid[first+j][second-i] = third+1;
                    }
                    if (lef_j && top_i && third+1 < grid[first-j][second-i]) {
                        q.emplace(first-j, second-i, third+1);
                        grid[first-j][second-i] = third+1;
                    }
                    q.pop();
                }
            }
            cout << ans << ' ';
            a[i-1][j-1] = ans;
        }
        cout << '\n';
    }

    return 0;
}
