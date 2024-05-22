#include <iostream>
#include <windows.h>
using namespace std;

main(){
    int i = 0, n = 30,r;
    string arr[n],arr2[n];
    for (int j = 0; j < n; j++)
    {
        arr[j] = '#';
        arr2[i] = " ";
    }
    bool isObstacle = false;
    int obstacle = 0;
	while (true)
    {
    system("CLS");
    r = rand() % 100 + 1;
    if(obstacle >= 3 && obstacle <= 4){
        r = 50;
        obstacle++;
        if (obstacle == 5){ obstacle = 0;}
    }
    if(isObstacle && obstacle == 2){
        r = 50;
        isObstacle = false;
        obstacle = 3;
    }
    if(r > 66 ){
        for (int j = n-1; j >= 0; j--)
        {
            if(j == 0){
                arr2[0] = "#";
                break;
            }
            arr[j] = arr[j-1];
            arr2[j] = arr2[j-1];   
        }
    }
    else if(r > 33){
        for (int j = n-1; j >= 0; j--)
        {
            if(j == 0){
                arr[0] = "#";
                break;
            }
            arr[j] = arr[j-1];
            arr2[j] = arr2[j-1];        
        }
        
    }
    else{
        isObstacle = true;
        obstacle++;
        for (int j = n-1; j >= 0; j--)
        {
            if(j == 0){
                arr[0] = " ";
                break;
            }
            arr[j] = arr[j-1];
            arr2[j] = arr2[j-1];
        }
    }
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
