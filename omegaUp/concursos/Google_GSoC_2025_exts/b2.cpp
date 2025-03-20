#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


bool isTree(const vector<pair<int, int>>& edges) {
    if (edges.empty()) return true;

    unordered_set<int> nodes; 
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> adjList;

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        nodes.insert(u);
        nodes.insert(v);
        indegree[v]++; 
        adjList[u].push_back(v);
    }

    vector<int> rootCandidates;
    for (int node : nodes) {
        if (indegree[node] == 0) {
            rootCandidates.push_back(node);
        }
    }

    if (rootCandidates.size() != 1) {
        return false;
    }

    int root = rootCandidates[0];

    for (int node : nodes) {
        if (node != root && indegree[node] != 1) {
            return false;
        }
    }

    unordered_set<int> visited;
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (visited.count(node)) {
            return false;
        }

        visited.insert(node);

        for (int neighbor : adjList[node]) {
            q.push(neighbor);
        }
    }

    return visited.size() == nodes.size();
}

int main() {
    int caseNumber = 1;

    while (true) {
        vector<pair<int, int>> edges;
        int u, v;

        while (cin >> u >> v) {
            if (u == 0 && v == 0) {
                break;
            }
            if (u == -1 && v == -1) {
                return 0;
            }
            edges.push_back({u, v});
        }

        if (isTree(edges)) {
            cout << "Case " << caseNumber << " is a tree." << endl;
        } else {
            cout << "Case " << caseNumber << " is not a tree." << endl;
        }

        caseNumber++;
    }

    return 0;
}