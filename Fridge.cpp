#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string nums = to_string(n);

    sort(nums.begin(), nums.end());
    int curNum = 1;
    for(int i{}; i < nums.size(); ++i){
        if(curNum < nums[i] - '0'){
            cout << curNum;
            return 0;
        }
        int cur = nums[i];
        int idx = i + 1;
        while(nums[idx] == cur){
            ++idx;
        }
        ++curNum;
    }
    for(int i{0}; i < nums.size(); ++i){
        string preFix{};
        for(int k{}; k <= i; ++k){
            preFix += nums[k];
        }
        for(int j{i + 1}; j < nums.size(); ++j){
            if(stoi(preFix + nums[j]) > curNum){
                cout << curNum;
                return 0;
            }
                    int cur = nums[i];
        int idx = j + 1;
        while(nums[idx] == cur){
            ++idx;
        }
            ++curNum;
        }
    }
    return 0;
}