#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int x=n/2+1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==x || j==x){
                printf("0");
            }
            else{
                printf("1");
            }
        }
        printf("\n");
    }

    return 0;
}