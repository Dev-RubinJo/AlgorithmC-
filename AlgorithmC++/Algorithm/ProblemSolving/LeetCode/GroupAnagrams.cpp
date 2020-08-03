//
//  GroupAnagrams.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/03.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> check;
        string str;
        for(int i = 0; i < strs.size(); i++) {
            int flag = 0;
            str = strs[i];
            sort(str.begin(), str.end());
            for(int j = 0; j < check.size(); j++) {
                if(check[j] == str) {
                    ans[j].push_back(strs[i]);
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                check.push_back(str);
                vector<string> temp = {strs[i]};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<string> temp = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.groupAnagrams(temp);

    
    
    return 0;
}
