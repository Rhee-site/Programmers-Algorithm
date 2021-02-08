#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef struct{
    int nLocationX = 0;
    int nLocationY = 0;
    int ndirection = 0;
}Position;

int solution(string dirs) {
    int answer = 0;
    
    Position CurrentLocation;
    Position ReverseLocation;
    vector<Position> VecPosition;
    
    for(int index = 0; index < dirs.size(); index++){
        char strTemp = dirs.at(index);
        bool bCheck = false;
        if(strTemp == 'U'){
            if(CurrentLocation.nLocationY < 5){
                CurrentLocation.nLocationY++;
                CurrentLocation.ndirection = 1;
                
                ReverseLocation.nLocationX = CurrentLocation.nLocationX;
                ReverseLocation.nLocationY = CurrentLocation.nLocationY - 1;
                ReverseLocation.ndirection = 2;
                
                bCheck = true;
            }
        }
        else if(strTemp == 'D'){
            if(CurrentLocation.nLocationY > -5){
                CurrentLocation.nLocationY--;
                CurrentLocation.ndirection = 2;
                
                ReverseLocation.nLocationX = CurrentLocation.nLocationX;
                ReverseLocation.nLocationY = CurrentLocation.nLocationY + 1;
                ReverseLocation.ndirection = 1;
                
                bCheck = true;
            }
        }
        else if(strTemp == 'R'){
            if(CurrentLocation.nLocationX < 5){
                CurrentLocation.nLocationX++;
                CurrentLocation.ndirection = 3;
                
                ReverseLocation.nLocationX = CurrentLocation.nLocationX - 1;
                ReverseLocation.nLocationY = CurrentLocation.nLocationY;
                ReverseLocation.ndirection = 4;
                
                bCheck = true;
            }
        }
        else if(strTemp == 'L'){
            if(CurrentLocation.nLocationX > -5){
                CurrentLocation.nLocationX--;
                CurrentLocation.ndirection = 4;
                
                ReverseLocation.nLocationX = CurrentLocation.nLocationX + 1;
                ReverseLocation.nLocationY = CurrentLocation.nLocationY;
                ReverseLocation.ndirection = 3;
                
                bCheck = true;
            }
        }
        
        if(bCheck){
            bool bOverLapCheck =false;
            for(int Inner = 0; Inner < VecPosition.size(); Inner++){
                if(CurrentLocation.nLocationX == VecPosition[Inner].nLocationX){
                    if(CurrentLocation.nLocationY == VecPosition[Inner].nLocationY){
                        if(CurrentLocation.ndirection == VecPosition[Inner].ndirection){
                            bOverLapCheck = true;
                            break;
                        }
                    }
                }
            }
            
            if(!bOverLapCheck){
                answer++;
                VecPosition.push_back(CurrentLocation);
                VecPosition.push_back(ReverseLocation);
            }
        }
    }
    
    return answer;
}