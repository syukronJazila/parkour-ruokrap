#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <iomanip>
#include "player.h"
#include "interface.h"

using namespace std;

struct Ammo{
    int posX,posY,LposX,LposY;
};

Player p1("@",29,14,29,14);
vector<Player> e1;
vector<Ammo> peluru;

int skor=0;

const int n = 73;
string ground1[n],ground2[n],ground3[n],ground4[n],ground5[n]; 

int r, k, musuh, jurang, nWall, groundLvl,nyawa=3,level = 1;
bool isEnemy, isJurang, isWall, isDead = false,cek = true,isCoin = false;
mutex mtx;
mutex mtx2;

void summonEnemy(int x,int y){
    Player tempEnemy("M",x,y,x,y);
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
    gotoxy(3,11);
    for(k = 0; k < n; k++){
        cout << ground5[k];
    }
    gotoxy(3,12);
    for(k = 0; k < n; k++){
        cout << ground4[k];
    }
    gotoxy(3,13);
    for(k = 0; k < n; k++){ 
        cout << ground3[k];
    }
    gotoxy(3,14);
    for(k = 0; k < n; k++){ 
        cout << ground2[k];
    }
    gotoxy(3,15);
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
            if (level == 3)musuh++;
            if((r < 50 && groundLvl > 2) || groundLvl == 5){ 
                groundLvl--; // mengurangi level ground
            }else if(r > 60){
                groundLvl++; // menambah level ground
            }else{ 
                r = 34; // setDefault
                if (level == 3)isCoin = true;
                goto skip;
            }
            if (level == 3)isCoin = true;
        }
        r=51;
    }
    skip:
    if(r > 50 ){ // kalau angka random 51 - 100 maka muncul dinding
        switch (groundLvl)
            {
            case 2:
                setGround("#","#"," "," "," ");
                if (musuh == 1 && e1.size() <= 1 && level == 3){summonEnemy(0,14); musuh = 0;}
                if(isCoin && level == 2){setGround("#","#"," ","*"," "); isCoin = false;} 
                break;
            case 3:
                setGround("#","#","#"," "," ");
                if (musuh >= 2 && e1.size() <= 1 && level == 3){summonEnemy(0,14); musuh = 0;}
                if((isCoin || nWall == 4 || nWall == 10) && level == 2 ){setGround("#","#","#"," ","*"); isCoin = false;} 
                break;
            case 4:
                setGround("#","#","#","#"," ");
                if (musuh >= 2 && e1.size() <= 1 && level == 3){summonEnemy(0,14); musuh = 0;}
                if((isCoin || nWall == 5 || nWall == 11) && level == 2){setGround("#","#","#","#"," "); isCoin = false;}
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
        if(isCoin && level == 2){setGround("#"," ","*"," "," "); isCoin = false;}
    }else{ // 0 - 33 muncul jurang 
        isJurang = true;
        jurang++;
        setGround(" "," "," "," "," ");
    }
}


void cekTombol() {
    Ammo tempPeluru;
    while (nyawa > 0) {
		int i,y;
        
        //? Buat cek tombok ke atas 
        if (GetAsyncKeyState('W') & 0x8000){ lock_guard<mutex> lock(mtx); p1.moveUp(ground2,ground3,ground4,ground5);if(level ==2)skor = p1.getKoin();}
            
        //? Buat cek tombok ke kiri dan kanan
        if (GetAsyncKeyState('A') & 0x8000){lock_guard<mutex> lock(mtx);p1.moveLeft(); }
        if (GetAsyncKeyState('D') & 0x8000){lock_guard<mutex> lock(mtx);p1.moveRight(); }
            
        //? peluru muncul klo spasi di tekan
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 && level == 3) {
        lock_guard<mutex> lock(mtx);
        //? tampilkan peluru di depan karakter
        gotoxy(p1.posX-1-3,p1.posY); cout << "-";
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
        else if (ground2[peluru[j].posX-3] == "#" && peluru[j].posY == 14 )peluru.erase(peluru.begin() + j);
        else if (ground3[peluru[j].posX-3] == "#" && peluru[j].posY == 13 )peluru.erase(peluru.begin() + j);
        else if (ground4[peluru[j].posX-3] == "#" && peluru[j].posY == 12 )peluru.erase(peluru.begin() + j);
        else if (ground5[peluru[j].posX-3] == "#" && peluru[j].posY == 11 )peluru.erase(peluru.begin() + j);
        else {
            gotoxy(peluru[j].posX, peluru[j].posY); cout << "-";    // Cetak karakter di posisi baru
            peluru[j].LposX = peluru[j].posX;  // Simpan posisi lama
            peluru[j].LposY = peluru[j].posY; 
        }
       
         
    }  
 }  

void Kalah(bool isJatuh){
    if(isJatuh){
        p1.posY = 15;
        p1.pindahPosisi();
    }else {p1.posX++;}
    nyawa-=1;
    isDead = true;
    e1.clear();
}

