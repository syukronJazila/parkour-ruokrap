#include <iostream>
#include <windows.h>
#include <conio.h>
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
    // arr => ground bawah (untuk tanah dan jurang), arr2 => ground atas (untuk dinding)
    // inisialisasi ground atas dan bawah
    for (int j = 0; j < n; j++)
    {
        arr[j] = '#'; // tanah
        arr2[j] = " "; // void (spasi dianggap tidak ada obstacle)
    }
    
    bool isObstacle = false;
    bool isWall = false;
    int obstacle = 0;
    int nWall = 0;
	while (true)
    {
        system("CLS");
        r = rand() % 100 + 1; // cari angka random 1 - 100

        if(obstacle >= 2 && obstacle <= 3){ 
         // untuk memastikan bahwa setelah muncul obstacle(jurang/dinding) 3 tanah setelahnya 
         // tidak muncul obstacle lain
            r = 50;
            obstacle++;
            if (obstacle == 4){ obstacle = 0;}
        }
        if(isObstacle && obstacle == 1){ // mengecek apakah muncul 2 jurang sekaligus 
            r = 50; // jika iya maka jurang kedua diganti dengan tanah
            isObstacle = false; 
            obstacle = 2; // untuk keperluan pengecekan berapa tanah yg telah muncul
        }
        if(isWall){ 
        // mengecek apakah dinding muncul, jika sudah muncul 1 dinding maka akan digenerate dinding
        // lain sebanyak 4 - 7 dinding. Banyaknya dinding yang muncul tergantung angka random yg dihasilkan
            if (r % 2 == 0){ // jika angka random genap maka banyak dinding dikurang satu
                nWall++; 
            }
            // else{ kalau ingin dindingnya lebih panjang
            //     nWall--;
            // } kalau tanpa else 4 - 7 dinding
            nWall++;
            r = 87; 
            if(nWall > 6){ // batas kemunculan dinding adalah 7 (karena nWall bisa bernilai 0 - 6)
                isWall = false;
                obstacle = 2;
                nWall = -1;
                r = 50;
            }
        }

        // menggeser tiap elemen arr dan arr2 ke kanan agar tampak seperti berjalan (sepert queue)
        for (int j = n-1; j >= 0; j--)
        {
            if(j == 0){
                arr[0] = "#"; // nilai defaulr ground bawah (# -> tanah / dinding)
                arr2[0] = " "; // nilai default ground atas (spasi -> tidak ada obstacle)
                break;
            }
            arr[j] = arr[j-1];
            arr2[j] = arr2[j-1];        
        }

        if(r > 80 ){ // kalau angka random 81 - 100 maka muncul dinding
            isWall = true;
            arr2[0] = "#";
        }else if(r > 33){ // 34 - 80 tidak akan muncul obstacle
            arr[0] = "#";
        }else{ // 0 - 33 muncul jurang 
            isObstacle = true;
            obstacle++;
            arr[0] = " ";
        }
        gotoxy(0,10);
        for(const string &a: arr2){ // mencetak ground atas
            cout << a;
        }
        cout << "\n"; 
        for(const string &a: arr){ // mencetak ground bawah
            cout << a;
        }
        Sleep(500);
    }
    
}
