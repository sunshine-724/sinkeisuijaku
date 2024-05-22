#include <handy.h>
#include <math.h>
#include <stdio.h>
/*60*60サイズ*/

int main() {
    HgOpen(60, 60);

    HgSetFillColor(HG_BLACK);
    HgSetColor(HG_BLACK);

    // 下側の模様を描く
    HgBoxFill(0, 0, 60, 30, 0);  // 後から１部削除して正規の絵を描く

    /* 下側の模様でいらない部分を削除する*/
    HgSetFillColor(HG_WHITE);
    HgFanFill(0, 28, 28, 1.5 * M_PI, 2 * M_PI, 0);
    HgFanFill(60, 28, 28, M_PI, 1.5 * M_PI, 0);


    // 上側の模様を描く
    HgSetFillColor(HG_BLACK);
    double xspade[3] = {0, 30, 60};  // 各座標の配列(左下から時計回り)
    double yspade[3] = {30, 60, 30};

    double *spadex;  // 座標を指定する時のポインター
    double *spadey;

    int k;  // カウンタ変数

    for (k = 0; k < 3; k++) {
        spadex = (&xspade[k]);
        spadey = (&yspade[k]);

        HgPolygonFill(3, spadex, spadey, 0);

        break;
    }

    HgFanFill(15, 30, 15, M_PI, 2 * M_PI, 0);
    HgFanFill(45, 30, 15, M_PI, 2 * M_PI, 0);


    HgGetChar();
    HgClose();

    return 0;
}
