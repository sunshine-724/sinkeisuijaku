#include <handy.h>
#include <math.h>
#include <stdio.h>

#define WINDOWX 100
#define WINDOWY 150

int main() {
    HgOpen(WINDOWX, WINDOWY);

    HgSetFillColor(HG_RED);
    HgBoxFill(40, 110, 20, 20, 0);  // 上
    HgBoxFill(40, 65, 20, 20, 0);   // 真ん中
    HgBoxFill(40, 20, 20, 20, 0);   // 下

    HgGetChar();
    HgClose();

    return 0;

}