void enemyMove(){
        while(nyawa > 0){
        for (int i=e1.size()-1; i>=0; i--){
            mtx2.lock(); 
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
            if (e1[i].posX == 72) {e1.erase(e1.begin() + i);}
            else if (e1[i].posX == p1.posX && e1[i].posY == p1.posY){Kalah(false);}
           // Kalau di depan musuh ad ground 2, lompat ke ground 3
            else if (ground2[e1[i].posX + 1-3]== "#" && !e1[i].jump2 ) {e1[i].jump2 = true; e1[i].posY--;}
            else if (ground3[e1[i].posX + 1-3]== "#" && !e1[i].jump3 ) {e1[i].jump3 = true; e1[i].posY--;}
            else if (ground4[e1[i].posX + 1-3]== "#" && !e1[i].jump4 ) {e1[i].jump4 = true; e1[i].posY--;}
            else if (ground5[e1[i].posX + 1-3]== "#" && !e1[i].jump5 ) {e1[i].jump5 = true; e1[i].posY--;}
            // kalau skrg musuh  di atas ground 5 dan g5 kosong, turunkan enemy
            else if (ground5[e1[i].posX-3] == " " && ground5[e1[i].posX+1-3] == " " && ground5[e1[i].posX+2-3] == " " && e1[i].jump5){e1[i].jump5 = false; e1[i].posY++;}
            else if (ground4[e1[i].posX-3] == " " && ground4[e1[i].posX+1-3] == " " && ground4[e1[i].posX+2-3] == " "&& e1[i].jump4){e1[i].jump4 = false; e1[i].posY++;}
            else if (ground3[e1[i].posX-3] == " " && ground3[e1[i].posX+1-3] == " " && ground3[e1[i].posX+2-3] == " " && e1[i].jump3){e1[i].jump3 = false; e1[i].posY++;}
            else if (ground2[e1[i].posX-3] == " " && ground2[e1[i].posX+1-3] == " " && ground2[e1[i].posX+2-3] == " "&& e1[i].jump2){e1[i].jump2 = false; e1[i].posY++;}
            
            else if ((ground5[e1[i].posX-3] == " " || (ground5[e1[i].posX-3] == " " && ground5[e1[i].posX+1-3] == " ")) && e1[i].jump5){e1[i].jump5 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground4[e1[i].posX-3] == " " || (ground4[e1[i].posX-3] == " " && ground4[e1[i].posX+1-3] == " "))  && e1[i].jump4){e1[i].jump4 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground3[e1[i].posX-3] == " " || (ground3[e1[i].posX-3] == " " && ground3[e1[i].posX+1-3] == " "))  && e1[i].jump3){e1[i].jump3 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
            else if ((ground2[e1[i].posX-3] == " " || (ground2[e1[i].posX-3] == " " && ground2[e1[i].posX+1-3] == " "))  && e1[i].jump2){e1[i].jump2 = false; e1[i].lompatEnemy(ground5,ground4,ground3,ground2);}
           
            if(!e1.empty()){e1[i].pindahPosisi();}
            mtx2.unlock();
        }
        Sleep(180);
    }
}

void cekPlayer(){
     // Periksa apakah karakter harus turun satu ground
    if(p1.posY == 13 && ground2[p1.posX-3] == " " && (ground2[p1.posX+1-3] == "#" || ground2[p1.posX+2-3] == "#" || ground2[p1.posX+3-3] == "#"))p1.moveDown();
    else if(p1.posY == 12 && ground3[p1.posX-3] == " " && (ground3[p1.posX+1-3] == "#" || ground3[p1.posX+2-3] == "#" || ground3[p1.posX+3-3] == "#"))p1.moveDown();
    else if(p1.posY == 11 && ground4[p1.posX-3] == " " && (ground4[p1.posX+1-3] == "#" || ground4[p1.posX+2-3] == "#" || ground4[p1.posX+3-3] == "#"))p1.moveDown();
    else if(p1.posY == 10 && ground5[p1.posX-3] == " " && (ground5[p1.posX+1-3] == "#" || ground5[p1.posX+2-3] == "#" || ground5[p1.posX+3-3] == "#"))p1.moveDown();
    
    // Periksa apakah karakter jatuh ke jurang
    if(p1.posY == 14 && ground1[p1.posX-3] == " " && ground2[p1.posX-2-3] == "#")Kalah(true);
    else if(p1.posY == 13 && ground2[p1.posX-3] == " " && ground1[p1.posX-3] == " " && ground3[p1.posX-3-2] == "#")Kalah(true);
    else if(p1.posY == 12 && ground3[p1.posX-3] == " " && ground2[p1.posX-3] == " " && ground1[p1.posX-3] == " " && ground4[p1.posX-2-3] == "#")Kalah(true);
    else if(p1.posY == 11 && ground4[p1.posX-3] == " " && ground3[p1.posX-3] == " " && ground2[p1.posX-3] == " " && ground1[p1.posX-3] == " " && ground5[p1.posX-2-3] == "#")Kalah(true);
    //Periksa apakah karakter nabrak dinding dari depan
    else if(p1.posY == 15 && ground1[p1.posX-3] == "#")Kalah(false); 
    else if(p1.posY == 14 && ground2[p1.posX-3] == "#")Kalah(false);
    else if(p1.posY == 13 && ground3[p1.posX-3] == "#")Kalah(false);
    else if(p1.posY == 12 && ground4[p1.posX-3] == "#")Kalah(false);
    else if(p1.posY == 11 && ground5[p1.posX-3] == "#")Kalah(false);
    
}

