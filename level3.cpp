#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "player.h"
using namespace std;

struct Ammo{
    int posX,posY,LposX,LposY;
};

Player p1("A",21,10,21,10);
vector<Player> e1;
vector<Ammo> peluru;

int skor=0;

const int n = 50;
string ground1[n],ground2[n],ground3[n],ground4[n],ground5[n]; 

int r, k, musuh, jurang, nWall, groundLvl;
bool isEnemy, isJurang, isWall;

void summonEnemy(int x,int y){
    Player tempEnemy("B",x,y,x,y);
    gotoxy(x,y); cout << tempEnemy.karakter;
    e1.push_back(tempEnemy);
}

void setDefault(){
     // inisialisasi ground dengan nilai default
    for (k = 0; k < n; k++){
        ground1[k] = '#'; 
        ground2[k] = " "; 
        ground3[k] = " "; 
        ground4[k] = " "; 
        ground5[k] = " "; 
    }
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
    for(k = 0; k < n; k++){
        cout << ground5[k];
    }
    gotoxy(0,8);
    for(k = 0; k < n; k++){
        cout << ground4[k];
    }
    gotoxy(0,9);
    for(k = 0; k < n; k++){ 
        cout << ground3[k];
    }
    gotoxy(0,10);
    for(k = 0; k < n; k++){ 
        cout << ground2[k];
    }
    gotoxy(0,11);
    for(k = 0; k < n; k++){ 
        cout << ground1[k];
    }
}

void shiftGround(){
    // menggeser tiap elemen ground ke kanan agar tampak seperti berjalan (sepert queue)
    for (k = n-1; k >= 1; k--){
        ground1[k] = ground1[k-1];
        ground2[k] = ground2[k-1];        
        ground3[k] = ground3[k-1];        
        ground4[k] = ground4[k-1];        
        ground5[k] = ground5[k-1];        
    }
}

void cekGround(){
    r = rand() % 100 + 1;
    if(jurang >= 2 && jurang <= 5){ 
     // untuk memastikan bahwa setelah muncul jurang jurang 4 tanah setelahnya tidak muncul jurang lain
        isJurang = false;
        if(r <= 33){ r = 61; }
        jurang++;
        if (jurang == 6){ jurang = 0; }
    }
    if(isJurang){ // mengecek apakah muncul jurang 
        r = 14; // jika iya maka buat jurang kedua
    }
    if(isWall){ 
        if(r < 15 && nWall > 4 && nWall < 11){ goto skip; }
        if (r % 2 == 0){ nWall++; } // jika angka random genap maka banyak dinding dikurang satu
        nWall++; 
        if(nWall > 13){ // batas kemunculan dinding adalah 13 (karena nWall bisa bernilai 1 - 13)
            nWall = 0;
            musuh++;
            if((r < 50 && groundLvl > 2) || groundLvl == 5){ 
                groundLvl--; // mengurangi level ground
            }else if(r > 60){
                groundLvl++; // menambah level ground
            }else{ 
                r = 34; // setDefault
                goto skip;
            }
        }
        r=51;
    }
    skip:
    if(r > 50 ){ // kalau angka random 51 - 100 maka muncul dinding
        switch (groundLvl)
            {
            case 2:
                setGround("#","#"," "," "," ");
                if (musuh == 1 && e1.size() == 0){summonEnemy(0,10); musuh = 0;}
                break;
            case 3:
                setGround("#","#","#"," "," ");
                if (musuh >= 2 && e1.size() == 0){summonEnemy(0,10); musuh = 0;}
                break;
            case 4:
                setGround("#","#","#","#"," ");
                if (musuh >= 2 && e1.size() == 0){summonEnemy(0,10); musuh = 0;}
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
}


void cekTombol(bool *isDead) {
    Ammo tempPeluru;
    while (!*isDead) {
		int i,y;
        
        //? Buat cek tombok ke atas 
        if (GetAsyncKeyState(VK_UP) & 0x8000) p1.moveUp(ground2,ground3,ground4,ground5);
            
        //? Buat cek tombok ke kiri dan kanan
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) p1.moveLeft();
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) p1.moveRight();
            
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
        Sleep(100);
    }
}



