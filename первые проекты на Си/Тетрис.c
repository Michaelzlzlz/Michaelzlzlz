#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define n 5 /*местоположение стакана, для настройки интерфейса*/
#define m 5

BOOL Cursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci; /*информация о курсоре*/
    HANDLE hStdOut; /*дескриптор вывода*/
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); /*чтение дескриптора ст. вывода*/
    cci.bVisible = bShow; /*чтение новой информации*/
    if(!SetConsoleCursorInfo(hStdOut,&cci)) /*установить*/
        return FALSE;
}

void strelka_New_Game() /*функция указывания стрелки на "новая игра" в меню*/
{
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1)
    {
        char prikaz;
        position.X = 0;
        position.Y = 0;
        SetConsoleCursorPosition(hConsole, position);
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));
        prikaz = getche(); /*ожидание ввода*/
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
        printf("\b ");
        switch(prikaz)
        {
            /*если S, то вниз по порядку, если W то вверх*/
            case 's':{
                position.X = 26;
                position.Y = 3;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 4;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_Rules(); /* переход стрелки из "новая игра" в "рекорды и правила"*/
            }

            case 'w': {         /* переход стрелки из "новая игра" в "выход"*/
                position.X = 26;
                position.Y = 3;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 5;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_Exit();
            }

            case ' ': new_game(); /* если пробел - то начать игру(или запустить игру)*/
        }
    }
}
/* далее протипно то же самое как и с функцией strelka_New_Game()*/
void strelka_Rules()
{
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1)
    {
        char prikaz;
        position.X = 0;
        position.Y = 0;
        SetConsoleCursorPosition(hConsole, position);
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));
        prikaz = getche();
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
        printf("\b ");
        switch(prikaz)
        {
            case 'w':{
                position.X = 26;
                position.Y = 4;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 3;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_New_Game();
            }

            case ' ':{ /*запустить правило и рекорды*/
                position.X = 24;
    position.Y = 2;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");                /*стираем меню*/
    position.X = 24;
    position.Y = 3;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 4;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 5;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 7;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
                position.X = 26;
                position.Y = 4;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                FILE *file; /*включить работу с файлами*/
                int i=10;
                position.X = 26;
                position.Y = 0;
                SetConsoleCursorPosition(hConsole, position);
                /*далее - правило*/
                printf("RULE:\nWASD control and space.\nA - move left. D - move right. S - accelerate the fall.\nW - flip 90 degrees. SPACE - instantly fall and go to the next block.\nFor each placed block give 4-5 balls. For the destroyed line give 100 balls.\nYou need to hold the glass so that the last line is empty and you need to score as many points as possible.\nBelow are the records of those who played the game.\nTo exit to the menu, press any button.");
                /*далее - рекорды*/
                position.X = 26;
                position.Y = 9;
                SetConsoleCursorPosition(hConsole, position);
                printf("RECORD:");
                char name[30];
                file = fopen("TetriS.txt", "r"); /*прочитать файл*/

                 SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
                while (fgets (name, 30, file)!=NULL) /*прочитать запись строки до тех пор пока строка не окажется пустым*/

                {
                    position.X = 26;
                    position.Y = i;
                    SetConsoleCursorPosition(hConsole, position);
                    printf("%s", name); /*выписывать строку с именем и рекордом*/
                    i++;}

                    fclose(file); /* закрыть файл */
                    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));
                    getche(); /* ожидать любую кнопку, после нажатий сотрется все и перейдут в меню*/
                    for (;i>=9;i--){
                    position.X = 26;
                    position.Y = i;
                    SetConsoleCursorPosition(hConsole, position);
                    printf("                                                                   ");
                    }
                    for (;i>=0;i--){
                    position.X = 0;
                    position.Y = i;
                    SetConsoleCursorPosition(hConsole, position);
                    printf("                                                                                                            ");
                    }
                    main();
                    }

            case 's':{
                position.X = 26;
                position.Y = 4;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 5;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_Exit();
            }
        }
    }
}

void strelka_Exit()
{
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1)
    {
        char prikaz;
        position.X = 0;
        position.Y = 0;
        SetConsoleCursorPosition(hConsole, position);
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));
        prikaz = getche();
        SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
        printf("\b ");
        switch(prikaz)
        {
            case 'w':{
                position.X = 26;
                position.Y = 5;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 4;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_Rules();
            }

            case 's':{
                position.X = 26;
                position.Y = 5;
                SetConsoleCursorPosition(hConsole, position);
                printf("\b   ");
                position.X = 26;
                position.Y = 3;
                SetConsoleCursorPosition(hConsole, position);
                printf("->");
                strelka_New_Game();
            }

            case ' ': {
                position.X = 0;
                position.Y = 10;
                SetConsoleCursorPosition(hConsole, position);
                exit(0)/*выход программы*/;
            }
        }
    }
}

int main() /*главная функция - напечатать главное меню*/
{   Cursor(FALSE); /*функция работы с курсором*/
    char title[] = " TETRIS ";
    CharToOem(title, title);
    SetConsoleTitle(title); /*назвать консоль "тетрис"*/
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HideCaret(hConsole);
    system("color 1E"); /*стандарт - синий фон с желтыми символами*/
    position.X = 32;
    position.Y = 2;

    SetConsoleCursorPosition(hConsole, position);
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 4));
    printf("T");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 2));
    printf("E");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    printf("T");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 5));
    printf("R");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 13));
    printf("I");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 11));
    printf("S");
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    position.X = 30;
    position.Y = 3;
    SetConsoleCursorPosition(hConsole, position);
    printf("NEW GAMES");
    position.X = 30;
    position.Y = 4;
    SetConsoleCursorPosition(hConsole, position);
    printf("RECORDS");
    position.X = 30;
    position.Y = 5;
    SetConsoleCursorPosition(hConsole, position);
    printf("EXIT");
    position.X = 30;
    position.Y = 7;
    SetConsoleCursorPosition(hConsole, position);
    printf("Team Z");
    position.X = 26;
    position.Y = 3;
    SetConsoleCursorPosition(hConsole, position);
    printf("->");
    strelka_New_Game(); /*активировать меню функциями(управление со стрелочками)*/
}


