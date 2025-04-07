#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int sum=0;
    int x;
    for(int i=2;i<=n;i++){
        x=1;
        for(int j=2;j<=i/2;j++){
            if(i%j==0){
                x=0;
                break;
            }
        }
        if(x==1){
            sum+=i;
        }
    }
    printf("The sum is :%d",sum);

    return 0;
}