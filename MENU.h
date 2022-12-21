#pragma once
#include "GAME.h"

class MENU
{
	vector<string> choice = { "NEW GAME", "LOAD GAME", "MUSIC:ON", "FAQs", "ABOUT US", "EXIT GAME" }; // thông tin các nhãn lựa chọn
	int space = 3;                      // khoảng cách các nhãn
	int x = 85, y = 15;                 // tọa độ nhãn đầu tiên
	int x_board = 80, y_board = 17;     // tọa độ bảng chứa các file đã lưu
	void getFilesSaved();               // đọc dữ liệu các file mở chương trình và gán hai danh sách vào đối tượng game
	GAME game;                          // đối tượng game
public:
	MENU() {
		getFilesSaved();
	}
	~MENU() = default;

	void menuControl();                 // chạy giao diện chương trình
	void decorateMenu();                // trang trí giao diện chương trình
	void drawTitle();                   // in tiêu đề trò chơi
	// void drawLeaderBoard();
	void showSavedFilesBoard();         // in bảng chứa các file đã lưu
	void printFAQs();                   // in thông tin FAQs
	void printAboutUS();                // in thông tin About Us
};

