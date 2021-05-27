#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int index = 1; index <= n; index++){
        if(n % index == 0)
            answer += index;
    }
    
    return answer;
}