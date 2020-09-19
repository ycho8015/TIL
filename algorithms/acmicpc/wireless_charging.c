#include <cstdio>
#include <vector>
using namespace std;

struct AP {
    int y;
    int x;
    int range;
    int power;
};

struct User {
    int y;
    int x;
};

const int MAX = 100;

vector<AP> BC;
vector<User> users[2];

int direction[2][MAX];
int dydx[2][5]
={
    {0, -1, 0, 1, 0},
    {0, 0, 1, 0, -1}
};

int total_power = 0;

int abs(int a, int b) {
    return a - b > 0 ? a - b : (-1) * (a - b);
}

int manhattanDist(int src_y, int src_x, int dest_y, int dest_x) {
    return abs(src_y, dest_y) + abs(src_x, dest_x);
}

bool isBoundary(int y, int x) {
    return y >= 1 && x >= 1 && y <= 10 && x <= 10;
}

void getCoord(int move) {
    users[0].push_back( {1, 1} );
    users[1].push_back( {10, 10} );
   
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < move; j++) {
            int y = users[i][j].y;
            int x = users[i][j].x;

            y += dydx[0][direction[i][j]];
            x += dydx[1][direction[i][j]];

            if (isBoundary(y, x)) {
                users[i].push_back( {y, x} );
            }
        }
    }
}

int max_current_power;
int check[8];
void DFS(int current_move, int current_user, int power) {
    if (current_user >= 2) {
        if (power > max_current_power)
            max_current_power = power;
    } else {
        for (int i = 0; i < BC.size(); i++) {
            int isChargable = manhattanDist(users[current_user][current_move].y, users[current_user][current_move].x, BC[i].y, BC[i].x);
            if (isChargable <= BC[i].range && !check[i]) {
                check[i] = 1;
                DFS(current_move, current_user + 1, power + BC[i].power);
                check[i] = 0;
            }
        }
        DFS(current_move, current_user + 1, power);
    }
}

void solve(int move) {
    for (int i = 0; i <= move; i++) {
        DFS(i, 0, 0);
        total_power += max_current_power;
        max_current_power = 0;
    }
}

int main () {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int move, temp_BC;
        scanf("%d %d", &move, &temp_BC);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < move; j++) {
                scanf("%d", &direction[i][j]);
            }
        }

        for (int i = 0; i < temp_BC; i++) {
            int x, y, range, power;
            scanf("%d %d %d %d", &x, &y, &range, &power);
            BC.push_back( {y, x, range, power} );
        }
        
        getCoord(move);
        solve(move);

        printf("#%d %d\n", tc, total_power);
        total_power = 0;
        BC.clear();
        users[0].clear();
        users[1].clear();
    }
    return 0;
}