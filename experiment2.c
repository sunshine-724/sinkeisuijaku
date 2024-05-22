#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    HgOpen(1700, 1000);
    HgSetFillColor(HG_GREEN);

    HgBoxFill(0, 0, 1700, 1000, 0);

    HgSetFont(HG_H, 100);

    HgText(300, 750, "1位\n");
    HgText(300, 625, "2位\n");
    HgText(300, 500, "aaaaa\n");
    HgText(300, 375, "aaaaa\n");
    HgText(300, 250, "aaaaa\n");
    HgText(300, 125, "aaaaa\n");
    HgText(300, 0, "aaaaa\n");
    HgText(300, -125, "aaaaa\n");

    HgText(700, 775, "aaaaa\n");
    HgText(700, 650, "aaaaa\n");
    HgText(700, 525, "aaaaa\n");
    HgText(700, 400, "aaaaa\n");
    HgText(700, 525, "aaaaa\n");
    HgText(700, 275, "aaaaa\n");
    HgText(700, 150, "aaaaa\n");
    HgText(700, 25, "aaaaa\n");
    HgText(700, -100, "aaaaa\n");

    HgGetChar();
    HgClose();

    return 0;
}
