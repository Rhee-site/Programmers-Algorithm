#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int nSrc, int nDst, int nTurm, vector<vector<int>> &answer){
    vector<int> VecnTemp;
    VecnTemp.push_back(nSrc);
    VecnTemp.push_back(nDst);
    
    if(n == 1)
        answer.push_back(VecnTemp);
    else{
        hanoi(n - 1, nSrc, nTurm, nDst, answer);
        answer.push_back(VecnTemp);
        hanoi(n - 1, nTurm, nDst, nSrc, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, 2, answer);
    
    return answer;
}