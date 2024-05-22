// ダイヤモンドの柄を作る(1/3縮尺サイズ 20*20)

#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {

    HgSetFillColor(HG_RED);

    HgBoxFill(0, 0, 20, 20, 0);

    HgSetFillColor(HG_WHITE);

    HgFanFill(0, 20, 10, 1.5 * M_PI, 2 * M_PI, 0);  // 左上
    HgFanFill(0, 0, 10, 0, 0.5 * M_PI, 0);          // 左下
    HgFanFill(20, 0, 10, 0.5 * M_PI, M_PI, 0);      // 右下
    HgFanFill(20, 20, 10, M_PI, 1.5 * M_PI, 0);     // 右上

    HgGetChar();
    HgClose();

    return 0;
}
