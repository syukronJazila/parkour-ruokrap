#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

main(){
    int i = 0, n = 30,r;
    string arr[n],arr2[n];

    for (int j = 0; j < n; j++)
    {
        arr[j] = '#';
        arr2[j] = " ";
    }
    
    bool isObstacle = false;
    bool isWall = false;
    int obstacle = 0;
    int nWall = 0;
	while (true)
    {
        system("CLS");
        r = rand() % 100 + 1;
        if(obstacle >= 2 && obstacle <= 3){
            r = 50;
            obstacle++;
            if (obstacle == 4){ obstacle = 0;}
        }
        if(isObstacle && obstacle == 1){
            r = 50;
            isObstacle = false;
            obstacle = 2;
        }
        if(isWall){
            if (r % 2 == 0){
                nWall++;
            }
            // else{ kalau ingin dindingnya lebih panjang
            //     nWall--;
            // } kalau tanpa else 4 - 7 dinding
            nWall++;
            r = 87;
            if(nWall > 6){
                isWall = false;
                obstacle = 2;
                nWall = -1;
                r = 50;
            }
        }

        for (int j = n-1; j >= 0; j--)
        {
            if(j == 0){
                arr[0] = "#";
                arr2[0] = " ";
                break;
            }
            arr[j] = arr[j-1];
            arr2[j] = arr2[j-1];        
        }

        if(r > 80 ){
            isWall = true;
            arr2[0] = "#";
        }else if(r > 33){
            arr[0] = "#";
        }else{
            isObstacle = true;
            obstacle++;
            arr[0] = " ";
        }
        gotoxy(0,10);
        for(const string &a: arr2){
            cout << a;
        }
        cout << "\n";
        for(const string &a: arr){
            cout << a;
        }
        Sleep(500);
    }
    
}
