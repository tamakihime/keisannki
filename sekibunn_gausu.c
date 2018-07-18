//
// Created by touho on 2018/06/22.
//
#include <stdio.h>
#include <math.h>
double sitenn=0;         //変更パラメータその3　始点
double syuutenn=1; //変更パラメータその2　終点
long double kannsuu(long double x){
    return 1/(sqrtl(x*x+309)); //変更パラメータその1　関数そのもの
}
double kukannkannsann(long double a){
    return a*(syuutenn-sitenn)/2;
}

long double bunntenn(long double j){
    return (sitenn-(-1)+j)/2*syuutenn;
}
long double gausukeisann(long double x, long double w){
    return w*kannsuu(x);;
}
double caluculate1(){
       double x1 ,w1;
       x1=0;
       w1=2;
       x1=bunntenn(x1);
       double answer=0;
       answer=answer+gausukeisann(x1,w1);
       return kukannkannsann(answer);
}
double caluculate2(){
    double x2[2],w1[2];
    x2[0]=sqrt(1.0/3);
    x2[1]=-sqrt(1.0/3);
    for(int i=0;i<2;i++){
        x2[i]=bunntenn(x2[i]);
    }
    double answer=0;
    for(int i=0;i<2;i++){
        answer=answer+gausukeisann(x2[i],1);
    }
    return kukannkannsann(answer);
}
double caluculate3(){
    double x3[3],w3[3];
    x3[0]=0.0;
    x3[1]=sqrt(0.6);
    x3[2]=-sqrt(0.6);
    for(int j=0;j<3;j++) {
        x3[j] = bunntenn(x3[j]);
    }
    w3[0]=8.0/9.0;
    w3[1]=5.0/9.0;
    w3[2]=5.0/9.0; //ウェイトの代入

    double answer=0;
    for(int k=0;k<3;k++) {
        answer = answer+gausukeisann(x3[k], w3[k]); //計算を行う
    }
    return kukannkannsann(answer); //区間換算を行う
}
double caluculate4(){
    long double x4[4],w4[4];
    x4[0]=sqrt(525+70*sqrt(30))/35;
    x4[1]=sqrt(525-70*sqrt(30))/35;
    x4[2]=-x4[1];
    x4[3]=-x4[0];
    for(int i=0;i<4;i++){
        x4[i]=bunntenn(x4[i]);
    }
    w4[0]=(18-sqrt(30))/36;
    w4[1]=(18+sqrt(30))/36;
    w4[2]=w4[1];
    w4[3]=w4[0];
    long double answer=0;
    for(int k=0;k<4;k++){
        answer = answer+gausukeisann(x4[k], w4[k]);
    }
    return kukannkannsann(answer);

}

int main(){
    //printf("bunntenn1: %.5e\n",caluculate1()-1);
    //printf("bunntenn2: %.5e\n",caluculate2()-1);
    //printf("bunntenn3: %.5e\n",caluculate3()-1);
    printf("bunntenn4: %.5Le\n",caluculate4()-logl((1+sqrtl(310))/sqrtl(309)));
}