#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;

const int MAX = 10000;
vector<int> graph[MAX];
vector<int> cost[MAX];
int visited[MAX];
int dist[MAX];
int n, m, src, dest; 

int main() {
    scanf("%d %d", &n, &m);

    int v, w, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v, &w, %c);
        graph[v].push_back(w);
        graph[w].push_back(v);
        cost[v].push_back(c);
        cost[w].push_back(c);

    }

    scanf("%d %d", &src, &dest);
    
    for (int i = 0; i < n; i++) 
        dist[i] = INT_MAX;
    
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX, min_idx = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_idx = j;
            }
        }

        visited[min_idx] = 1;

        for (int j = 0; j < graph[min_idx].size(); j++) {
            int next_node = graph[min_idx][j];
            int next_cost = cost[min_idx][j];

            if (dist[next_node] > next_cost + 1) 
                dist[next_node] = next_cost + 1;
        }
    }

    printf("%d", dist[dest]);
    return 0;
}