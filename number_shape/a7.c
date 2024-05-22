#include <handy.h>
#include <math.h>
#include <stdio.h>

#define WINDOWX 100
#define WINDOWY 150

int main() {
    HgOpen(WINDOWX, WINDOWY);

    HgSetFillColor(HG_RED);
    HgBoxFill(15, 110, 20, 20, 0);  // 左上
    HgBoxFill(15, 65, 20, 20, 0);   // 左真ん中
    HgBoxFill(15, 20, 20, 20, 0);   // 左下
    HgBoxFill(65, 20, 20, 20, 0);   // 右下
    HgBoxFill(65, 65, 20, 20, 0);   // 右真ん中
    HgBoxFill(65, 110, 20, 20, 0);  // 右上

    HgBoxFill(40,87.5,20,20,0); //中心の上

    HgGetChar();
    HgClose();

    return 0;
}
