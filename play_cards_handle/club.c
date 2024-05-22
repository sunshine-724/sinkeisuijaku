   // club(三つ葉のクローバー)の柄を作る (size:60*60)

#include <handy.h>
#include <math.h>
#include <stdio.h>


int main() {
    HgOpen(60, 60);
    HgSetFillColor(HG_BLACK);

    double x[4] = {20, 27.5, 32.5, 40};  // 各座標の定義
    double y[4] = {0, 25, 25, 0};

    double *pointerx;  // 座標の配列を指すポインター
    double *pointery;

    int k;  // カウンタ変数

    HgCircleFill(13, 25, 13, 0);
    HgCircleFill(30, 45, 15, 0);
    HgCircleFill(47, 25, 13, 0);

    // 塗りつぶす色を黒に設定

    HgSetFillColor(HG_BLACK);

    HgBoxFill(23, 23, 15, 15,0);

    for (k = 0; k < 4; k++) {
        pointerx = &(x[k]);
        pointery = &(y[k]);
        HgPolygonFill(4, pointerx, pointery, 0);

        break;
    }

    HgGetChar();
    HgClose();

    return 0;
}
