 #include <bits/stdc++.h>
    using namespace std;

    const int INF = 1e9;

    struct Edge {
        int u, v;
        long long w;
    };

    int main() {

        int n;
        int tc = 1;

        while (cin >> n) {
            vector<int> busy(n + 1);
            for (int i = 1; i <= n; i++) cin >> busy[i];

            int r;
            cin >> r;

            vector<Edge> edges;
            while (r--) {
                int u, v;
                cin >> u >> v;
                long long w = busy[v] - busy[u];
                w = w * w * w;
                edges.push_back({u, v, w});
            }

            vector<long long> dist(n + 1, INF);
            dist[1] = 0;

            for (int i = 1; i < n; i++) {
                for (auto &e : edges) {
                    if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                        dist[e.v] = dist[e.u] + e.w;
                    }
                }
            }

            vector<int> bad(n + 1, 0);

            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    bad[e.v] = 1;
                }
            }

            queue<int> q;
            for (int i = 1; i <= n; i++) {
                if (bad[i]) q.push(i);
            }

            vector<vector<int>> adj(n + 1);
            for (auto &e : edges) adj[e.u].push_back(e.v);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!bad[v]) {
                        bad[v] = 1;
                        q.push(v);
                    }
                }
            }

            int qn;
            cin >> qn;

            cout << "Set #" << tc++ << "\n";
            while (qn--) {
                int x;
                cin >> x;
                if (dist[x] == INF || dist[x] < 3 || bad[x]) cout << "?\n";
                else cout << dist[x] << "\n";
            }
        }

        return 0;
    }