#include<bits/stdc++.h>
using namespace std;
bool dist(long x){
    int a[5],i;

    bool dig[10];
    for(i=0;i<=9;i++){
        dig[i]=false;
    }

    i=0;
    while(x>0){
        a[i]=x%10;
        x-=a[i];
        x/=10;

        if(!dig[a[i]]){
            dig[a[i]]=true;
        }
        else{return false;}

        i++;

    }
    return true;


}
int main(){
    long y;
    cin>>y;

    for(long i=y+1;i<=10000;i++){
        if (dist(i)){cout<<i;break;}

    }

}
