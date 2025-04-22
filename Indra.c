#include<stdio.h>

int main(){

    float radius;
    printf("Input the radius:");
    scanf("%f",&radius);

    float height;
    printf("Input the height:");
    scanf("%f",&height);

    float area;
    area=2*3.1416*radius*(radius+height);

    float volume;
    volume=3.1416*radius*radius*height;
    
    printf("Area is=%f\n",area);
    printf("Volume is=%f\n",volume);

    return 0;
}