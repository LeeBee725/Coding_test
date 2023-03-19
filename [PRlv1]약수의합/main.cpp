#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> divisor;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            answer += i;
            if (i != n / i)
                answer += n / i;
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(0) << "\n";
    cout << solution(12) << "\n";
    cout << solution(5) << "\n";
    cout << solution(25) << "\n";
    return 0;
}