#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    int nFront = 0;
    int nBack = distance;
    
    while(nFront <= nBack){
        int nMiddle = (nFront + nBack) / 2;
        int nDeleteIndex = -1;
        int nDeleteCount = 0;
        
        for(int index = 0; index <= rocks.size(); index++){
            int nDistance = 0;
            if(index == 0){
                nDistance = rocks[index];
            }
            else{
                if(index == rocks.size()){
                    nDistance = distance - rocks[rocks.size() - 1];
                }
                else{
                    nDistance = rocks[index] - rocks[nDeleteIndex];
                }
            }
            
            if(nDistance < nMiddle)
                nDeleteCount++;
            else
                nDeleteIndex = index;
        }
        
        if(nDeleteCount > n){
            nBack = nMiddle - 1;
        }
        else if(nDeleteCount <= n){
            nFront = nMiddle + 1;
            answer = max(answer, nMiddle);
        }
    }
    
    return answer;
}