// スペードの柄を作る

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
    double x[4] = {20, 10, 50, 40};  // 4角形の座標（左下から時計回り）
    double y[4] = {25, 42, 42, 25};

    double *pointerx;  // 各座標の配列を指すポインター
    double *pointery;

    int k;  // カウンタ変数

    HgOpen(60, 60);

    HgSetFillColor(HG_BLACK);

    // 下側の模様を描く
    HgBoxFill(10, 0, 40, 25, 0);  // 後から　　１部削除して正規の絵を描く

    HgSetFillColor(HG_WHITE);
    HgFanFill(0, 25, 25, 1.5 * M_PI, 2 * M_PI,
              0);  // 下側の模様でいらない部分を削除する
    HgFanFill(60, 25, 25, M_PI, 1.5 * M_PI, 0);

    HgSetFillColor(HG_BLACK);
    HgFanFill(14, 25, 14, M_PI, 2 * M_PI, 0);  // 半円（下側を描く）
    HgFanFill(46, 25, 14, M_PI, 2 * M_PI, 0);

    HgFanFill(20, 25, 20, 0.67 * M_PI, M_PI, 0);  // 半円（上側を描く）
    HgFanFill(40, 25, 20, 0, 0.34 * M_PI, 0);

    // 4角形を描く

    for (k = 0; k < 4; k++) {
        pointerx = (&x[k]);
        pointery = (&y[k]);

        HgPolygonFill(4, pointerx, pointery, 0);

        break;
    }
    HgBoxFill(12, 42, 36, 18, 0);

    HgSetFillColor(HG_WHITE);

    HgFanFill(12, 60, 18, 1.5 * M_PI, 2 * M_PI,
              0);  // 小数で表わす（分数ではダメ）
    HgFanFill(48, 60, 18, M_PI, 1.5 * M_PI, 0);

    HgGetChar();
    HgClose();

    return 0;
}
