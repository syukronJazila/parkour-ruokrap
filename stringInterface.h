#ifndef STRINGINTERFACE_H
#define STRINGINTERFACE_H

#include "library.h"

vector<string> parkourText = {
    "ooooooooo.         .o.       ooooooooo.   oooo    oooo   .oooooo.   ooooo     ooo ooooooooo.   ",
    "`888   `Y88.      .888.      `888   `Y88. `888   .8P'   d8P'  `Y8b  `888'     `8' `888   `Y88. ",
    " 888   .d88'     .8\"888.      888   .d88'  888  d8'    888      888  888       8   888   .d88' ",
    " 888ooo88P'     .8' `888.     888ooo88P'   88888[      888      888  888       8   888ooo88P'  ",
    " 888           .88ooo8888.    888`88b.     888`88b.    888      888  888       8   888`88b.    ",
    " 888          .8'     `888.   888  `88b.   888  `88b.  `88b    d88'  `88.    .8'   888  `88b.  ",
    "o888o        o88o     o8888o o888o  o888o o888o  o888o  `Y8bood8P'     `YbodP'    o888o  o888o "};

vector<string> ruokrapText = {
    "ooooooooo.   ooooo     ooo   .oooooo.   oooo    oooo ooooooooo.         .o.       ooooooooo.   ",
    "`888   `Y88. `888'     `8'  d8P'  `Y8b  `888   .8P'  `888   `Y88.      .888.      `888   `Y88. ",
    " 888   .d88'  888       8  888      888  888  d8'     888   .d88'     .8\"888.      888   .d88' ",
    " 888ooo88P'   888       8  888      888  88888[       888ooo88P'     .8' `888.     888ooo88P'  ",
    " 888`88b.     888       8  888      888  888`88b.     888`88b.      .88ooo8888.    888         ",
    " 888  `88b.   `88.    .8'  `88b    d88'  888  `88b.   888  `88b.   .8'     `888.   888         ",
    "o888o  o888o    `YbodP'     `Y8bood8P'  o888o  o888o o888o  o888o o88o     o8888o o888o        "};

const string menu =
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
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   #                                         #\n"
    "#                                      #                                                                   ###########################################\n"
    "########################################                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #                                                                   #\n"
    "                                       #####################################################################";
const string defaultMenu[] = {
    "                                                                   ",
    "                                                                   ",
    "                  __  __                   __  __  __              ",
    "             |\\ |/  \\|__)|\\/| /\\ |    |\\/|/  \\|  \\|_        ",
    "             | \\|\\__/| \\ |  |/--\\|__  |  |\\__/|__/|__         ",
    "                                                                   ",
    "                                                                   ",
    "                                                                   ",
    "                                                                   ",
    "              __     __     __ __ __       __  __  __      ",
    "             |_ |\\ ||  \\|  |_ (_ (_   |\\/|/  \\|  \\|_       ",
    "             |__| \\||__/|__|____)__)  |  |\\__/|__/|__     ",
    "                                                                   ",
    "                                                                   ",
    "                                                                   ",
    "                                                                   ",
    "                    __ __  __   ___ __  __  __                     ",
    "                   /  |__)|_  /\\ | /  \\|__)(_                    ",
    "                   \\__| \\ |__/--\\| \\__/| \\ __)                ",
    "                                                                   ",
    "                                                                   ",
    "                                                                   "};

const string normalMenu[] = {
    "\033[1;36m//////////////////////////////////////////////////\033[0m\n",
    "\033[1;36m//        __  __                   __  __  __   //\033[0m\n",
    "\033[1;36m//   |\\ |/  \\|__)|\\/| /\\ |    |\\/|/  \\|  \\|_    //\033[0m\n",
    "\033[1;36m//   | \\|\\__/| \\ |  |/--\\|__  |  |\\__/|__/|__   //\033[0m\n",
    "\033[1;36m//                                              //\033[0m\n",
    "\033[1;36m//////////////////////////////////////////////////\033[0m"};

