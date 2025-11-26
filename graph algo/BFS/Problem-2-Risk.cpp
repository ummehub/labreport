#include <bits/stdc++.h>
using namespace std;

int main() {
int test = 1;

    while (true) {
        vector<vector<int>> graph(21);

        for (int i = 1; i < 20; i++) {
            int x;
            if (!(cin >> x)) return 0;
            for (int j = 0; j < x; j++) {
                int v;
                cin >> v;
                graph[i].push_back(v);
                graph[v].push_back(i);
            }
        }

        int N;
        cin >> N;

        cout << "Test Set #" << test++ << "\n";

        while (N--) {
            int A, B;
            cin >> A >> B;

            vector<int> dist(21, -1);
            queue<int> q;

            dist[A] = 0;
            q.push(A);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << setw(2) << A << " to " << setw(2) << B
                 << ": " << dist[B] << "\n";
        }

        cout << "\n";
    }
}
