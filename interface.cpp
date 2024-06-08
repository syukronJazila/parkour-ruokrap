#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <vector>
// #include "intro.h"

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
        string line1 =
"                        ####################################################################################################\n"
"                        #                                                                                                  #\n"
"                        #  ooooooooo.         .o.       ooooooooo.   oooo    oooo   .oooooo.   ooooo     ooo ooooooooo.    #\n"
"                        #  `888   `Y88.      .888.      `888   `Y88. `888   .8P'   d8P'  `Y8b  `888'     `8' `888   `Y88.  #\n"
"                        #   888   .d88'     .8\"888.      888   .d88'  888  d8'    888      888  888       8   888   .d88'  #\n"
"                        #   888ooo88P'     .8' `888.     888ooo88P'   88888[      888      888  888       8   888ooo88P'   #\n"
"                        #   888           .88ooo8888.    888`88b.     888`88b.    888      888  888       8   888`88b.     #\n"
"                        #   888          .8'     `888.   888  `88b.   888  `88b.  `88b    d88'  `88.    .8'   888  `88b.   #\n"
"                        #  o888o        o88o     o8888o o888o  o888o o888o  o888o  `Y8bood8P'     `YbodP'    o888o  o888o  #\n"
"#########################                                                                                                  ###########################\n"
"#                       #                                                                                                  #                         #\n"
"#                       #  ooooooooo.   ooooo     ooo   .oooooo.   oooo    oooo ooooooooo.         .o.       ooooooooo.    #                         #\n"
"#                       #  `888   `Y88. `888'     `8'  d8P'  `Y8b  `888   .8P'  `888   `Y88.      .888.      `888   `Y88.  #                         #\n"
"#                       #   888   .d88'  888       8  888      888  888  d8'     888   .d88'     .8\"888.      888   .d88'  #                         #\n"
"#                       #   888ooo88P'   888       8  888      888  88888[       888ooo88P'     .8' `888.     888ooo88P'   #                         #\n"
"#                       #   888`88b.     888       8  888      888  888`88b.     888`88b.      .88ooo8888.    888          #                         #\n"
"#                       #   888  `88b.   `88.    .8'  `88b    d88'  888  `88b.   888  `88b.   .8'     `888.   888          #                         #\n"
"#                       #  o888o  o888o    `YbodP'     `Y8bood8P'  o888o  o888o o888o  o888o o88o     o8888o o888o         #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       ####################################################################################################                         #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                      #####################################################################                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #        \033[1;36m//////////////////////////////////////////////////\033[0m         #                                         #\n"
"#                                      #        \033[1;36m//        __  __                   __  __  __   //\033[0m         #                                         #\n"
"#                                      #        \033[1;36m//   |\\ |/  \\|__)|\\/| /\\ |    |\\/|/  \\|  \\|_    //\033[0m         #                                         #\n"
"#                                      #        \033[1;36m//   | \\|\\__/| \\ |  |/--\\|__  |  |\\__/|__/|__   //\033[0m         #                                         #\n"
"#                                      #        \033[1;36m//                                              //\033[0m         #                                         #\n"
"#                                      #        \033[1;36m//////////////////////////////////////////////////\033[0m         #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #              __     __     __ __ __       __  __  __              #                                         #\n"
"#                                      #             |_ |\\ ||  \\|  |_ (_ (_   |\\/|/  \\|  \\|_               ###########################################\n"
"########################################             |__| \\||__/|__|____)__)  |  |\\__/|__/|__              #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                    __ __  __   ___ __  __  __                     #\n"
"                                       #                   /  |__)|_  /\\ | /  \\|__)(_                      #\n"
"                                       #                   \\__| \\ |__/--\\| \\__/| \\ __)                     #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #####################################################################";
    string line2 =
