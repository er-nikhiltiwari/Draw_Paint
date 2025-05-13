#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include<X11/Xlib.h>
#include <math.h>
int CurX, CurY, LMode, CMode, RMode, OldColor = BLACK, TempX, TempY, OldTempColor, Color, ColorCode, BGColorCode, BGColor, CursorColor, LineType, MMode = 0, MovX1, MovX2, MovY1, MovY2;

void CLine(int X1, int Y1, int X2, int Y2, int color);
void Undo();
void Move(int MovX, int MovY);
int Operations [1000][10];
int OperationCount = 0;

int main(){
    delay(1000);
    int ColorList[8]={RED, BLUE, GREEN, BLACK, WHITE, LIGHTBLUE, LIGHTRED, BROWN};
    Color = WHITE;
    setcolor(WHITE);
    CursorColor = WHITE;



    
    int gd = DETECT,gm, in = 0, XMax, YMax;
    initgraph(&gd,&gm, "");
    setbkcolor(BLACK);

    setlinestyle(0, 0, 3);
    LineType = 0;
    delay(5000);
    XMax = getmaxx();
    YMax = getmaxy();
    CurX = XMax/2;
    CurY = YMax/2;

    putpixel(CurX, CurY, YELLOW);
    printf("\tControls:\n\tC:Circle mode\tL: line mode\tR:Rectangle mode\tF: fill \tB:Background Color \tX: Line type \tU: Undo\n\tColors:\n\t1.Red\t2.Blue\t3.Green\t4.Black\t5/White\t6.Light blue\t7.Light red\t8.Brown");
    while(1==1){
        char Key = getch();
        switch(Key){
            case 'w':
                if((CMode==1||LMode==1) && (CurX == TempX && CurY == TempY)){
                }
                else{
                    putpixel(CurX, CurY, OldColor);
                }
                CurY = CurY-10;
                OldColor = getpixel(CurX, CurY);
                putpixel(CurX, CurY, CursorColor);
                break;
            case 'a':
                if((CMode==1||LMode==1) && (CurX == TempX && CurY == TempY)){
                }
                else{
                    putpixel(CurX, CurY, OldColor);
                }
                CurX = CurX-10;
                OldColor = getpixel(CurX, CurY);
                putpixel(CurX, CurY, CursorColor);
                break;
            case 's':
                if((CMode==1||LMode==1) && (CurX == TempX && CurY == TempY)){
                }
                else{
                    putpixel(CurX, CurY, OldColor);
                }
                CurY = CurY+10;
                OldColor = getpixel(CurX, CurY);
                putpixel(CurX, CurY, CursorColor);
                break;
            case 'd':
                if((CMode==1||LMode==1) && (CurX == TempX && CurY == TempY)){
                }
                else{
                    putpixel(CurX, CurY, OldColor);
                }
                CurX = CurX+10;
                OldColor = getpixel(CurX, CurY);
                putpixel(CurX, CurY, CursorColor);
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                ColorCode = (int) Key-'0';
                Color = ColorList[ColorCode-1];
                setcolor(Color);
                break;
            case 'l':
                if(LMode||CMode){
                    line(TempX, TempY, CurX, CurY);
                    OldColor = Color;
                    LMode = 0;
                    RMode = 0;
                    CMode = 0;
                    OperationCount++;
                    Operations[OperationCount][0] = 1;
                    Operations[OperationCount][1] = Color;
                    Operations[OperationCount][2] = TempX;
                    Operations[OperationCount][3] = TempY;
                    Operations[OperationCount][4] = CurX;
                    Operations[OperationCount][5] = CurY; 
                    Operations[OperationCount][6] = LineType; 
                    system("clear||cls");

                }else{
                    LMode = 1;
                    OldTempColor = getpixel(CurX, CurY);
                    putpixel(CurX, CurY, RED);
                    TempX = CurX;
                    TempY = CurY;
                }
                break;
            case 'c':
                if(CMode||LMode){
                    int Radius;
                    Radius = (int) pow(pow(CurX-TempX, 2)+pow(CurY-TempY,2), 0.5);
                    circle(TempX, TempY, Radius);
                    OldColor = Color;
                    CMode = 0;
                    LMode = 0;
                    RMode = 0;
                    putpixel(TempX, TempY, OldTempColor);
                    OperationCount++;
                    Operations[OperationCount][0] = 2;
                    Operations[OperationCount][1] = Color;
                    Operations[OperationCount][2] = TempX;
                    Operations[OperationCount][3] = TempY;
                    Operations[OperationCount][4] = Radius;
                    system("clear||cls");

                }else{
                    CMode = 1;
                    OldTempColor = getpixel(CurX, CurY);
                    putpixel(CurX, CurY, RED);
                    TempX = CurX;
                    TempY = CurY;

                }
                break;
            case 'r':
                if(CMode, LMode, RMode){
                    rectangle(TempX, TempY, CurX, CurY);
                    OldColor = Color;
                    CMode = 0;
                    LMode = 0;
                    RMode = 0;
                    OperationCount++;
                    Operations[OperationCount][0] = 5;
                    Operations[OperationCount][1] = Color;
                    Operations[OperationCount][2] = TempX;
                    Operations[OperationCount][3] = TempY;
                    Operations[OperationCount][4] = CurX;
                    Operations[OperationCount][5] = CurY;
                    system("clear||cls");

                }else{
                    RMode = 1;
                    OldTempColor = getpixel(CurX, CurY);
                    putpixel(CurX, CurY, RED);
                    TempX = CurX;
                    TempY = CurY;
                }
            case 'p':
                OperationCount++;
                Operations[OperationCount][0] = 3;
                Operations[OperationCount][1] = Color;
                Operations[OperationCount][2] = CurX;
                Operations[OperationCount][3] = CurY;
                Operations[OperationCount][4] = Color;
                putpixel(CurX, CurY, Color);
                putpixel(CurX+1, CurY, Color);
                putpixel(CurX-1, CurY, Color);
                putpixel(CurX, CurY+1, Color);
                putpixel(CurX, CurY-1, Color);
                putpixel(CurX+1, CurY+1, Color);
                putpixel(CurX+1, CurY-1, Color);
                putpixel(CurX-1, CurY+1, Color);
                putpixel(CurX-1, CurY-1, Color);
                OldColor = Color;
                break;
            case 'f':
                floodfill(CurX, CurY, Color);
                OldColor = Color;
                OperationCount++;
                Operations[OperationCount][0] = 4;
                Operations[OperationCount][1] = Color;
                Operations[OperationCount][2] = CurX;
                Operations[OperationCount][3] = CurY;
                Operations[OperationCount][4] = getpixel(CurX, CurY);
                break;
            case 'm':
                if(MMode == 0){
                    MMode = 1;
                    TempX = CurX;
                    TempY = CurY;
                }else if(MMode == 1){
                    MMode = 2;
                    MovX1 = (CurX>TempX)?(TempX):(CurX);
                    MovX2 = (CurX<TempX)?(TempX):(CurX);
                    MovY1 = (CurY>TempY)?(TempY):(TempY);
                    MovY2 = (CurY<TempY)?(TempY):(CurY);
                }
                else{
                    MMode=0;
                }

                break;
            case 'b':
                char BGKey = getch();
                BGColorCode = (int) BGKey-'0';
                BGColor = ColorList[BGColorCode-1];
                setbkcolor(BGColor);
                if(BGColor == WHITE||BGColor == GREEN|| BGColor == YELLOW){
                    CursorColor = BLACK;
                }else{
                    CursorColor = WHITE;
                }
                break;
            case 'u':
                Undo();
                break;
            case 'x':
                printf("\n\tLine styles:\t1.Solid\t2.Dotted\t3.Dashed\n\tChoice:");
                char LineTypeKey = getch(); 
                OperationCount++;
                Undo();
                (LineType == '1')?(LineType = 0,setlinestyle(0,0,3)):((LineType=='2')?(LineType = 1,setlinestyle(1,0,3)):(LineType = 3,setlinestyle(3,0,3)));
                break;
            case 'e':
                getch();
                getchar();
                closegraph();
                exit(1);
        }

    }

    return 0;
}

