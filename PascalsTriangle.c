#include <stdio.h>

int main(){

  int n;
  printf("Enter your pattern :");
  scanf("%d",&n);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
      printf("  ");
    }
    int value=1;
    for(int k=1;k<=i;k++){
      printf("  %d ",value);
      value=value*(i-k)/(k);
    }
    printf("\n");
  }

  return 0;
}