#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll dua[10],r,c,p;
ll tree[130][130];
deque<str> ans;
void quad(str s){
    ll xa,xb,ya,yb;
    xa=1;ya=1;xb=dua[p];yb=dua[p];
    for(ll i=1;i<=s.size();i++){
        if(s[i-1]=='0'){xb-=dua[p-i];yb-=dua[p-i];}
        else if(s[i-1]=='1'){xa+=dua[p-i];yb-=dua[p-i];}
        else if(s[i-1]=='2'){xb-=dua[p-i];ya+=dua[p-i];}
        else if(s[i-1]=='3'){xa+=dua[p-i];ya+=dua[p-i];}
    }
    //cout<<xa<<xb<<ya<<yb<<endl;
    //cout<<s<<endl;

    ll zero=0;ll one=0;
    bool partial=false;
    bool homogen=false;
    for(ll i=ya;i<=yb;i++){
        for(ll j=xa;j<=xb;j++){
            if(tree[i][j]==1){one++;}
            else{zero++;}
        }
        if((one>0)&&(zero>0)){partial=true;break;}
    }
    //cout<<one<<endl<<zero<<endl<<endl;
    if(partial){
        str temp;
        temp=s;temp+='0';quad(temp);
        temp=s;temp+='1';quad(temp);
        temp=s;temp+='2';quad(temp);
        temp=s;temp+='3';quad(temp);
    }
    else{
        if(zero==0){ans.push_back(s);}
    }

}
int main(){
    dua[0]=1;
    for(ll i=1;i<=8;i++){
        dua[i]=dua[i-1]*2;
    }
    cin>>r>>c;
    p=max(r,c);
    for(ll i=1;i<=7;i++){
        if(p<=dua[i]){p=i;break;}
    }

    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cin>>tree[i][j];
        }
    }
    bool pure=true;

    for(ll i=1;i<=dua[p];i++){
        for(ll j=1;j<=dua[p];j++){
            if(tree[i][j]==0){pure=false;break;}
        }
        if(!pure){break;}
    }

    if(!pure){
    quad("0");
    quad("1");
    quad("2");
    quad("3");
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<1;
        cout<<ans.front()<<endl;
        ans.pop_front();
    }
    }
    else{
        cout<<1<<endl<<1<<endl;
    }

}
