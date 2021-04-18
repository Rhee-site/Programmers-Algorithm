#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        string strSrc = phone_book[i];
        string strDst = phone_book[i + 1].substr(0, strSrc.size());
        if(strSrc == strDst){
            answer = false;
            break;
        }
    }
    
    return answer;
}