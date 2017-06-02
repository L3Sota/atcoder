// DATA STRUCTURES
#include <queue>
#include <tuple>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <utility>

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

const int TOO_BIG = 123456;
int R, C, sy, sx, gy, gx;
char **c;
int **s;

int adj[4][2] = {
    {-1, 0},
    { 0, 1},
    { 0,-1},
    { 1, 0}
};

int find(std::queue< std::tuple<int, int, int, int> > sque) {
    while (!sque.empty()) {
        auto next = sque.front();
        sque.pop();
        int y, x, turns, dir;
        std::tie(y, x, turns, dir) = next;
        if (y == gy && x == gx)
        {
            return turns;
        }
        REP(i,4) {
            int ny = y + adj[i][0];
            int nx = x + adj[i][1];
            if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
                int nturns;
                int ndir = i;
                if (dir == 4 || dir == i) {
                    nturns = turns;
                } else {
                    nturns = turns + 1;
                }
                if (nturns <= 2 && c[ny][nx] == '.' && s[ny][nx] > nturns) {
                    s[ny][nx] = nturns;
                    sque.emplace(ny, nx, nturns, ndir);
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    std::cin >> R >> C;
    c = new char*[R];
    s = new int*[R];
    for (int i = 0; i < R; ++i)
    {
        c[i] = new char[C];
        s[i] = new int[C];
        for (int j = 0; j < C; ++j)
        {
            s[i][j] = TOO_BIG;
            std::cin >> c[i][j];
            if (c[i][j] == 'S') {
                sx = j;
                sy = i;
                c[i][j] = '*';
            }
            if (c[i][j] == 'T') {
                gx = j;
                gy = i;
                c[i][j] = '.';
            }
        }
    }

    std::queue< std::tuple<int, int, int, int> > search;
    search.emplace(sy, sx, 0, 4);
    s[sy][sx] = 0;
    int result = find(search);
    if (result == -1 || result > 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

    return 0;
}