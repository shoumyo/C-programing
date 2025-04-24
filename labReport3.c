#include<stdio.h>




int main(){

    int cirId[100];
    int recId[100];
    int cubeId[100];
    float circleDiameter[100];
    float rectangleHeight[100];
    float rectangleWidth[100];
    float cubeHeight[100];
    float cubeWidth[100];
    float cubeDepth[100];
    
    for(int i=0;i<100;i++){
      cirId[i]=0;
      recId[i]=0;
      cubeId[i]=0;;
      circleDiameter[i]=0;
      rectangleHeight[i]=0;
      rectangleWidth[i]=0;
      cubeHeight[i]=0;
      cubeWidth[i]=0;
      cubeDepth[i]=0;
    }

  int id=0;
  int totalShape=0;
  int circle=0;
  int rectangle=0;
  int cube=0;
  double totalArea=0;
  double cirArea=0;
  double recArea=0;
  double cubeArea=0;


  int i=0;
  while(i<100){
    int n;
    printf("Input the number:");
    scanf("%d",&n);
    if(n==1){
      printf("Input diameter:");
      scanf("%f",&circleDiameter[id]);
      totalShape++;
      circle++;
      cirArea+=3.1416*circleDiameter[id]*circleDiameter[id];
      totalArea+=3.1416*circleDiameter[id]*circleDiameter[id];
      id++;
      i++;
    }

    else if(n==2){
      printf("Input height & width:");
      scanf("%fx%f",&rectangleHeight[id],&rectangleWidth[id]);
      totalShape++;
      rectangle++;
      recArea+=rectangleHeight[id]*rectangleWidth[id];
      totalArea+=rectangleHeight[id]*rectangleWidth[id];
      id++;
      i++;
    }

    else if(n==3){
      printf("Input height,width & depth:");
      scanf("%fx%fx%f",&cubeHeight[id],&cubeWidth[id],&cubeDepth[id]);
      totalShape++;
      cube++;
      cubeArea+=cubeHeight[id]*cubeWidth[id]*cubeDepth[id];
      totalArea+=cubeHeight[id]*cubeWidth[id]*cubeDepth[id];
      id++;
      i++;
    }

    else if(n==4){
      for(int i=0;i<id;i++){
        if(circleDiameter[i]!=0){
          printf("%d  circle          %f\n",i+1,circleDiameter[i]);
        }
        else if(rectangleHeight[i]!=0 || rectangleWidth[i]!=0){
          printf("%d  rectangle       %f x %f\n",i+1,rectangleHeight[i],rectangleWidth[i]);
        }
        else{
          printf("%d  cube            %f x %f x %f\n",i+1,cubeHeight[i],cubeWidth[i],cubeDepth[i]);
        }
      }
    }

    else if(n==5){
      printf("Total shape:%d\n",totalShape);
      printf("Total numver of rectangle:%d\n",rectangle);
      printf("Total number of cubes:%d\n",cube);
      printf("Total number of circles:%d\n");
      printf("Total area:%lf\n",totalArea);
      printf("The total area occupied by rectanlges:%lf (%lf )\n",recArea,(recArea/totalArea)*100);
      printf("The total area occupied by circles:%lf (%lf )\n",cirArea,(cirArea/totalArea)*100);
      printf("The total area occupied by cubes:%lf (%lf )\n",cubeArea,(cubeArea/totalArea)*100);
    }

    else{
      printf("Thank you\n");
      break;
    }

  }


  return 0;
}