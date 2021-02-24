#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    sort(nums.begin(), nums.end());
    
    string strBitMask(3, 1);
    strBitMask.resize(nums.size(), 0);
    
    vector<int> VecnResult;
    
    do{
        int nSum = 0;
        for(int index = 0; index < nums.size(); index++)
            if(strBitMask[index])
                nSum += nums[index];
        VecnResult.push_back(nSum);
    }while(prev_permutation(strBitMask.begin(), strBitMask.end()));
    
    for(int index = 0; index < VecnResult.size(); index++){
        bool bCheck = true;
        for(int i = 2; i <= VecnResult[index] / 2; i++){
            if(VecnResult[index] % i == 0){
                bCheck = false;
                break;
            }
        }
        
        if(bCheck)
            answer++;
    }
    
    return answer;
}