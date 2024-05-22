// ハートの柄の正規サイズを生成する （倍率1/3倍の時サイズは20*20）

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
    double x[3] = {0, 10, 20};  // 各座標の配列
    double y[3] = {14, 0, 14};
    int k;  // カウンタ変数

    double *pointerx;  // 座標を指定する時のポインター
    double *pointery;

    HgOpen(20, 20);

    HgSetFillColor(HG_RED);

    // ハートの柄を作る

    // ハートの上の部分
    HgFanFill(5, 14, 5, 0, M_PI, 0);
    HgFanFill(15, 14, 5, 0, M_PI, 0);

    // ハートの下の部分

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
