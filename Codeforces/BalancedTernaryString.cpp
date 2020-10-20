#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
str s;
deque <int> p[5];
vector <int> ch[5][5];
int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int num = int(s[i])-48;
        p[num].push_back(i);
    }

    for(int i=0;i<3;i++){
        if(p[i].size()>n/3){
            for(int j=2;j>=0;j--){
                if(i==j)continue;
                int t=j;
                if(i==2){t=1-j;}
                if(p[t].size()<n/3){
                    int give = min (p[i].size()-n/3 , n/3-p[t].size());
                    for(int k=1;k<=give;k++){
                        if(i<t){int x = p[i].back();ch[i][t].push_back(x);p[i].pop_back();}
                        else{int x = p[i].front();ch[i][t].push_back(x);p[i].pop_front();}
                    }
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<ch[i][j].size();k++){
                str temp = "";temp+=char(j+48);
                s.replace(ch[i][j][k],1,temp);
            }
        }
    }
    cout<<s<<endl;
}
