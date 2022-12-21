#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <time.h>
#include <mmsystem.h>
#include <thread>
using namespace std;

enum class COLOR {         // nhóm màu
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_AQUA,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_WHITE
};

#define BACKGROUND_COLOR (int)COLOR::WHITE   // màu nền mặc định 
#define TEXT_COLOR (int)COLOR::BLACK       // màu kí tự mặc định
#define SYSTEM_COLOR "color 70"

void gotoXY(short x, short y);           // di chuyển con trỏ đến vị trí [x,y] trong console

void ShowCur(bool CursorVisibility);      // ẩn, hiện con trỏ

void SetBackGroundColor(WORD color);      // thay đổi màu nền của kí tự

void SetTextColor(WORD color);          // thay đổi màu của kí tự

void FixConsoleWindow();          // vô hiệu hóa tính năng thay đổi kích thước console

void resizeConsole(int width, int height);        // thay đổi kích thước console

void ClearScreen();            // xóa toàn bộ kí tự trên console
