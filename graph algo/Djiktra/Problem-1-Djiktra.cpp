#include <bits/stdc++.h>
    using namespace std;

    const long long INF = 1e18;
    vector<pair<int,long long>> graph_[200005];
    long long dist_[200005];
    int parent_[200005];

    int main() {

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            long long w;
            cin >> a >> b >> w;
            graph_[a].push_back({b, w});
            graph_[b].push_back({a, w});
        }

        for (int i = 1; i <= n; i++) {
            dist_[i] = INF;
            parent_[i] = -1;
        }

        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist_[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            long long d = p.first;
            int u = p.second;

            if (d > dist_[u]) continue;

            for (auto edge : graph_[u]) {
                int v = edge.first;
                long long w = edge.second;

                if (dist_[u] + w < dist_[v]) {
                    dist_[v] = dist_[u] + w;
                    parent_[v] = u;
                    pq.push({dist_[v], v});
                }
            }
        }

        if (dist_[n] == INF) {
            cout << -1;
            return 0;
        }

        vector<int> path;
        int cur = n;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent_[cur];
        }

        reverse(path.begin(), path.end());

        for (int x : path) cout << x << " ";
        return 0;
    }