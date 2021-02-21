#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int index = 0; index < skill_trees.size(); index++){
        string strTarget = skill_trees[index];
        
        string strResult;
        int nLastOrder = 0;
        bool bOrderCheck = true;
        
        for(int Src = 0; Src < skill.size(); Src++){
            for(int Dst = nLastOrder; Dst < strTarget.size(); Dst++){
                if(skill.at(Src) == strTarget.at(Dst)){
                    nLastOrder = Dst;
                    strResult += strTarget.at(Dst);
                    break;
                }
                else{
                    if(Src != skill.size() - 1){
                        for(int a = Src; a < skill.size(); a++){
                            if(skill.at(a) == strTarget.at(Dst)) {
                                bOrderCheck = false;
                                break;
                            }
                        }
                    }
                }
                
                if(!bOrderCheck)
                    break;
            }        
        }
        
        if(bOrderCheck){
            bool bCheck = true;
            for(int Test = 0; Test < strResult.size(); Test++){
                if(strResult.at(Test) != skill.at(Test)){
                    bCheck = false;
                    break;   
                }
            }      
        
            if(bCheck)
                answer++;
        }
    }
    
    return answer;
}