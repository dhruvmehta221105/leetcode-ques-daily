class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> graph(n + 1);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        vector<bool> vis(n + 1, false);

        queue<int> q;
        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &[next, weight] : graph[node]){

                ans = min(ans, weight);

                if(!vis[next]){
                    vis[next] = true;
                    q.push(next);
                }
            }
        }

        return ans;
    }
};