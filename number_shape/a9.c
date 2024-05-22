#include <handy.h>
#include <math.h>
#include <stdio.h>

// 縦刻みは15,20,5,20,5,20,15  (20が模様を描くところ)
// 横刻みは20,20,10,20,10,20,10,20,20  (左右端の20以外の20が模様を描くところ/)

#define WINDOWX 100
#define WINDOWY 150

int main() {
    HgOpen(WINDOWX, WINDOWY);

    HgSetFillColor(HG_RED);

    HgBoxFill(15, 110, 20, 20, 0);  // 左上
    HgBoxFill(15, 80, 20, 20, 0);   // 左で上から２番目
    HgBoxFill(15, 50, 20, 20, 0);   // 左で下から２番目
    HgBoxFill(15, 20, 20, 20, 0);   // 左下
    HgBoxFill(65, 20, 20, 20, 0);   // 右下
    HgBoxFill(65, 50, 20, 20, 0);   // 右で下から２番目
    HgBoxFill(65, 80, 20, 20, 0);   // 右で上から２番目
    HgBoxFill(65, 110, 20, 20, 0);  // 右上

    HgBoxFill(40,65,20,20,0); //中心の中心

    HgGetChar();
    HgClose();

    return 0;
}
