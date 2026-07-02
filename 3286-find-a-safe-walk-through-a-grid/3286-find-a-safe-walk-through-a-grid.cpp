class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        queue<tuple<int,int,int>> q;

        q.push({0,0,startHealth});

        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n,
            vector<bool>(health+1,false))
        );

        vis[0][0][startHealth]=true;

        while(!q.empty()){

            auto [x,y,h]=q.front();
            q.pop();

            if(x==m-1 && y==n-1)
                return true;

            for(auto d:dir){

                int nx=x+d.first;
                int ny=y+d.second;

                if(nx<0||ny<0||nx>=m||ny>=n)
                    continue;

                int nh=h-grid[nx][ny];

                if(nh<=0)
                    continue;

                if(vis[nx][ny][nh])
                    continue;

                vis[nx][ny][nh]=true;
                q.push({nx,ny,nh});
            }
        }

        return false;
    }
};