#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<long long> Vecllanswer;
    for(int index = 0; index < n; index++){
        if(Vecllanswer.size() < 3)
            Vecllanswer.push_back(index + 1);
        else
            Vecllanswer.push_back((Vecllanswer[index - 1] % 1234567) + (Vecllanswer[index - 2] % 1234567));
    }
    
    answer = Vecllanswer.back() % 1234567;
    
    return answer;
}