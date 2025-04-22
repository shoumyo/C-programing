#include<stdio.h>

struct circle{
  int cirId;
  float diameter;
};

struct rectangle{
  int recId;
  float height;
  float width;
};

struct cube{
  int cubeId;
  float cHeight;
  float cWidth;
  float depth;
};

struct wareHouse{
    struct circle c;
    struct rectangle r;
    struct cube cc;
    
};


int main(){

  int id=1;
  int totalShape=0;
  int circle=0;
  int rectangle=0;
  int cube=0;
  double totalArea=0;
  double cirArea=0;
  double recArea=0;
  double cubeArea=0;


  struct wareHouse w[100];
  for(int i=0;i<100;i++){
    w[i].c.cirId=0;
    w[i].r.recId=0;
    w[i].cc.cubeId=0;
  }


  int i=0;
  while(i<100){
    int n;
    printf("Input the number:");
    scanf("%d",&n);
    if(n==1){
      printf("Input diameter:");
      scanf("%f",&w[i].c.diameter);
      totalShape++;
      circle++;
      w[i].c.cirId=id;
      id++;
      cirArea+=3.1416*w[i].c.diameter*w[i].c.diameter;
      totalArea+=3.1416*w[i].c.diameter*w[i].c.diameter;
      i++;
    }

    else if(n==2){
      printf("Input height & width:");
      scanf("%fx%f",&w[i].r.height,&w[i].r.width);
      totalShape++;
      rectangle++;
      w[i].r.recId=id;
      id++;
      recArea+=w[i].r.height*w[i].r.width;
      totalArea+=w[i].r.height*w[i].r.width;
      i++;
    }

    else if(n==3){
      printf("Input height,width & depth:");
      scanf("%fx%fx%f",&w[i].cc.cHeight,&w[i].cc.cWidth,&w[i].cc.depth);
      totalShape++;
      cube++;
      w[i].cc.cubeId=id;
      id++;
      cubeArea+=w[i].cc.cHeight*w[i].cc.cWidth*w[i].cc.depth;
      totalArea+=w[i].cc.cHeight*w[i].cc.cWidth*w[i].cc.depth;
      i++;
    }

    else if(n==4){
      for(int i=1;i<=totalShape;i++){
        if(w[i-1].c.cirId==i){
          printf("%d  circle          %f\n",i,w[i-1].c.diameter);
        }
        else if(w[i-1].r.recId==i){
          printf("%d  rectangle       %f x %f\n",i,w[i-1].r.height,w[i-1].r.width);
        }
        else{
          printf("%d  cube            %f x %f x %f\n",i,w[i-1].cc.cHeight,w[i-1].cc.cWidth,w[i-1].cc.depth);
        }
      }
      i++;
    }

    else if(n==5){
      printf("Total shape:%d\n",totalShape);
      printf("Total numver of rectangle:%d\n",rectangle);
      printf("Total number of cubes:%d\n",cube);
      printf("Total number of circles:%d\n");
      printf("Total area:%lf\n",totalArea);
      printf("The total area occupied by rectanlges:%lf (%lf %)\n",recArea,(recArea/totalArea)*100);
      printf("The total area occupied by circles:%lf (%lf %)\n",cirArea,(cirArea/totalArea)*100);
      printf("The total area occupied by cubes:%lf (%lf %)\n",cubeArea,(cubeArea/totalArea)*100);
      i++;
    }

    else{
      printf("Thank you\n");
      break;
    }

  }


  return 0;
}