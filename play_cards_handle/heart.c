//ハートの柄を生成する （倍率1倍の時サイズは60*60）

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
    double x[3] = {0, 30, 60};  // 各座標の配列
    double y[3] = {40, 0, 40};
    int k;  // カウンタ変数

    double *pointerx;  // 座標を指定する時のポインター
    double *pointery;

    HgOpen(60, 60);

    HgSetFillColor(HG_RED);

    // ハートの柄を作る

    //ハートの上の部分
    HgFanFill(15, 40, 15, 0, M_PI, 0);
    HgFanFill(45, 40, 15, 0, M_PI, 0);

    //ハートの下の部分

    for (k = 0; k < 3; k++) {
        pointerx = &(x[k]);
        pointery = &(y[k]);

        HgPolygonFill(3, pointerx, pointery, 0);

        break;
    }

    HgGetChar();
    HgClose();

    return 0;
}