const string endlessMenu[] = {
    "\033[1;36m/////////////////////////////////////////////////\033[0m",
    "\033[1;36m//    __     __     __ __ __       __  __  __  //\033[0m",
    "\033[1;36m//   |_ |\\ ||  \\|  |_ (_ (_   |\\/|/  \\|  \\|_   //\033[0m",
    "\033[1;36m//   |__| \\||__/|__|____)__)  |  |\\__/|__/|__  //\033[0m",
    "\033[1;36m//                                             //\033[0m",
    "\033[1;36m/////////////////////////////////////////////////\033[0m"};

const string creatorMenu[] = {
    "\033[1;36m/////////////////////////////////////////////////\033[0m",
    "\033[1;36m//          __ __  __   ___ __  __  __         //\033[0m",
    "\033[1;36m//         /  |__)|_  /\\ | /  \\|__)(_          //\033[0m",
    "\033[1;36m//         \\__| \\ |__/--\\| \\__/| \\ __)         //\033[0m",
    "\033[1;36m//                                             //\033[0m",
    "\033[1;36m/////////////////////////////////////////////////\033[0m"};

const string *menuArr[] = {normalMenu, endlessMenu, creatorMenu};

const int menuSizes[] = {
    sizeof(normalMenu) / sizeof(normalMenu[0]),
    sizeof(endlessMenu) / sizeof(endlessMenu[0]),
    sizeof(creatorMenu) / sizeof(creatorMenu[0])};

const string inGameuUI =
    "---                                                                            \n"
    "-------------------------------------------------------------------------------\n"
    "// Lives : -/- | Score :   -/-   | Coin :  -/-  | Hostile Killed :  -/-      //\n"
    "-------------------------------------------------------------------------------\n"
    "//                                                                           //\n"
    "//                                                                           //\n"
    "//                                                                           //\n"
    "//                                                                           //\n"
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
    "                                                                               \n";

const string keysFunction =
    "---- Movement ----------------------------------Shoot -------------------------\n"
    "//     W      |  (W) to jump,                -         Use the arrow         //\n"
    "//            |  (A), (D) to go left & right -         keys to shoot         //\n"
    "// A   S   D  |  (S) to stop the game.       -          the hostiles.        //\n"
    "-------------------------------------------------------------------------------\n";

const string keysFunctionHidden =
    "-- Press (H) to show the keys' function.                                       \n"
    "                                                                               \n"
    "                                                                               \n"
    "                                                                               \n"
    "                                                                               \n"
    "                                                                               ";

string gameStart3 = "Game start in 3";
string gameStart2 = "Game start in 2";
string gameStart1 = "Game start in 1";
string gameStart0 = "Go!            ";
string gameStart = "               ";
string gameStarts[5] = {gameStart3, gameStart2, gameStart1, gameStart0, gameStart};

const string level1 =
    "--- Level 1 --- Reach the score to complete the level.";

const string level2 =
    "--- Level 2 --- Take the coins and reach the score to complete the level.";

const string level3 =
    "--- Level 1 --- Kill the monsters and reach the score to complete the level.";

void green(){
    cout << "\033[32m";
}

void red(){
    cout << "\033[31m";
}

void white(){
    cout << "\033[0m";
}

const string levels[] = {level1, level2, level3};

inline const string levelCompleted(int level)
{
    return "\033[32m--- Level " + to_string(level) + " is completed! Please reset to go to the next level.\033[0m";
}

const string levelCompletedinUI =
    "    You have completed the level.     \n"
    "Press any key to go to the next level.";

const string levelLostinUI =
    "             You are run out of lives.                      \n"
    "          Re-run the program to start over.                 \n"
    "(this game is already easy and you couldn't beat that, bro?)";

vector<string> emoteToRoastPlayer = {
    "                 ___-----------___",
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
    "                   ~--___-___--~"};

#endif
