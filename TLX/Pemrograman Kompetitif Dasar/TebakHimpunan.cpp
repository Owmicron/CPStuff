#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dbl;
char sub[100];
str response;
int x;
vector<int> ans;
bool known[2000],got,v[2000],yes;
int soal,n,k,q,info;
int main(){
    scanf("%s %d",&sub,&soal);
    scanf("%d %d %d",&n,&k,&q);

    if(soal==0){
        printf("3 2 5 6\n");
        fflush(stdout);
        cin>>response;
    }
    else if(soal==5){
        known[0]=true;v[0]=false;
        known[n+1]=true;v[n+1]=false;
        int l=1;int r=n;
        while(l<=r){
            int mid = (l+r)/2;
            if(!known[mid]){
                printf("1 %d\n",mid);
                fflush(stdout);
                cin>>response;
                if(response=="ya"){x=mid;break;}
                else if(response=="bisajadi"){
                    known[mid]=true;
                    v[mid]=true;
                    l=mid+1;
                }
                else{
                    known[mid]=true;
                    v[mid]=false;
                    r=mid-1;
                }

                if(known[mid+1] && v[mid]){
                    if(v[mid] && !v[mid+1]){
                        x = mid;
                        break;
                    }
                }
                else if(known[mid-1] && !v[mid]){
                    if(!v[mid] && v[mid-1]){
                        x = mid-1;
                        break;
                    }
                }
            }
        }
        printf("%d ",x);fflush(stdout);
        for(int i=1;i<=x;i++){
            printf("%d",i);fflush(stdout);
            if(i<x){printf(" ");fflush(stdout);}
            else{printf("\n");fflush(stdout);}
        }
        cin>>response;

    }
    else{
    if(k==2){
        for(int i=1;i<n;i++){
            if(!known[i]){
                yes=true;
                for(int j=i+1;j<=n;j++){
                    if(info==n){break;}
                    printf("2 %d %d\n",i,j);
                    fflush(stdout);
                    cin>>response;
                    if(response == "ya"){got=true;break;}
                    else if(response == "tidak"){
                        if(yes){
                            v[i]=false;v[j]=false;known[i]=true;known[j]=true;info+=2;
                            yes = false;
                            for(int k=i+1;k<j;k++){
                                v[k]=true;known[k]=true;info++;
                            }
                        }
                        else{
                            known[j]=true;info++;
                            v[j]=false;
                        }
                    }
                    else{
                        if(!yes){
                            known[j]=true;info++;
                            v[j]=true;
                        }
                    }
                }
            }
            if(yes){known[i]=true;v[i]=true;info++;}
            if(info == n){break;}
            if(got){break;}
        }
    }
    else if(k==1){
        for(int i=1;i<=n;i++){
            printf("1 %d\n",i);
            fflush(stdout);
            cin>>response;
            if(response=="ya"){
                got=true; break;
            }
            else if(response=="tidak"){
                v[i]=false;
            }
            else{
                v[i]=true;
            }
        }
    }

    if(!got){
        for(int i=1;i<=n;i++){
            if(v[i]){ans.push_back(i);}
        }

        if(soal<6 || ans.size() < n-1){
            //printf("wi\n");
            printf("%d ",ans.size());
            fflush(stdout);
//            while(!ans.empty()){
//                printf("%d",ans.back()); fflush(stdout);
//                ans.pop_back();
//                if(!ans.empty()){printf(" ");fflush(stdout);}
//                else{printf("\n");fflush(stdout);}
//            }
            for(int i=0;i<ans.size();i++){
                printf("%d",ans.at(i)); fflush(stdout);
                if(i<ans.size()-1){printf(" ");fflush(stdout);}
                else{printf("\n");fflush(stdout);}
            }
            cin>>response;
        }
        else{
            //printf("wa");
            for(int j=1;j<=n;j++){
                printf("%d",n-1);fflush(stdout);
                for(int i=1;i<=n;i++){
                    if(i==j){continue;}
                    else{
                        printf(" %d",i);fflush(stdout);
                    }
                }
                printf("\n");fflush(stdout);
                cin>>response;
                if(response=="ya"){got=true;break;}
            }
            if(!got){
                printf("%d ",n);fflush(stdout);
                for(int i=1;i<=n;i++){
                    if(i<n){printf("%d ",i);fflush(stdout);}
                    else{printf("%d\n",i);fflush(stdout);}
                }
                cin>>response;
            }
        }
    }

    }
}