//? Disini ntar klo mau build tempatnya, sekalian gerakan peluru
void tembakPeluru(){
    int j;
    //? Kita gerakkan setiap peluru
    for (j=peluru.size()-1; j>=0; j--){
       
        gotoxy(peluru[j].LposX, peluru[j].LposY); cout << " ";  // Hapus karakter lama
        peluru[j].posX--;
        //Menghapus peluru yg kenak dinding
        if (peluru[j].posX == 3) peluru.erase(peluru.begin() + j);
        else if (ground2[peluru[j].posX] == "#" && peluru[j].posY == 10 )peluru.erase(peluru.begin() + j);
        else if (ground3[peluru[j].posX] == "#" && peluru[j].posY == 9 )peluru.erase(peluru.begin() + j);
        else if (ground4[peluru[j].posX] == "#" && peluru[j].posY == 8 )peluru.erase(peluru.begin() + j);
        else if (ground5[peluru[j].posX] == "#" && peluru[j].posY == 7 )peluru.erase(peluru.begin() + j);
        else {
            gotoxy(peluru[j].posX, peluru[j].posY); cout << "-";    // Cetak karakter di posisi baru
            peluru[j].LposX = peluru[j].posX;  // Simpan posisi lama
            peluru[j].LposY = peluru[j].posY; 
        }
       
         
    }  
 }  

void Kalah(bool isJatuh,bool *isDead){
    if(isJatuh){
        p1.posY = 11;
        p1.pindahPosisi();
    }else p1.posX++;
    *isDead = true;
    e1.clear();
    gotoxy(21,4);
    cout <<"YOU LOSE";
    gotoxy(19,5);
    cout << "YOUR SCORE:" << skor;
}

void enemyMove(bool *isDead){
    while(!*isDead){
        for (int i=e1.size()-1; i>=0; i--){
            for(int j=peluru.size()-1; j>=0; j--){
                //cek Player2 kena peluru
                if((peluru[i].posX == e1[j].posX || peluru[i].posX+1 == e1[j].posX || peluru[i].posX == e1[j].posX-1 ) && peluru[i].posY == e1[j].posY){
                    peluru.erase(peluru.begin() + i); 
                    e1.erase(e1.begin() + j);
                    skor++;
                }
            }
            e1[i].posX++; 
            //Kalau uda lewat batas, hapus enemy
            if (e1[i].posX == 50) {e1.erase(e1.begin() + i);}
            else if (e1[i].posX == p1.posX && e1[i].posY == p1.posY){Kalah(false,isDead); e1.erase(e1.begin() + i);}
            // Kalau di depan musuh ad ground 2, lompat ke ground 3
            else if (ground2[e1[i].posX + 1]== "#" && !e1[i].jump2 ) {e1[i].jump2 = true; e1[i].posY--;}
            else if (ground3[e1[i].posX + 1]== "#" && !e1[i].jump3 ) {e1[i].jump3 = true; e1[i].posY--;}
            else if (ground4[e1[i].posX + 1]== "#" && !e1[i].jump4 ) {e1[i].jump4 = true; e1[i].posY--;}
            else if (ground5[e1[i].posX + 1]== "#" && !e1[i].jump5 ) {e1[i].jump5 = true; e1[i].posY--;}
            // kalau skrg musuh  di atas ground 5 dan g5 kosong, turunkan enemy
            else if (ground5[e1[i].posX] == " " && ground5[e1[i].posX+1] == " " && ground5[e1[i].posX+2] == " " && e1[i].jump5){e1[i].jump5 = false; e1[i].posY++;}
            else if (ground4[e1[i].posX] == " " && ground4[e1[i].posX+1] == " " && ground4[e1[i].posX+2] == " "&& e1[i].jump4){e1[i].jump4 = false; e1[i].posY++;}
            else if (ground3[e1[i].posX] == " " && ground3[e1[i].posX+1] == " " && ground3[e1[i].posX+2] == " " && e1[i].jump3){e1[i].jump3 = false; e1[i].posY++;}
            else if (ground2[e1[i].posX] == " " && ground2[e1[i].posX+1] == " " && ground2[e1[i].posX+2] == " "&& e1[i].jump2){e1[i].jump2 = false; e1[i].posY++;}
            
            else if ((ground5[e1[i].posX] == " " || (ground5[e1[i].posX] == " " && ground5[e1[i].posX+1] == " ")) && e1[i].jump5){e1[i].jump5 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground4[e1[i].posX] == " " || (ground4[e1[i].posX] == " " && ground4[e1[i].posX+1] == " "))  && e1[i].jump4){e1[i].jump4 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground3[e1[i].posX] == " " || (ground3[e1[i].posX] == " " && ground3[e1[i].posX+1] == " "))  && e1[i].jump3){e1[i].jump3 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground2[e1[i].posX] == " " || (ground2[e1[i].posX] == " " && ground2[e1[i].posX+1] == " "))  && e1[i].jump2){e1[i].jump2 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            e1[i].pindahPosisi();
        }
        Sleep(170);
    }
}

