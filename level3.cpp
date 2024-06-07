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

//? deklarasi player
Player p1;
vector<Ammo> peluru;
bool sudah=true, isLift = false, isOnWall = false, isDead = false;
string arr[50],arr2[50];
int l=0,skor=0;

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
    Ammo tempPeluru;
    while (!isDead) {
        bool moved = false;
		int i,y;
        if (sudah == true){
            //? Buat cek tombok ke atas 
            l = 0;
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                if (p1.posY > 0) {
                for (i=1; i<=3; i++){
                        //? Minus artinya naik
                        p1.posY -= 1;
                        pindahPosisi();
                        Sleep(115);
                }
                
                if(arr2[p1.posX] == "#" && p1.posY < 10 && !isLift ){
                    if(p1.posY == 7){ l = 1;}
                    else if (p1.posY == 8){ l = 2;}
                    else if (p1.posY == 9){ l = 3;}
                    isLift = true;
                }
                    for (i=1+l; i<=3; i++){
                        p1.posY += 1;
                        pindahPosisi();
                        Sleep(100);  
                    }
                }
                //? Fix bug melayang setelah lompat di obstacle
                // while (arr2[p1.posX] == " " && arr[p1.posX] == "#"){
                //     p1.posY += 1;
                //     pindahPosisi();
                //     Sleep(100);
                // }
                if(p1.posY == 9 && arr2[p1.posX] == " " && arr[p1.posX] == "#"){
                     p1.posY += 1;
                    pindahPosisi();
                    Sleep(100); 
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
                if (p1.posX < 49) {  // Assuming console width is 80
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
void tembakPeluru(){
            int j;
            //? Kita gerakkan setiap peluru
            for (j=peluru.size()-1; j>=0; j--){
                sudah = false;
                gotoxy(peluru[j].LposX, peluru[j].LposY); cout << " ";  // Hapus karakter lama
                peluru[j].posX--;
                if (peluru[j].posX == 3 || arr2[peluru[j].posX] == "#") {
                    //gotoxy(a.posX, a.posY); cout << " ";
                    peluru.erase(peluru.begin() + j);
                }else if (peluru[j].posX == 3){ 
                    arr2[peluru[j].posX] = " ";
                    peluru.erase(peluru.begin() + j); 
                 }else if ((arr2[peluru[j].posX] == "B" || arr2[peluru[j].posX +1] == "B" || arr2[peluru[j].posX-1] == "B" ) && peluru[j].posY == 10){
                    arr2[peluru[j].posX] = " ";
                    arr2[peluru[j].posX - 1] = " ";
                    arr2[peluru[j].posX + 1] = " ";
                    peluru.erase(peluru.begin() + j); 
                    skor++;
                 }
                    
                 else {
                    gotoxy(peluru[j].posX, peluru[j].posY); cout << "-";    // Cetak karakter di posisi baru
                    peluru[j].LposX = peluru[j].posX;  // Simpan posisi lama
                    peluru[j].LposY = peluru[j].posY;
                    
                }
                sudah = true;
                 
            }  
 }  

main(){
    system("cls");
    
    
    //? pakek thread, jadi ada 2 program yg bekerja di waktu bersamaan, cekTombol() dan main() program
	thread threadPemeriksaanTombol(cekTombol);
    p1.posX = 21;
	p1.posY = 10;
	p1.LposX = 21;
	p1.LposY = 10;

    int i = 0, n = 50,r,musuh=0,nEnemy=0;

    for (int j = 0; j < n; j++)
    {
        arr[j] = '#';
        arr2[j] = " ";
    }
    bool isObstacle = false;
    bool isWall = false;
    bool isEnemy = false;
    int obstacle = 0;
    int nWall = 0;

	while (!isDead)
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
                musuh++;
            }
        }

        if (musuh == 2){
            r=50;
            nEnemy++;
            
            if (nEnemy > 4){
                isEnemy = true;
                nEnemy = 0;
                obstacle = 2;
                musuh=0;
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
            if (isEnemy){
                isEnemy = false;
                obstacle++;
                arr2[0] = "B";
                musuh=0;
            }else {
                isWall = true;
                arr2[0] = "#";
             } 
        }else if(r > 33){
            arr[0] = "#"; 
        }else if(r > 15){ // 0 - 33 muncul jurang 
            isObstacle = true;
            obstacle++;
            arr[0] = " ";
        }

        for(int j = 0; j < n; j++){ // mencetak ground atas
            gotoxy(j,10);cout << arr2[j];
        }
        for(int j = 0; j < n; j++){ // mencetak ground atas
            gotoxy(j,11);cout << arr[j];
        }

        gotoxy(0,0);
        cout << "Skor = " << skor;

        tembakPeluru();

        if(isLift && arr2[p1.posX] == " " && p1.posY < 10){
            if(p1.posY == 6){ l = -1;}
            else if (p1.posY == 7){ l = 0;}
            else if (p1.posY == 8){ l = 1;}
            else if (p1.posY == 9){ p1.posY = 10; l = 3;}
            isLift = false;
        }

        	
        if(arr[p1.posX] == " " && p1.posY == 10){
            p1.posY = 11;
            isDead = true;
            gotoxy(21,4);
            cout <<"YOU LOSE";
            gotoxy(19,5);
            cout << "YOUR SCORE:" << skor;
        }	
        if((arr2[p1.posX] == "#" || arr2[p1.posX] == "B")  && p1.posY == 10){
            p1.posX = p1.posX+1;
            isDead = true;
            gotoxy(21,4); 
            cout <<"YOU LOSE";
            gotoxy(19,5);
             cout << "YOUR SCORE:" << skor;
        }
        if(skor == 2){
            gotoxy(21,4); 
            cout <<"YOU WIN";
            isDead = true;
        }
        gotoxy(p1.posX,p1.posY); cout << "A" ;
        Sleep(200);
    }
    threadPemeriksaanTombol.join();
    exit;

}


