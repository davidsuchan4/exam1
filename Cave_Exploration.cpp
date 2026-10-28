#include <bits/stdc++.h>
using namespace std;

long long dfs(long long r, long long c, long long n, long long time, vector<vector<long long>>& dirs, vector<vector<long long>> graph){
    if(r >= n || r < 0 || c >= n || c < 0){
        return INT_MAX;
    }
    if(r == n - 1 && c == n - 1){
        return time;
    }

    long long minimum = INT_MAX;

    for(long long i{}; i < 4; ++i){
        long long newR = r + dirs[i][0];
        long long newC = c + dirs[i][1];
        if(newR >= 0 && newR < n && newC >= 0 && newC < n){
            if(graph[newR][newC] == INT_MAX){
                continue;
            }
            long long newTime{};
            if(graph[newR][newC] > time){
                newTime = graph[newR][newC];
            }
            else{
                newTime = time;
            }
            vector<vector<long long>> tempG = graph;
            tempG[newR][newC] = INT_MAX;
            minimum = min(minimum, dfs(newR, newC, n, newTime, dirs, tempG));
            
            
        }
    }
    return minimum;

}

int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> graph;
    for(long long j{}; j < n; ++j){
        vector<long long> test;
        for(long long i{};  i < n; ++i){
            long long temp;
            cin >> temp;
            test.push_back(temp);
        }
        graph.push_back(test);
    }

    vector<vector<long long>> dirs = {
        {1, 0}, {0,1}, {-1,0}, {0, -1}
    };

    cout << dfs(0, 0, n, 1, dirs, graph);

    return 0;
}