void cekPlayer(bool* isDead){
     // Periksa apakah karakter harus turun satu ground
    if(p1.posY == 9 && ground2[p1.posX] == " " && (ground2[p1.posX+1] == "#" || ground2[p1.posX+2] == "#" || ground2[p1.posX+3] == "#"))p1.moveDown();
    if(p1.posY == 8 && ground3[p1.posX] == " " && (ground3[p1.posX+1] == "#" || ground3[p1.posX+2] == "#" || ground3[p1.posX+3] == "#"))p1.moveDown();
    if(p1.posY == 7 && ground4[p1.posX] == " " && (ground4[p1.posX+1] == "#" || ground4[p1.posX+2] == "#" || ground4[p1.posX+3] == "#"))p1.moveDown();
    if(p1.posY == 6 && ground5[p1.posX] == " " && (ground5[p1.posX+1] == "#" || ground5[p1.posX+2] == "#" || ground5[p1.posX+3] == "#"))p1.moveDown();
    
    //Periksa apakah karakter nabrak dinding
    if(p1.posY == 11 && ground1[p1.posX] == "#")Kalah(false,isDead);
    if(p1.posY == 10 && ground2[p1.posX] == "#")Kalah(false,isDead);
    if(p1.posY == 9 && ground3[p1.posX] == "#")Kalah(false,isDead);
    if(p1.posY == 8 && ground4[p1.posX] == "#")Kalah(false,isDead);
    if(p1.posY == 7 && ground5[p1.posX] == "#")Kalah(false,isDead);
    
    // Periksa apakah karakter jatuh ke jurang
    if(p1.posY == 10 && ground1[p1.posX] == " " && ground2[p1.posX-2] == "#")Kalah(true,isDead);
    if(p1.posY == 9 && ground2[p1.posX] == " " && ground1[p1.posX] == " " && ground3[p1.posX-2] == "#")Kalah(true,isDead);
    if(p1.posY == 8 && ground3[p1.posX] == " " && ground2[p1.posX] == " " && ground1[p1.posX] == " " && ground4[p1.posX-2] == "#")Kalah(true,isDead);
    if(p1.posY == 7 && ground4[p1.posX] == " " && ground3[p1.posX] == " " && ground2[p1.posX] == " " && ground1[p1.posX] == " " && ground5[p1.posX-2] == "#")Kalah(true,isDead);
}

main(){
    start:
    system("cls");
    p1.posY=10;
    bool isDead = false;
    skor = 0;
    
    //? pakek thread, jadi ada 2 program yg bekerja di waktu bersamaan, cekTombol() dan main() program
	thread threadPemeriksaanTombol(cekTombol, &isDead);
    thread musuhGerak(enemyMove, &isDead);

    char c;
    musuh=0; jurang = 0; nWall = 0; groundLvl=2;
    isEnemy = false; isJurang = false; isWall = false;

    setDefault();

	while (!isDead)
    {
        system("CLS");
    
        shiftGround();
        cekGround();
        printGround();

        gotoxy(0,0);
        cout << "Skor = " << skor;

        tembakPeluru();
        cekPlayer(&isDead);

        gotoxy(p1.posX,p1.posY); cout << p1.karakter ; 
        Sleep(200);
    }

    threadPemeriksaanTombol.join();
    musuhGerak.join();
    gotoxy(22,0);cout << "Press E to End, R to Restart";
    while(c != 'E' && c != 'e'){
        gotoxy(33,5);
        c = getch();
        if(c == 'R' || c == 'r'){
            isDead = false;
            goto start; 
        }
    }
    exit;

}
