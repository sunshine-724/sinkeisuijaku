#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*順位のテスト*/

int main() {
    srand(time(NULL));  // 乱数を現在時刻で初期化する

    int player[9];
    int k;           // カウンタ変数
    int member = 8;  // 今回は８人を想定

    for (k = 1; k < 9; k++) {
        player[k] = rand() % 30;  // 0~29の範囲のランダムな数字を格納する
        HgSleep(0.2);
    }

    /*順位を決める*/
    int rank[9];  // 要素番号はプレイヤー名を表していて各値は順位を格納している
    int counter1;  // カウンタ変数
    int counter2;  // カウンタ変数(順位を表す(最初は1))
    int line = 1;  // テキストの列を表す変数(最初は一行目からなので1から)
    int max1 = -1;  // 最高点数(最初は-1)
    int max2 = -1;  // ２番目に高い点数(最初は-1)
    int max3 = -1;  // ３番目に高い点数 (最初は-1)
    int max4 = -1;
    int max5 = -1;
    int max6 = -1;
    int max7 = -1;
    int max8 = -1;

    /*player配列の要素番号は0~8まで(0は誰も該当しない)*/

    /*1位、2位、3位の点数を確定させる*/

    for (counter1 = 1; counter1 <= 8; counter1++) {
        if (player[counter1] >= max1) {
            if (!(player[counter1] == max1)) {
                /* n番目に高かった数字をn+1番目に高い点数へ更新する*/
                max8 = max7;
                max7 = max6;
                max6 = max5;
                max5 = max4;
                max4 = max3;
                max3 = max2;
                max2 = max1;
            }
            max1 = player[counter1];
        } else if (player[counter1] >= max2) {
            if (!(player[counter1] == max2)) {
                max8 = max7;
                max7 = max6;
                max6 = max5;
                max5 = max4;
                max4 = max3;
                max3 = max2;
            }
            max2 = player[counter1];
        } else if (player[counter1] >= max3) {
            if (!(player[counter1] == max3)) {
                max8 = max7;
                max7 = max6;
                max6 = max5;
                max5 = max4;
                max4 = max3;
            }
            max3 = player[counter1];
        } else if (player[counter1] >= max4) {
            if (!(player[counter1] == max4)) {
                max8 = max7;
                max7 = max6;
                max6 = max5;
                max5 = max4;
            }
            max4 = player[counter1];
        } else if (player[counter1] >= max5) {
            if (!(player[counter1] == max5)) {
                max8 = max7;
                max7 = max6;
                max6 = max5;
            }
            max5 = player[counter1];
        } else if (player[counter1] >= max6) {
            if (!(player[counter1] == max6)) {
                max8 = max7;
                max7 = max6;
            }
            max6 = player[counter1];
        } else if (player[counter1] >= max7) {
            if (!(player[counter1] == max7)) {
                max8 = max7;
            }
            max7 = player[counter1];
        } else {
            max8 = player[counter1];
        }
    }

    /*1位、2位、3位と入賞しているプレイヤーを確定させる*/

    for (counter1 = 1; counter1 <= 8; counter1++) {
        if (max1 == player[counter1]) {
            rank[counter1] = 1;
        } else if (max2 == player[counter1]) {
            rank[counter1] = 2;
        } else if (max3 == player[counter1]) {
            rank[counter1] = 3;
        } else if (max4 == player[counter1]) {
            rank[counter1] = 4;
        } else if (max5 == player[counter1]) {
            rank[counter1] = 5;
        } else if (max6 == player[counter1]) {
            rank[counter1] = 6;
        } else if (max7 == player[counter1]) {
            rank[counter1] = 7;
        } else {
            rank[counter1] = 8;
        }
    }

    HgOpen(1700, 1000);

    HgSetFillColor(HG_GREEN);
    HgBoxFill(0, 0, 1700, 1000, 0);
    HgSetFont(HG_H, 100);

    for (counter2 = 1; counter2 <= 8; counter2++) {
        for (counter1 = 1; counter1 <= 8; counter1++) {
            if (rank[counter1] == counter2) {
                HgText(300, 875 - (125 * line), "%d位\n", counter2);
                HgText(700, 875 - (125 * line), "プレイヤー%d\n", counter1);
                if (player[counter1] >= 10) {
                    HgText(1300, 875 - (125 * line), "%d点\n",
                           player[counter1]);
                } else {
                    HgText(1300, 875 - (125 * line), "  %d点\n",
                           player[counter1]);
                }

                line++;  // インクリメント（一列下げる)
            }
        }
    }

    HgSleep(10);

    HgSetFont(HG_H, 50);
    HgSetColor(HG_RED);

    HgText(1575, 0, "キ\n｜\nを\n入\n力\nす\nる\nと\n終\n了\nし\nま\nす\n");

    printf("プレイヤー1 点数%d\n", player[1]);
    printf("プレイヤー2 点数%d\n", player[2]);
    printf("プレイヤー3 点数%d\n", player[3]);
    printf("プレイヤー4 点数%d\n", player[4]);
    printf("プレイヤー5 点数%d\n", player[5]);
    printf("プレイヤー6 点数%d\n", player[6]);
    printf("プレイヤー7 点数%d\n", player[7]);
    printf("プレイヤー8 点数%d\n", player[8]);

    printf("プレイヤー1 順位%d\n", rank[1]);
    printf("プレイヤー2 順位%d\n", rank[2]);
    printf("プレイヤー3 順位%d\n", rank[3]);
    printf("プレイヤー4 順位%d\n", rank[4]);
    printf("プレイヤー5 順位%d\n", rank[5]);
    printf("プレイヤー6 順位%d\n", rank[6]);
    printf("プレイヤー7 順位%d\n", rank[7]);
    printf("プレイヤー8 順位%d\n", rank[8]);

    HgGetChar();
    HgClose();

    return 0;
}
