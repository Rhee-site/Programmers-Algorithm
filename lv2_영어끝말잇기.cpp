#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckFirstWord(string StrSrcWord, string StrDstWord){
    if(StrSrcWord.back() == StrDstWord.front())
        return true;
    else
        return false;
}

bool CheckExistWord(vector<string> VecstrWords, string strTarget){
    bool bResult = false;
    for(int index = 0; index < VecstrWords.size(); index++){
        if(!VecstrWords[index].compare(strTarget)){
            bResult = true;
            break;
        }
    }
    return bResult;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
  
    vector<string> VecstrWords;
    vector<int> VecnCount(n);
        
    VecstrWords.push_back(words[0]);
    int nIndex = 0;
    VecnCount[nIndex]++;
    nIndex++;
        
    for(int index = 1; index < words.size(); index++){
        string strTemp = words[index];
        VecnCount[nIndex]++;
        
        if(CheckFirstWord(VecstrWords.back(), strTemp)){
            if(!CheckExistWord(VecstrWords, strTemp))
                VecstrWords.push_back(strTemp);
            else{
                answer.push_back(nIndex + 1);
                answer.push_back(VecnCount[nIndex]);
                break;
            }
        }
        else{
            answer.push_back(nIndex + 1);
            answer.push_back(VecnCount[nIndex]);
            break;
        }
        
        nIndex++;
        if(nIndex == n)
            nIndex = 0;
    }

    if(!answer.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}