#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int Outter = 0; Outter < prices.size(); Outter++){
        int nTurm = 0;
        for(int Inner = Outter + 1; Inner < prices.size(); Inner++){
            if(prices[Outter] <= prices[Inner]){
                nTurm++;   
            }
            else{
                nTurm++;
                break;
            }
        }
        answer.push_back(nTurm);
    }
    
    return answer;
}