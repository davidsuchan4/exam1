#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string numbers = to_string(n);
    vector<int> nums;
    for(int i{}; i < n; ++i){
        nums.push_back(nums[i]);
    }
    sort(nums.begin(), nums.end());
    

}