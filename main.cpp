// Importing necessary libraries and defining a few variables 
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string> 
//#include "ansi_escape_codes.hpp" //
// General form for ANSI escape codes \ESC[code Your output \ESC[m // 

using namespace std; 
// using namespace ansi_escape_codes; //

bool isGameRunning = false;

// Grid Dimensions 
int xAxis = 25;
int yAxis = 25;
int useryValue = 12;
int userxValue = 12;

int score = 0;

// Creating the Grid for the Game 

void countScore(int score) {   
    while (isGameRunning = true) {
        Sleep(50);
        score++;
        cout << "\r" << score << "score       " << flush;
    }
}

// Creating User Grid and handling user input 

void createGrid() {
    bool isGameRunning = true;
    int player = 1;
    int userGrid[xAxis][yAxis];

    for (int i = 0; i < xAxis; i++) {
        for (int j = 0; j < yAxis; j++) {
            userGrid[i][j] = 0;
            userGrid[useryValue][userxValue] = player;
        }
    }

    for (int i = 0; i < xAxis; i++) {
        for (int j = 0; j < yAxis; j++) {
            cout << userGrid[i][j] << " ";
        }
        cout << "\n";
    }
    
    for (;;) {
        char userMovement = getch();
        if (userMovement == 'a') {
            userxValue = userxValue -1;
            userGrid[useryValue][userxValue] = player;
            system("cls");
            createGrid();
        }
        if (userMovement == 'd') {
            userxValue = userxValue + 1;
            userGrid[useryValue][userxValue] = player;
            system("cls");
            createGrid();
        }
        if (userMovement == 'w') {
            useryValue = useryValue + 1; 
            userGrid[useryValue][userxValue] = player;
            system("cls");
            createGrid();
        }
        if (userMovement == 's') {
            useryValue = useryValue - 1;
            userGrid[useryValue][userxValue] = player;
            system("cls");
            createGrid();
        }
    }
    // Note to self, separate the function which creates the grid, and the one that handles the input  
}

// Setting up instructions, and allowing the use to start the game when they would like 

void instructions() {
    cout << "Welcome to Deepinder's Racing Game" << endl;
    Sleep(50); 
    cout << "Use the Keys A and D to dodge the obstacles" << endl;
    cout << "Your score will increase the longer you survive" << endl;
    Sleep(50);    cout << "Hit the y key to begin" << endl;
    char input = getch();
    if (input == 'y') {
    createGrid();
    countScore(score);
    }
}

// Main Function 

int main() {
    system("COLOR F2");
    system("COLOR 60");
    instructions();
}