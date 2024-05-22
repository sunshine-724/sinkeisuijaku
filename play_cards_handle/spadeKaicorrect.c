#include <handy.h>
#include <math.h>
#include <stdio.h>
/*20*20サイズ*/

int main() {
    HgOpen(20, 20);

    HgSetFillColor(HG_BLACK);
    HgSetColor(HG_BLACK);

    // 下側の模様を描く
    HgBoxFill(0, 0, 20, 10, 0);  // 後から１部削除して正規の絵を描く

    /* 下側の模様でいらない部分を削除する*/
    HgSetFillColor(HG_WHITE);
    HgFanFill(0, 10, 10, 1.5 * M_PI, 2 * M_PI, 0);
    HgFanFill(20, 10, 10, M_PI, 1.5 * M_PI, 0);

    // 上側の模様を描く
    HgSetFillColor(HG_BLACK);
    double xspade[3] = {0, 10, 20};  // 各座標の配列(左下から時計回り)
    double yspade[3] = {10, 20, 10};

    double *spadex;  // 座標を指定する時のポインター
    double *spadey;

    int k;  // カウンタ変数

    for (k = 0; k < 3; k++) {
        spadex = (&xspade[k]);
        spadey = (&yspade[k]);

        HgPolygonFill(3, spadex, spadey, 0);

        break;
    }

    HgFanFill(5, 10, 5, M_PI, 2 * M_PI, 0);
    HgFanFill(15, 10, 5, M_PI, 2 * M_PI, 0);

    HgGetChar();
    HgClose();

    return 0;
}
