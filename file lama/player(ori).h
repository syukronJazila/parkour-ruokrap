#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;  
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Player {
public:
    string karakter;
    int posX, posY, LposX, LposY;
    bool jump2 = false, jump3 = false, jump4 = false, jump5 = false;

    Player(string karakter,int posX, int posY, int LposX, int LposY) {
        this->karakter = karakter;
        this->posX = posX;
        this->posY = posY;
        this->LposX = LposX;
        this->LposY = LposY;
    }


    void moveUp(string ground2[50],string ground3[50],string ground4[50],string ground5[50]) {
        int i;
        //Untuk Naik
        for (i=1; i<=3; i++){
            posY--;
            pindahPosisi();
            Sleep(115);
        }
        //Untuk turun
        for (i=1; i<=3; i++){
            // jika ada ground(bukan jurang) dibawah karakter maka hentikan turun 
            if(posY == 9 && ground2[posX] == "#"){break;}
            if(posY == 8 && ground3[posX] == "#"){break;}
            if(posY == 7 && ground4[posX] == "#"){break;}
            if(posY == 6 && ground5[posX] == "#"){break;}
            posY += 1;
            pindahPosisi();
            Sleep(100);  
            // jika turun sudah selesai dan karakter masih melayang maka turun 1 ground
            // sama seperti Fix bug melayang setelah lompat di obstacle
            if(i == 3){
                if(posY == 9 && ground2[posX] == " "){moveDown();}
                if(posY == 8 && ground3[posX] == " "){moveDown();}
                if(posY == 7 && ground4[posX] == " "){moveDown();}
                if(posY == 6 && ground5[posX] == " "){moveDown();}
            }
        }
    }

    void moveDown(){posY++;}

    void moveLeft() {
        if (posX > 0) {
            posX -= 1;
            pindahPosisi(); 
        }
    }

    void moveRight() {
        if (posX < 49) {  
            posX += 1;
            pindahPosisi();
        }
    }


    void pindahPosisi(){
        gotoxy(LposX,LposY); cout << " ";  // Hapus karakter lama
        gotoxy(posX, posY); cout << karakter;    // Cetak karakter di posisi baru
        LposX = posX;  // Simpan posisi lama
        LposY = posY;
    }


};