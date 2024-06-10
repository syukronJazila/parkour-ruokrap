
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void gotoxy2(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void inGame(){
    gotoxy2(0,0); cout << "--- Level 1 --- Reach the score to complete the level.\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "// Lives :  /3 | Score :    /100 | Coin :   /10 | Hostile Killed :   /15     //\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "//                                                                           //\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "---- Movement ----------------------------------Shoot -------------------------\n";
    cout << "//     W      |  (W) to jump,                -         Use the arrow         //\n";
    cout << "//            |  (A), (D) to go left & right -         keys to shoot         //\n";
    cout << "// A       D  |                              -         the hostiles.         //\n";
    cout << "-------------------------------------------------------------------------------\n";
}

class Player {
public:
    string karakter;
    int posX, posY, LposX, LposY,skor=0;
    bool jump2 = false, jump3 = false, jump4 = false, jump5 = false;

    Player(string karakter,int posX, int posY, int LposX, int LposY) {
        this->karakter = karakter;
        this->posX = posX;
        this->posY = posY;
        this->LposX = LposX;
        this->LposY = LposY;
    }


    void moveUp(string (&ground2)[73],string (&ground3)[73],string (&ground4)[73],string (&ground5)[73]) {
        int i;
        //Untuk Naik
        for (i=1; i<=3; i++){
            posY--;
            if((ground3[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 13){skor++; ground3[posX-3] = " ";}
            if((ground4[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 12){skor++; ground4[posX-3] = " ";}
            if((ground5[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 11){skor++; ground5[posX-3] = " ";}
    
            pindahPosisi();
            Sleep(115);
        }
        //Untuk turun
        for (i=1; i<=3; i++){
            // jika ada ground(bukan jurang) dibawah karakter maka hentikan turun 
            if(posY == 13 && ground2[posX-3] == "#"){break;}
            if(posY == 12 && ground3[posX-3] == "#"){break;}
            if(posY == 11 && ground4[posX-3] == "#"){break;}
            if(posY == 10 && ground5[posX-3] == "#"){break;}
            posY += 1;

            if((ground3[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 13){skor++; ground3[posX-3] = " ";}
            if((ground4[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 12){skor++; ground4[posX-3] = " ";}
            if((ground5[posX-3] == "*" || ground3[posX-1-3] == "*") && posY == 11){skor++; ground5[posX-3] = " ";}
        

            pindahPosisi();
            Sleep(100);  
            // jika turun sudah selesai dan karakter masih melayang maka turun 1 ground
            // sama seperti Fix bug melayang setelah lompat di obstacle
            if(i == 3){
                if(posY == 13 && ground2[posX-3] == " "){moveDown();}
                if(posY == 12 && ground3[posX-3] == " "){moveDown();}
                if(posY == 11 && ground4[posX-3] == " "){moveDown();}
                if(posY == 10 && ground5[posX-3] == " "){moveDown();}
            }
        }
    }

    int getKoin(){
        return skor;
    }

    void moveDown(){posY++;}

    void moveLeft() {
        if (posX > 2) {
            posX -= 1;
            pindahPosisi(); 
        }
    }

    void moveRight() {
        if (posX < 75) {  
            posX += 1;
            pindahPosisi();
        }
    }


    void pindahPosisi(){
        gotoxy2(LposX,LposY); cout << " ";  // Hapus karakter lama
        gotoxy2(posX, posY); cout << karakter;    // Cetak karakter di posisi baru
        LposX = posX;  // Simpan posisi lama
        LposY = posY;
    }

    void lompatEnemy(string (&ground2)[73],string (&ground3)[73],string (&ground4)[73],string (&ground5)[73]){
       int i;
       //Untuk Naik
       for (i=1; i<=3; i++){
           posY--; 
           posX++;
           pindahPosisi();
           Sleep(115);
    }
    moveRight();
    moveRight();
        
        //Untuk turun
        for (i=1; i<=3; i++){
            posY++;
            pindahPosisi();
            Sleep(100);  
            if(posY == 13 && ground2[posX-3] == "#"){break;}
            if(posY == 12 && ground3[posX-3] == "#"){break;}
            if(posY == 11 && ground4[posX-3] == "#"){break;}
            if(posY == 10 && ground5[posX-3] == "#"){break;}
            // jika turun sudah selesai dan karakter masih melayang maka turun 1 ground
            // sama seperti Fix bug melayang setelah lompat di obstacle
            if(i == 3){
                if(posY == 13 && ground2[posX] == " "){posY++;}
                if(posY == 12 && ground3[posX] == " "){posY++;}
                if(posY == 11 && ground4[posX] == " "){posY++;}
                if(posY == 10 && ground5[posX] == " "){posY++;}
            }
        }
    }

};
