// 118 - Mutant Flatworld Explorers
#include <iostream>
#include <map>
using namespace std;

int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
                // east   south    west     north
map <int, char> dt;

// 右轉 +1 左轉 -1
int main(){
    dt[0] = 'E';
    dt[1] = 'S';
    dt[2] = 'W';
    dt[3] = 'N';
    int n, m;
    cin >> n >> m;
    int x, y;
    char face;
    int vis[n+5][m+5] = {0};
    while (cin >> x >> y >> face){
        string d;
        cin >> d;
        int now;
        if (face == 'E') now = 0;
        else if (face == 'S') now = 1;
        else if (face == 'W') now = 2;
        else now = 3;
        bool in_the_map = true;
        int nx = x, ny = y;
        for (auto i : d){
            if (i == 'F'){
                nx = x + dir[now][0];
                ny = y + dir[now][1];
                if (nx < 0 || ny < 0 || nx > n || ny > m){
                    if (vis[x][y] == 1) continue;
                    vis[x][y] = 1;
                    in_the_map = false;
                    break;
                }
                x = nx;
                y = ny;
            }else if (i == 'R'){
                now = (now + 1) % 4;
            }else if (i == 'L'){
                now--;
                if (now < 0) now += 4;
            }
        }
        if (in_the_map) cout << x << ' ' << y << ' ' << dt[now] << '\n';
        else cout << x << ' ' << y << ' ' << dt[now] << " LOST\n";
    }
}