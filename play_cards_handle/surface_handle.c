#include <handy.h>
#include <math.h>
#include <stdio.h>

// 縦10pix、横10pixのひし形を描く

int main() {
    double redx;
    double redy;  // 赤のひし形の中心座標

    redx = 5;  // 中心座標の初期位置
    redy = 5;

    /*ひし形の各点の座標*/
    double px[4];  // 点p0~p4のx座標
    double py[4];  // 点p0~p4のy座標

    int l;  // 点p0からp4までを表す変数(ひし形に対して左が0、下が1、以下反時計回り(0~3))

    double *pointerx;  // 図形を描くためのポインタ
    double *pointery;

    int j, k;  // カウンタ変数 j:縦 k:横

    HgOpen(80, 120);  // トランプカードの原寸大

    HgSetFillColor(HG_RED);  // 赤のひし形だけを描く

    for (j = 1; j <= 12; j++) {
        for (k = 1; k <= 8; k++) {
            px[0] = redx - 5;
            px[1] = redx;
            px[2] = redx + 5;
            px[3] = redx;

            py[0] = redy;
            py[1] = redy - 5;
            py[2] = redy;
            py[3] = redy + 5;

            for (l = 0; l < 4; l++) {
                pointerx = (&px[l]);
                pointery = (&py[l]);

                HgPolygonFill(4, pointerx, pointery, 0);
                break;
            }
            redx += 10;  // 中心のx座標を10だけ増加する
        }
        redy += 10;  // 中心のy座標を10だけ増加し、x座標を初期位置に戻す
        redx = 5;
    }

    HgGetChar();
    HgClose();

    return 0;
}
