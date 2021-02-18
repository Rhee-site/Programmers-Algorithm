#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int index = 0; index < commands.size(); index++){
        int nStartIndex = commands[index][0] - 1;
        int nEndIndex = commands[index][1];
        int nTargetIndex = commands[index][2] - 1;
        
        vector<int> VecnTemp;
        VecnTemp.assign(array.begin() + nStartIndex, array.begin() + nEndIndex);
        
        sort(VecnTemp.begin(), VecnTemp.end());
        answer.push_back(VecnTemp[nTargetIndex]);
    }
    
    return answer;
}