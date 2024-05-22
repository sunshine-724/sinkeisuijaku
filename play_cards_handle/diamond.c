// ダイヤモンドの柄を作る

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
    HgOpen(60, 60);

    HgSetFillColor(HG_RED);

    HgBoxFill(0, 0, 60, 60, 0);

    HgSetFillColor(HG_WHITE);

    HgFanFill(0, 60, 30, 1.5 * M_PI, 2 * M_PI, 0);  // 左上
    HgFanFill(0, 0, 30, 0, 0.5 * M_PI, 0);          // 左下
    HgFanFill(60, 0, 30, 0.5 * M_PI, M_PI, 0);      // 右下
    HgFanFill(60, 60, 30, M_PI, 1.5 * M_PI, 0);     // 右上

    HgGetChar();
    HgClose();

    return 0;
}
