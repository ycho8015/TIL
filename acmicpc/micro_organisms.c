#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 100;

struct vNode {
	int y;
	int x;
	int num;
	int dir;
};

vector<vNode> micro;

int map[MAX][MAX][2];
int direction[2][5]
= {
	{0, -1, 1, 0, 0},
	{0, 0, 0, -1, 1}
};

int dir_change[5] = {0, 2, 1, 4, 3};

int n, k, m;

bool isBoundary(int y, int x) {
	return y > 0 && x > 0 && y < n - 1 && x < n - 1;
}

int BFS() {
	int num_left = 0;
	int idx = 0;
	while (idx < m) {
		for (int i = 0; i < micro.size(); i++) {
			int y = micro[i].y + direction[0][micro[i].dir];
			int x = micro[i].x + direction[1][micro[i].dir];
			micro[i].y = y;
			micro[i].x = x;

			if (isBoundary(y, x)) {
				map[y][x][0] += micro[i].num;
				if (map[y][x][1] < micro[i].num)
					map[y][x][1] = micro[i].num;
			} else {
				micro[i].num /= 2;
				map[y][x][0] += micro[i].num;
				micro[i].dir = dir_change[micro[i].dir];
				if (map[y][x][1] < micro[i].num)
					map[y][x][1] = micro[i].num;
			}
		}


		for (int i = 0; i < micro.size(); i++) {
			int y = micro[i].y;
			int x = micro[i].x;
	
			if (map[y][x][1] == micro[i].num) 
				micro[i].num = map[y][x][0];
			else
				micro[i].num = 0;
		}
		memset(map, 0, sizeof(map));
		
		for (vector<vNode>::iterator iter = micro.begin(); iter != micro.end(); ) {
			if ((*iter).num == 0) {
				iter = micro.erase(iter);
			} else {
				iter++;
			}
		}
		
		idx++;
	}
	for (int i = 0; i < micro.size(); i++) {
		num_left += micro[i].num;
	}
	return num_left;
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			int y, x, num, dir;
			scanf("%d %d %d %d", &y, &x, &num, &dir);
			micro.push_back( {y, x, num, dir} );
		}

		int num_left = BFS();
		printf("#%d %d\n", tc, num_left);

		micro.clear();
	}
	return 0;
}