#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",n-j+1);
        }
        for(int k=1;k<=n-i;k++){
            printf("%d",n-i+1);
        }
        printf("\n");
    }
    

    return 0;
}