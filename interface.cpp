#include "library.h"
#include "stringInterface.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenu(const string menu[], int size, int startX, int startY)
{
    for (int i = 0; i < size; ++i)
    {
        gotoxy(startX, startY + i);
        cout << menu[i] << flush;
    }
}
void printWithZigzag(const vector<string> &lines, int delay_ms = 1, int start_col = 1, int start_row = 1)
{
    int numLines = lines.size();
    int maxLen = 0;
    for (const auto &line : lines)
    {
        if (line.length() > maxLen)
        {
            maxLen = line.length();
        }
    }

    for (int diag = 0; diag < numLines + maxLen - 1; ++diag)
    {
        for (int row = 0; row < numLines; ++row)
        {
            int col = diag - row + start_col;   // Adjust starting column
            int adjusted_row = row + start_row; // Adjust starting row
            if (col >= start_col && col < start_col + lines[row].length())
            {
                gotoxy(col, adjusted_row);
                cout << lines[row][col - start_col] << flush; // Adjust column index
                this_thread::sleep_for(chrono::milliseconds(delay_ms));
            }
        }
    }
}

void printWithZigzag(const string &text, int delay_ms = 1, int start_col = 1, int start_row = 1)
{
    int len = text.length();
    int current_col = start_col;
    int current_row = start_row;

    for (int i = 0; i < len; ++i)
    {
        if (text[i] == '\n')
        {
            current_col = start_col;
            current_row++;
        }
        else
        {
            gotoxy(current_col, current_row);
            cout << text[i] << flush;
            current_col++;
            this_thread::sleep_for(chrono::milliseconds(delay_ms));
        }
    }
}

void processText(const vector<string> &lines, int zigzag_delay = 1, int start_col = 96, int start_row = 5)
{
    printWithZigzag(lines, zigzag_delay, start_col, start_row);
}

void processTextString(const string &text, float zigzag_delay = 1, int start_col = 96, int start_row = 5)
{
    printWithZigzag(text, zigzag_delay, start_col, start_row);
}
void printXY(vector<string> text, int x, int y)
{
    for (const string &line : text)
    {
        gotoxy(x, y);
        cout << line << endl;
        y++;
    }
}

void printLevel(int i){
    gotoxy(0, 0);
    cout << levels[i];
};

void printKeysf(){
    gotoxy(0, 17);
    cout << keysFunction;
};

int main()
{
    system("cls");

    // Process the text with the given parameters
    int i = 12;
    processText(parkourText, 1, 28, 3); // Start from column 10 and row 5
    for (const string &line : ruokrapText)
    {
        gotoxy(28, i);
        cout << line << endl;
        i++;
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
    for (int i = 0; i < 4; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        system("CLS");
        this_thread::sleep_for(chrono::milliseconds(100));
        printXY(parkourText, 28, 3);
        printXY(ruokrapText, 28, 12);
    }
    gotoxy(35, 22);
    cout << "Press any key to continue";
    getch();
    processTextString(menu, 0.005, 1, 1);

    // y = 28, x = 40
    // printXY(defaultMenu, 40, 28);
    int x = 35;
    int y = 28;

    printMenu(defaultMenu, sizeof(defaultMenu) / sizeof(defaultMenu[0]), 41, 28);
    this_thread::sleep_for(chrono::milliseconds(100));
    // x = 56;
    // y = 30;
    printMenu(normalMenu, menuSizes[0], 49, 29);

    i = 0;
    a:
    while (true)
    {
        char ch = _getch();
        if (!(ch == '\r' || ch == '\n'))
        {
            if (ch == 80)
            {
                i = ++i % 3;
            }
            else if (ch == 72)
            {
                i = ((--i < 0) ? 2 : i) % 3;
            }

            printMenu(defaultMenu, sizeof(defaultMenu) / sizeof(defaultMenu[0]), 41, 28);
            printMenu(menuArr[i], menuSizes[i], 49, 29 + i * 7);
        }
        else
        {
            system("cls");
            if(i==0){
            cout << inGameuUI;
            break;
            }
            if(i==1){
                cout << "Click any key to get back to menu.";
                getch();
            }
            else {
                cout << "Parkour Ruokrap by Pembantai 24 SKS (P24S)" << endl;
                cout << "Click any key to get back to menu.";
            }
            goto a;
        }
    }
    int level = 0;
    this_thread::sleep_for(chrono::seconds(1));
    printLevel(level);
    printKeysf();
    for (int ll = 0; ll < 5; ll++)
    {
        gotoxy(54, 8);
        cout << gameStarts[ll];
        this_thread::sleep_for(chrono::seconds(1));
    }
    
}
