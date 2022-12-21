#include "MENU.h"

int main() {
	resizeConsole(1333, 750);                       // thay đổi kích thước console
	FixConsoleWindow();                             // vô hiệu hóa thay đổi kích thước console
	SetConsoleTitle(L"Crossing Road");              // đặt tiêu đề console
	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);  // ẩn thanh cuộn
	system(SYSTEM_COLOR);                           // cài màu nền, màu chữ chương trình
	ShowCur(false);                                 // ẩn con trỏ
	SetConsoleOutputCP(65001);                      // cài xuất theo code UTF-8
	MENU menu;                                      // tạo đối tượng menu
	menu.menuControl();                             // chạy chương trình
	return 0;
}