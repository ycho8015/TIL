#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

typedef struct vNode_ {
    int src;
    int dest;
    int cost;
}vNode;

bool comp(vNode a, vNode b) {
    return a.cost < b.cost;
}

int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b); 

    if (a == b) return 1;
    return 0;
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vNode> graph;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph.push_back( {a, b, c} );
    }

    sort(graph.begin(), graph.end(), comp);

    int parent[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (!findParent(parent, graph[i].src, graph[i].dest)) {
            unionParent(parent, graph[i].src, graph[i].dest);
            sum += graph[i].cost;
        }
    }

    printf("%d", sum);
    return 0;
}