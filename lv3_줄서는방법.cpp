#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long factorial(int n){
    if(n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;    
  
    vector<int> VecnNumbers;
    for(int index = 1; index < n + 1; index++)
        VecnNumbers.push_back(index);
    
    while(n != 0){
        long long nTurm = factorial(n) / n;
        long long nTargetIndex = (k - 1) / nTurm;
        answer.push_back(VecnNumbers[nTargetIndex]);
        VecnNumbers.erase(VecnNumbers.begin() + nTargetIndex);
        n--;
        k %= nTurm;
        if(k == 0)
            k = nTurm;
    }
    
    return answer;
}