void nextLevel(){
    gotoxy(0,0);
    green();
    cout << inGameuUI;
    int i =9;
        for(const string &str: levelCompletedinUI){
            gotoxy(19,i); cout << str<< endl;
            i++;
        }
    white();
    char a = getch();
    setDefault();
    skor = 0;
    nyawa = 3;
    isDead = false;
    level++;
    chrono::seconds durasi(2);
    auto startTime = chrono::high_resolution_clock::now();
    this_thread::sleep_for(durasi);
}

main(){
    mainInterface();
    //? pakek thread, jadi ada 2 program yg bekerja di waktu bersamaan, cekTombol() dan main() program
	thread threadPemeriksaanTombol(cekTombol);
    thread musuhGerak(enemyMove);

    while(true){
    system("cls");
    p1.posY=14;
    skor = 0;

    musuh=0; jurang = 0; nWall = 0; groundLvl=2;
    isEnemy = false; isJurang = false; isWall = false,isDead = false;

    setDefault();
    // lvl 1
    while (!isDead && nyawa > 0 && level == 1)
    {
        if(skor == 10){
            nextLevel();
            break;
        }
        skor++;
        system("CLS");
        inGame();
    
        shiftGround();
        cekGround();
        printGround();

        gotoxy(11,2);
        cout << nyawa;
        gotoxy(25,2);
        cout << setw(3) << setfill('0') << skor; 

        cekPlayer();

        gotoxy(p1.posX,p1.posY); cout << p1.karakter ;
        Sleep(200);
    }
    nWall = 0; groundLvl=2;
    p1.posY=14;
    p1.posX=29;
    // lvl 2
    while (!isDead && nyawa > 0 && level == 2)
    {
        if(skor == 1){
           nextLevel();
           break;
        }
        system("CLS");
        inGame();
    
        shiftGround();
        cekGround();
        printGround();
        gotoxy(11,2);
        cout << nyawa;

        gotoxy(0,0); cout << level2;
        gotoxy(42,2); cout << setw(2) << setfill('0') << skor; 

        cekPlayer();

        gotoxy(p1.posX,p1.posY); cout << p1.karakter ;
        Sleep(200);
    }
    nWall = 0; groundLvl=2;
    p1.posY=14;
    p1.posX=29;

	while (!isDead && nyawa > 0 && level == 3)
    {
        if(skor > 1){
            level++;
            e1.clear();
            break;
        }
        system("CLS");
        inGame();
    
        shiftGround();
        cekGround();
        printGround();

        gotoxy(11,2);
        cout << nyawa;

        gotoxy(0,0); cout << level3;
        gotoxy(67,2); cout << setw(2) << setfill('0') << skor; 

        tembakPeluru();
        cekPlayer();

        gotoxy(p1.posX,p1.posY); cout << p1.karakter ;
        Sleep(200);
    }

    if (level <= 3 && nyawa != 0){
        gotoxy(31,8);
        cout <<"YOU LOSE";
        gotoxy(29,9);
        cout << "YOUR SCORE:" << skor;
        gotoxy(33,10);cout << "Noob";
        gotoxy(0,16);cout << " ";
    }

    if(nyawa == 0){
        red();
        gotoxy(0,0);cout << inGameuUI;
        for(int i = 0; i < 3; i++){
            gotoxy(10, 4+i); cout << levelLostinUI[i];
        }
        int i =8;
        for(const string &str: emoteToRoastPlayer){
            gotoxy(15,i); cout << str<< endl;
            i++;
        }
        white();
    }

    if(level > 3){
        green();
        cout << inGameuUI;
        int i =9;
        for(const string &str: levelCompletedinUI){
            gotoxy(19,i); cout << str<< endl;
            i++;
        }
        white();
    }

    chrono::seconds durasi(2);
    auto startTime = chrono::high_resolution_clock::now();
    this_thread::sleep_for(durasi);

    }
    cek = false;  
    
    threadPemeriksaanTombol.join();
    musuhGerak.join();

    char c = getch();

}