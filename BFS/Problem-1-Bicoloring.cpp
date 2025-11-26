#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int l;
        cin >> l;

        vector<vector<int>> graph(n);

        while (l--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(n, -1);
        queue<int> q;
        bool ok = true;

        color[0] = 0;
        q.push(0);

        while (!q.empty() && ok) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
