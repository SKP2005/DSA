#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
        q.push({0,-1});
        while(!q.empty()){
            int u=q.front().first;
            int p=q.front().second;
            q.pop();
            if(vis[u]) return true;
            vis[u]=1;
            for(auto nei:adj[u]){
                if(nei!=p){
                    q.push({nei,u});
                }
            }
        }
        return false;
    }
};