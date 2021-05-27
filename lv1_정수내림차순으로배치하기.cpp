#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string strNumber = to_string(n);
    sort(strNumber.begin(), strNumber.end(), greater<int>());
    answer = stoll(strNumber);
    
    return answer;
}