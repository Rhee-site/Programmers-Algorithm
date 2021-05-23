#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;
    for(int index = 0; index < s.length(); index++){
        if(st.size() > 0 && st.top() == s[index]){
            st.pop();
        }
        else{
            st.push(s[index]);   
        }
    }
    
    if(st.empty())
        answer = 1;
    
    return answer;
}