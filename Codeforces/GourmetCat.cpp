#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a,b,c,day;
int add(int start){
    int x=start;
    int f[8];
    int ans=0;
    for(int i=1;i<=7;i++)f[i]=0;
    int aa=a;int bb=b;int cc=c;
    while(1>0){
        f[x]++;
        if(f[x]>1){break;}

        if((x==1)||(x==4)||(x==7)){
            aa--;
            if(aa<0){break;}
            else{ans++;}
        }
        if((x==2)||(x==6)){
            bb--;
            if(bb<0){break;}
            else{ans++;}
        }
        if((x==3)||(x==5)){
            cc--;
            if(cc<0){break;}
            else{ans++;}
        }
        x++;if(x>7){x=1;}
    }
    return ans;
}
int main(){
    scanf("%d %d %d",&a,&b,&c);
    int week=INT_MAX;
    week = min(week,a/3);
    week = min(week,b/2);
    week = min(week,c/2);

    day = 7*week;
    a -= (3*week);
    b -= (2*week);
    c -= (2*week);
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if((a>=0)&&(b>=0)&&(c>=0)){
        int mx=0;
        for(int i=1;i<=7;i++){
            mx = max(mx,add(i));
            //cout<<add(i)<<endl;
        }
        day+=mx;
    }
    printf("%d\n",day);
}
