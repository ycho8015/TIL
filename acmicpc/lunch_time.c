#include <cstdio>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

struct Person {
    int y;
    int x;
    int which;
    int dist;
};

struct Stair {
    int y;
    int x;
    int length;
    int num_people;
};

vector<Person> people;
vector<Stair> stairs;
int n, min_time_traveled = INT_MAX;

int abs(int x) {
    return x > 0 ? x : (-1) * x;
}

int manhattanDist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

bool comp(Person a, Person b) {
    if (a.dist < b.dist)
        return true;
    return false;
}

int getTime() {
    int traveled_time = 0;
    queue<Person> q;
    for (int i = 0; i < people.size(); i++) {
        q.push(people[i]);
    }

    while (!q.empty()) {
        int size = q.size();
        traveled_time++;
        while (size--) {
            Person node = q.front();
            q.pop();
            
            if (node.dist > stairs[node.which].length || (node.dist < stairs[node.which].length && node.dist != 0)) {
                node.dist -= 1;
                q.push(node);
            } else if (node.dist == 0) {
                stairs[node.which].num_people -= 1;
            } else if (node.dist == stairs[node.which].length && stairs[node.which].num_people < 3) {
                stairs[node.which].num_people += 1;
                node.dist -= 1;
                q.push(node);
            } else if (node.dist == stairs[node.which].length && stairs[node.which].num_people > 2) {
                q.push(node);
            }
        }
    }
    return traveled_time - 1;
}

int result[10];
void solve(int k) {
    if (k >= people.size()) {
        sort(people.begin(), people.end(), comp);
        int time_traveled = getTime();
        if (time_traveled < min_time_traveled)
            min_time_traveled = time_traveled;
    } else {
        for (int i = 0; i < stairs.size(); i++) {
            people[k].which = i;
            people[k].dist = manhattanDist(people[k].y, people[k].x, stairs[i].y, stairs[i].x) + stairs[i].length + 1;
            solve(k + 1);
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num;
                scanf("%d", &num);
                if (num == 1) {
                    people.push_back( {i, j, 0, 0} );
                } else if (num >= 2) {
                    stairs.push_back( {i, j, num, 0} );
                }
            }
        }
        solve(0);

        printf("#%d %d\n", tc, min_time_traveled);
        stairs.clear();
        people.clear();
        min_time_traveled = INT_MAX;
    }
    return 0;
}
