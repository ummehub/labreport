 #include <bits/stdc++.h>
    using namespace std;

    const int INF = 1e9;

    struct Edge {
        int u, v, w;
    };

    int main() {

        int T;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;

            vector<Edge> edges(m);
            for (int i = 0; i < m; i++) {
                cin >> edges[i].u >> edges[i].v >> edges[i].w;
            }

            vector<int> dist(n, INF);
            dist[0] = 0;

            for (int i = 1; i < n; i++) {
                for (auto &e : edges) {
                    if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                        dist[e.v] = dist[e.u] + e.w;
                    }
                }
            }

            bool neg = false;
            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    neg = true;
                    break;
                }
            }

            cout << (neg ? "possible" : "not possible") << "\n";
        }

        return 0;
    }