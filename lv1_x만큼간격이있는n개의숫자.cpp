#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    answer.push_back(x);
    for(int index = 1; index < n; index++)
        answer.push_back(answer.back() + x);
    
    return answer;
}