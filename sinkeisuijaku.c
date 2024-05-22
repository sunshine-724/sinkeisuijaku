/*神経衰弱 joker2枚は抜いてある 合計52枚  52=2*2*13
  g2353991 kazuki nakagawa*/

/*メモ(随時更新)
  横に13枚ずつ縦に4枚ずつにトランプを配置
  そしてカード同士を縦に70pixel、横に20pixelの間隔を開ける

  この時カードの横のサイズは100pixel
              縦のサイズは150pixel
  また左側と下側にそれぞれ10pixel程の空白を開けてある
  よって最初のトランプの左下の始点は(10,10)*/

/*このプログラムの遊び方（基本的なやり方は画面の指示に従えば良い）
1.プレイヤーの人数を選択
2.トランプを2枚クリックする
3.選んだ2枚のトランプが同じならば得点が入るのでもう１回。そうでないならば次のプレイヤーに移る
4.3.のあとどこでもいいので一度クリックしてトランプを裏返す
5.全てのトランプを取り終えたらランキング画面に移る
6.ランキング画面表示された10秒後任意のタイミングで任意のキーを押すと終了する
*/

/*プログラムの詳細
1.トランプの表面を表示させる
2.トランプが選択されたら裏面を表示させる
3.もう一度別のトランプが選択されたら裏面を表示させる
4.2枚のトランプが同じならば得点が入り、そうでないならばプレイヤーを移し再び表面を表示させ、クリックさせる
5.上の操作を26回繰り返したらゲーム終了画面に移る
6.プレイヤーの点数に応じてランキングを作成する
7.ランキングを表示させる
8.キーが押されたら終了する*/

/*わかっている不具合
  なし(多分)*/

/*改善点
コードが汚すぎるのでもっと関数や構造体などを使ってグループ化させる
*/

/*工夫した点
トランプの模様は全て自作でhandyで1から作った。
トランプの配置は現実と一緒で完全ランダム*/


#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOWX 1700
#define WINDOWY 1000

/*プリプロセッサ命令*/
int open();
int draw(int number, int mark, double randompointx, double randompointy);
int score(int member, int player[9]);
/*関数の詳細
1.与えられたnumber変数の値に合う座標をpointx,pointy配列で指定する
2.number変数と1で獲得したpointx,pointy配列を使い適切な位置に柄の左下の座標を(xsum,ysum)と配列として保存させる
3.2で獲得したxsum,ysumとrandompointx,randompointyをそれぞれ足し合わせる（具体的にはマークの種類とトランプの番号と各柄の左下の座標）
4.mark変数とnumber変数と3で獲得したxsum,ysumを使い適切な位置に適切な柄を描く（具体的にはマークの種類とトランプの番号と各柄の左下の座標）*/

