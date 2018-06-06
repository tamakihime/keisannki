# include<stdio.h>
#include <stdlib.h>
#include <tgmath.h>

double a[3][4];
double answer[3]={};
int testin(){
    for(int i=0;i<3;++i){
        a[i][0]=3-i;

    }
    a[0][1]=2;
    a[0][2]=1;
    a[0][3]=6;
    a[1][1]=4;
    a[1][2]=3;
    a[1][3]=10;
    a[2][1]=3;
    a[2][2]=5;
    a[2][3]=12.5;
}
int input(){
    for(int i= 0;i<4;i++) {
        char  buf[1000]={};
        fgets(buf, 1000, stdin);
        sscanf(buf, "%lf %lf %lf %lf\n", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    return 0;
}
int pipot() {
    double temp[4];
    double max = 0;
    int maxpar = 0;
    for (int j = 1; j < 3; j++) {
        if (fabs(max) < fabs(a[j][1])) {
            max = a[j][1];
            maxpar = j;
        }
    }
    for(int k=0;k<4;k++){
        temp[k] = a[1][k];
        a[1][k] = a[maxpar][k];
        a[maxpar][k] = temp[k];
    }

}
int LU_line(){
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            a[i][j]=a[i][j]/a[i][i];
            for(int k=i+1;k<3;k++){
                a[k][j]=a[k][j]-a[k][i]*a[i][j];
            }
        }

    }
}
int dainyuu_zennsinn(){
    for(int i=0;i<3;i++){
        answer[i]=(a[i][3]-(answer[0]*a[i][0]+answer[1]*a[i][1]))/a[i][i];

    }
}
int dainyuu_kousinn(){
    double temp[3]={};
    for(int i=2; i>-1;--i){
        temp[2-i]=answer[i]-(temp[0]*a[i][2]+temp[1]*a[i][1]);
    }
    for(int i=0;i<3;i++){
        answer[i]=temp[2-i];
    }
}
int dainyuu(){
    dainyuu_zennsinn();
    dainyuu_kousinn();
}
int print(){
    for(int i=0;i<3;i++){
        printf("ans[%d]:%lf\n",i,answer[i]);
    }

}

int main(){
    //8 7 stin();
    input();
    LU_line();
    dainyuu();
    print();
}