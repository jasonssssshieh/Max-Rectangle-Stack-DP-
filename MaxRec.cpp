
//
//  main.cpp
//  Maximal Rectangle(Stack)
//
//  Created by Zijian Xie on 2016/11/9.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class MaxRec{
private:
    vector<vector<int>> nums;
public:
    MaxRec(vector<vector<int>>& num){
        nums = num;
    }
    int MaxArea(vector<int> nums){
        nums.push_back(0);//control the end!
        stack<int> s;
        int res = -1;
        for(int i = 0; i < nums.size();){
            if(s.empty() || nums[s.top()] < nums[i]){
                s.push(i++);
            }else{
                int j = s.top();
                s.pop();
                res = max(res, nums[j] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        cout<<"Current Largest area is "<< res<<". "<<endl;
        return res;
    }
    
    int MaxR(){
        if(nums.empty()) return 0;
        int m = (int)nums.size(), n = (int)nums[0].size();
        vector<int> dp(n,0);
        int res = -1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dp[j] = nums[i][j] == 0 ? 0 : dp[j] + nums[i][j];
            }
            res = max(res, MaxArea(dp));
        }
        cout<<"Largest size rectangle is "<< res<<". "<<endl;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> num = {{1,0,0,1,1,1},{1,0,1,1,0,1},{0,1,1,1,1,1},{0,0,1,1,1,1}};
    MaxRec* test = new MaxRec(num);
    test->MaxR();
    return 0;
}

/*
 class MaxArea{
 private:
 vector<int> nums;
 stack<int> s;
 public:
 MaxArea(vector<int>& num){
 nums = num;
 }
 
 int MaxA(){
 int res = -1;
 for(int i = 0; i < nums.size();){
 if(s.empty() || nums[s.top()] < nums[i]){
 s.push(i++);
 }else{
 int j = s.top();
 s.pop();
 res = max(res, nums[j] * (s.empty() ? i : i - s.top() - 1));
 }
 }
 cout<<"Largest area is "<< res<<". "<<endl;
 return res;
 }
 };
 
 int main(int argc, const char * argv[]) {
 vector<int> num = {4,5,6,7,0,3,2,5,2,1,5,6,8};
 MaxArea* test = new MaxArea(num);
 test->MaxA();
 return 0;
 }
 */
