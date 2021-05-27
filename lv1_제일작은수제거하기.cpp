#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int nTargetNumber = *min_element(arr.begin(), arr.end());
    for(vector<int>::iterator iter = arr.begin(); iter != arr.end();){
        if(*iter == nTargetNumber){
            iter = arr.erase(iter);
        }
        else{
            answer.push_back(*iter);
            iter++;   
        }
    }
    
    if(!answer.size())
        answer.push_back(-1);
        
    return answer;
}