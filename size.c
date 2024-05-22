#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//カードの中の模様のサイズを決める

int main() { HgOpen(80, 120); 

HgSetColor(HG_BLUE);

//横線
HgLine(0,20,80,20);
HgLine(0,40,80,40);
HgLine(0,50,80,50);
HgLine(0,70,80,70);
HgLine(0,80,80,80);
HgLine(0,100,80,100);

//縦線
HgSetColor(HG_RED);
HgLine(10,0,10,120);
HgLine(30,0,30,120);
HgLine(50,0,50,120);
HgLine(70,0,70,120);


HgGetChar();
HgClose();

return 0;

}