void new_game() /*запуск новой игры*/
{
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /*очищаем меню*/
    position.X = 24;
    position.Y = 2;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 3;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 4;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 5;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");
    position.X = 24;
    position.Y = 7;
    SetConsoleCursorPosition(hConsole, position);
    printf("                 ");


    void display(char k,int color) /*функция распечатать стакан*/
    {
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
                if ((position.Y==0+m)||(position.Y == 1+m)||(position.Y == 22+m)||(position.X == 4+n)||(position.X == 24+n))
                                    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
                            switch(k){
                            case '1':{SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));break;}
                            case '2':{SetConsoleTextAttribute(hConsole, (WORD) ((2 << 4) | 2));break;}
                            case '3':{SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 11));break;}
                            case '4':{SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));break;}
                            case '5':{SetConsoleTextAttribute(hConsole, (WORD) ((5 << 4) | 5));break;}
                            case '6':{SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 14));break;}
                            case '7':{SetConsoleTextAttribute(hConsole, (WORD) ((9 << 4) | 9));break;}
                            case '8':{SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 10));break;}
                            case '9':{SetConsoleTextAttribute(hConsole, (WORD) ((13 << 4) | 13));break;}
                            case '0':{SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 12));break;}
                            case 'Q':{SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));break;}
                            case 'W':{SetConsoleTextAttribute(hConsole, (WORD) ((2 << 4) | 2));break;}
                            case 'E':{SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 11));break;}
                            case 'R':{SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));break;}
                            case 'T':{SetConsoleTextAttribute(hConsole, (WORD) ((5 << 4) | 5));break;}
                            case 'Y':{SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 14));break;}
                            case 'U':{SetConsoleTextAttribute(hConsole, (WORD) ((9 << 4) | 9));break;}
                            case 'I':{SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 10));break;}
                            case 'L':{SetConsoleTextAttribute(hConsole, (WORD) ((13 << 4) | 13));break;}
                            case 'P':{SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 12));break;}
                            case 'N':{SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0)); break;}
                            case 'V':{SetConsoleTextAttribute(hConsole, (WORD) ((color << 4) | color)); break;}
                            }
            printf("%c", k);
            position.X++;
    }


    /*создаем стакан*/
    int i, j;
    char k[22][23]={'Q', 'Q','Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q','Q','Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'N', 'N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','N','N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N','Q',
                    'Q', 'Q','Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q','Q','Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q','Q',
                    };
    int ball=0; /* баллы за игры = 0*/
    position.X = 40+n;
    position.Y = 10+m;
    SetConsoleCursorPosition(hConsole, position);
    printf("ball: %d            ", ball);
    position.X = 4+n;
    position.Y = 0+m;
    SetConsoleCursorPosition(hConsole, position);
    int f=0; int color=0; int color1=1;
    for (j = 2; j < 22; ++j){
        for (i = 1; i < 21; ++i){
           display(k[i][j],color); /*вызвать функцию распечатывания стакана*/
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }
    char enter;
    time_t tmp1=0, tmp2=0, tmpf=0;
    tmp1=clock();
    tmpf=tmp1;
    int pozit=NULL;
    int dop=0;
    while(1){ /*основной запуск*/
            if ( _kbhit() ){ /*запустить, если получен символ*/
            position.X = 0+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);
           enter = _getch();
           if ((enter=='W')||(enter=='H')){enter='w';} /*улучшения управления деталей - для стрелочек и для заглавных WASD*/
           if ((enter=='S')||(enter=='P')){enter='s';}
           if ((enter=='A')||(enter=='K')){enter='a';}
           if ((enter=='D')||(enter=='M')){enter='d';}
           /*putch(enter);*/ /*<= снять комментарий при разработке*/
           switch(enter){

            case 'a':{ /*сдвиг слева*/
                f=0;
                for (j = 0; j < 22; ++j){
                    for (i = 0; i < 22; ++i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||(k[i][j]=='0')||
                               (k[i][j]=='V'))&&
                               ((k[i-2][j]=='Q')||(k[i-2][j]=='W')||(k[i-2][j]=='E')||
                               (k[i-2][j]=='R')||(k[i-2][j]=='T')||(k[i-2][j]=='Y')||
                               (k[i-2][j]=='U')||(k[i-2][j]=='I')||(k[i-2][j]=='L')||
                               (k[i-2][j]=='P'))){f++;}}} /*проверка наличия падающего блока и застывшего блока слева одновременно*/

                if (f==0){ /*если не обнаружено застывшего блока, то выполняем операцию с повторным проверкой*/
                 for (j = 0; j < 22; ++j){
                    for (i = 0; i < 22; ++i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                               (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i-2][j]!='Q')||
                               (k[i-2][j]!='W')||(k[i-2][j]!='E')||(k[i-2][j]!='R')||
                               (k[i-2][j]!='T')||(k[i-2][j]!='Y')||(k[i-2][j]!='U')||
                               (k[i-2][j]!='I')||(k[i-2][j]!='L')||(k[i-2][j]!='P')))
                               {k[i-2][j]=k[i][j]; k[i][j]='N';}}}


                }


                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);

                f=0;
        for (j = 2; j < 22; ++j){ /*распечатать стакан*/
            for (i = 1; i < 21; ++i){
            display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }break;}

            case 'd':{ f=0; /*сдвиг справо, прототипно то же самое, что и со сдвигом слева*/
                for (j = 0; j < 22; ++j){
                    for (i = 22; i > 0; --i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                                (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                                (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                                (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i+2][j]=='Q')||
                                (k[i+2][j]=='W')||(k[i+2][j]=='E')||(k[i+2][j]=='R')||
                                (k[i+2][j]=='T')||(k[i+2][j]=='Y')||(k[i+2][j]=='U')||
                                (k[i+2][j]=='I')||(k[i+2][j]=='L')||(k[i+2][j]=='P'))){f++;}}}

                if (f==0){
                 for (j = 0; j < 22; ++j){
                    for (i = 22; i > 0; --i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                               (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i+2][j]!='Q')||
                               (k[i+2][j]!='W')||(k[i+2][j]!='E')||(k[i+2][j]!='R')||
                               (k[i+2][j]!='T')||(k[i+2][j]!='Y')||(k[i+2][j]!='U')||
                               (k[i+2][j]!='I')||(k[i+2][j]!='L')||(k[i+2][j]!='P')))
                               {k[i+2][j]=k[i][j]; k[i][j]='N';}}}}

                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);

                f=0;
                for (j = 2; j < 22; ++j){
        for (i = 1; i < 21; ++i){
           display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }break;}

                case 's':{ /*спуск вниз, то же самое, что и с двигом слева или справа, только массивы другие*/
                f=0;
                for (j = 22; j > -1; --j){ /*проверка стакана снизу вверх*/
                    for (i = 0; i < 22; ++i){
                             if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                               (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i][j+1]=='Q')||
                               (k[i][j+1]=='W')||(k[i][j+1]=='E')||(k[i][j+1]=='R')||
                               (k[i][j+1]=='T')||(k[i][j+1]=='Y')||(k[i][j+1]=='U')||
                               (k[i][j+1]=='I')||(k[i][j+1]=='L')||(k[i][j+1]=='P')))
                               {f++;}}}

                if (f==0){
                 for (j = 22; j > -1; --j){
                    for (i = 0; i < 22; ++i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                               (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i][j+1]!='Q')||
                               (k[i][j+1]!='W')||(k[i][j+1]!='E')||(k[i][j+1]!='R')||
                               (k[i][j+1]!='T')||(k[i][j+1]!='Y')||(k[i][j+1]!='U')||
                               (k[i][j+1]!='I')||(k[i][j+1]!='L')||(k[i][j+1]!='P')))
                               {k[i][j+1]=k[i][j]; k[i][j]='N';}}}


                        }


                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);

                f=0;
                for (j = 2; j < 22; ++j){
        for (i = 1; i < 21; ++i){
           display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }break;}

                case 'w':{ /* поворот детали - сложная операция с массивами*/
                         for (j = 21; j >= 1; --j){ /*проверка стакана снизу вверх*/
                    for (i = 20; i >= 1; --i){
                            if (k[i][j]=='V'){
                                if (pozit==1){ /*позиции задают при получении блока. у каждого блока не больше 4-ех позиций*/
                                        if (color==1){ /*у каждого блока есть номер по цветам*/
                                                if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i-2][j+1]=='N')&&(k[i-1][j+1]=='N')) /*проверка отсутвия чужих блоков*/

                                                    {k[i][j-1]='1'; k[i+1][j-1]='1'; k[i][j+1]='1';
                                                    k[i+1][j+1]='1'; k[i-2][j+1]='1'; k[i-1][j+1]='1';/* заполняем переворот(переход к новой позиции*/


                                                    k[i-2][j]='N'; k[i-1][j]='N'; k[i+2][j]='N'; /*удалить заполненые ячейки прошлого позиции*/
                                                    k[i+3][j]='N'; k[i+2][j+1]='N'; k[i+3][j+1]='N';
                                                    pozit++; /*обозначить что позиция перешла к следующему*/
                                                    }}
                                                    /*далее - с другими деталями и позиции также как и с первым позицией первого детали*/

                                        if (color==2){
                                                if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i+2][j-1]=='N')&&
                                                    (k[i+3][j-1]=='N'))

                                                    {k[i-1][j-1]='2'; k[i][j-1]='2'; k[i+1][j-1]='2';
                                                    k[i+2][j-1]='2';


                                                    k[i+3][j]='N'; k[i+4][j]='N'; k[i+3][j+1]='N';
                                                    k[i+4][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==11){
                                                    if ((k[i][j-1]=='N')&&
                                                    (k[i+1][j-1]=='N'))

                                                    { k[i][j-1]='3';
                                                    k[i+1][j-1]='3';


                                                    k[i+3][j]='N'; k[i+2][j]='N';
                                                    pozit++;
                                                    }}

                                                if (color==13){
                                                    if ((k[i-2][j+1]=='N')&&(k[i-1][j+1]=='N')&&(k[i-2][j]=='N')&&
                                                    (k[i-1][j]=='N')&&(k[i+2][j]=='N')&&(k[i+3][j]=='N')&&
                                                    (k[i+2][j-1]=='N')&&(k[i+3][j-1]=='N'))

                                                    {k[i-2][j+1]='9'; k[i-1][j+1]='9'; k[i-2][j]='9';
                                                    k[i-1][j]='9'; k[i+2][j]='9'; k[i+3][j]='9'; k[i+2][j-1]='9'; k[i+3][j-1]='9';

                                                    k[i-2][j-1]='N'; k[i-1][j-1]='N'; k[i][j-1]='N';
                                                    k[i+1][j-1]='N'; k[i][j+1]='N'; k[i+1][j+1]='N';  k[i+2][j+1]='N'; k[i+3][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==9){
                                                    if ((k[i][j-2]=='N')&&(k[i+1][j-2]=='N')&&
                                                    (k[i][j-1]=='N')&&
                                                    (k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N'))

                                                    {k[i][j-2]='7'; k[i+1][j-2]='7';
                                                    k[i][j-1]='7'; k[i+1][j-1]='7'; k[i][j+1]='7'; k[i+1][j+1]='7';

                                                    k[i-1][j]='N'; k[i-2][j]='N'; k[i+2][j]='N';
                                                    k[i+3][j]='N';k[i+4][j]='N'; k[i+5][j]='N';
                                                    pozit++;
                                                    }}

                                               if (color==10){
                                                   if ((k[i-2][j-1]=='N')&&(k[i-1][j-1]=='N')&&(k[i-2][j]=='N')&&
                                                    (k[i-1][j]=='N'))

                                                    {k[i-2][j-1]='8'; k[i-1][j-1]='8'; k[i-2][j]='8';
                                                    k[i-1][j]='8';


                                                    k[i+2][j]='N'; k[i+3][j]='N'; k[i-2][j+1]='N';
                                                    k[i-1][j+1]='N';
                                                    pozit++;
                                                    }}

                                               if (color==12){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i-2][j+1]=='N')&&
                                                    (k[i-1][j+1]=='N'))

                                                    {k[i][j-1]='0'; k[i+1][j-1]='0'; k[i-2][j+1]='0';
                                                    k[i-1][j+1]='0';


                                                    k[i][j+1]='N'; k[i+1][j+1]='N'; k[i+2][j+1]='N';
                                                    k[i+3][j+1]='N';
                                                    pozit++;
                                                    }}

                                               if (color==5){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i-2][j-1]=='N')&&(k[i-1][j-1]=='N'))

                                                    {k[i][j-1]='5'; k[i+1][j-1]='5'; k[i][j+1]='5';
                                                    k[i+1][j+1]='5'; k[i-2][j-1]='5'; k[i-1][j-1]='5';


                                                    k[i-2][j]='N'; k[i-1][j]='N'; k[i+2][j]='N';
                                                    k[i+3][j]='N'; k[i-1][j+1]='N'; k[i-2][j+1]='N';
                                                    pozit++;
                                                    }}
                                                break;}

                                        if (pozit==2){
                                               if (color==1){
                                                   if ((k[i-1][j-1]=='N')&&(k[i-2][j-1]=='N')&&(k[i-1][j]=='N')&&
                                                    (k[i-2][j]=='N')&&(k[i+2][j]=='N')&&(k[i+3][j]=='N'))

                                                    {k[i-1][j-1]='1'; k[i-2][j-1]='1'; k[i-1][j]='1';
                                                    k[i-2][j]='1'; k[i+2][j]='1'; k[i+3][j]='1';


                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i][j+1]='N';
                                                    k[i+1][j+1]='N'; k[i-2][j+1]='N'; k[i-1][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==13){
                                                    if ((k[i-2][j-1]=='N')&&(k[i-1][j-1]=='N')&&(k[i][j-1]=='N')&&
                                                    (k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&(k[i+1][j+1]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N'))

                                                    {k[i-2][j-1]='9'; k[i-1][j-1]='9'; k[i][j-1]='9';
                                                    k[i+1][j-1]='9'; k[i][j+1]='9'; k[i+1][j+1]='9'; k[i+2][j+1]='9'; k[i+3][j+1]='9';

                                                    k[i-2][j+1]='N'; k[i-1][j+1]='N'; k[i-2][j]='N';
                                                    k[i-1][j]='N'; k[i+2][j]='N'; k[i+3][j]='N';  k[i+2][j-1]='N'; k[i+3][j-1]='N';
                                                    pozit--;
                                                    }}

                                                if (color==11){
                                                    if ((k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N'))

                                                    { k[i+2][j]='3';
                                                    k[i+3][j]='3';


                                                    k[i][j+1]='N'; k[i+1][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==2){
                                                    if ((k[i+3][j-1]=='N')&&(k[i+4][j-1]=='N')&&(k[i+3][j]=='N')&&
                                                    (k[i+4][j]=='N'))

                                                    {k[i+3][j-1]='2'; k[i+4][j-1]='2'; k[i+3][j]='2';
                                                    k[i+4][j]='2';


                                                    k[i-1][j+1]='N'; k[i][j+1]='N'; k[i+1][j+1]='N';
                                                    k[i+2][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==9){
                                                    if ((k[i-4][j]=='N')&&(k[i-3][j]=='N')&&
                                                    (k[i-2][j]=='N')&&
                                                    (k[i-1][j]=='N')&&(k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N'))

                                                    {k[i-1][j]='7'; k[i-2][j]='7'; k[i-3][j]='7';
                                                    k[i-4][j]='7'; k[i+2][j]='7'; k[i+3][j]='7';

                                                    k[i][j-2]='N'; k[i+1][j-2]='N';
                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i][j+1]='N'; k[i+1][j+1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==10){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i+2][j-1]=='N')&&
                                                    (k[i+3][j-1]=='N'))

                                                    {k[i][j-1]='8'; k[i+1][j-1]='8'; k[i+2][j-1]='8';
                                                    k[i+3][j-1]='8';

                                                    k[i-2][j-1]='N'; k[i-1][j-1]='N'; k[i+1][j+1]='N';
                                                    k[i][j+1]='N';
                                                    pozit++;
                                                    }}
                                                if (color==12){
                                                    if ((k[i-1][j-1]=='N')&&(k[i-2][j-1]=='N')&&(k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N'))

                                                    {k[i-1][j-1]='0'; k[i-2][j-1]='0'; k[i+2][j]='0';
                                                    k[i+3][j]='0';

                                                    k[i-2][j]='N'; k[i-1][j]='N'; k[i-2][j+1]='N';
                                                    k[i-1][j+1]='N';
                                                    pozit++;
                                                    }}
                                                if (color==5){
                                                    if ((k[i-2][j]=='N')&&(k[i-1][j]=='N')&&(k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N')&&(k[i+2][j-1]=='N')&&(k[i+3][j-1]=='N'))

                                                    {k[i-2][j]='5'; k[i-1][j]='5'; k[i+2][j]='5';
                                                    k[i+3][j]='5'; k[i+2][j-1]='5'; k[i+3][j-1]='5';

                                                    k[i-2][j-1]='N'; k[i-1][j-1]='N'; k[i][j-1]='N';
                                                    k[i+1][j-1]='N'; k[i][j+1]='N'; k[i+1][j+1]='N';
                                                    pozit++;
                                                    }}
                                                break;}

                                        if (pozit==3){
                                                if (color==1){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i+2][j-1]=='N')&&(k[i+3][j-1]=='N'))

                                                    {k[i][j-1]='1'; k[i+1][j-1]='1'; k[i][j+1]='1';
                                                    k[i+1][j+1]='1'; k[i+2][j-1]='1'; k[i+3][j-1]='1';


                                                    k[i-1][j-1]='N'; k[i-2][j-1]='N'; k[i-1][j]='N';
                                                    k[i-2][j]='N'; k[i+2][j]='N'; k[i+3][j]='N';
                                                    pozit++;
                                                    }}

                                                if (color==2){
                                                    if ((k[i+1][j+1]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N')&&
                                                    (k[i+4][j+1]=='N'))

                                                    {k[i+1][j+1]='2'; k[i+2][j+1]='2'; k[i+3][j+1]='2';
                                                    k[i+4][j+1]='2'; k[i+3][j]='V';

                                                    k[i-1][j-1]='N'; k[i][j-1]='N'; k[i-1][j]='N';
                                                    k[i][j]='N';
                                                    pozit++;
                                                    }}

                                                if (color==11){
                                                    if ((k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N'))

                                                    { k[i][j+1]='3';
                                                    k[i+1][j+1]='3';


                                                    k[i-1][j]='N'; k[i-2][j]='N';
                                                    pozit++;
                                                    }}

                                                if (color==10){
                                                    if ((k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N'))

                                                    { k[i+2][j]='8';
                                                    k[i+3][j]='8'; k[i+2][j+1]='8'; k[i+3][j+1]='8';


                                                    k[i-2][j]='N'; k[i-1][j]='N'; k[i+2][j-1]='N';
                                                    k[i+3][j-1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==9){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&
                                                    (k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i][j+2]=='N')&&
                                                    (k[i+1][j+2]=='N'))

                                                    {k[i][j-1]='7'; k[i+1][j-1]='7'; k[i][j+1]='7';
                                                    k[i+1][j+1]='7'; k[i][j+2]='7'; k[i+1][j+2]='7';

                                                    k[i-1][j]='N'; k[i-2][j]='N'; k[i-3][j]='N';
                                                    k[i-4][j]='N'; k[i+2][j]='N'; k[i+3][j]='N';
                                                    pozit++;
                                                    }}

                                                if (color==12){
                                                    if ((k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i+2][j-1]=='N')&&(k[i+3][j+-1]=='N'))

                                                    { k[i][j+1]='0';
                                                    k[i+1][j+1]='0'; k[i+2][j-1]='0'; k[i+3][j-1]='0';


                                                    k[i-2][j-1]='N'; k[i-1][j-1]='N'; k[i][j-1]='N';
                                                    k[i+1][j-1]='N';
                                                    pozit++;
                                                    }}

                                                if (color==5){
                                                    if ((k[i][j-1]=='N')&&(k[i+1][j-1]=='N')&&(k[i][j+1]=='N')&&
                                                    (k[i+1][j+1]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N'))

                                                    {k[i][j-1]='5'; k[i+1][j-1]='5'; k[i][j+1]='5';
                                                    k[i+1][j+1]='5'; k[i+2][j+1]='5'; k[i+3][j+1]='5';

                                                    k[i-2][j]='N'; k[i-1][j]='N'; k[i+2][j]='N';
                                                    k[i+3][j]='N'; k[i+2][j-1]='N'; k[i+3][j-1]='N';
                                                    pozit++;
                                                    }}
                                                break;}

                                        if (pozit==4){ /*последняя позиция после выполнения, позиция 4 переходит в 1*/
                                                if (color==1){
                                                    if ((k[i-1][j]=='N')&&(k[i-2][j]=='N')&&(k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N'))

                                                    {k[i-1][j]='1'; k[i-2][j]='1'; k[i+2][j]='1';
                                                    k[i+3][j]='1'; k[i+2][j+1]='1'; k[i+3][j+1]='1';


                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i][j+1]='N';
                                                    k[i+1][j+1]='N'; k[i+2][j-1]='N'; k[i+3][j-1]='N';
                                                    pozit=pozit-3; /* позиция 4 переходит в 1-ую изначальную позицию*/
                                                    }}

                                                if (color==2){
                                                    if ((k[i-4][j]=='N')&&(k[i-3][j]=='N')&&(k[i-4][j+1]=='N')&&
                                                    (k[i-3][j+1]=='N'))

                                                    {k[i-4][j]='2'; k[i-4][j+1]='2';
                                                    k[i-3][j+1]='2'; k[i-3][j]='V'; k[i][j]='2';

                                                    k[i-2][j-1]='N'; k[i-1][j-1]='N'; k[i][j-1]='N';
                                                    k[i+1][j-1]='N';
                                                    pozit=pozit-3;
                                                    }}

                                                if (color==11){
                                                    if ((k[i-1][j]=='N')&&
                                                    (k[i-2][j]=='N'))

                                                    { k[i-1][j]='3';
                                                    k[i-2][j]='3';


                                                    k[i][j-1]='N'; k[i+1][j-1]='N';
                                                    pozit=pozit-3;
                                                    }}

                                                if (color==10){
                                                    if ((k[i-2][j+1]=='N')&&
                                                    (k[i-1][j+1]=='N')&&(k[i][j+1]=='N')&&(k[i+1][j+1]=='N'))

                                                    { k[i-2][j+1]='8';
                                                    k[i-1][j+1]='8'; k[i][j+1]='8'; k[i+1][j+1]='8';


                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i+2][j+1]='N';
                                                    k[i+3][j+1]='N';
                                                    pozit=pozit-3;
                                                    }}

                                                if (color==9){
                                                    if ((k[i-2][j]=='N')&&(k[i-1][j]=='N')&&
                                                    (k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N')&&(k[i+4][j]=='N')&&
                                                    (k[i+5][j]=='N'))

                                                    {k[i-2][j]='7'; k[i-1][j]='7'; k[i+2][j]='7'; k[i+3][j]='7';
                                                    k[i+4][j]='7'; k[i+5][j]='7';

                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i][j+1]='N';
                                                    k[i+1][j+1]='N'; k[i][j+2]='N'; k[i+1][j+2]='N';
                                                    pozit=pozit-3;
                                                    }}

                                                if (color==12){
                                                    if ((k[i-2][j]=='N')&&
                                                    (k[i-1][j]=='N')&&(k[i+2][j+1]=='N')&&(k[i+3][j+1]=='N'))

                                                    { k[i-2][j]='0';
                                                    k[i-1][j]='0'; k[i+2][j+1]='0'; k[i+3][j+1]='0';


                                                    k[i+2][j-1]='N'; k[i+3][j-1]='N'; k[i+2][j]='N';
                                                    k[i+3][j]='N';
                                                    pozit=pozit-3;
                                                    }}

                                                if (color==5){
                                                    if ((k[i-2][j]=='N')&&(k[i-1][j]=='N')&&(k[i+2][j]=='N')&&
                                                    (k[i+3][j]=='N')&&(k[i-2][j+1]=='N')&&(k[i-1][j+1]=='N'))

                                                    {k[i-2][j]='5'; k[i-1][j]='5'; k[i+2][j]='5';
                                                    k[i+3][j]='5'; k[i-2][j+1]='5'; k[i-1][j+1]='5';

                                                    k[i][j-1]='N'; k[i+1][j-1]='N'; k[i][j+1]='N';
                                                    k[i+1][j+1]='N'; k[i+2][j+1]='N'; k[i+3][j+1]='N';
                                                    pozit=pozit-3;
                                                    }}
                                    break;}
                                }
                            }
                        }
                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);
                f=0;
                for (j = 2; j < 22; ++j){ /*распечатать стакан после выполненного переворота*/
        for (i = 1; i < 21; ++i){
           display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }break;}

                case ' ':{ /*то же самое что и в case 's':, но выполняется сразу до конца*/
                f=0;
                while((f==0)&&(dop!=0)){
                for (j = 22; j > -1; --j){
                    for (i = 0; i < 22; ++i){
                             if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||
                                 (k[i][j]=='0')||(k[i][j]=='V'))&&((k[i][j+1]=='Q')||
                                (k[i][j+1]=='W')||(k[i][j+1]=='E')||
                               (k[i][j+1]=='R')||(k[i][j+1]=='T')||(k[i][j+1]=='Y')||
                               (k[i][j+1]=='U')||(k[i][j+1]=='I')||(k[i][j+1]=='L')||(k[i][j+1]=='P'))){f++;}}}

                            if (f==0){
                 for (j = 22; j > -1; --j){
                    for (i = 0; i < 22; ++i){
                            if(((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||(k[i][j]=='0')||
                                (k[i][j]=='V'))&&((k[i][j+1]!='Q')||(k[i][j+1]!='W')||
                                (k[i][j+1]!='E')||
                               (k[i][j+1]!='R')||(k[i][j+1]!='T')||(k[i][j+1]!='Y')||
                               (k[i][j+1]!='U')||(k[i][j+1]!='I')||(k[i][j+1]!='L')||(k[i][j+1]!='P'))){k[i][j+1]=k[i][j]; k[i][j]='N';}}}


                        }}


                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);

                f=0;
                for (j = 2; j < 22; ++j){
        for (i = 1; i < 21; ++i){
           display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }break;}
            }
        }

            if (difftime(tmp2,tmp1) > 400) { /*если разница времени больше 400*/
                    tmp1=tmp2;}
        position.X = 0+n;
        position.Y = 0+m;
        SetConsoleCursorPosition(hConsole, position);
        tmp2=clock();
        if (difftime(tmp2,tmp1) >= 400){
            position.X = 30+n;
            position.Y = 3+m;
            SetConsoleCursorPosition(hConsole, position);
            tmp1=tmp2;
            /*printf("%5d", (tmp2-tmpf)/400);*/ /*<-снять стрелки при разработке программы*/
            if (tmp2==tmp1){
                f=0;
                for (j = 22; j >= 0; --j){ /*проверка падает ли блок или уже упал блок*/
                    for (i = 1; i < 21; ++i){
                        if((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||(k[i][j]=='0')||(k[i][j]=='V')){
                            if ((k[i][j+1]=='Q')||(k[i][j+1]=='W')||(k[i][j+1]=='E')||
                               (k[i][j+1]=='R')||(k[i][j+1]=='T')||(k[i][j+1]=='Y')||
                               (k[i][j+1]=='U')||(k[i][j+1]=='I')||(k[i][j+1]=='L')||(k[i][j+1]=='P')){
                                f++;}
                        }
                    }
                }



                if(f==0){ /*если деталь не упал, то автоматически падает на один блок ниже*/
                    for (j = 22; j >= 0; --j){
                        for (i = 1; i < 21; ++i){
                            if((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||(k[i][j]=='0')||(k[i][j]=='V')){
                                k[i][j+1]=k[i][j];
                                k[i][j]='N';
                            }
                        }
                    }
                }
                else{
                    for (j = 22; j >= 0; --j){/*если деталь упал, то его активные символы превращаются в буквы - неактивные символы*/
                        for (i = 1; i < 21; ++i){
                            if(k[i][j]=='1') k[i][j]='Q';
                            if(k[i][j]=='2') k[i][j]='W';
                            if(k[i][j]=='3') k[i][j]='E';
                            if(k[i][j]=='4') k[i][j]='R';
                            if(k[i][j]=='5') k[i][j]='T';
                            if(k[i][j]=='6') k[i][j]='Y';
                            if(k[i][j]=='7') k[i][j]='U';
                            if(k[i][j]=='8') k[i][j]='I';
                            if(k[i][j]=='9') k[i][j]='L';
                            if(k[i][j]=='0') k[i][j]='P';
                            while (k[i][j]=='V'){ /* символ V - исключение для поворота деталей. для V есть свое особое условие превращения.*/
                                    if (color==1) k[i][j]='Q';
                                    if (color==2) k[i][j]='W';
                                    if (color==11) k[i][j]='E';
                                    if (color==4) k[i][j]='R';
                                    if (color==5) k[i][j]='T';
                                    if (color==14) k[i][j]='Y';
                                    if (color==9) k[i][j]='U';
                                    if (color==10) k[i][j]='I';
                                    if (color==13) k[i][j]='L';
                                    if (color==12) k[i][j]='P';
                                }

                            }
                        }
                    }

                position.X = 4+n;
                position.Y = 0+m;
                SetConsoleCursorPosition(hConsole, position);

                f=0;
                for (j = 2; j < 22; ++j){ /*распечатать стакан*/
        for (i = 1; i < 21; ++i){
           display(k[i][j],color);
        }
    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
    f++;
    position.X = 4+n;
    position.Y = m+f;
    SetConsoleCursorPosition(hConsole, position);
    }





                f=0; /*есть ли активные блоки*/
                for (j = 22; j >= 0; --j){
                    for (i = 1; i < 21; ++i){
                        if((k[i][j]=='1')||(k[i][j]=='2')||(k[i][j]=='3')||
                               (k[i][j]=='4')||(k[i][j]=='5')||(k[i][j]=='6')||
                               (k[i][j]=='7')||(k[i][j]=='8')||(k[i][j]=='9')||(k[i][j]=='0')||(k[i][j]=='V')) f++;
                    }
                }
                int proverka=0;  int jp;
                if(f==0){ /*если активных блоков нет - то проверим, есть ли заполненая строка*/

                    for (j = 2; j < 23; ++j){
                            if (proverka>=20){
                                    ball=ball+100; /*если заполнена, то начислим баллы*/

                                for (jp = j-1; jp >= 1; --jp){ /*удаление заполненного строки и смещения деталей сверху вниз*/
                                    for (i = 1; i < 21; ++i){
                                        k[i][jp]=k[i][jp-1];}
                                        } } proverka=0;
                    for (i = 1; i < 21; ++i){
                        if (k[i][j]!='N'){ proverka++; }
                    }}

                        ball=ball+dop; /*начисление баллов за размещенный деталь*/
                position.X = 40+n;
        position.Y = 10+m;
        SetConsoleCursorPosition(hConsole, position);
        SetConsoleCursorPosition(hConsole, position);
        printf("ball: %d", ball); /*отобразить балл*/
        position.X = 4+n;
        position.Y = 0+m;
        SetConsoleCursorPosition(hConsole, position);
        srand(time(NULL));  /*создать рандомное число*/
            color = rand( )%31;
                if ((color == 6)||(color == 17)||(color == 24)) {color=1;}
                if ((color == 7)||(color == 18)||(color == 25)) {color=12;}
                if ((color == 8)||(color == 19)||(color == 26)) {color=11;}
                if ((color == 0)||(color == 20)||(color == 27)) {color=9;}
                if ((color == 3)||(color == 21)||(color == 28)) {color=10;}
                if ((color == 15)||(color == 23)||(color == 29)) {color=5;}
                if ((color == 16)||(color == 22)||(color == 30)) {color=14;}
                while (color1==color){color=rand()%31;} /*если цвет совпадает с прошлым, то смешать еще раз*/
                color1=color;
                int pos_x=0;
                while (((pos_x % 2) == 0 )||((pos_x<4)||(pos_x>=15))){pos_x=rand()%14;} /*место размещения блока рандомна*/
                if ((color == 6)||(color == 17)||(color == 24)) {color=1;}
                if ((color == 7)||(color == 18)||(color == 25)) {color=12;}
                if ((color == 8)||(color == 19)||(color == 26)) {color=11;}
                if ((color == 0)||(color == 20)||(color == 27)) {color=9;}
                if ((color == 3)||(color == 21)||(color == 28)) {color=10;}
                if ((color == 15)||(color == 23)||(color == 29)) {color=5;}
                if ((color == 16)||(color == 22)||(color == 30)) {color=14;}

                        if (color==1){ pozit=1; /*выставить блок исходя из номера цвета*/
                    k[pos_x][0]='1';
                    k[pos_x+1][0]='1';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='1';
                    k[pos_x+4][0]='1';
                    k[pos_x+5][0]='1';
                    k[pos_x+4][1]='1';
                    k[pos_x+5][1]='1';
                    dop=4;

                }
                        if (color==2){ pozit=1;
                    k[pos_x][0]='2';
                    k[pos_x+1][0]='V';
                    k[pos_x+2][1]='2';
                    k[pos_x+3][1]='2';
                    k[pos_x+4][0]='2';
                    k[pos_x+5][0]='2';
                    k[pos_x+4][1]='2';
                    k[pos_x+5][1]='2';
                    k[pos_x][1]='2';
                    k[pos_x+1][1]='2';
                    dop=5;
                }
                if (color==11){ pozit=1;
                    k[pos_x][0]='3';
                    k[pos_x+1][0]='3';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='3';
                    k[pos_x+4][0]='3';
                    k[pos_x+5][0]='3';
                    k[pos_x+2][1]='3';
                    k[pos_x+3][1]='3';
                    dop=4;
                }

                        if (color==4){

                    k[pos_x+2][0]='4';
                    k[pos_x+3][0]='4';
                    k[pos_x+2][1]='4';
                    k[pos_x+3][1]='4';
                    k[pos_x+2][2]='4';
                    k[pos_x+3][2]='4';
                    k[pos_x][1]='4';
                    k[pos_x+1][1]='4';
                    k[pos_x+4][1]='4';
                    k[pos_x+5][1]='4';
                    dop=5;
                }
                if (color==5){  pozit=1;
                    k[pos_x][0]='5';
                    k[pos_x+1][0]='5';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='5';
                    k[pos_x+4][0]='5';
                    k[pos_x+5][0]='5';
                    k[pos_x][1]='5';
                    k[pos_x+1][1]='5';
                    dop=4;
                }
                if (color==14){
                    k[pos_x][0]='6';
                    k[pos_x+1][0]='6';
                    k[pos_x+2][0]='6';
                    k[pos_x+3][0]='6';
                    k[pos_x][1]='6';
                    k[pos_x+1][1]='6';
                    k[pos_x+2][1]='6';
                    k[pos_x+3][1]='6';
                    dop=4;
                    }

                    if (color==9){ pozit=1;
                    k[pos_x][0]='7';
                    k[pos_x+1][0]='7';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='7';
                    k[pos_x+4][0]='7';
                    k[pos_x+5][0]='7';
                    k[pos_x+6][0]='7';
                    k[pos_x+7][0]='7';
                    dop=4;
                    }

                    if (color==10){pozit=1;

                    k[pos_x][1]='8';
                    k[pos_x+1][1]='8';
                    k[pos_x+2][1]='8';
                    k[pos_x+3][1]='8';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='8';
                    k[pos_x+4][0]='8';
                    k[pos_x+5][0]='8';
                    dop=4;
                }
                if (color==13){ pozit=1;
                    k[pos_x][0]='9';
                    k[pos_x+1][0]='9';
                    k[pos_x+2][0]='9';
                    k[pos_x+3][0]='9';
                    k[pos_x+2][1]='V';
                    k[pos_x+3][1]='9';
                    k[pos_x+2][2]='9';
                    k[pos_x+3][2]='9';
                    k[pos_x+4][2]='9';
                    k[pos_x+5][2]='9';
                    dop=5;
                }
                if (color==12){ pozit=1;
                    k[pos_x][0]='0';
                    k[pos_x+1][0]='0';
                    k[pos_x+2][0]='V';
                    k[pos_x+3][0]='0';
                    k[pos_x+2][1]='0';
                    k[pos_x+3][1]='0';
                    k[pos_x+4][1]='0';
                    k[pos_x+5][1]='0';
                    dop=4;
                }
            }

                for(i=1;i<21;i++){ /*если последняя строка заполнена*/
                   if ((k[i][2]=='Q')||(k[i][2]=='W')||(k[i][2]=='E')||
                               (k[i][2]=='R')||(k[i][2]=='T')||(k[i][2]=='Y')||
                               (k[i][2]=='U')||(k[i][2]=='I')||(k[i][2]=='L')||(k[i][2]=='P')){

                                   position.X = 30+n;
                                    position.Y = 8+m;

                                    SetConsoleCursorPosition(hConsole, position);
                                    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 14));
                                   printf("GAME OVER"); /*объявить игру оконченным*/
                                    int z;
                                    char name[21];
                                    FILE *file;

                                    if ((file = fopen("TetriS.txt","a")) == NULL)
                                            printf("Error! No memory!\n");
                                            else{
                                    position.X = 25+n;
                                    position.Y = 12+m;

                                    SetConsoleCursorPosition(hConsole, position);
                                    SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 14));
                                    printf ("You name(English, 20 symbol ):"); /*попросить ввести свое симя*/
                                                gets(name);
                                                fprintf(file,"%s - %d\n", name, ball); /*запись имени и балла*/

     }
     fclose(file); /*закрыть файл*/



    for (z=m; z<50+m;z++){
            position.X = n;
            position.Y = z;
            SetConsoleCursorPosition(hConsole, position);
            SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 1));
        printf("                                                                                         ");
    } /*стереть отображение стакана*/
 main(); /*вернуться к главному меню*/




                    }
                }
            }
        }
    }
}