"                        ####################################################################################################\n"
"                        #                                                                                                  #\n"
"                        #  ooooooooo.         .o.       ooooooooo.   oooo    oooo   .oooooo.   ooooo     ooo ooooooooo.    #\n"
"                        #  `888   `Y88.      .888.      `888   `Y88. `888   .8P'   d8P'  `Y8b  `888'     `8' `888   `Y88.  #\n"
"                        #   888   .d88'     .8\"888.      888   .d88'  888  d8'    888      888  888       8   888   .d88'  #\n"
"                        #   888ooo88P'     .8' `888.     888ooo88P'   88888[      888      888  888       8   888ooo88P'   #\n"
"                        #   888           .88ooo8888.    888`88b.     888`88b.    888      888  888       8   888`88b.     #\n"
"                        #   888          .8'     `888.   888  `88b.   888  `88b.  `88b    d88'  `88.    .8'   888  `88b.   #\n"
"                        #  o888o        o88o     o8888o o888o  o888o o888o  o888o  `Y8bood8P'     `YbodP'    o888o  o888o  #\n"
"#########################                                                                                                  ###########################\n"
"#                       #                                                                                                  #                         #\n"
"#                       #  ooooooooo.   ooooo     ooo   .oooooo.   oooo    oooo ooooooooo.         .o.       ooooooooo.    #                         #\n"
"#                       #  `888   `Y88. `888'     `8'  d8P'  `Y8b  `888   .8P'  `888   `Y88.      .888.      `888   `Y88.  #                         #\n"
"#                       #   888   .d88'  888       8  888      888  888  d8'     888   .d88'     .8\"888.      888   .d88'  #                         #\n"
"#                       #   888ooo88P'   888       8  888      888  88888[       888ooo88P'     .8' `888.     888ooo88P'   #                         #\n"
"#                       #   888`88b.     888       8  888      888  888`88b.     888`88b.      .88ooo8888.    888          #                         #\n"
"#                       #   888  `88b.   `88.    .8'  `88b    d88'  888  `88b.   888  `88b.   .8'     `888.   888          #                         #\n"
"#                       #  o888o  o888o    `YbodP'     `Y8bood8P'  o888o  o888o o888o  o888o o88o     o8888o o888o         #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       ####################################################################################################                         #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                      #####################################################################                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                  __  __                   __  __  __              #                                         #\n"
"#                                      #             |\\ |/  \\|__)|\\/| /\\ |    |\\/|/  \\|  \\|_               #                                         #\n"
"#                                      #             | \\|\\__/| \\ |  |/--\\|__  |  |\\__/|__/|__              #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #         \033[1;36m/////////////////////////////////////////////////\033[0m         #                                         #\n"
"#                                      #         \033[1;36m//   __     __     __ __ __       __  __  __   //\033[0m         #                                         #\n"
"#                                      #         \033[1;36m//  |_ |\\ ||  \\|  |_ (_ (_   |\\/|/  \\|  \\|_    //\033[0m         ###########################################\n"
"########################################         \033[1;36m//  |__| \\||__/|__|____)__)  |  |\\__/|__/|__   //\033[0m         #\n"
"                                       #         \033[1;36m//                                             //\033[0m         #\n"
"                                       #         \033[1;36m/////////////////////////////////////////////////\033[0m         #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                    __ __  __   ___ __  __  __                     #\n"
"                                       #                   /  |__)|_  /\\ | /  \\|__)(_                      #\n"
"                                       #                   \\__| \\ |__/--\\| \\__/| \\ __)                     #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #####################################################################";
    string line3 =
