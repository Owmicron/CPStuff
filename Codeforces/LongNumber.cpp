#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int id[20],n,f;
bool seq;
str s,ans;
int main(){
    cin>>n;
    cin>>s;
    for(int i=1;i<=9;i++){
        cin>>id[i];
    }
    for(int i=0;i<s.size();i++){
        char a = s[i];
        int x = int(a)-48;
        char b;
        if(id[x]>x){
            f++;
            if(f==1){seq=true;}
            if(seq)b = char(id[x]+48);
            else{b=a;}
        }
        else if(id[x]==x){
            if(seq)b = char(id[x]+48);
            else{b=a;}
        }
        else{
            if(seq==true){seq=false;}
            b = a;
        }
        ans+=b;
    }
    cout<<ans;
}
