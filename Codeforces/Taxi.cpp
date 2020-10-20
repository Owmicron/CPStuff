#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,n,s,t;
int main(){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s;
            if(s==1){a++;}
            if(s==2){b++;}
            if(s==3){c++;}
            if(s==4){d++;}

        }
        t+=d;
        d=0;


        if(c>=a){t+=a;c-=a;a=0;}
        else{t+=c;a-=c;c=0;}


        t+=(b/2);
        if (b % 2 == 0){b=0;}
        else{b=1;}

        if (c>0){t+=c;c=0;}
        if (b>0){
            if(a>0){
                t++;
                if(a<=2){a=0;}
                else{a-=2;}

            }
            else{
                t++;

            }

        }
        if (a>0){
            if(a<=4){t++;}
            else{t+=(a/4);
            if(a % 4 !=0 ){t++;a=0;}
            }

        }
        cout<<t;
}
