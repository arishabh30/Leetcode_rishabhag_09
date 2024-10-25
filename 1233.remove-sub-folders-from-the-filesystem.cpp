#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
private:
    // using set --- (O(N*L^2))
    void usingSet(vector<string>& folder, vector<string>& res){

        unordered_set<string> s(folder.begin(), folder.end());

        for(int i=0;i<folder.size();i++){
            bool flag = false;
            string curr = folder[i];

            while(!curr.empty()){
                int last_idx = curr.find_last_of('/');
                if(last_idx == string::npos) break;

                curr = curr.substr(0, last_idx);

                if(s.count(curr)){
                    flag = true;
                    break;
                }
            }

            if(!flag) res.push_back(folder[i]);
        }
    }

    // using sorting ---- (O(N.LlogN))
    void usingSorting(vector<string>&folder, vector<string>&res){
        sort(folder.begin(), folder.end());
        res.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string last = res.back();
            last+='/';


            if(folder[i].compare(0, last.size(), last)!=0){
                res.push_back(folder[i]);
            }
        }
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {


        vector<string> res;
        // using set
        // usingSet(folder, res);

        // using sorting and comparing
        usingSorting(folder, res);
        return res;
    }

    
};
// @lc code=end

