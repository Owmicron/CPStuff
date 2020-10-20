#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int t;
str z;
str ans (str s){
    sort(s.begin(),s.end());
    deque<char> d;
    d.push_front(s[0]);
    bool used[200];
    for(int i=1;i<s.size();i++)used[i]=false;

    int sold=1;
    while(sold>0){
        sold = 0;
        for(int i=0;i<s.size();i++){
            if(used[i])continue;
            char a,b;
            a = s[i];
            b = d.front();
            if(abs(int(a) - int(b))!=1){
                d.push_front(a);
                sold++;
                used[i]=true;
                continue;
            }
            b = d.back();
            if(abs(int(a) - int(b))!=1){
                d.push_back(a);
                sold++;
                used[i]=true;
                continue;
            }
        }
    }

    if(d.size()==s.size()){
        str temp="";
        while(!d.empty()){
            char x = d.front();
            temp+=x;
            d.pop_front();
        }
        return temp;
    }
    else return "No answer";
}
int main(){
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>z;
        cout<<ans(z)<<endl;
    }
}

