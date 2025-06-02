#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool detectCycle(int u,int p,int V,vector<int> &adj[],vector<int>&vis){
        vis[u]=1;
        for(auto it:adj[u]){
            if(!vis[it]){
                if(detectCycle(it,u,V,adj,vis)) return true;
            } 
            else if(it!=p){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(detectCycle(i,-1,V,adj,vis)) return true;
        }
        return false;
    }
};