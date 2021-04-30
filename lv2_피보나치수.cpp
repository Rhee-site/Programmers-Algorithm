#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> VecnNumbers(n + 1);
    VecnNumbers[0] = 0;
    VecnNumbers[1] = 1;
    for(int index = 2; index <= n; index++)
        VecnNumbers[index] = (VecnNumbers[index - 1] + VecnNumbers[index - 2]) % 1234567;
    answer = VecnNumbers[n];
    
    return answer;
}