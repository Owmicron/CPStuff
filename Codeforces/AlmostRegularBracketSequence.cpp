#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,open[2000000],close[2000000],ans;
str s;
bool valid;
void p_open (){
    int batas = 0;
    for(int i=1;i<s.size();i++){
        open[i]=open[i-1];
        close[i]=close[i-1];
        if(s[i]=='(')open[i]++;
        else close[i]++;
        if(open[i]<close[i]){valid=false;break;}
        if (open[i]-1 < close[i]+1){batas=i;}
    }
    for(int i=batas+1;i<=n;i++){
        if(s[i]=='(')ans++;
    }
    if(!valid)ans=0;
}
int main(){
    cin>>n;
    cin>>s;
    valid=true;
    if(n%2==1){valid=false;}
    else{
        int o,c;
        o=0;c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')o++;
            else if(s[i]==')')c++;
        }
        if(abs(o-c)==2){
            if(o<c){
                str temp="";
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='(')temp+=")";
                    else{temp+="(";}
                }
                s=" "+temp;
            }
            else{s=" "+s;}
            p_open();
        }
        else{
            valid=false;
        }
    }
    cout<<ans;
}
