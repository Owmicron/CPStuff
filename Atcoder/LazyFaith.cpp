#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a,b,q;
ll INF = 100000000000000;
ll s[200000],t[200000],xi,pos;

ll shrine_left (ll x){
    if(x<s[1]){return INF;}
    else{
        ll l = 1;
        ll r = a;
        while(l<=r){
            ll mid = (l+r)/2;
            if(s[mid]<=x && s[mid+1]>x){pos = s[mid]; return (ll) abs(x-s[mid]);}
            else if(s[mid]<=x && s[mid+1]<=x){l=mid+1;}
            else {r=mid-1;}
        }
    }
}
ll shrine_right (ll x){
    if(x>s[a]){return INF;}
    else{
        ll l = 1;
        ll r = a;
        while(l<=r){
            ll mid = (l+r)/2;
            if(s[mid]>=x && s[mid-1]<x){pos=s[mid]; return (ll) abs(x-s[mid]);}
            else if(s[mid]>=x && s[mid-1]>=x){r=mid-1;}
            else{l=mid+1;}
        }
    }
}
ll temple_left (ll x){
    if(x<t[1]){return INF;}
    else{
        ll l = 1;
        ll r = b;
        while(l<=r){
            ll mid = (l+r)/2;
            if(t[mid]<=x && t[mid+1]>x){pos = t[mid];return (ll) abs(x-t[mid]);}
            else if(t[mid]<=x && t[mid+1]<=x){l=mid+1;}
            else {r=mid-1;}
        }
    }
}
ll temple_right (ll x){
    if(x>t[b]){return INF;}
    else{
        ll l = 1;
        ll r = b;
        while(l<=r){
            ll mid = (l+r)/2;
            if(t[mid]>=x && t[mid-1]<x){pos=t[mid]; return (ll) abs(x-t[mid]);}
            else if(t[mid]>=x && t[mid-1]>=x){r=mid-1;}
            else{l=mid+1;}
        }
    }
}


int main(){
    cin>>a>>b>>q;
    for(int i=1;i<=a;i++)cin>>s[i];
    sort(s+1,s+1+a);s[a+1]=INF;

    for(int i=1;i<=b;i++)cin>>t[i];
    sort(t+1,t+1+b);t[b+1]=INF;

    for(int query=1;query<=q;query++){
        ll dist = INF;
        cin >> xi;
        ll temp;
        pos = xi;
        temp = shrine_left(pos);
        temp += temple_left(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = shrine_left(pos);
        temp += temple_right(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = shrine_right(pos);
        temp += temple_left(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = shrine_right(pos);
        temp += temple_right(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = temple_left(pos);
        temp += shrine_left(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = temple_left(pos);
        temp += shrine_right(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = temple_right(pos);
        temp += shrine_left(pos);
        dist = min(dist,temp);

        pos = xi;
        temp = temple_right(pos);
        temp += shrine_right(pos);
        dist = min(dist,temp);

        cout<<dist<<endl;
    }
}
