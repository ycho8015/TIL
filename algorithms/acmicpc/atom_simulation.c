#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 4005;

struct vNode {
    int y;
    int x;
    int dir;
    int energy;
};

vector<vNode> atoms;

int map[MAX][MAX];
int direction[2][4]
={
    {1, -1, 0, 0},
    {0, 0, -1, 1}
};

int total_energy;

bool isBoundary(int y, int x) {
    return y >= 0 && x >= 0 && y < MAX && x < MAX;
}

void solve() {
    while (!atoms.empty()) {
        int size = (int)atoms.size();
        for (int i = 0; i < size; i++) {
            int y = atoms[i].y;
            int x = atoms[i].x;
            int dir = atoms[i].dir;
            int energy = atoms[i].energy;

            map[y][x] = 0;

            int ny = y + direction[0][dir];
            int nx = x + direction[1][dir];

            if (isBoundary(ny, nx)) {
                map[ny][nx] += energy;
                atoms[i].y = ny;
                atoms[i].x = nx;
            } else {
                atoms[i].energy = 0;
            }
        }

        for (int i = 0; i < size; i++) {
            int y = atoms[i].y;
            int x = atoms[i].x;
            int energy = atoms[i].energy;
		
            if (energy == 0) continue;
            
            if (map[y][x] != energy) {
                total_energy += map[y][x];
                atoms[i].energy = 0;
                map[y][x] = 0;
            }
        }

        for (vector<vNode> :: iterator iter = atoms.begin(); iter != atoms.end(); ) {
            if ((*iter).energy == 0)
                iter = atoms.erase(iter);
            else
                iter++;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int y, x, dir, energy;
            scanf("%d %d %d %d", &x, &y, &dir, &energy);   
            atoms.push_back( { 2 * (y + 1000), 2 * (x + 1000), dir, energy} );
        }

        solve();

        printf("#%d %d\n", tc, total_energy);
        total_energy = 0;
        atoms.clear();
    }
    return 0;
}