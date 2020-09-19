#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

void BFS(vector <int> graph[], bool visited[], int v) {
    queue <int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int size = (int)q.size();
        while (size--) {
            int v = q.front();
            q.pop();
            printf("%d ", v);
            for (int i = 0 ; i < graph[v].size(); i++) {
                int w = graph[v][i];
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector <int> graph[MAX];

    int v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v, &w);
        graph[v].push_back(w);
        graph[w].push_back(v);
    } 

    bool visited[MAX] = {false};
    BFS(graph, visited, 0);

    return 0;
}