"                        ####################################################################################################\n"
"                        #                                                                                                  #\n"
"                        #  ooooooooo.         .o.       ooooooooo.   oooo    oooo   .oooooo.   ooooo     ooo ooooooooo.    #\n"
"                        #  `888   `Y88.      .888.      `888   `Y88. `888   .8P'   d8P'  `Y8b  `888'     `8' `888   `Y88.  #\n"
"                        #   888   .d88'     .8\"888.      888   .d88'  888  d8'    888      888  888       8   888   .d88'  #\n"
"                        #   888ooo88P'     .8' `888.     888ooo88P'   88888[      888      888  888       8   888ooo88P'   #\n"
"                        #   888           .88ooo8888.    888`88b.     888`88b.    888      888  888       8   888`88b.     #\n"
"                        #   888          .8'     `888.   888  `88b.   888  `88b.  `88b    d88'  `88.    .8'   888  `88b.   #\n"
"                        #  o888o        o88o     o8888o o888o  o888o o888o  o888o  `Y8bood8P'     `YbodP'    o888o  o888o  #\n"
"#########################                                                                                                  ###########################\n"
"#                       #                                                                                                  #                         #\n"
"#                       #  ooooooooo.   ooooo     ooo   .oooooo.   oooo    oooo ooooooooo.         .o.       ooooooooo.    #                         #\n"
"#                       #  `888   `Y88. `888'     `8'  d8P'  `Y8b  `888   .8P'  `888   `Y88.      .888.      `888   `Y88.  #                         #\n"
"#                       #   888   .d88'  888       8  888      888  888  d8'     888   .d88'     .8\"888.      888   .d88'  #                         #\n"
"#                       #   888ooo88P'   888       8  888      888  88888[       888ooo88P'     .8' `888.     888ooo88P'   #                         #\n"
"#                       #   888`88b.     888       8  888      888  888`88b.     888`88b.      .88ooo8888.    888          #                         #\n"
"#                       #   888  `88b.   `88.    .8'  `88b    d88'  888  `88b.   888  `88b.   .8'     `888.   888          #                         #\n"
"#                       #  o888o  o888o    `YbodP'     `Y8bood8P'  o888o  o888o o888o  o888o o88o     o8888o o888o         #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       #                                                                                                  #                         #\n"
"#                       ####################################################################################################                         #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                                                                                                                                    #\n"
"#                                      #####################################################################                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                  __  __                   __  __  __              #                                         #\n"
"#                                      #             |\\ |/  \\|__)|\\/| /\\ |    |\\/|/  \\|  \\|_               #                                         #\n"
"#                                      #             | \\|\\__/| \\ |  |/--\\|__  |  |\\__/|__/|__              #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #                                                                   #                                         #\n"
"#                                      #              __     __     __ __ __       __  __  __              #                                         #\n"
"#                                      #             |_ |\\ ||  \\|  |_ (_ (_   |\\/|/  \\|  \\|_               ###########################################\n"
"########################################             |__| \\||__/|__|____)__)  |  |\\__/|__/|__              #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #                                                                   #\n"
"                                       #         \033[1;36m/////////////////////////////////////////////////\033[0m         #\n"
"                                       #         \033[1;36m//         __ __  __   ___ __  __  __          //\033[0m         #\n"
"                                       #         \033[1;36m//        /  |__)|_  /\\ | /  \\|__)(_           //\033[0m         #\n"
"                                       #         \033[1;36m//        \\__| \\ |__/--\\| \\__/| \\ __)          //\033[0m         #\n"
"                                       #         \033[1;36m//                                             //\033[0m         #\n"
"                                       #         \033[1;36m/////////////////////////////////////////////////\033[0m         #\n"
"                                       #                                                                   #\n"
"                                       #####################################################################";

    string line4 = "--- Level 1 --- Reach the score to complete the level.\n"
                   "-------------------------------------------------------------------------------\n"
                   "// Lives : 3/3 | Score :   0/100 | Coin :  0/10 | Hostile Killed :  0/15     //\n"
                   "-------------------------------------------------------------------------------\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "//                                                                           //\n"
                   "// ##    #######                                                             //\n"
                   "// ##    ##################                                                  //\n"
                   "// ##    ###############################                              $      //\n"
                   "// ##    ################################################################### //\n"
                   "-------------------------------------------------------------------------------\n"
                   "---- Movement ----------------------------------Shoot -------------------------\n"
                   "//     W      |  (W) to jump,                -         Use the arrow         //\n"
                   "//            |  (A), (D) to go left & right -         keys to shoot         //\n"
                   "// A   S   D  |  (S) to stop the game.       -          the hostiles.        //\n"
                   "-------------------------------------------------------------------------------\n";
    string level1 = "--- Level 1 --- Reach the score to complete the level.";
    string level1Comp = "\033[32m--- Level 1 is completed! Go suicide to go to the next level.\033[0m";
    string level1CompEx = "-------------------------------------------------------------------------------\n"
                          "// \033[31mLives : 1/3\033[0m | \033[32mScore : 100/100\033[0m | Coin : 10/10 | Hostile Killed : 15/15     //\n"
                          "-------------------------------------------------------------------------------\n";
    string gameStart3 = "Game start in 3";
    string gameStart2 = "Game start in 2";
    string gameStart1 = "Game start in 1";
    string gameStart0 = "Go!            ";
    string gameStart = "               ";
    string gameStarts[5] = {gameStart3, gameStart2, gameStart1, gameStart0, gameStart};
    system("cls");
    string lines[3] = {line1, line2, line3}; //array string menu di awal
    char ch;
    int menu = 0;
    cout << lines[menu];
    while (true)
    {
        ch = _getch();
        if (!(ch == '\r' || ch == '\n'))
        {
            if (ch == 80 && menu < 2)
            {
                menu += 1;
                system("cls");
                cout << lines[menu];
            }
            else if (ch == 72 && menu > 0)
            {
                menu -= 1;
                system("cls");
                cout << lines[menu];
            }
        }
        else
        {
            system("cls");
            cout << line4;
            break;
        }
    }

    for (int ll = 0; ll < 5; ll++)
    {
        gotoxy(54, 8);
        cout << gameStarts[ll];
        this_thread::sleep_for(chrono::seconds(1));
    }
    // getchar();
    gotoxy(0, 0);
    cout << level1Comp;
    gotoxy(0, 1);
    cout << level1CompEx;
    this_thread::sleep_for(chrono::seconds(5));
    gotoxy(0, 0);
    string line5 =
        "\033[32m---                                                                            \n"
        "-------------------------------------------------------------------------------\n"
        "// Lives : -/- | Score :   -/-   | Coin :  -/-  | Hostile Killed :  -/-      //\n"
        "-------------------------------------------------------------------------------\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                     You have completed the level.                         //\n"
        "//                 Press any key to go to the next level.                    //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "-------------------------------------------------------------------------------\n"
        "--                                                                             \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n\033[0m";
    cout << line5;
    this_thread::sleep_for(chrono::seconds(5));
    string line6 =
        "\033[31m---                                                                            \n"
        "-------------------------------------------------------------------------------\n"
        "// Lives : -/- | Score :   -/-   | Coin :  -/-  | Hostile Killed :  -/-      //\n"
        "-------------------------------------------------------------------------------\n"
        "//                                                                           //\n"
        "//                     You are run out of lives.                             //\n"
        "//                 Re-run the program to start over.                         //\n"
        "//       (this game is already easy and you couldn't beat that, bro?)        //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "//                                                                           //\n"
        "-------------------------------------------------------------------------------\n"
        "--                                                                             \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n"
        "                                                                               \n\033[0m";
    vector<string> asciiArtStrings = {
        "\033[31m                 ___-----------___",
        "           __--~~                 ~~--__",
        "       _-~~                             ~~-_",
        "    _-~                                     ~-_",
        "   /                                           \\",
        "  |                                             |",
        " |                                               |",
        " |                                               |",
        "|                                                 |",
        "|                                                 |",
        "|                                                 |",
        " |                                               |",
        " |  |    _-------_               _-------_    |  |",
        " |  |  /~         ~\\           /~         ~\\  |  |",
        "  ||  |             |         |             |  ||",
        "  || |               |       |               | ||",
        "  || |              |         |              | ||",
        "  |   \\_           /           \\           _/   |",
        " |      ~~--_____-~    /~V~\\    ~-_____--~~      |",
        " |                    |     |                    |",
        "|                    |       |                    |",
        "|                    |  /^\\  |                    |",
        " |                    ~~   ~~                    |",
        "  \\_         _                       _         _/",
        "    ~--____-~ ~\\                   /~ ~-____--~",
        "         \\     /\\                 /\\     /",
        "          \\    | ( ,           , ) |    /",
        "           |   | (~(__(  |  )__)~) |   |",
        "            |   \\/ (  (~~|~~)  ) \\/   |",
        "             |   |  [ [  |  ] ]  /   |",
        "              |                     |",
        "               \\                   /",
        "                ~-_             _-~",
        "                   ~--___-___--~\033[0m"};
    gotoxy(0, 0);
    cout << line6;
    int i = 8;
    for (const string &str : asciiArtStrings)
    {
        gotoxy(15, i);
        cout << str << endl;
        i++;
    }
    getchar();
    return 0;
}