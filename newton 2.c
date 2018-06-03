

#include <stdio.h>
#include <malloc.h>
//以下の式の会を求める
//求める式0＝ｘ*ｘ*ｘ-ｙ
//求める式＝// 0＝ｘ*ｘ＋ｙ*ｙ－1
/*J行列(微分したやつ)
 * 3x*x  -1
 *
 * 2x    2y
 *
 * 普通のやつ
 * ｘ*x*x-y
 *
 * x*x+y*y-1
 *               set_yakobi                              set_mormal
 * x_k+1   |x_k| |3x^2:yakobi_0[0]  -1:yakobi_1[0]|-1  |xk*xk*xk-yk :normal[0]  |
 *       = |   |-|                                  |   *|    　　　　　　　　　　| 全体はallcaluclate
 * y_k+1   |y_k| |2x  :yakobi_0[1]  2y:yakobi_1[1]|    |xk*xk+yk*yk-1: normal[1]|
 */

double normal_0,normal_1;
double yakobi_0_0,yakobi_0_1;
double yakobi_1_0,yakobi_1_1;
double xk,yk;
double gyaku_0_1,gyaku_1_1;
double gyaku_0_0,gyaku_1_0;
double set_gyaku(){
    double bunnbo = yakobi_0_0*yakobi_1_1-yakobi_1_0*yakobi_0_1;
    gyaku_0_0=yakobi_1_1/bunnbo;
    gyaku_1_0=-1*yakobi_1_0/bunnbo;
    gyaku_0_1=-1*yakobi_0_1/bunnbo;
    gyaku_1_1=yakobi_0_0/bunnbo;
    yakobi_0_0=gyaku_0_0;
    yakobi_1_0=gyaku_1_0;
    yakobi_0_1=gyaku_0_1;
    yakobi_1_1=gyaku_1_1;
    return 0;
}
double set_normal(){
    normal_0=(xk-1)*(xk-1)+(yk-2)*(yk-2)-5;
    normal_1=(xk-3)*(xk-3)+(yk-4)*(yk-4)-(3.09)*(3.09);
    return 0;
}
double set_yakobi(){
    yakobi_0_0=2*(xk-1);
    yakobi_1_0=2*(yk-2);
    yakobi_1_1=2*(yk-4);
    yakobi_0_1=2*(xk-3);
    set_gyaku();
    return 0;
}
double allcalucrate(){
    double x_k1,y_k1;
    x_k1=xk-(yakobi_0_0*normal_0+yakobi_1_0*normal_1);
    y_k1=yk-(yakobi_0_1*normal_0+yakobi_1_1*normal_1);
    xk=x_k1;
    yk=y_k1;
    return 0;
}
int main(){
    //初期値を受け取る
    xk=6;
    yk=12;
    for (int i = 0; i < 500; ++i) {
        set_normal();//普通の関数にセットする
        set_yakobi();//ヤコビ行列を計算する
        allcalucrate();//実際のニュートン近似
    }
    printf("x:%lf y:%lf\n", xk, yk);



}