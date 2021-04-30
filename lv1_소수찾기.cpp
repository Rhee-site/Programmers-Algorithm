#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> VecnNumbers;
    for(int index = 0; index <= n; index++)
        VecnNumbers.push_back(true);
    
    for(int index = 2; index * index <= n; index++)
        if(VecnNumbers[index])
            for(int i = index * index; i <= n; i += index)
                VecnNumbers[i] = false;
    
    for(int index = 0; index < VecnNumbers.size(); index++)
        if(VecnNumbers[index])
            answer++;
    
    return answer - 2;
}