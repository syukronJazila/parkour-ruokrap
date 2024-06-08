#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <thread>
using namespace std;

const int n = 50;
string ground1[n],ground2[n],ground3[n],ground4[n],ground5[n]; 

struct Player{
	int posX,posY,LposX,LposY;
};

struct Ammo{
    char garis;
    int posX,posY,LposX,LposY;
    // Lpos = posisi lama
    //pos = posisi skrg
};

//? dekelarasi karakter peluru, karena bnyak jadi pakek vektor
vector<Ammo> peluru;
Ammo tempPeluru;
//? deklarasi player
Player p1;
bool sudah=true;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void setGround(string a,string b,string c,string d,string e){
    ground1[0] = a; 
    ground2[0] = b; 
    ground3[0] = c; 
    ground4[0] = d; 
    ground5[0] = e; 
}

void printGround(){
    gotoxy(0,7);
    for(int j = 0; j < n; j++){
        cout << ground5[j];
    }
    gotoxy(0,8);
    for(int j = 0; j < n; j++){
        cout << ground4[j];
    }
    gotoxy(0,9);
    for(int j = 0; j < n; j++){ 
        cout << ground3[j];
    }
    gotoxy(0,10);
    for(int j = 0; j < n; j++){ 
        cout << ground2[j];
    }
    gotoxy(0,11);
    for(int j = 0; j < n; j++){ 
        cout << ground1[j];
    }
}

void shiftGround(){
    // menggeser tiap elemen ground ke kanan agar tampak seperti berjalan (sepert queue)
    for (int j = n-1; j >= 0; j--)
    {
        ground1[j] = ground1[j-1];
        ground2[j] = ground2[j-1];        
        ground3[j] = ground3[j-1];        
        ground4[j] = ground4[j-1];        
        ground5[j] = ground5[j-1];        
    }
}

void pindahPosisi(){

	gotoxy(p1.LposX, p1.LposY); cout << " ";  // Hapus karakter lama
    gotoxy(p1.posX, p1.posY); cout << "A";    // Cetak karakter di posisi baru
    p1.LposX = p1.posX;  // Simpan posisi lama
    p1.LposY = p1.posY;
}
int kiri = 0;
void cekTombol() {
    while (true) {
		int i;

            //? Buat cek tombok ke atas
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                if (p1.posY > 0) {
                for (i=1; i<=3; i++){
                        //? Minus artinya naik
                        p1.posY -= 1;
                        pindahPosisi();
                        Sleep(115);
                }
                
                    for (i=1; i<=3; i++){
                        p1.posY += 1;
                        pindahPosisi();
                        Sleep(100);  
                    }
                }
                 
            }
            // Cek tombol ke kiri
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            if (p1.posX > 0) {
                p1.posX -= 1;
                pindahPosisi();
                Sleep(100);
            }
        }
        // Cek tombol ke kanan
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            if (p1.posX < 79) {  // Asumsi lebar konsol adalah 80
                p1.posX += 1;
                pindahPosisi();
                Sleep(100);
            }
        }
            Sleep(100); 
    }
}


main(){
    thread threadPemeriksaanTombol(cekTombol);
    int i = 0,r,k=0,groundLvl=2;
    char c;
    p1.posX = 35;
	p1.posY = 10;
	p1.LposX = 35;
	p1.LposY = 10;
    gotoxy(p1.posX,p1.posY); cout << "A";
    // inisialisasi ground dengan nilai default
    for (int j = 0; j < n; j++)
    {
        ground1[j] = '#'; 
        ground2[j] = " "; 
        ground3[j] = " "; 
        ground4[j] = " "; 
        ground5[j] = " "; 
    }
    
    bool isJurang = false;
    bool isWall = false;
    int jurang = 0;
    int nWall = 0;
	while (true)
    {
        system("CLS");gotoxy(0,3); cout << "kiri = " << kiri;  
        k++;
        r = rand() % 100 + 1; // cari angka random 1 - 100

        shiftGround();

        if(jurang >= 2 && jurang <= 5){ 
         // untuk memastikan bahwa setelah muncul jurang jurang 4 tanah setelahnya 
         // tidak muncul jurang lain
            isJurang = false;
            if(r <= 33){
                r = 61;
            }
            jurang++;
            if (jurang == 6){ jurang = 0;}
        }
        if(isJurang){ // mengecek apakah muncul jurang 
            r = 14; // jika iya maka buat jurang kedua
        }
        if(isWall){ 
            if(r < 15 && nWall > 4 && nWall < 11){
                goto skip;
            }
            if (r % 2 == 0){ // jika angka random genap maka banyak dinding dikurang satu
                nWall++; 
            }
            nWall++; 
            if(nWall > 13){ // batas kemunculan dinding adalah 13 (karena nWall bisa bernilai 1 - 13)
                nWall = 0;
                if((r < 50 && groundLvl > 2) || groundLvl == 5){ 
                    groundLvl--; // mengurangi level ground
                }else if(r > 60){
                    groundLvl++; // menambah level ground
                }else{ // buat jadi else if groundLvl == 2 jika hanya ingin lvl2 ke lvl 1
                    r = 34; // obstacle baru 
                    goto skip;
                }
            }
            r=51;
        }

        skip:
        if(r > 50 ){ // kalau angka random 50 - 100 maka muncul dinding
            switch (groundLvl)
                {
                case 2:
                    setGround("#","#"," "," "," ");
                    break;
                case 3:
                    setGround("#","#","#"," "," ");
                    break;
                case 4:
                    setGround("#","#","#","#"," ");
                    break;
                case 5:
                    setGround("#","#","#","#","#");
                    break;

                default: 
                    break;
                }
            isWall = true;
        }else if(r > 33){ // 34 - 50 set default
            setGround("#"," "," "," "," ");
        }else{ // 0 - 33 muncul jurang 
            isJurang = true;
            jurang++;
            setGround(" "," "," "," "," ");
        }
        gotoxy(p1.posX,p1.posY); cout << "A" ;
        printGround();
        gotoxy(0,0);cout << k;
        Sleep(200);
    }
    threadPemeriksaanTombol.join();
    c = getch();
    
}