/*draw関数の定義*/
int draw(int number, int mark, double randompointx, double randompointy) {
    /*各カードのマークの左下の座標を(0,0)にした時の(x,y)(0<=x<=100,0<=y<=150)(左から右にそして上から下に順に生成する)*/
    double pointx[16];
    double pointy[16];
    // 変数number:カードを識別する変数(1~13)
    // 変数mark:マークを識別する変数(1:diamond,2:heart,3:club,4:spade)

    /*マークの反転は考えない*/
    pointx[0] = 30;  // 中心の中心(1と11~13の中心座標)
    pointy[0] = 55;
    pointx[1] = 15;  // 一番左上
    pointy[1] = 110;
    pointx[2] = 40;  // 中心の一番上
    pointy[2] = 110;
    pointx[3] = 65;  // 一番右上
    pointy[3] = 110;
    pointx[4] = 40;  // 中心の上
    pointy[4] = 87.5;
    pointx[5] = 15;  // 左で上から２番目
    pointy[5] = 80;
    pointx[6] = 65;  // 右で上から２番目
    pointy[6] = 80;
    pointx[7] = 15;  // 左真ん中
    pointy[7] = 65;
    pointx[8] = 65;  // 右真ん中
    pointy[8] = 65;
    pointx[9] = 15;  // 左で下から２番目
    pointy[9] = 50;
    pointx[10] = 65;  // 右で下から２番目
    pointy[10] = 50;
    pointx[11] = 40;  // 中心の下
    pointy[11] = 42.5;
    pointx[12] = 15;  // １番左下
    pointy[12] = 20;
    pointx[13] = 40;  // 中心の１番下
    pointy[13] = 20;
    pointx[14] = 65;  // １番右下
    pointy[14] = 20;
    pointx[15] = 40;  // 中心の中心(1と13以外)
    pointy[15] = 65;

    /*ここから手順２（各適切な数字に対して適切な柄の左下の座標を定義する*/
    int xsum[13];  // 座標を保存する配列
    int ysum[13];

    switch (number) {
        case 1:
            xsum[0] = pointx[0];
            ysum[0] = pointy[0];
            break;

        case 2:
            xsum[0] = pointx[2];
            ysum[0] = pointy[2];
            xsum[1] = pointx[13];
            ysum[1] = pointy[13];
            break;

        case 3:
            xsum[0] = pointx[2];
            ysum[0] = pointy[2];
            xsum[1] = pointx[15];
            ysum[1] = pointy[15];
            xsum[2] = pointx[13];
            ysum[2] = pointy[13];
            break;

        case 4:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[12];
            ysum[2] = pointy[12];
            xsum[3] = pointx[14];
            ysum[3] = pointy[14];
            break;

        case 5:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[15];
            ysum[2] = pointy[15];
            xsum[3] = pointx[12];
            ysum[3] = pointy[12];
            xsum[4] = pointx[14];
            ysum[4] = pointy[14];
            break;

        case 6:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[7];
            ysum[2] = pointy[7];
            xsum[3] = pointx[8];
            ysum[3] = pointy[8];
            xsum[4] = pointx[12];
            ysum[4] = pointy[12];
            xsum[5] = pointx[14];
            ysum[5] = pointy[14];
            break;

        case 7:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[4];
            ysum[2] = pointy[4];
            xsum[3] = pointx[7];
            ysum[3] = pointy[7];
            xsum[4] = pointx[8];
            ysum[4] = pointy[8];
            xsum[5] = pointx[12];
            ysum[5] = pointy[12];
            xsum[6] = pointx[14];
            ysum[6] = pointy[14];
            break;

        case 8:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[4];
            ysum[2] = pointy[4];
            xsum[3] = pointx[7];
            ysum[3] = pointy[7];
            xsum[4] = pointx[8];
            ysum[4] = pointy[8];
            xsum[5] = pointx[11];
            ysum[5] = pointy[11];
            xsum[6] = pointx[12];
            ysum[6] = pointy[12];
            xsum[7] = pointx[14];
            ysum[7] = pointy[14];
            break;

        case 9:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[5];
            ysum[2] = pointy[5];
            xsum[3] = pointx[6];
            ysum[3] = pointy[6];
            xsum[4] = pointx[15];
            ysum[4] = pointy[15];
            xsum[5] = pointx[9];
            ysum[5] = pointy[9];
            xsum[6] = pointx[10];
            ysum[6] = pointy[10];
            xsum[7] = pointx[12];
            ysum[7] = pointy[12];
            xsum[8] = pointx[14];
            ysum[8] = pointy[14];
            break;

        case 10:
            xsum[0] = pointx[1];
            ysum[0] = pointy[1];
            xsum[1] = pointx[3];
            ysum[1] = pointy[3];
            xsum[2] = pointx[4];
            ysum[2] = pointy[4];
            xsum[3] = pointx[5];
            ysum[3] = pointy[5];
            xsum[4] = pointx[6];
            ysum[4] = pointy[6];
            xsum[5] = pointx[9];
            ysum[5] = pointy[9];
            xsum[6] = pointx[10];
            ysum[6] = pointy[10];
            xsum[7] = pointx[11];
            ysum[7] = pointy[11];
            xsum[8] = pointx[12];
            ysum[8] = pointy[12];
            xsum[9] = pointx[14];
            ysum[9] = pointy[14];
            break;

        case 11:  // 11~13は自作(ここの動作がおかしい)
            xsum[0] = pointx[0];
            ysum[0] = pointy[0];
            xsum[1] = pointx[13];
            ysum[1] = pointy[13];
            break;

        case 12:
            xsum[0] = pointx[0];
            ysum[0] = pointy[0];
            xsum[1] = pointx[12];
            ysum[1] = pointy[12];
            xsum[2] = pointx[14];
            ysum[2] = pointy[14];
            break;

        case 13:
            xsum[0] = pointx[0];
            ysum[0] = pointy[0];
            xsum[1] = pointx[12];
            ysum[1] = pointy[12];
            xsum[2] = pointx[13];
            ysum[2] = pointy[13];
            xsum[3] = pointx[14];
            ysum[3] = pointy[14];
            break;
    }  // switch文の終了のかっこ

    /*xsumとysumを補正する（トランプそれぞれの座標が違うため）*/
    int count;  // カウンタ変数
    if (1 <= number && number <= 10) {
        for (count = 0; count < number; count++) {
            xsum[count] += randompointx;
            ysum[count] += randompointy;
        }
    } else {
        for (count = 0; count < number - 9; count++) {
            xsum[count] += randompointx;
            ysum[count] += randompointy;
        }
    }

    /*座標に適切なマークを表示させる*/
    // 大きい柄だけ特別な操作がいる（後で考える）
    int count1;  // カウンタ変数(1と11~13は例外なので別々に分ける)
    /*トランプの番号によって操作が違うので分ける（2~10は原型の1/3縮尺、1,11~13は原型の2/3縮尺*/
    if (2 <= number && number <= 10) {
        for (count1 = 0; count1 < number; count1++) {
            switch (mark) {
                /*ダイヤモンド*/
                case 1:
                    HgSetFillColor(HG_RED);

                    HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 20, 20, 0);

                    HgSetFillColor(HG_WHITE);

                    HgFanFill(xsum[count1] + 0, ysum[count1] + 20, 10,
                              1.5 * M_PI, 2 * M_PI, 0);  // 左上
                    HgFanFill(xsum[count1] + 0, ysum[count1] + 0, 10, 0,
                              0.5 * M_PI,
                              0);  // 左下
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 0, 10,
                              0.5 * M_PI, M_PI, 0);  // 右下
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 20, 10, M_PI,
                              1.5 * M_PI, 0);  // 右上
                    break;

                /*ハート*/
                case 2: {
                    double xheart[3] = {xsum[count1] + 0, xsum[count1] + 10,
                                        xsum[count1] + 20};  // 各座標の配列
                    double yheart[3] = {ysum[count1] + 14, ysum[count1] + 0,
                                        ysum[count1] + 14};
                    int heart;  // カウンタ変数

                    double *heartx;  // 座標を指定する時のポインター
                    double *hearty;

                    HgSetFillColor(HG_RED);

                    // ハートの柄を作る

                    // ハートの上の部分
                    HgFanFill(xsum[count1] + 5, ysum[count1] + 14, 5, 0, M_PI,
                              0);
                    HgFanFill(xsum[count1] + 15, ysum[count1] + 14, 5, 0, M_PI,
                              0);

                    // ハートの下の部分

                    for (heart = 0; heart < 3; heart++) {
                        heartx = &(xheart[heart]);
                        hearty = &(yheart[heart]);

                        HgPolygonFill(3, heartx, hearty, 0);

                        break;
                    }
                    break;
                }

                /*クラブ*/
                case 3:
                    HgSetFillColor(HG_BLACK);

                    double xclub[4] = {xsum[count1] + 7, xsum[count1] + 10,
                                       xsum[count1] + 11,
                                       xsum[count1] + 14};  // 各座標の定義
                    double yclub[4] = {ysum[count1] + 0, ysum[count1] + 9,
                                       ysum[count1] + 9, ysum[count1] + 0};

                    double *clubx;  // 座標の配列を指すポインター
                    double *cluby;

                    int club;  // カウンタ変数

                    HgCircleFill(xsum[count1] + 5, ysum[count1] + 9, 5, 0);
                    HgCircleFill(xsum[count1] + 10, ysum[count1] + 15, 5, 0);
                    HgCircleFill(xsum[count1] + 16, ysum[count1] + 9, 5, 0);

                    // 塗りつぶす色を黒に設定

                    HgSetFillColor(HG_BLACK);

                    HgBoxFill(8, 8, 5, 5, 0);

                    for (club = 0; club < 4; club++) {
                        clubx = &(xclub[club]);
                        cluby = &(yclub[club]);
                        HgPolygonFill(4, clubx, cluby, 0);

                        break;
                    }
                    break;

                /*スペード*/
                case 4: {
                    HgSetFillColor(HG_BLACK);
                    HgSetColor(HG_BLACK);

                    // 下側の模様を描く
                    HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 20, 10,
                              0);  // 後から１部削除して正規の絵を描く

                    /* 下側の模様でいらない部分を削除する*/
                    HgSetFillColor(HG_WHITE);
                    HgFanFill(xsum[count1] + 0, ysum[count1] + 10, 10,
                              1.5 * M_PI, 2 * M_PI, 0);
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 10, 10, M_PI,
                              1.5 * M_PI, 0);

                    // 上側の模様を描く
                    HgSetFillColor(HG_BLACK);
                    double xspade[3] = {
                        xsum[count1] + 0, xsum[count1] + 10,
                        xsum[count1] + 20};  // 各座標の配列(左下から時計回り)
                    double yspade[3] = {ysum[count1] + 10, ysum[count1] + 20,
                                        ysum[count1] + 10};

                    double *spadex;  // 座標を指定する時のポインター
                    double *spadey;

                    int k;  // カウンタ変数

                    for (k = 0; k < 3; k++) {
                        spadex = (&xspade[k]);
                        spadey = (&yspade[k]);

                        HgPolygonFill(3, spadex, spadey, 0);

                        break;
                    }

                    HgFanFill(xsum[count1] + 5, ysum[count1] + 10, 5, M_PI,
                              2 * M_PI, 0);
                    HgFanFill(xsum[count1] + 15, ysum[count1] + 10, 5, M_PI,
                              2 * M_PI, 0);

                } break;

            }        // switch文の終了
        }            // for文の終了
    }                // 11~13の場合
    else {           /*2/3縮尺サイズ*/
        count1 = 0;  // カウンタ変数を初期化
        switch (mark) {
            /*ダイヤモンド*/
            case 1:
                HgSetFillColor(HG_RED);

                HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 40, 40, 0);

                HgSetFillColor(HG_WHITE);

                HgFanFill(xsum[count1] + 0, ysum[count1] + 40, 20, 1.5 * M_PI,
                          2 * M_PI, 0);  // 左上
                HgFanFill(xsum[count1] + 0, ysum[count1] + 0, 20, 0, 0.5 * M_PI,
                          0);  // 左下
                HgFanFill(xsum[count1] + 40, ysum[count1] + 0, 20, 0.5 * M_PI,
                          M_PI, 0);  // 右下
                HgFanFill(xsum[count1] + 40, ysum[count1] + 40, 20, M_PI,
                          1.5 * M_PI, 0);  // 右上
                break;

            /*ハート*/
            case 2: {
                double xheart[3] = {xsum[count1] + 0, xsum[count1] + 20,
                                    xsum[count1] + 40};  // 各座標の配列
                double yheart[3] = {ysum[count1] + 27, ysum[count1] + 0,
                                    ysum[count1] + 27};
                int heart;  // カウンタ変数

                double *heartx;  // 座標を指定する時のポインター
                double *hearty;

                HgSetFillColor(HG_RED);

                // ハートの柄を作る

                // ハートの上の部分
                HgFanFill(xsum[count1] + 10, ysum[count1] + 27, 10, 0, M_PI, 0);
                HgFanFill(xsum[count1] + 30, ysum[count1] + 27, 10, 0, M_PI, 0);

                // ハートの下の部分

                for (heart = 0; heart < 3; heart++) {
                    heartx = &(xheart[heart]);
                    hearty = &(yheart[heart]);

                    HgPolygonFill(3, heartx, hearty, 0);

                    break;
                }
                break;
            }

            /*クラブ*/
            case 3:
                HgSetFillColor(HG_BLACK);

                double xclub[4] = {xsum[count1] + 14, xsum[count1] + 19,
                                   xsum[count1] + 22,
                                   xsum[count1] + 27};  // 各座標の定義
                double yclub[4] = {ysum[count1] + 0, ysum[count1] + 17,
                                   ysum[count1] + 17, ysum[count1] + 0};

                double *clubx;  // 座標の配列を指すポインター
                double *cluby;

                int club;  // カウンタ変数

                HgCircleFill(xsum[count1] + 9, ysum[count1] + 17, 9, 0);
                HgCircleFill(xsum[count1] + 20, ysum[count1] + 30, 10, 0);
                HgCircleFill(xsum[count1] + 32, ysum[count1] + 17, 9, 0);

                // 塗りつぶす色を黒に設定

                HgSetFillColor(HG_BLACK);

                HgBoxFill(xsum[count1] + 16, ysum[count1] + 16, 10, 10, 0);

                for (club = 0; club < 4; club++) {
                    clubx = &(xclub[club]);
                    cluby = &(yclub[club]);
                    HgPolygonFill(4, clubx, cluby, 0);

                    break;
                }
                break;
                /*スペード*/
            case 4: {
                HgSetFillColor(HG_BLACK);
                HgSetColor(HG_BLACK);

                // 下側の模様を描く
                HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 40, 20,
                          0);  // 後から１部削除して正規の絵を描く

                /* 下側の模様でいらない部分を削除する*/
                HgSetFillColor(HG_WHITE);
                HgFanFill(xsum[count1] + 0, ysum[count1] + 20, 20, 1.5 * M_PI,
                          2 * M_PI, 0);
                HgFanFill(xsum[count1] + 40, ysum[count1] + 20, 20, M_PI,
                          1.5 * M_PI, 0);

                // 上側の模様を描く
                HgSetFillColor(HG_BLACK);
                double xspade[3] = {
                    xsum[count1] + 0, xsum[count1] + 20,
                    xsum[count1] + 40};  // 各座標の配列(左下から時計回り)
                double yspade[3] = {ysum[count1] + 20, ysum[count1] + 40,
                                    ysum[count1] + 20};

                double *spadex;  // 座標を指定する時のポインター
                double *spadey;

                int k;  // カウンタ変数

                for (k = 0; k < 3; k++) {
                    spadex = (&xspade[k]);
                    spadey = (&yspade[k]);

                    HgPolygonFill(3, spadex, spadey, 0);

                    break;
                }

                HgFanFill(xsum[count1] + 10, ysum[count1] + 20, 10, M_PI,
                          2 * M_PI, 0);
                HgFanFill(xsum[count1] + 30, ysum[count1] + 20, 10, M_PI,
                          2 * M_PI, 0);
            }
        }  // switch文の終了

        /*11~13は大きいサイズの柄と小さいサイズの柄をそれぞれ1,2,3回描く(ここから下は小さいサイズの柄を適切な数の分描く)*/
        for (count1 = 1; count1 <= number - 10; count1++) {
            switch (mark) {
                /*ダイヤモンド*/
                case 1:
                    HgSetFillColor(HG_RED);

                    HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 20, 20, 0);

                    HgSetFillColor(HG_WHITE);

                    HgFanFill(xsum[count1] + 0, ysum[count1] + 20, 10,
                              1.5 * M_PI, 2 * M_PI, 0);  // 左上
                    HgFanFill(xsum[count1] + 0, ysum[count1] + 0, 10, 0,
                              0.5 * M_PI,
                              0);  // 左下
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 0, 10,
                              0.5 * M_PI, M_PI, 0);  // 右下
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 20, 10, M_PI,
                              1.5 * M_PI, 0);  // 右上
                    break;

                /*ハート*/
                case 2: {
                    double xheart[3] = {xsum[count1] + 0, xsum[count1] + 10,
                                        xsum[count1] + 20};  // 各座標の配列
                    double yheart[3] = {ysum[count1] + 14, ysum[count1] + 0,
                                        ysum[count1] + 14};
                    int heart;  // カウンタ変数

                    double *heartx;  // 座標を指定する時のポインター
                    double *hearty;

                    HgSetFillColor(HG_RED);

                    // ハートの柄を作る

                    // ハートの上の部分
                    HgFanFill(xsum[count1] + 5, ysum[count1] + 14, 5, 0, M_PI,
                              0);
                    HgFanFill(xsum[count1] + 15, ysum[count1] + 14, 5, 0, M_PI,
                              0);

                    // ハートの下の部分

                    for (heart = 0; heart < 3; heart++) {
                        heartx = &(xheart[heart]);
                        hearty = &(yheart[heart]);

                        HgPolygonFill(3, heartx, hearty, 0);

                        break;
                    }
                    break;
                }

                /*クラブ*/
                case 3:
                    HgSetFillColor(HG_BLACK);

                    double xclub[4] = {xsum[count1] + 7, xsum[count1] + 10,
                                       xsum[count1] + 11,
                                       xsum[count1] + 14};  // 各座標の定義
                    double yclub[4] = {ysum[count1] + 0, ysum[count1] + 9,
                                       ysum[count1] + 9, ysum[count1] + 0};

                    double *clubx;  // 座標の配列を指すポインター
                    double *cluby;

                    int club;  // カウンタ変数

                    HgCircleFill(xsum[count1] + 5, ysum[count1] + 9, 5, 0);
                    HgCircleFill(xsum[count1] + 10, ysum[count1] + 15, 5, 0);
                    HgCircleFill(xsum[count1] + 16, ysum[count1] + 9, 5, 0);

                    // 塗りつぶす色を黒に設定

                    HgSetFillColor(HG_BLACK);

                    HgBoxFill(8, 8, 5, 5, 0);

                    for (club = 0; club < 4; club++) {
                        clubx = &(xclub[club]);
                        cluby = &(yclub[club]);
                        HgPolygonFill(4, clubx, cluby, 0);

                        break;
                    }

                    /*スペード*/
                case 4: {
                    HgSetFillColor(HG_BLACK);
                    HgSetColor(HG_BLACK);

                    // 下側の模様を描く
                    HgBoxFill(xsum[count1] + 0, ysum[count1] + 0, 20, 10,
                              0);  // 後から１部削除して正規の絵を描く

                    /* 下側の模様でいらない部分を削除する*/
                    HgSetFillColor(HG_WHITE);
                    HgFanFill(xsum[count1] + 0, ysum[count1] + 10, 10,
                              1.5 * M_PI, 2 * M_PI, 0);
                    HgFanFill(xsum[count1] + 20, ysum[count1] + 10, 10, M_PI,
                              1.5 * M_PI, 0);

                    // 上側の模様を描く
                    HgSetFillColor(HG_BLACK);
                    double xspade[3] = {
                        xsum[count1] + 0, xsum[count1] + 10,
                        xsum[count1] + 20};  // 各座標の配列(左下から時計回り)
                    double yspade[3] = {ysum[count1] + 10, ysum[count1] + 20,
                                        ysum[count1] + 10};

                    double *spadex;  // 座標を指定する時のポインター
                    double *spadey;

                    int k;  // カウンタ変数

                    for (k = 0; k < 3; k++) {
                        spadex = (&xspade[k]);
                        spadey = (&yspade[k]);

                        HgPolygonFill(3, spadex, spadey, 0);

                        break;
                    }

                    HgFanFill(xsum[count1] + 5, ysum[count1] + 10, 5, M_PI,
                              2 * M_PI, 0);
                    HgFanFill(xsum[count1] + 15, ysum[count1] + 10, 5, M_PI,
                              2 * M_PI, 0);

                } break;
            }  // switch文の終了
        }      // for文の終了
    }          // else文の終了

    return 0;
}  // draw関数の全ての処理が終了

