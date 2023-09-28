#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // converting the adjacency matrix to an adjacency list
        int n = isConnected[0].size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt=0;
        vector<int> vis(n, 0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
        
    }
};
// @lc code=end

