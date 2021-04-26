#if 0
#else
#include"libOne.h"
void gmain() {
    window(1200, 700);

    //文字列全体
    const int rows = 4, cols = 50;
    const char* str[rows] = {
       //         1         2         3         4         5 
       //12345678901234567890123456789012345678901234567890
        "お釈迦様はおっしゃった。　　",
        "自然界によいもわるいも存在しない。　　",
        "人間も同じである。",
        "                ｸﾓｸﾓｶﾞｹﾆｺﾝﾁﾀﾋﾞﾅｼ    　　　   ",
    };
    //表示する文字は１文字ずつ、これにコピーしていく
    char dispStr[rows][cols] = { '\0' };
    //カウンター
    int row = 0;//行
    int col = 0;//列
    int loopCnt = 0;
    int interval = 5;

    //メインループ
    while (notQuit) {
        //表示する文字をループする度に
        //１文字ずつdispStrにコピーしていく
        if (row < rows && loopCnt % interval == 0) {
            //１バイト目がマルチバイト文字かチェック
            bool multi = IsDBCSLeadByte(str[row][col]);
            //とりあえず１バイトコピー
            dispStr[row][col] = str[row][col];
            col++;
            if (multi) {
                //マルチバイト文字なら２バイト目をコピー
                dispStr[row][col] = str[row][col];
                col++;
            }
            if (str[row][col] == '\0') {
                //次の行へ
                col = 0;
                row++;
            }
        }
        if (row < rows) {
            loopCnt++;
        }
        else {
            //全部表示したのでリセット
            col = 0;
            row = 0;
            loopCnt = 0;
            memset(dispStr[0], '\0', rows * cols);
        }
        
        //dispStrを表示
        clear(200,220,200);
        //表示開始位置
        float px = 200;
        float py = 200;
        float size = 50;//テキストサイズ
        float spacing = 10;//行間
        fill(90);
        textSize(size);
        for (int i = 0; i < (row+1); i++) {
            float ofsetY = (size + spacing) * (i + 1);
            text(dispStr[i], px, py + ofsetY);
        }
    }
}
#endif