/*open関数の定義*/

int open() {
    HgSetFillColor(HG_GREEN);
    HgBoxFill(0, 0, 1700, 1000, 0);  // 背景

    HgSetColor(HG_RED);
    HgSetFont(HG_H, 200);

    HgSleep(1);

    HgText(450, 500, "神経衰弱\n");  // 横幅おおよそ800pixと見るべき

    HgSleep(1.5);
    HgSetFont(HG_H, 50);

    HgText(525, 200, "画面をクリックしてください\n");

    hgevent *event;
    HgSetEventMask(HG_MOUSE_DOWN);  // 入力をマウスだけにする（ずっと）
    event = HgEvent();              // マウスクリックを待つ

    /*クリックされたらスタート画面を表示させる*/

    HgClear();                       // 画面を1回クリアする
    HgBoxFill(0, 0, 1700, 1000, 0);  // 背景

    /*実際にプレイする人数(初期化、もし適切にクリックされていたら変数memberの値が0以外になる)*/
    int member = 0;

    HgText(300, 800, "プレイヤーの人数を選択してください（２人〜８人）\n");

    HgSetFillColor(HgRGB(0, 164, 151));
    HgBoxFill(300, 700, 225, 150, 0);
    HgBoxFill(600, 700, 225, 150, 0);
    HgBoxFill(900, 700, 225, 150, 0);
    HgBoxFill(1200, 700, 225, 150, 0);
    HgBoxFill(300, 400, 225, 150, 0);
    HgBoxFill(600, 400, 225, 150, 0);
    HgBoxFill(900, 400, 225, 150, 0);

    HgSetFont(HG_H, 100);
    HgText(300, 600, "２人\n");
    HgText(600, 600, "３人\n");
    HgText(900, 600, "４人\n");
    HgText(1200, 600, "５人\n");
    HgText(300, 300, "６人\n");
    HgText(600, 300, "７人\n");
    HgText(900, 300, "８人\n");

    int x, y;  // クリックされたx,y座標

    for (;;) {
        HgSetEventMask(HG_MOUSE_DOWN);  // 入力をマウス入力のみにする
        event = HgEvent();              // マウスクリックを待つ

        x = event->x;  // クリックされたx座標を取り出す
        y = event->y;  // クリックされたy座標を取り出す

        /*選択された領域内の人数に沿って条件分岐する*/
        int k;  // カウンタ変数
        for (k = 1; k <= 4; k++) {
            if (((300 * k <= x) && (x <= (300 * k) + 225)) &&
                (700 <= y && y <= 700 + 150)) {
                member = k + 1;
            } else if (((300 * k <= x) && (x <= (300 * k) + 225)) &&
                       (400 <= y && y <= 400 + 150)) {
                member = k + 5;
            }
        }

        /*もし適切にクリックされていたら再度クリックさせるのを解除させる(領域外なら変数の値は0のまま)*/
        if (!(member == 0)) {
            break;
        }  // if文の終了

        /*領域外にクリックされた時に再度クリックするよう促すメッセージを表示*/
        HgSetColor(HG_RED);
        HgSetFont(HG_H, 100);
        HgText(300, 0, "再度クリックして下さい！\n");
    }           // for文の終了
    HgClear();  // 画面を一度初期化

    HgSetFillColor(HG_GREEN);
    HgBoxFill(0, 0, 1700, 1000, 0);  // 背景を再度描写

    return member;  // 変数memberを返す
}

