#include <bits/stdc++.h>
using namespace std;

int main() {
    string nums;
    cin >> nums;
    vector<int> count(10, 0);
    for (int i{}; i < nums.size(); ++i) {
        ++count[nums[i] - '0'];
    }

    string answer = "1" + string(count[0] + 1, '0');

    for (int digit = 1; digit <= 9; ++digit) {
        string candidate(count[digit] + 1, char('0' + digit));

        if (candidate.size() < answer.size() ||
            (candidate.size() == answer.size() && candidate < answer)) {
            answer = candidate;
        }
    }

    cout << answer;
    return 0;
}