void CLine(int X1, int Y1, int X2, int Y2, int color){
    return;
}


void Undo(){
    
    printf("Undoing...");
    delay(200);
    system("clear||cls");
    cleardevice();
    for(int i = 0; i<OperationCount; i++){
        setcolor(Operations[i][1]);
        switch(Operations[i][0]){
            case 1:
                setlinestyle(0, 0, Operations[i][6]);
                line(Operations[i][2], Operations[i][3], Operations[i][4], Operations[i][5]);
                break;
            case 2:
                circle(Operations[i][2], Operations[i][3], Operations[i][4]);
                break;
            case 3:
                putpixel(Operations[i][2], Operations[i][3], Operations[i][4]);
                putpixel(Operations[i][2], Operations[i][3], Color);
                putpixel(Operations[i][2]+1, Operations[i][3], Color);
                putpixel(Operations[i][2]-1, Operations[i][3], Color);
                putpixel(Operations[i][2], Operations[i][3]+1, Color);
                putpixel(Operations[i][2], Operations[i][3]-1, Color);
                putpixel(Operations[i][2]+1, Operations[i][3]+1, Color);
                putpixel(Operations[i][2]+1, Operations[i][3]-1, Color);
                putpixel(Operations[i][2]-1, Operations[i][3]+1, Color);
                putpixel(Operations[i][2]-1, Operations[i][3]-1, Color);
                break;
            case 4:
                floodfill(Operations[i][2], Operations[i][3], Operations[i][4]);
                break;
            case 5:
                rectangle(Operations[i][2], Operations[i][3], Operations[i][4], Operations[i][5]);
        }
    }
    OperationCount--;
}