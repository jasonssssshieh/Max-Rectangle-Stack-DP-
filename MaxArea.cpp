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

class MaxArea{
private:
    vector<int> nums;
    stack<int> s;
public:
    MaxArea(vector<int>& num){
        nums = num;
    }
    
    int MaxA(){
        nums.push_back(0);
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
