#include<iostream>
#include<string>
#include<queue>
using namespace std;
void firstNonRep(string ip){
    queue<char> q;
    int countArr[26]={0};
    for(int i=0;ip[i];i++){
        q.push(ip[i]);
        countArr[ip[i]-'a']++;
        while(!q.empty()){
             if (countArr[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }
        if(q.empty()){
            cout<<-1<<" ";
        }
    }
    cout<<endl;
}
int main(){
    string input="aabc";
    firstNonRep(input);
    return 0;
}
