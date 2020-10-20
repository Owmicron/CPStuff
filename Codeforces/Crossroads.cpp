#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool s[5],l[5],r[5],p[5],acc;
int main(){
    for(int i=1;i<=4;i++){
        cin>>l[i]>>s[i]>>r[i]>>p[i];
    }

//    for(int i=1;i<=4;i++){
//        cout<<s[i]<<l[i]<<r[i]<<p[i]<<endl;
//    }

    if(p[1]){
            if(l[2] || s[3] || r[4] || s[1]){acc=true;}
    }
    if(p[2]){
            if(l[3] || s[4] || r[1] || s[2]){acc=true;}
    }
    if(p[3]){
            if(l[4] || s[1] || r[2] || s[3]){acc=true;}
    }
    if(p[4]){
            if(l[1] || s[2] || r[3] || s[4]){acc=true;}
    }


    if(acc){cout<<"YES";}
    else{cout<<"NO";}


}
