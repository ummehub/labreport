#include <bits/stdc++.h>
    using namespace std;

    const long long INF = 1e18;
    vector<pair<int,long long>> g[5005];
    long long dist1_[5005], dist2_[5005];

    int main() {

        int T;
        cin >> T;
        for (int tc = 1; tc <= T; tc++) {
            int N, R;
            cin >> N >> R;

            for (int i = 1; i <= N; i++) {
                g[i].clear();
                dist1_[i] = INF;
                dist2_[i] = INF;
            }

            for (int i = 0; i < R; i++) {
                int u, v;
                long long w;
                cin >> u >> v >> w;
                g[u].push_back({v, w});
                g[v].push_back({u, w});
            }

            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            dist1_[1] = 0;
            pq.push({0, 1});

            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();

                long long d = p.first;
                int u = p.second;

                if (d > dist2_[u]) continue;

                for (auto edge : g[u]) {
                    int v = edge.first;
                    long long w = edge.second;
                    long long nd = d + w;

                    if (nd < dist1_[v]) {
                        dist2_[v] = dist1_[v];
                        dist1_[v] = nd;
                        pq.push({nd, v});
                    }
                    else if (nd > dist1_[v] && nd < dist2_[v]) {
                        dist2_[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }

            cout << "Case " << tc << ": " << dist2_[N] << "\n";
        }
        return 0;
    }