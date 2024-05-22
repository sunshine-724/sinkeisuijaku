/*g2353991 kazuki nakagawa
  斜方投射しバウンドし続ける円*/

/*handyが落ちる時と落ちない時がある*/

#include <stdio.h>
#include <handy.h>
#include <math.h> //三角関数を使うため導入

#define WINDOWX 1400 // ウィンドウの横の大きさ
#define WINDOWY 800  // ウィンドウの縦の大きさ
#define R 10         // 円の半径
#define E 0.8        // 円と床との反発係数

int main()
{ /*動く球に関するパラメーター*/

  double x0;     // 円の初期x座標
  double y0;     // 円の初期y座標
  double x, y;   // 円の中心座標（変数）
  double v0;     // 斜めの初速度 (km/h)→(m/s)→(pixel/flame)
  double vx, vy; // 円の速度のx成分とy成分
  double θ;      // 投げる角度(rad)
  double g;      // 重力加速度(m/s^2)→(pixel/flame^2)
  int tx;        // 球が飛んでから静止するまでの時間（flame)
  int ty;        /* 球が飛んでから床に着地するまでの時間 (flame)
                   (これは床に着地した後時間がリセットt=0となって再度カウントする)*/

  /*床と着地に関するパラメーター*/

  int k = 0;    // 何回着地したかをカウントする変数(最初は０)
  double xx[2]; // 着地した時のx座標(3回まで記録する)
  int xx0[2];   // 着地した時のx座標を表示させるため小数を整数に直す為のx座標

  /*軌跡に関するパラメーター*/

  int num;     // 軌跡を表示させるか否かを入力させる値
  double maxx; // 球を飛ばした時の最高点の座標
  double maxy;

  /*その他*/

  double t; // 時間を(flame)→(s)に直し1秒ごとに表示させる

  /*10(pixel)=1(m)とし,50(flame)=1(s)とする*/

  printf("input number of velocity(km/h) (0<v<200): "); // 速度を入力
  scanf("%lf", &v0);                                    // double型を入力するので変換指定子は%lf

  /*範囲外の速度を入力した場合もう1度入力させる*/

  for (; !(0 < v0 && v0 < 200);)
  {
    printf("input number of velocity(km/h) (0<v<200): "); // 速度を入力
    scanf("%lf", &v0);                                    // double型を入力するので変換指定子は%lf
  }

    printf("input number of degrees(°) (0°<θ<90°): "); // 投げる角度を入力
    scanf("%lf", &θ);
  

  /*範囲外の角度を入力した場合もう1度入力させる*/

  for (; !(0 < θ && θ < 90);)
  {
    printf("input number of degrees(°) (0°<θ<90°): "); // 投げる角度を入力
    scanf("%lf", &θ);
  }

  /*軌跡を表示させるか否か 表示させるなら１、しないなら０、それ以外の数字はもう1度入力させる*/

  printf("display locus:1\nempty:0\ninput number: ");
  scanf("%d", &num);

  /*０か１以外を入力した場合もう1度入力させる*/

  for (; !(num == 1 || num == 0);)
  {
    printf("display locus:1\nempty:0\ninput number: "); // 軌跡を表示させるか否か
    scanf("%d", &num);
  }

  /*単位換算*/

  v0 = (v0 / 3.6) * ((double)10 / (double)50); // (km/h)→(m/s)→(pixel/flame)
  g = (9.8) * ((double)10 / (50 * 50));        //(m/s^2)→ (pixel/flame^2)

  /*ウィンドウを開ける*/

  HgOpen(WINDOWX, WINDOWY);

  /*入力した初速度と角度を水平方向と鉛直方向に分解する*/

  vx = v0 * cos((θ * M_PI) / 180); // πはc言語ではM_PIと表す また単位を(°)→(rad)に直している
  vy = v0 * sin((θ * M_PI) / 180);

  /*以下円の中心座標の計算とその計算結果を入力して円を繰り返し描画させる*/

  for (x0 = 0, y0 = 10, tx = 0, ty = 0; tx <= 1000; tx++, ty++) // t=50で１秒
  {
    x = x0 + vx * tx;
    y = y0 + vy * ty - (0.5) * g * ty * ty; // 1/2だと小数点を切り捨てて０になる

    /*秒数を表示する*/
    t = tx / 50;
    printf("%lf\n", t);

    /*最高点を記録する為のコード*/
    if (y >= maxy)
    {
      maxy = y;
      maxx = x;
    }

    /*計算結果を入力して円を繰り返し描画させる*/

    HgClear();
    HgCircle(x, y, R); // 0.02秒に1回円を表示
    HgSleep(0.02);     // t=50で１秒

    /*もし途中で球と床が衝突した場合、速度のy成分を０にし反発係数を考慮して再び跳ぶようにする*/

    if (y <= 3) // これにより球が反射する速度制限あり
    {
      vy = -E * (vy - g * ty); // vyを反発係数に従ってバウンドさせる
      ty = 0;                  // tyを初期化する

      if (k < 3) // もし衝突回数が２回以下なら衝突時のx座標を記録させる
      {
        xx[k] = x;      // 衝突した時のx座標を小数で記録
        xx0[k] = xx[k]; // 衝突した時のx座標を整数値で記録
      }

      k++; // 床に衝突した時にカウントする変数を1足す

      continue;
    }
  }

  /*もし軌跡を描画させるなら以下を実行する*/
  if (num == 1)
  {
    vy = v0 * sin((θ * M_PI) / 180); // vyの値は反発係数を含めた値となっているので再計算させ初期のvyに戻す

    HgSetFillColor(HG_RED);

    for (x0 = 0, y0 = 10, tx = 0, ty = 0; tx <= 1000; tx++, ty++)
    {
      x = x0 + vx * tx;
      y = y0 + vy * ty - (0.5) * g * ty * ty;

      HgCircleFill(x, y, 5, 0);

      if (y <= 3) // これにより球が反射する速度制限あり
      {
        vy = -E * (vy - g * ty); // vyを反発係数に従ってバウンドさせる
        ty = 0;                  // tyを初期化する
        continue;
      }
    }
  }

  /*おおよその目安を表示(20(m)=100(pix))で区切っている*/

  HgSetFillColor(HG_BLACK);
  HgBoxFill(199, 0, 2, 800, 0);
  HgBoxFill(399, 0, 2, 800, 0);
  HgBoxFill(599, 0, 2, 800, 0);
  HgBoxFill(799, 0, 2, 800, 0);
  HgBoxFill(999, 0, 2, 800, 0);
  HgBoxFill(1199, 0, 2, 800, 0);
  HgBoxFill(1399, 0, 2, 800, 0);

  /*最高点を表示*/
  printf("max point(%lf,%lf)\n", maxx, maxy);
  HgSetFillColor(HG_BLUE);
  HgCircleFill(maxx, maxy, 10, 0);
  HgBoxFill(maxx, 0, 1, maxy, 0);
  HgBoxFill(0, maxy, maxx, 1, 0);

  int Maxx = maxx; // double型からint型に変換する(文章で座標として表示するため)
  int Maxy = maxy;

  HgText(maxx - 10, maxy + 10, "(%d,%d)\n", Maxx, Maxy); // 座標を図に表示

  /*着地点を最大３つまで表示*/
  for (k = 0; k < 3; k++)
  {
    HgSetFillColor(HG_GREEN);
    HgCircleFill(xx[k], 10, 10, 0);              // 着地点を円で表示
    HgText(xx0[k] - 10, 20, "(%d,0)\n", xx0[k]); // 着地点を座標で表示
  }

  /*プログラムを終了させる*/

  HgGetChar();
  HgClose();

  return 0;
}
