// TETRA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
//#include <conio.h> 
#include <ctime>

class Screen {
public:
    int score = 0;
    char OutLine[1000] = "", OutLine1[1000] = "", OutLine2[1000] = "";
    int Cash[20][10] = { {0,0,0,0,0,0,0,0,0,0},  //экран
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
    };

   void  Draw() {
       printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF  Score:%d\n",score);
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (Cash[i][j] > 0) {
                    strcat_s(OutLine, "\xC9\xCD\xCD\xCD\xBB");
                    strcat_s(OutLine1, "\xBA\xB0\xB0\xB0\xBA");
                    strcat_s(OutLine2, "\xC8\xCD\xCD\xCD\xBC");
                }
                else {
                    strcat_s(OutLine, "     ");
                    strcat_s(OutLine1, "     ");
                    strcat_s(OutLine2, "     ");
                }
            }
            printf("\xB3%s\xB3\n\xB3%s\xB3\n\xB3%s\xB3\n", OutLine, OutLine1, OutLine2);

            OutLine[0] = 0; OutLine1[0] = 0; OutLine2[0] = 0;
        }
        printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
    }

   void SetFig(int mass[4][2]) {

       for (int i = 0; i < 4; i++)
       {
           Cash[mass[i][1]][mass[i][0]] = 1;
           
       }
       
   }
   
   void DeleteFig(int mass[4][2]) {
       for (int i = 0; i < 4; i++)
       {
           Cash[mass[i][1]][mass[i][0]] = 0;
           
       }
   }

   void MoveFig(int mass[4][2], int dx = 0, int dy = 0) {
       int massiv2[4][2];

       //границы
       for (int i = 0; i < 4; i++) {
           if (mass[i][0] + dx >= 10 || mass[i][0] + dx < 0 ) {
               return;
           }
           if (mass[i][1] + dy >= 20 ) {
               return;
           }
       }

       //Если не вышел то пробуем удалить
       DeleteFig(mass);
       //проверяем есть ли  на новых координатах место
       for (int i = 0; i < 4; i++) {
          
               if (Cash[mass[i][1]+dy][mass[i][0]+dx] == 1 ) {
                   SetFig(mass);
                   return;
               }
           
       }

       //Ставим новые координаты
       for (int i = 0; i < 4; i++)
       {

           
           mass[i][0] = dx + mass[i][0];
           mass[i][1] = dy + mass[i][1];

       }
       
       //Рисуем
       SetFig(mass);
   }


   bool MoveDown(int mass[4][2]) {
       DeleteFig(mass);
       //границы
       for (int i = 0; i < 4; i++) {
           if (mass[i][1] + 1 >= 20) {
               SetFig(mass);
               return false;
           }
           else if (Cash[mass[i][1]+1][mass[i][0]] == 1) {
               SetFig(mass);
               return false;
           }
       }
       SetFig(mass);
       return true;
   }
   
   void Rotaite(int mass[4][2]) {
       DeleteFig(mass);
       int RotateX = mass[1][0]; // указываем центр вращения для X
       int RotateY = mass[1][1]; // указываем центр вращения для Y



       for (int i = 0; i < 4; i++)
       {
           int x = mass[i][1] - RotateY; // y - y0
           int y = mass[i][0] - RotateX; // x - x0
           if (Cash[RotateY + y][RotateX - x] == 1) {
               SetFig(mass);
               return;
           }
           //границы
           for (int i = 0; i < 4; i++) {
               if (RotateX - x >= 10 || RotateX - x < 0) {
                   return;
               }
               if (RotateY + y >= 20) {
                   return;
               }
           }
       }

       for (int i = 0; i < 4; i++)
       {
           int x = mass[i][1] - RotateY; // y - y0
           int y = mass[i][0] - RotateX; // x - x0
           mass[i][1] = RotateY + y;
           mass[i][0] = RotateX - x;
       }
   }

   bool CheckLine(int mass[4][2]) {

       for (int i = 0; i < 4;i++) {
           if (Cash[mass[i][1]][mass[i][0]]==1) {
               return false;
           }
       }


       int lineF = 0;

       for (int i = 0; i < 20; i++) {
           lineF = 0;

           for (int j = 0; j < 10; j++) {
               if (Cash[i][j] == 1) {
                   lineF += 1;
               }
           }

           if (lineF==10) {
               score += 100;
               for (int g = 0; g < 10;g++) { //занулили линию
                   Cash[i][g] = 1;
               }

               for (int a = i; a > 1;a--) { //смещаем на 1
                   for (int f = 0; f < 10; f++) {
                       Cash[a][f] = Cash[a - 1][f];
                       Cash[a - 1][f] = 0;
                   }
               }

           }

       }

       return true;
   }


   bool EndGame() {
         
               for (int i = 0; i < 20;i++) {
                   for (int j = 0; j < 10;j++) {
                       Cash[i][j] = 0;
                   }
               }
               system("cls");
               int i = 6;
               while (i>0) {
                   printf("\n");
                   i--;
               }
               printf("        GAME OVER\n");
               printf("        SCORE: %d", score);
               Sleep(4000);
               score = 0;
               system("cls");
       return true;
   }
};

