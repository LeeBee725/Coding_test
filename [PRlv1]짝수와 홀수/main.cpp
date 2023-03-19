#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if (num % 2 == 0) answer = "Even";
    else answer = "Odd";
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(3) << "\n";
    cout << solution(4) << "\n";
    return 0;
}