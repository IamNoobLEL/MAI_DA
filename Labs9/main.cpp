#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int v, vector<bool> &visited, vector<int> &component, const vector<vector<int>> &graph) {
    visited[v] = true;
    component.push_back(v);
    for (int u : graph[v]) {
        if (!visited[u]) {
            DFS(u, visited, component, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            DFS(i, visited, component, graph);
            sort(component.begin(), component.end());
            for (int v : component) {
                cout << v + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
