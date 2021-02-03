#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> VecResult;

    for(int nActive = 0; nActive < moves.size(); nActive++){
        for(int nBag = 0; nBag < board.size(); nBag++){
            if(board[nBag][moves[nActive] - 1]){
                VecResult.push_back(board[nBag][moves[nActive] - 1]);   
                board[nBag][moves[nActive] - 1] = 0;
                break;
            }
        }

        if(VecResult.size() > 1){
            int nCount = VecResult.size();
            if(VecResult[nCount - 1] == VecResult[nCount - 2]){
                VecResult.pop_back();
                VecResult.pop_back();
                answer += 2;
            }
        }
    }

    return answer;
}