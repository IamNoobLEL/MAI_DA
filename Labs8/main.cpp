#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool greedyTopologicalSort(int N, vector<vector<int>>& adj, vector<int>& result) {
    vector<int> in_degree(N + 1, 0);
    set<int> zero_in_degree;

    for (int i = 1; i <= N; ++i) {
        for (int j : adj[i]) {
            in_degree[j]++;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            zero_in_degree.insert(i);
        }
    }

    while (!zero_in_degree.empty()) {
        int u = *zero_in_degree.begin();
        zero_in_degree.erase(zero_in_degree.begin());
        result.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                zero_in_degree.insert(v);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] != 0) return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> result;
    if (greedyTopologicalSort(N, adj, result)) {
        for (int i = 0; i < result.size() - 1; ++i) {
            cout << result[i] << " " << result[i + 1] << endl;
        }
    } else {
        cout << "-1";
    }

    return 0;
}
