#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
 
using namespace std;

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
void pindahPosisi(){

	gotoxy(p1.LposX, p1.LposY); cout << " ";  // Hapus karakter lama
    gotoxy(p1.posX, p1.posY); cout << "A";    // Cetak karakter di posisi baru
    p1.LposX = p1.posX;  // Simpan posisi lama
    p1.LposY = p1.posY;
}


void cekTombol() {
    while (true) {
        bool moved = false;
		int i;
        if (sudah == true){
            //? Buat cek tombok ke atas
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                if (p1.posY > 0) {
                for (i=1; i<=3; i++){
                        //? Minus artinya naik
                        p1.posY -= 1;
                        pindahPosisi();
                        Sleep(50);
                    }
                    for (i=1; i<=3; i++){
                        p1.posY += 1;
                        pindahPosisi();
                        Sleep(50);
                    }
                }
            }
            //? Buat cek tombok ke kiri
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (p1.posX > 0) {
                    //? gerak ke kiri
                    p1.posX -= 1;
                    pindahPosisi(); 
                }
            }
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (p1.posX < 79) {  // Assuming console width is 80
                    p1.posX += 1;
                    pindahPosisi();
                }
            }
            
            //? peluru muncul klo spasi di tekan
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            //? tampilkan peluru di depan karakter
            gotoxy(p1.posX-1,p1.posY); cout << "-";
            tempPeluru.posX = p1.posX-1;
            tempPeluru.posY = p1.posY;
            tempPeluru.LposX = p1.posX-1;
            tempPeluru.LposY = p1.posY;
            //? masukkan peluru ke vektor
            peluru.push_back(tempPeluru);
            
            }

            Sleep(100);  // Menghindari penggunaan CPU yang tinggi
        }
    }
}



//? Disini ntar klo mau build tempatnya, sekalian gerakan peluru
void programLain(){
	while(true){
            int j;
            //? Kita gerakkan setiap peluru
            for (j=peluru.size()-1; j>=0; j--){
                sudah = false;
                gotoxy(peluru[j].LposX, peluru[j].LposY); cout << " ";  // Hapus karakter lama
                peluru[j].posX--;
                if (peluru[j].posX == 3) {
                    //gotoxy(a.posX, a.posY); cout << " ";
                    peluru.erase(peluru.begin() + j);
                    sudah=true;
                }else {
                    gotoxy(peluru[j].posX, peluru[j].posY); cout << "-";    // Cetak karakter di posisi baru
                    peluru[j].LposX = peluru[j].posX;  // Simpan posisi lama
                    peluru[j].LposY = peluru[j].posY;
                    sudah = true;
                }
                
            }
            Sleep(400);
	} 
}

main(){
    system("cls");
    //? pakek thread, jadi ada 2 program yg bekerja di waktu bersamaan, cekTombol() dan main() program
	thread threadPemeriksaanTombol(cekTombol);
	gotoxy(1,10); cout <<"##########################################";
	
	p1.posX = 5;
	p1.posY = 9;
	p1.LposX = 5;
	p1.LposY = 9;
	gotoxy(p1.posX,p1.posY); cout << "A";
	programLain();
}