#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s,a;
int n;
bool valid;
int main(){
    cin>>n;
    cin>>s;
    valid =true;
    if(n%2==1){valid=false;}
    else if(s[0]==')' || s[s.size()-1] == '('){valid=false;}
    else{
        for(int i=1;i<s.size()-1;i++){
            a+=s[i];
        }
        int open=0,close=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='(')open++;
            else if(a[i]==')')close++;
        }
        if(open> a.size()/2 || close>a.size()/2){valid=false;}
        else{
            int po,pc;
            po = a.size()/2 - open;
            pc = a.size()/2 - close;
            for(int i=0;i<a.size();i++){
                if(a[i]=='?'){
                    if(po>0){po--;a[i]='(';}
                    else{pc--;a[i]=')';}
                }
            }
            int no,nc;
            no=0;nc=0;
            for(int i=0;i<a.size();i++){
                if(a[i]=='(')no++;
                else{nc++;}
                if(nc>no){valid=false;break;}
            }
        }
    }
    if(!valid)cout<<":(\n";
    else{
        cout<<"("<<a<<")\n";
    }
}
