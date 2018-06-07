#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//
// Created by touho on 2018/06/07.
//
double syoki[3][4]={};
double answer [3]={};
double beforeanwser[4]={};
int testin(){
    syoki[0][0]=4;
    syoki[0][1]=1;
    syoki[0][2]=-1;
    syoki[0][3]=10.6;
    syoki[1][0]=1;
    syoki[1][1]=3;
    syoki[1][2]=1;
    syoki[1][3]=15.1;
    syoki[2][0]=1;
    syoki[2][1]=-1;
    syoki[2][2]=3;
    syoki[2][3]=7.3;
}
int input () {
    char buf[1000];
    for (int i = 0; i < 3; i++) {
        fgets(buf, 500, stdin);
        sscanf(buf, "%lf %lf %lf %lf", &syoki[i][0], &syoki[i][1], &syoki[i][2], &syoki[i][3]);;
    }
}
int siki(){
        for(int i=0;i<3;i++){
            for(int k=0;k<4;k++) {
                if (i != k) {
                    syoki[i][k]=syoki[i][k]/syoki[i][i]*-1;
                }
            }
        }
    }

int yakobi(){
        beforeanwser[3]=-1;
        for(int i=1;1;i++){
            for(int j=0;j<3;j++) {
                double sum=0;
                for(int k=0;k<4;k++){
                    if(k!=j) {
                        sum = sum + syoki[j][k] * beforeanwser[k];
                    }
                }
                answer[j]=sum;
            }
            if(fabs(answer[0]-beforeanwser[0])<0.0000000001 && fabs(answer[1]-beforeanwser[1])<0.0000000001&& fabs(answer[2]-beforeanwser[2])<0.0000000001 ) {
                return i;
            }
            for(int k=0;k<3;k++){
                beforeanwser[k]=answer[k];
            }
        }

    }

int main(){
    testin();
    input();
    siki();
    int k=yakobi();
    for(int i=0;i<3;i++) {
        printf("answer%d:%lf\n",i,answer[i]);
    }
    printf("%d\n",k);
}