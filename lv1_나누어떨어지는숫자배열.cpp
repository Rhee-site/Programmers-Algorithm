#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int index = 0; index < arr.size(); index++)
        if(!(arr[index] % divisor))
            answer.push_back(arr[index]);
        
    if(!answer.size())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}