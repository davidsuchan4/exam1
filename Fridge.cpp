#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string nums = to_string(n);

    sort(nums.begin(), nums.end());
    int idx{};
    int curNum = 1;
    for(int i{}; i < nums.size(); ++i){
        if(curNum < nums[idx] - '0'){
            cout << curNum;
            return 0;
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
            ++curNum;
        }
    }
    return 0;
}