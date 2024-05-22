#include <handy.h>
#include <math.h>
#include <stdio.h>

#define WINDOWX 100
#define WINDOWY 150

int main() {
    HgOpen(WINDOWX, WINDOWY);

    HgSetFillColor(HG_RED);
    HgBoxFill(30, 55, 40, 40, 0);

    HgGetChar();
    HgClose();

    return 0;
}