class Figura {
    int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // S
        3,5,4,6, // Z
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };

    
public:
    void NewFig(int massi[4][2]) {
        int n = rand() % 7;
        for (int i = 0; i < 4; i++)
        {   
           
            massi[i][0] = 3 + figures[n][i] % 2;
            massi[i][1] = -1 + figures[n][i] / 2;
        }



    }
};

class GameLogic{
    int dx=0, dy = 0;
    Screen* scn = new Screen;
    Figura* figura = new Figura;
    int massi[4][2] = { 0 };
    int start = 0;

public:

    GameLogic() {
        figura->NewFig(massi);//создаем новую фигуру
        start = clock();
    }

   bool Game() {
       while (1) {
           if (GetAsyncKeyState(VK_LEFT)) { dx += -1; }
           if (GetAsyncKeyState(VK_RIGHT)) { dx += 1; }
           if (GetAsyncKeyState(VK_DOWN)) { dy += 1; }
           if (GetAsyncKeyState(VK_UP)) { scn->Rotaite(massi); }
           scn->MoveFig(massi, dx, dy);
           scn->Draw();
           Sleep(10);
           system("cls");
           dx = 0;
           dy = 0;
           //
          


           if (!scn->MoveDown(massi) && (clock() - start) >= 500) {
               figura->NewFig(massi);
               
               if (!scn->CheckLine(massi)) {
                   scn->EndGame();
               }
           }

           if ((clock() - start) >= 500) {

               start = clock();
               scn->MoveFig(massi, dx, dy + 1);
           }

           if (GetAsyncKeyState(VK_ESCAPE)) {
               return false;
           }

       }
    }
};

int main()
{
    /*int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // S
        3,5,4,6, // Z
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };
    int x=2, y = -2, dx=0,dy=0;
    int n = 4; // задаем тип тетрамино
    int massi[4][2] = { 0 }; //0-x 1-y
    //Переводим в обычные координаты
    for (int i = 0; i < 4; i++)
    {
        massi[i][0] = x+figures[n][i] % 2;
        massi[i][1] = y+figures[n][i] / 2;
    }

    std::cout << "Hello World!\n";
    Screen *scn = new Screen;
    GameLogic *game = new GameLogic();
    Figura* figura = new Figura;
    figura->NewFig(massi);
    */

    GameLogic* game = new GameLogic();
    game->Game();
    //while (1) {
        
       // !game->Game();
        
        /*
        if (GetAsyncKeyState(VK_LEFT)) { dx+= -1; }
        if (GetAsyncKeyState(VK_RIGHT)) { dx += 1; }
        if (GetAsyncKeyState(VK_DOWN)) { dy += 1; }
        if (GetAsyncKeyState(VK_UP)) { scn->Rotaite(massi); }


        scn->MoveFig(massi, dx, dy+1);
        scn->Draw();
        Sleep(10);
        system("cls");
        dx = 0;
        dy = 0;
       
        if (!scn->MoveDown(massi)) {
            x = 2; y = -2;
            n = rand() % 7;
            figura->NewFig(massi);
            //Переводим в обычные координаты
           // for (int i = 0; i < 4; i++)
          //  {
          //      massi[i][0] = x + figures[n][i] % 2;
          //      massi[i][1] = y + figures[n][i] / 2;
           // }

            if (!scn->CheckLine(massi)) {
                scn->EndGame();
            }
        }
        */
        
   // }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
