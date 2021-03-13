#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    bool operator()(pair<int, int> First, pair<int, int> Second){
            return First.second < Second.second;
    }
}Compare;

typedef struct{
    string strType;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    int nSum;
}MusicInfo;

bool VecCompare(MusicInfo First, MusicInfo Second){
    return First.nSum > Second.nSum;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<string> VecstrGeners;
    VecstrGeners.assign(genres.begin(), genres.end());
    sort(VecstrGeners.begin(), VecstrGeners.end());
    VecstrGeners.erase(unique(VecstrGeners.begin(),VecstrGeners.end()),VecstrGeners.end());
    
    vector<MusicInfo> VecMusic;
    for(int index = 0; index < VecstrGeners.size(); index++){
        MusicInfo Temp;
        Temp.strType = VecstrGeners[index];
        VecMusic.push_back(Temp);
    }
    
    for(int index = 0; index < genres.size(); index++){
        for(int sub = 0; sub < VecMusic.size(); sub++){
            if(genres[index] == VecMusic[sub].strType){
                pair<int, int> Temp;
                Temp.first = index;
                Temp.second = plays[index];
                VecMusic[sub].pq.push(Temp);
                VecMusic[sub].nSum += Temp.second;
                break;
            }
        }
    }
    
    sort(VecMusic.begin(), VecMusic.end(), VecCompare);
    
    for(int index = 0; index < VecMusic.size(); index++){
        answer.push_back(VecMusic[index].pq.top().first);
        VecMusic[index].pq.pop();
        if(VecMusic[index].pq.size())
            answer.push_back(VecMusic[index].pq.top().first);
    }
    
    return answer;
}