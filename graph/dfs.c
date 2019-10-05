#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100;

void DFS(vector <int> graph[], bool visited[], int v) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];
        if (!visited[w])
            DFS(graph, visited, w);
    }
}
int main() {
    int n , m;
    scanf("%d %d", &n, &m);

    vector <int> graph[MAX];

    int v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v, &w);
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    bool visited[MAX] = {false};
    DFS(graph, visited, 0);

    return 0;
}