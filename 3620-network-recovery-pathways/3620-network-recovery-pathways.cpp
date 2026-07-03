class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            maxCost = max(maxCost, e[2]);
        }

        // Topological Sort
        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {

            const long long INF = 4e18;
            vector<long long> dp(n, INF);
            dp[0] = 0;

            for (int u : topo) {

                if (dp[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : graph[u]) {

                    if (w < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    dp[v] = min(dp[v], dp[u] + w);
                }
            }

            return dp[n - 1] <= k;
        };

        int low = 0;
        int high = maxCost;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};