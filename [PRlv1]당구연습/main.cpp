#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int distanceSquare(vector<int> p1, vector<int> p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (auto point : balls) {
        vector<vector<int>> moved = {
            {-startX, startY},
            {m + (m-startX), startY},
            {startX, -startY},
            {startX, n + (n-startY)}
        };
        vector<int> cand;
        for (auto move: moved) {
            if (startY == point[1] && \
                ((move[0] < point[0] && point[0] < startX) || (startX < point[0] && point[0] < move[0])) ||
                startX == point[0] && \
                ((move[1] < point[1] && point[1] < startY) || (startY < point[1] && point[1] < move[1]))
                )
                continue;
            cand.push_back(distanceSquare(move, point));
        }
        answer.push_back(*min_element(cand.begin(), cand.end()));
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> res = solution(10, 10, 3, 7, {{7, 7}, {2, 7}, {7, 3}});
    for(auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}