#include <cstdio>
#include <queue>
#include <limits.h>

using namespace std;

const int MAX = 16;

int map[MAX][MAX][2];
int sequence[MAX];
int direction[2][4]
= {
	{-1, 1, 0, 0},
	{0, 0, 1, -1}
};

int n, row, col;
int bricks_left = INT_MAX;

struct Point {
	int y;
	int x;
	int bricks;
};

// 좌표의 범위 체크
bool isBoundary(int y, int x) {
	return y >= 0 && x >= 0 && y < row && x < col;
}

// 현재 맵을 복사
void copyMap() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j][1] = map[i][j][0];
		}
	}
}

// 벽돌을 떨어트린 뒤 맵의 정보를 업데이트
void updateMap() {
	queue<int> q;
    
    // 각 열 마다 세로 방향으로 탐색을 하며 남은 벽돌이 1이상일 경우 큐에 저장
	for (int i = 0; i < col; i++) {
		for (int j = row - 1; j >= 0; j--) {
			if (map[j][i][1] > 0) {
				q.push(map[j][i][1]);
				map[j][i][1] = 0;
			}
		}
        
        // 바닥에서부터 벽돌 채우기
		int idx = row - 1;
		while (!q.empty()) {
			map[idx--][i][1] = q.front();
            q.pop();
		}
	}
}

void BFS(int y, int x) {
	queue<Point> q;
	q.push( {y, x, map[y][x][1]} );

	map[y][x][1] = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Point node = q.front();
			q.pop();
			int y = node.y;
			int x = node.x;
			int bricks = node.bricks;
			
            // 벽돌의 폭발 범위
			for (int i = 0; i < bricks; i++) {
				for (int j = 0; j < 4; j++) {
					int ny = y + direction[0][j] * i;
					int nx = x + direction[1][j] * i;
					
                    // 폭발 범위 안에 있는 벽돌이 1이상이라면 큐에 저장
					if (isBoundary(ny, nx)) {
						if (map[ny][nx][1] > 0) {
							q.push({ ny, nx, map[ny][nx][1] });
							map[ny][nx][1] = 0;
						}
					}
				}
			}
		}
	}
}

// 중복순열으로 n개 구슬의 열 위치를 구한 뒤 벽돌 깨기를 진행
void solve(int x) {
	if (x >= n) {
		copyMap();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < row; j++) {
				if (map[j][sequence[i]][1] > 0) {
					BFS(j, sequence[i]);
					updateMap();
					break;
				}
			}
		}
        
        // 남은 벽돌의 수를 계산
		int num_left = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j][1] > 0)
                    num_left++;
            }
        }
        
        // 가장 적게 남은 벽돌의 수를 저장
        if (bricks_left > num_left)
			bricks_left = num_left;
	}
	else {
        // 중복순열
		for (int i = 0; i < col; i++) {
			sequence[x] = i;
			solve(x + 1);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &n, &col, &row);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				scanf("%d", &map[i][j][0]);
			}
		}

		solve(0);

		printf("#%d %d\n", tc, bricks_left);
		bricks_left = INT_MAX;
	}
	return 0;
}