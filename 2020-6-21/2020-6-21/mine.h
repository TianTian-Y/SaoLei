#ifndef _MINE_H
#define _MINE_H

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

#pragma warning (disable:4996)

#define ROW 12
#define COL 12
#define MINE 20

void Game();
void InitBoard(char Board[][COL], int row, int col, char elem); 
void ShowBoard(char Board[][COL], int row, int col);
void SetMine(char Mine[][COL], int row, int col);
char GetMine(char Mine[][y], int x, int y);



#endif