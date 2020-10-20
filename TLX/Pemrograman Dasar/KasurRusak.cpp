#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool ispal(str s){
    if(s.size()<=1){return true;}
    else{
        if(s[0]==s[s.size()-1]){
            s.replace(0,1,"");
            s.replace(s.size()-1,1,"");
            return ispal(s);
        }
        else{return false;}
    }
}
int main(){
    str x;
    cin>>x;
    //cout<<x[x.size()-1];
    if(ispal(x)){cout<<"YA"<<endl;}
    else{cout<<"BUKAN"<<endl;}
}

