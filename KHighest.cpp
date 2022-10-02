class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>&grid)
    {
        if (i<0 || j<0 || i==grid.size()|| j==grid[0].size()|| grid[i][j]==0) return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<int>>&grid,vector<int>&price,vector<vector<int>>&store)
    {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),false));
        q.push({{i,j},0});
        vis[i][j]=true;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int i=p.first.first,j=p.first.second,dist=p.second;
            if (grid[i][j]>=price[0] && grid[i][j]<=price[1])
            {
               vector<int>v;
                v.push_back(dist);
                v.push_back(grid[i][j]);
                v.push_back(i);
                v.push_back(j);
                store.push_back(v);
            }
            if (isValid(i+1,j,grid)&& !vis[i+1][j])
                q.push({{i+1,j},dist+1}),vis[i+1][j]=true;
             if (isValid(i,j+1,grid)&& !vis[i][j+1])
                q.push({{i,j+1},dist+1}),vis[i][j+1]=true;
             if (isValid(i-1,j,grid)&& !vis[i-1][j])
                q.push({{i-1,j},dist+1}),vis[i-1][j]=true;
             if (isValid(i,j-1,grid)&& !vis[i][j-1])
                q.push({{i,j-1},dist+1}),vis[i][j-1]=true;
        }
        
        
    }
    
    
   vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)     
    {
        vector<vector<int>>store;
        bfs(start[0],start[1],grid,pricing,store);
        sort(store.begin(),store.end());
       int run=store.size()<k?store.size():k;
       vector<vector<int>>ans(run);
       for (int i=0;i<run;i++)
       {
           ans[i].push_back(store[i][2]);
           ans[i].push_back(store[i][3]);
       }
       return ans;
    }
};
