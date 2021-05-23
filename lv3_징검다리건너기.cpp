#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckPossible(vector<int> stones, int nMiddle, int k){
    int nCount = 0;
    for(int index = 0; index < stones.size(); index++){
        if(stones[index] - nMiddle <= 0)
            nCount++;
        else
            nCount = 0;
        
        if(nCount >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int nFront = 1;
    int nBack = *max_element(stones.begin(), stones.end());
    
    while(nFront <= nBack){
        int nMiddle = (nFront + nBack) / 2;
        if(CheckPossible(stones, nMiddle, k))
            nBack = nMiddle - 1;
        else
            nFront = nMiddle + 1;
    }
    answer = nFront;
    return answer;
}