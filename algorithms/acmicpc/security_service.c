#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;

struct Point {
	int y;
	int x;
};

vector<Point> v;
int n, m;

int abs(int x) {
	return x > 0 ? x : (-1) * x;
}

int manhattan(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}
int solve() {
	int result = INT_MIN;
	int total_house = 0;
	int coverage = manhattan(0, 0, n - 1, n - 1) + 1;
	
	for (int k = 1; k <=coverage; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = k * k + (k - 1) * (k - 1);
				sum *= -1;
				int cnt = 0;
				for (int node = 0; node < v.size(); node++) {
					int y = v[node].y;
					int x = v[node].x;
					if (manhattan(i, j, y, x) < k) {
						sum += m;
						cnt++;
					}
				}
				if (sum >= 0 && total_house < cnt)
					total_house = cnt;
			}
		}
	}
	return total_house;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int num;
				scanf("%d", &num);
				if (num > 0)
					v.push_back({ i, j });
			}
		}

		int result = solve();
		printf("#%d %d\n", tc, result);
		v.clear();
	}
	return 0;
}

