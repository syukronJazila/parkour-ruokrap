#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H" << flush;
}

void printWithZigzag(const vector<string>& lines, int delay_ms = 1, int start_col = 1) {
    int numLines = lines.size();
    int maxLen = 0;
    for (const auto& line : lines) {
        if (line.length() > maxLen) {
            maxLen = line.length();
        }
    }

    for (int diag = 0; diag < numLines + maxLen - 1; ++diag) {
        for (int row = 0; row < numLines; ++row) {
            int col = diag - row;
            if (col >= 0 && col < lines[row].length()) {
                gotoxy(start_col + col, row + 1);
                cout << lines[row][col] << flush;
                this_thread::sleep_for(chrono::milliseconds(delay_ms));
            }
        }
    }
}

void clearScreen() {
    cout << "\033[2J\033[H" << flush;
}

void moveTextLeft(vector<string>& lines, int delay_ms = 25, int repetitions = 30) {
    int numLines = lines.size();
    int count = 0;

    while (count < repetitions) {
        clearScreen();

        bool isEmpty = true;
        for (int i = 0; i < numLines; ++i) {
            if (!lines[i].empty()) {
                isEmpty = false;
            }
        }

        if (isEmpty) break;  // Stop when all lines are empty

        for (int i = 0; i < numLines; ++i) {
            if (!lines[i].empty()) {
                lines[i] = lines[i].substr(1);  // Remove the very left character
            }
        }

        for (int i = 0; i < numLines; ++i) {
            if (!lines[i].empty()) {
                gotoxy(1, i + 1);
                cout << lines[i] << flush;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(delay_ms));
        count++;
    }
}

void processText(vector<string>& lines, const vector<string>& lines2, int move_delay = 25, int move_reps = 30, int zigzag_delay = 1, int start_col = 96) {
    // Initial zigzag print of lines
    printWithZigzag(lines);

    // Move the text to the left and remove the leftmost character
    moveTextLeft(lines, move_delay, move_reps);

    // Print lines2 using the zigzag algorithm starting from column 96
    printWithZigzag(lines2, zigzag_delay, start_col);

    // Clear lines vector for the next iteration
    for (auto& line : lines) {
        line.clear();
    }
}

int main() {
    vector<string> lines = {
        "ooooooooo.      .o.       ooooooooo.   oooo    oooo   .oooooo.   ooooo     ooo ooooooooo.   ",
        "`888   `Y88.   .888.      `888   `Y88. `888   .8P'   d8P'  `Y8b  `888'     `8' `888   `Y88. ",
        " 888   .d88'  .8\"888.      888   .d88'  888  d8'    888      888  888       8   888   .d88' ",
        " 888ooo88P'  .8' `888.     888ooo88P'   88888[      888      888  888       8   888ooo88P'  ",
        " 888        .88ooo8888.    888`88b.     888`88b.    888      888  888       8   888`88b.    ",
        " 888       .8'     `888.   888  `88b.   888  `88b.  `88b    d88'  `88.    .8'   888  `88b.  ",
        "o888o     o88o     o8888o o888o  o888o o888o  o888o  `Y8bood8P'     `YbodP'    o888o  o888o "
    };
    vector<string> lines2 = {
        "ooooo     ooo   .oooooo.   oooo    oooo ooooooooo.         .o.       ooooooooo.",
        "`888'     `8'  d8P'  `Y8b  `888   .8P'  `888   `Y88.      .888.      `888   `Y88.",
        " 888       8  888      888  888  d8'     888   .d88'     .8\"888.      888   .d88'",
        " 888       8  888      888  88888[       888ooo88P'     .8' `888.     888ooo88P'",
        " 888       8  888      888  888`88b.     888`88b.      .88ooo8888.    888       ",
        " `88.    .8'  `88b    d88'  888  `88b.   888  `88b.   .8'     `888.   888       ",
        "   `YbodP'     `Y8bood8P'  o888o  o888o o888o  o888o o88o     o8888o o888o      "
    };

    // Process the text with the given parameters
    processText(lines, lines2, 25, 79, 1, 14); // please check the params in the code above to see what are the params used to

    return 0;
}
