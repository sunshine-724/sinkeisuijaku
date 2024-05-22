// club(三つ葉のクローバー)の柄を作る (size:20*20)

#include <handy.h>
#include <math.h>
#include <stdio.h>


int main() {
    HgSetFillColor(HG_BLACK);

    double xclub[4] = {7, 10, 11, 14};  // 各座標の定義
    double yclub[4] = {0, 9, 9, 0};

    double *clubx;  // 座標の配列を指すポインター
    double *cluby;

    int club;  // カウンタ変数

    HgCircleFill(5, 9, 5, 0);
    HgCircleFill(10, 15, 5, 0);
    HgCircleFill(16, 9, 5, 0);

    // 塗りつぶす色を黒に設定

    HgSetFillColor(HG_BLACK);

    HgBoxFill(8, 8, 5, 5,0);

    for (club = 0; club < 4; club++) {
        clubx = &(xclub[club]);
        cluby = &(yclub[club]);
        HgPolygonFill(4, clubx, cluby, 0);

        break;
    }

    HgGetChar();
    HgClose();

    return 0;
}
