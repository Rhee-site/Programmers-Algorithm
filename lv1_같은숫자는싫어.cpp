#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int nTargetNumber = arr.front();
    answer.push_back(nTargetNumber);
    for(int index = 1; index < arr.size(); index++){
        if(nTargetNumber != arr[index]){
            nTargetNumber = arr[index];
            answer.push_back(nTargetNumber);
        }
    }
    
    return answer;
}