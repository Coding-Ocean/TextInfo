#if 0
#else
#include"libOne.h"
void gmain() {
    window(1200, 700);

    //������S��
    const int rows = 4, cols = 50;
    const char* str[rows] = {
       //         1         2         3         4         5 
       //12345678901234567890123456789012345678901234567890
        "���߉ޗl�͂�����������B�@�@",
        "���R�E�ɂ悢����邢�����݂��Ȃ��B�@�@",
        "�l�Ԃ������ł���B",
        "                �ӸӶ޹ƺ�����ż    �@�@�@   ",
    };
    //�\�����镶���͂P�������A����ɃR�s�[���Ă���
    char dispStr[rows][cols] = { '\0' };
    //�J�E���^�[
    int row = 0;//�s
    int col = 0;//��
    int loopCnt = 0;
    int interval = 5;

    //���C�����[�v
    while (notQuit) {
        //�\�����镶�������[�v����x��
        //�P��������dispStr�ɃR�s�[���Ă���
        if (row < rows && loopCnt % interval == 0) {
            //�P�o�C�g�ڂ��}���`�o�C�g�������`�F�b�N
            bool multi = IsDBCSLeadByte(str[row][col]);
            //�Ƃ肠�����P�o�C�g�R�s�[
            dispStr[row][col] = str[row][col];
            col++;
            if (multi) {
                //�}���`�o�C�g�����Ȃ�Q�o�C�g�ڂ��R�s�[
                dispStr[row][col] = str[row][col];
                col++;
            }
            if (str[row][col] == '\0') {
                //���̍s��
                col = 0;
                row++;
            }
        }
        if (row < rows) {
            loopCnt++;
        }
        else {
            //�S���\�������̂Ń��Z�b�g
            col = 0;
            row = 0;
            loopCnt = 0;
            memset(dispStr[0], '\0', rows * cols);
        }
        
        //dispStr��\��
        clear(200,220,200);
        //�\���J�n�ʒu
        float px = 200;
        float py = 200;
        float size = 50;//�e�L�X�g�T�C�Y
        float spacing = 10;//�s��
        fill(90);
        textSize(size);
        for (int i = 0; i < (row+1); i++) {
            float ofsetY = (size + spacing) * (i + 1);
            text(dispStr[i], px, py + ofsetY);
        }
    }
}
#endif