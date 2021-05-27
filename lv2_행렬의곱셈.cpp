#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int nSrcRowCount = arr1.size();
    int nSrcColCount = arr1.front().size();
    int nDstColCount = arr2.front().size();
    
    for(int index = 0; index < nSrcRowCount; index++){
        vector<int> VecnTemp;
        answer.push_back(VecnTemp);
    }
    
    for(int SrcRow = 0; SrcRow < nSrcRowCount; SrcRow++){
        for(int DstCol = 0; DstCol < nDstColCount; DstCol++){
            int nSum = 0;
            for(int SrcCol = 0; SrcCol < nSrcColCount; SrcCol++)
                nSum += arr1[SrcRow][SrcCol] * arr2[SrcCol][DstCol];
            answer[SrcRow].push_back(nSum);
        }
    }
    
    return answer;
}