/*score関数の定義(スコアに応じて表示するスコアが変化する)*/

int score(int member, int player[9]) {
    /*一度スコアの部分を空白にして再度スコアを表示させる*/
    HgSetColor(HG_GREEN);
    HgBoxFill(0, 831, 1554, 869, 0);

    switch (member) {
        case 2:
            HgSetFont(HG_H, 100);
            HgSetColor(HG_BLUE);
            HgText(0, 865, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(775, 865, "Player2:%d", player[2]);
            break;

        case 3:
            HgSetFont(HG_H, 100);
            HgSetColor(HG_BLUE);
            HgText(0, 865, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(550, 865, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(1100, 865, "Player3:%d", player[3]);
            break;

        case 4:
            HgSetFont(HG_H, 75);
            HgSetColor(HG_BLUE);
            HgText(0, 865, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(400, 865, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(800, 865, "Player3:%d", player[3]);
            HgSetColor(HG_CYAN);
            HgText(1200, 865, "Player4:%d", player[4]);
            break;

        case 5:
            HgSetFont(HG_H, 75);
            HgSetColor(HG_BLUE);
            HgText(0, 920, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(400, 920, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(800, 920, "Player3:%d", player[3]);
            HgSetColor(HG_CYAN);
            HgText(1200, 920, "Player4:%d", player[4]);
            HgSetColor(HG_ORANGE);
            HgText(0, 830, "Player5:%d", player[5]);
            break;
        case 6:
            HgSetFont(HG_H, 75);
            HgSetColor(HG_BLUE);
            HgText(0, 920, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(400, 920, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(800, 920, "Player3:%d", player[3]);
            HgSetColor(HG_CYAN);
            HgText(1200, 920, "Player4:%d", player[4]);
            HgSetColor(HG_ORANGE);
            HgText(0, 830, "Player5:%d", player[5]);
            HgSetColor(HG_PINK);
            HgText(400, 830, "Player6:%d", player[6]);
            break;

        case 7:
            HgSetFont(HG_H, 75);
            HgSetColor(HG_BLUE);
            HgText(0, 920, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(400, 920, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(800, 920, "Player3:%d", player[3]);
            HgSetColor(HG_CYAN);
            HgText(1200, 920, "Player4:%d", player[4]);
            HgSetColor(HG_ORANGE);
            HgText(0, 830, "Player5:%d", player[5]);
            HgSetColor(HG_PINK);
            HgText(400, 830, "Player6:%d", player[6]);
            HgSetColor(HG_MAGENTA);
            HgText(800, 830, "Player7:%d", player[7]);
            break;

        case 8:
            HgSetFont(HG_H, 75);
            HgSetColor(HG_BLUE);
            HgText(0, 920, "Player1:%d", player[1]);
            HgSetColor(HG_YELLOW);
            HgText(400, 920, "Player2:%d", player[2]);
            HgSetColor(HG_PURPLE);
            HgText(800, 920, "Player3:%d", player[3]);
            HgSetColor(HG_CYAN);
            HgText(1200, 920, "Player4:%d", player[4]);
            HgSetColor(HG_ORANGE);
            HgText(0, 830, "Player5:%d", player[5]);
            HgSetColor(HG_PINK);
            HgText(400, 830, "Player6:%d", player[6]);
            HgSetColor(HG_MAGENTA);
            HgText(800, 830, "Player7:%d", player[7]);
            HgSetColor(HG_BROWN);
            HgText(1200, 830, "Player8:%d", player[8]);
            break;

    }  // switch文が終了

    return 0;
}  // score関数の定義が終了

/*ここから実際動かすプログラム*/

int main() {
    /*トランプ１つ１つの情報*/
    int h, i;          // カウンタ変数 h:縦の枚数 i:横の枚数
    int cardx[4][13];  // 各トランプの左下のx座標を記録する
    int cardy[4][13];  // 各トランプの左下のy座標を記録する
    int x, y;          // 各トランプ左下の座標

    /*トランプの表紙関連*/
    double redx;  // 赤のひし形の中心座標（x、y)
    double redy;

    double px[4];  // 点p0~p4のx座標
    double py[4];  // 点p0~p4のy座標

    int l;  // 点p0からp4までを表す変数(ひし形に対して左が0、下が1、以下反時計回り(0~3))

    double *pointer_px;  // 図形を描くためのポインタ px,pyを指す
    double *pointer_py;

    int j, k; /* カウンタ変数
                (トランプ1枚に対しひし形を縦に15,横に10個描く)
                j:トランプ1枚に対して縦(1<=j<=15)
                k:トランプ1枚に対して横(1<=k<=10)*/

    int x0, y0;                // クリックされたx、y座標
    HgOpen(WINDOWX, WINDOWY);  // ウィンドウを開ける

    /*プレイヤー関係*/
    int member;  // 何人プレイするのかを表す変数

    member = open();  // open関数から何人プレイするのかを読み込む

    int player[9] = {};  // 各プレイヤーの点数を０点に初期化する

    /*プレイヤーの現在のスコアを表示する（全て0)*/
    score(member, player);

    /*今現在どのプレイヤーが引いているのかを判断する変数*/
    int playernow = 1;  // 変数を初期化(最初はプレイヤー１)

    HgSetFillColor(HG_RED);  // トランプの柄を作るための色指定

    hgevent *event;  // イベントを扱うための変数

    // トランプ52枚の表紙を全てを読み込ませ表示させる
    for (h = 0; h < 4; h++) {
        for (i = 0; i < 13; i++) {
            x = 10 + (100 + 20) * i;
            y = 10 + (150 + 70) * h;
            HgBox(x, y, 100,
                  150);  // トランプカードの枠を表示 始点は(0,0)

            /*トランプの表紙の柄を表示させる*/

            redx = x + 5;  // 初期位置(トランプで柄を描く時のひし形の中心座標
                           // x,yの座標が変わるたびに変わる)
            redy = y + 5;

            for (j = 1; j <= 15; j++) {
                for (k = 1; k <= 10; k++) {
                    /* 各ひし形に対して（x座標、y座標を分けて）４点を記録
                     * (p0:左p1:下p2:右 p3:上) */
                    px[0] = redx - 5;
                    px[1] = redx;
                    px[2] = redx + 5;
                    px[3] = redx;

                    py[0] = redy;
                    py[1] = redy - 5;
                    py[2] = redy;
                    py[3] = redy + 5;

                    for (l = 0; l < 4; l++) {
                        pointer_px = &(px[l]);  // 座標を配列から呼び出す
                        pointer_py = &(py[l]);

                        HgPolygonFill(4, pointer_px, pointer_py, 0);

                        break;
                    }
                    redx += 10;  // x座標を10増やす
                }
                redy += 10;    // y座標を１０増やす
                redx = x + 5;  // x座標を初期化
            }

            // そのカードの情報を記録する(情報としてカードの左下の座標)

            cardx[h][i] = x;
            cardy[h][i] = y;
        }
    }

    /*トランプとスコアを区切るための太い直線(見やすくするため)*/
    HgSetFillColor(HG_PURPLE);
    HgBoxFill(0, 825, 1700, 5, 0);
    HgBoxFill(1555, 0, 5, 1000, 0);

    /*全てのトランプの裏の柄の情報(トランプ左下の基準点をx1[n],y1[n](n:0~51)とする)*/

    srand(time(NULL));  // 乱数を現在時刻で初期化する
    int x1[52];
    int y1[52];
    int m, n, o;  // カウンタ変数
    int random;   // 乱数の値（0~51)までの値を得る

    /*乱数から配列内に値を格納させる*/

    /*とりあえず配列52個に値を格納させる*/
    for (m = 0; m < 52; m++) {
        random = rand() % 52;  // 乱数を得る(0~51)

        x1[m] = random;
        y1[m] = random;
    }

    /*配列の中身の数字が一緒かどうかをチェックする
    1.
    配列の要素番号が一緒ならば配列の値は一緒なので同値性のチェックを飛ばす
       ex.x1[1]==x1[1]
    2.
    配列の要素番号が異なっててかつ配列の値が異なってていれば現在調べている配列の要素番号に+1して再度手順1からチェックさせる
    3.
    配列の要素番号が異なっててかつ配列の値が同じであれば現在調べている値を再び乱数を得る,そして再び値が同じかどうかチェックさせる*/

    for (n = 0; n < 52; n++) {
        for (o = 0; o < 52; o++) {
            if (n == o) {
                continue;  // もし配列の番号が一緒ならば、配列の中の数値の同値性チェックを飛ばす
            } else if (!(x1[n] == x1[o])) {
                continue;
            } else {
                random = rand() % 52;  // 乱数を得る(0~51)

                x1[n] = random;
                y1[n] = random;

                o = -1;  // 再び要素番号が０のものから再度チェックさせる(次にcontinue文があるせいでカウンタ変数が+1されるのでo=-1に再設定させる)

                continue;
            }
        }
    }

    /*x1,y1を本来位置する座標へと変換(上書き）する*/
    int p;  // カウンタ変数（一番最初からダイヤ、ハート、クラブ、スペードの順に52個(0~51)定義する

    for (p = 0; p < 52; p++) {
        x1[p] = 10 + (120 * (x1[p] % 13));
        y1[p] = 10 + (220 * (y1[p] % 4));
    }

    /*クリックしたところをトランプがめくれてトランプの裏の情報が一致するようにそれぞれに番号を振っている(配列でいうと要素番号0~51)
      また神経衰弱では同じ番号がペアになったら自分のポイントになるのでペアを数字で表す
      具体的には0~51を13で割った余りに１足したもの*/

    int q;  // ペア番号
    int pair
        [3];  // 1回目と2回目に何を引いたかを記憶する配列(1~13のペアを記憶するのが目的）
    int Pair
        [3]; /* 1回目と2回目に何を引いたかを記憶する配列（0~51の値を記憶するのが目的)
              引いたカードの数字の情報と引いた柄（マークの種類）の情報*/
    int turn = 1;  // 今何枚目を引いているのかを表すカウンタ変数(1か2どっちか)

    int r = 0;  // カウンタ変数(初期化)

    int remaining = 52;  // 残り枚数(最初は52枚)

    /*クリックしてはいけない領域を表す配列*/
    double impossiblex[52];
    double impossibley[52];
    double impossible2x;
    double impossible2y;

    int counter3;  // カウンタ変数
    /*配列の値を領域外に初期化しないと左下がクリックできない*/
    for (counter3 = 0; counter3 < 52; counter3++) {
        impossiblex[counter3] = -100;
        impossibley[counter3] = -150;
    }

    for (;;) {
        /*今どのプレイヤーなのかを随時更新する*/
        HgSetFont(HG_H, 100);

        HgSetFillColor(HG_GREEN);
        HgBoxFill(1580, 0, 120, 200, 0);

        HgSetColor(HG_RED);
        switch (playernow) {
            case 1:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n１\n");
                break;
            case 2:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n２\n");
                break;
            case 3:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n３\n");
                break;
            case 4:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n４\n");
                break;
            case 5:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n５\n");
                break;
            case 6:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n６\n");
                break;
            case 7:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n７\n");
                break;
            case 8:
                HgText(1575, -100, "プ\nレ\nイ\nヤ\n｜\n８\n");
                break;
        }

        HgSetEventMask(HG_MOUSE_DOWN);  // 入力をマウスだけにする（ずっと）
        event = HgEvent();              // マウスクリックを待つ

        x0 = event->x;  // クリックされたx座標を取り出す
        y0 = event->y;  // クリックされたy座標を取り出す

        /*トランプをクリックしていない場合再度クリックさせる*/

        /*トランプがすでにペアとなってトランプがない場合もしくはクリックしたところにトランプがない場合残りの処理を飛ばして再度入力させる*/

        /*プログラムの詳細
        1.クリックしたところにトランプがない場合再度入力させる(h,i:カウンタ変数)
        2.クリックしたところにトランプはあるけれど、すでにペアになっていて空白のところを間違ってクリックした場合再度入力させる
        3.２ターン目の時に１ターン目に取ったトランプを再度クリックした時、再度入力させる
        4.両方違う場合クリックに対応したトランプの裏面を表示させる(ここから次のプログラムへ移れる)*/

        /*トランプの領域外をクリックしたり、ペア済みのトランプをクリックしたときに再度クリックさせる*/

        int judge1[52] =
            {};  // 再度入力させるかを決めるjudge変数(配列の全ての値に0を格納している)
        int judge2[52] =
            {};  // 再度入力させるかを決めるjudge変数(配列の全ての値に0を格納している)
        int no = 0;  // カウンタ変数

        for (h = 0; h < 4; h++) {
            for (i = 0; i < 13; i++) {
                if ((cardx[h][i] <= x0 && x0 <= cardx[h][i] + 100) &&
                    (cardy[h][i] <= y0 && y0 <= cardy[h][i] + 150)) {
                } else { /* 配列judge1の値を1にする(もし領域内にクリックしていたら要素番号51番目が0になり、領域外ならば要素番号51番目が1になる)*/
                    judge1[no] = 1;
                    no++;
                }

            }  // for文の終了
        }      // for文の終了

        /*再度クリックさせるかを判断させる*/
        if (judge1[51] == 1) {
            continue;  // 再度クリックさせる
        }

        /*ここから2の部分*/
        no = 0;  // 初期化(再びカウンタ変数として使うため)
        int no1 = 0;  // カウンタ変数
        for (no = 0; no <= 2 * r; no++) {
            if ((impossiblex[no] <= x0 && x0 <= impossiblex[no] + 100) &&
                (impossibley[no] <= y0 && y0 <= impossibley[no] + 150)) {
            } else {
                judge2[no1] = 1;
                no1++;
            }
        }
        /*再度クリックさせるかを判断させる(要素番号2*r番目が0ならば再度クリックさせる)*/
        if (judge2[2 * r] == 0) {
            continue;  // 再度クリックさせる
        }

        /*ここから3の部分*/
        if ((turn == 2) && ((impossible2x <= x0 && x0 <= impossible2x + 100) &&
                            (impossible2y <= y0 && y0 <= impossible2y + 150))) {
            continue;
        } else {
            impossible2x = 0;  // 適切に入力されていたら領域を初期化する
            impossible2y = 0;
        }

        /*トランプをクリックした場合適切なトランプの裏面を表示させる*/

        /*関数で必要な引数*/
        int number;
        int mark;
        int randompointx;  // 乱数によって得た座標
        int randompointy;

        for (p = 0; p < 52; p++) {
            if ((x1[p] <= x0 && x0 <= x1[p] + 100) &&
                (y1[p] <= y0 && y0 <= y1[p] + 150)) {
                /*1枚目に選択したトランプを2枚目の時再度クリックさせないように選択してはいけない領域を一時的に作る*/

                if (turn == 1) {
                    impossible2x = x1[p];
                    impossible2y = y1[p];
                }
                /*対応したトランプを表示する*/
                // 選択されたトランプの表紙を消す（白で上書きする）
                HgSetFillColor(HG_WHITE);
                HgBoxFill(x1[p], y1[p], 100, 150, 0);

                /*各トランプの座標を*/
                switch (p) {
                    case 0:  // ダイヤの１
                        draw(number = 1, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 1:
                        draw(number = 2, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 2:
                        draw(number = 3, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 3:
                        draw(number = 4, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 4:
                        draw(number = 5, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 5:
                        draw(number = 6, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 6:
                        draw(number = 7, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 7:
                        draw(number = 8, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 8:
                        draw(number = 9, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 9:
                        draw(number = 10, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 10:
                        draw(number = 11, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 11:
                        draw(number = 12, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 12:
                        draw(number = 13, mark = 1, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                        /*ここからハート*/
                    case 13:
                        draw(number = 1, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 14:
                        draw(number = 2, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 15:
                        draw(number = 3, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 16:
                        draw(number = 4, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 17:
                        draw(number = 5, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 18:
                        draw(number = 6, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 19:
                        draw(number = 7, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 20:
                        draw(number = 8, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 21:
                        draw(number = 9, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 22:
                        draw(number = 10, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 23:
                        draw(number = 11, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 24:
                        draw(number = 12, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 25:
                        draw(number = 13, mark = 2, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                        /*ここからクラブ*/
                    case 26:
                        draw(number = 1, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 27:
                        draw(number = 2, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 28:
                        draw(number = 3, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 29:
                        draw(number = 4, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 30:
                        draw(number = 5, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 31:
                        draw(number = 6, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 32:
                        draw(number = 7, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 33:
                        draw(number = 8, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 34:
                        draw(number = 9, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 35:
                        draw(number = 10, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 36:
                        draw(number = 11, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 37:
                        draw(number = 12, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 38:
                        draw(number = 13, mark = 3, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 39:
                        draw(number = 1, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 40:
                        draw(number = 2, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 41:
                        draw(number = 3, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 42:
                        draw(number = 4, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 43:
                        draw(number = 5, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 44:
                        draw(number = 6, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 45:
                        draw(number = 7, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 46:
                        draw(number = 8, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 47:
                        draw(number = 9, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 48:
                        draw(number = 10, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 49:
                        draw(number = 11, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 50:
                        draw(number = 12, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                    case 51:
                        draw(number = 13, mark = 4, randompointx = x1[p],
                             randompointy = y1[p]);
                        break;
                }  // switch文の終了

                /*どのペアが出たか算出する*/
                q = p % 13;
                q++;             // これによりqは1~13のどれかになる
                Pair[turn] = p;  // 0~51の数字が格納される
                pair[turn] = q;  // 1~13の値が格納される
                break;           // for文を抜け出す

            }  // if文の終了
        }  // クリックした座標を変換させるfor文を終了させる

        /*もし0ターン目ならターン数を増やさずに再度クリックさせる、１ターン目ならターン数を増やして再度クリックさせる、２ターン目ならペアかどうかを判断させる*/

        switch (turn) {
            case 0:
                continue;  // 再度マウスクリックを待つ(for文の先頭まで戻る)
                break;  // 形式上のbreak（実際は上にcontinueがあるので実行されない)

            case 1:
                turn++;  // ２ターン目にする
                continue;  // 再度マウスクリックを待つ(for文の先頭まで戻る)
                break;  // 形式上のbreak（実際は上にcontinueがあるので実行されない)

            case 2:
                break;
        }

        /*ペアが揃ったかを確認する
          もし引いた2枚ともの数字が同じであればそれらのトランプ2枚をフィールドから削除する(白で上書きする)
          そうでなければまた表紙を表示させて、再度マウスクリックを待つ
          表面を表示させる際クリックさせる*/
        if (pair[1] == pair[2]) {
            /* もしペアが揃ったらクリックさせ、ペアのところを空白にする*/
            HgSetEventMask(HG_MOUSE_DOWN);  // 入力をマウスだけにする（ずっと）
            event = HgEvent();  // マウスクリックを待つ

            /* ペアのところを2枚とも空白にする*/
            HgSetFillColor(HG_GREEN);
            HgBoxFill(x1[Pair[1]], y1[Pair[1]], 100, 150, 0);
            HgBoxFill(x1[Pair[2]], y1[Pair[2]], 100, 150, 0);

            /*ペアになって空白になったところを再度クリックさせないようにする*/

            // 要素番号が偶数番目が1ターン目、奇数番目が２ターン目

            // rはカウンタ変数
            impossiblex[2 * r] = x1[Pair[1]];
            impossibley[2 * r] = y1[Pair[1]];
            impossiblex[2 * r + 1] = x1[Pair[2]];
            impossibley[2 * r + 1] = y1[Pair[2]];

            r++;  // 注意:ループではない

            /*ペアを揃えたプレイヤーはもう一回プレイできるのでplayernow変数はそのままで現在のプレイヤーの点数を１足す*/
            player[playernow]++;

            /*１足した点数を画面上に表示させる*/
            score(member, player);

            /*残り枚数を2枚減らす*/
            remaining -= 2;

            /*もし残り枚数が0枚になったらfor文を抜け出す*/
            if (remaining == 0) {
                break;
            }

            /*ペアが揃っていない場合*/

        } else {
            /*ペアが揃っていなくてもクリックさせ、ペアのところを空白にする*/
            HgSetEventMask(HG_MOUSE_DOWN);  // 入力をマウスだけにする（ずっと）
            event = HgEvent();  // マウスクリックを待つ

            /*一度トランプの柄を空白にしてから表紙を表示させるコード(j,k:カウンタ変数)*/
            /* ペアではないところを2枚とも空白にする*/
            HgSetFillColor(HG_GREEN);
            HgBoxFill(x1[Pair[1]], y1[Pair[1]], 100, 150, 0);
            HgBoxFill(x1[Pair[2]], y1[Pair[2]], 100, 150, 0);

            /*表面の柄を表示*/
            for (turn = 1; turn <= 2; turn++) {
                // redx,redyを再定義する

                redx = x1[Pair[turn]] + 5;
                redy = y1[Pair[turn]] + 5;

                HgSetFillColor(HG_RED);  // 領域内の色を赤にする
                for (j = 1; j <= 15; j++) {
                    for (k = 1; k <= 10; k++) {
                        /* 各ひし形に対して（x座標、y座標を分けて）４点を記録
                         * (p0:左p1:下p2:右 p3:上) */
                        px[0] = redx - 5;
                        px[1] = redx;
                        px[2] = redx + 5;
                        px[3] = redx;

                        py[0] = redy;
                        py[1] = redy - 5;
                        py[2] = redy;
                        py[3] = redy + 5;

                        for (l = 0; l < 4; l++) {
                            pointer_px = &(px[l]);  // 座標を配列から呼び出す
                            pointer_py = &(py[l]);

                            HgPolygonFill(4, pointer_px, pointer_py, 0);

                            break;
                        }
                        redx += 10;  // x座標を10増やす
                    }
                    redy += 10;                 // y座標を１０増やす
                    redx = x1[Pair[turn]] + 5;  // x座標を初期化
                }  // ひとつのトランプの表紙を表示させるfor文の終了
            }  // ふたつのトランプの表紙を表示させるfor文の終了

            /*次のプレイヤーが誰なのかを決める*/
            playernow++;  // 次のプレイヤーに移行（これでプレイヤー変数が実際のプレイヤーの数を超えたらplayernow変数を１に初期化する)
            if (member < playernow) {
                playernow = 1;
            }
        }  // else文の終了(ペアかそうでないかの条件分岐が終了)

        turn = 1;  // turn変数の初期化
        continue;  // 再度入力させる
    }              // for文の終了

    /*残り枚数が0枚になってからの結果画面*/

    /*順位を決める*/
    int rank[9];  // 要素番号はプレイヤー名を表していて各値は順位を格納している
    int counter1;  // カウンタ変数
    int counter2;
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

    for (counter1 = 1; counter1 <= member; counter1++) {
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

    for (counter1 = 1; counter1 <= member; counter1++) {
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
    /*1位から8位まで表示*/

    HgClear();
    HgSetFillColor(HG_GREEN);
    HgBoxFill(0, 0, 1700, 1000, 0);  // 背景を再度貼り直す
    HgSetFont(HG_H, 100);

    HgSetColor(HG_RED);  // 結果を表示させる色

    /*各順位とそれに対応するプレイヤー名と点数を表示*/
    for (counter2 = 1; counter2 <= member; counter2++) {
        for (counter1 = 1; counter1 <= member; counter1++) {
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

    HgText(1575, 0, "キ\n｜\nを\n入\n力\nす\nる\nと\n終\n了\nし\nま\nす\n");

    HgGetChar();
    HgClose();

    return 0;
}  // プログラムが終了
