// スペードの柄を作る(サイズは20pixel*20pixel(小数点は切り上げ))

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
    double xspade[4] = {7, 4, 17, 14};  // 4角形の座標（左下から時計回り）
    double yspade[4] = {9, 14, 14, 9};

    double *spadex;  // 各座標の配列を指すポインター
    double *spadey;

    int spade;  // カウンタ変数

    HgOpen(20, 20);

    HgSetFillColor(HG_BLACK);

    // 下側の模様を描く
    HgBoxFill(4, 0, 14, 9, 0);  // 後から１部削除して正規の絵を描く

    HgSetFillColor(HG_WHITE);
    HgFanFill(0, 9, 9, 1.5 * M_PI, 2 * M_PI,
              0);  // 下側の模様でいらない部分を削除する
    HgFanFill(20, 9, 9, M_PI, 1.5 * M_PI, 0);

    HgSetFillColor(HG_BLACK);
    HgFanFill(5, 9, 5, M_PI, 2 * M_PI, 0);  // 半円（下側を描く）
    HgFanFill(16, 9, 5, M_PI, 2 * M_PI, 0);

    HgFanFill(7, 9, 7, 0.67 * M_PI, M_PI, 0);  // 半円（上側を描く）
    HgFanFill(14, 9, 7, 0, 0.34 * M_PI, 0);

    // 4角形を描く

    for (spade = 0; spade < 4; spade++) {
        spadex = (&xspade[spade]);
        spadey = (&yspade[spade]);

        HgPolygonFill(4, spadex, spadey, 0);

        break;
    }
    HgBoxFill(4, 14, 12, 6, 0);

    HgSetFillColor(HG_WHITE);

    HgFanFill(4, 21, 6, 1.5 * M_PI, 2 * M_PI,
              0);  // 小数で表わす（分数ではダメ）
    HgFanFill(16, 21, 6, M_PI, 1.5 * M_PI, 0);

    HgGetChar();
    HgClose();

    return 0;
}
