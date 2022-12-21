#include "Menu.h"

void MENU::menuControl()
{
	system(SYSTEM_COLOR);
	system("cls");
	bool input = true;
	int pos = 0;                        // biến vị trí

	ShowCur(false);
	game.play_BackGroud_music();        // chạy nhạc nền trò chơi
	drawTitle();
	decorateMenu();
	input = true;

	while (true)
	{
		space = 3;
		if (input)
		{
			for (int i = 0; i < choice.size(); i++)
			{
				if (i == pos)
					// khi trùng vị trí các mục thì in màu đỏ
					SetTextColor((int)COLOR::RED);
				else
					// không thì màu đen
					SetTextColor((int)COLOR::BLACK);

				if (i == 3)
					// trường hợp đặc biệt khi in "FAQs"
					gotoXY(x + 2, y + i * space);
				else
					gotoXY(x, y + i * space);
				cout << choice[i] << endl;
				gotoXY(x - 6, y + i * space - 1);
				cout << "====================";
				gotoXY(x - 6, y + i * space + 1);
				cout << "====================";
			}
		}
		input = false;
		// nhận ký tự gõ từ người chơi
		switch (_getch())
		{
		case 'w': case 'W':
			input = true;
			pos--;
			pos = (pos + choice.size()) % choice.size();
			break;
		case 's': case 'S':
			input = true;
			pos++;
			pos %= choice.size();
			break;
		case 13:
			input = true;
			switch (pos)
			{
			case 0:
				// NEW GAME
				system("cls");
				game.NewGame();
				break;
			case 1:
				// LOAD GAME
				showSavedFilesBoard();
				break;
			case 2:
				// SET MUSIC
				if (game.getBackGroundMusic()) {
					PlaySound(0, 0, 0);
					choice[2] = "MUSIC:OFF";
					game.setBackGroundMusic(false);
				}
				else {
					game.play_BackGroud_music();
					choice[2] = "MUSIC:ON ";
					game.setBackGroundMusic(true);
				}
				continue;
				break;
			case 3: 
				// FAQs
				printFAQs();
				break;
			case 4: 
				// ABOUT US
				printAboutUS();
				break;
			case 5: 
				// EXIT
				system("cls");
				system("color 07");
				return;
			}
			drawTitle();
			decorateMenu();
		}
	}
}

void MENU::drawTitle()
{
	SetTextColor((int)COLOR::LIGHT_PURPLE);

	gotoXY(x - 41, 6); cout << u8"▄█████▄ ██████▄ ▄██████▄ ▄█████▄ ▄█████▄ ██ ███    ██ ▄██████▄     ██████▄ ▄██████▄ ▄█████▄ ██████▄";
	gotoXY(x - 41, 7); cout << u8"██   ▀▀ ██   ██ ██    ██ ██    ▀ ██    ▀ ██ ████   ██ ██    ▀▀     ██   ██ ██    ██ ██   ██ ██   ██";
	gotoXY(x - 41, 8); cout << u8"██      ██████  ██    ██ ▀█████▄ ▀█████▄ ██ ██ ██  ██ ██   ▄▄▄     ██████  ██    ██ ███████ ██   ██";
	gotoXY(x - 41, 9); cout << u8"██   ▄▄ ██   ██ ██    ██ ▄    ██ ▄    ██ ██ ██  ██ ██ ██    ██     ██   ██ ██    ██ ██   ██ ██   ██";
   gotoXY(x - 41, 10); cout << u8"▀█████▀ ██   ██ ▀██████▀ ▀█████▀ ▀█████▀ ██ ██   ████ ▀██████▀     ██   ██ ▀██████▀ ██   ██ ██████▀";

}

//void MENU::drawLeaderBoard()
//{
//	system("cls");
//	system(SYSTEM_COLOR);
//	SetTextColor((int)COLOR::LIGHT_PURPLE);
//	gotoXY(x - 30, 6); cout << "| |     ___   ____    _| |  ___   ____ | |     ___   ____   ____   _| |";
//	gotoXY(x - 30, 7); cout << "| |__  / -_) / _` | / _` | / -_) | '_| | '_ | / _ | / _` | | '_| / _` |";
//	gotoXY(x - 30, 8); cout << "|____| |___| |__,_| |__,_| |___| |_|   |_.__/ |___/ |__,_| |_|   |__,_|";
//
//	
//
//	gotoXY(x, 22); cout << ".... Press any key to go back ....";
//	if (_getch())
//		ClearScreen();
//}

void MENU::printFAQs()
{
	system("cls");
	system(SYSTEM_COLOR);
	SetTextColor((int)COLOR::LIGHT_PURPLE);
	gotoXY(x - 13, y - 6); cout << "ooooooooooo   o        oooooooo      8880oooooo";
	gotoXY(x - 13, y - 5); cout << "888          888      o888   888o   8888";
	gotoXY(x - 13, y - 4); cout << "888ooo88    8  88    888       888    888ooooooo";
	gotoXY(x - 13, y - 3); cout << "888        8oooo88    888o   8o888           888 ";
	gotoXY(x - 13, y - 2); cout << "o888o    o88o  o888o   88ooo880o     88oooooo88";
	gotoXY(x - 13, y - 1); cout << "                             888o8             ";


	gotoXY(x - 16, y + 4); cout << "WHAT IS THIS?                 " << endl;
	gotoXY(x - 16, y + 5); cout << "Crossing Road is a little game with a simple concept:" << endl;
	gotoXY(x - 16, y + 6); cout << "help your character cross a road." << endl;
	gotoXY(x - 16, y + 7); cout << "HOW TO PLAY?                 " << endl;
	gotoXY(x - 16, y + 8); cout << "Use 'W' or 'S' to move your character from side to side" << endl;
	gotoXY(x - 16, y + 9); cout << "while 'A' or 'D' to move left and right." << endl;
	gotoXY(x - 10, y + 12); cout << ".... Press any key to get back ...." << endl;

	if (_getch())
		ClearScreen();
}

void MENU::printAboutUS()
{
	system("cls");
	system(SYSTEM_COLOR);
	SetTextColor((int)COLOR::LIGHT_PURPLE);
	gotoXY(x - 32, y - 8); cout << "     o      oooooooooo    ooooooo  ooooo  oooo ooooooooooo      ooooo  oooo oooooooo8  ";
	gotoXY(x - 32, y - 7); cout << "    888      888    888 o888   888o 888    88  88  888  88       888    88 888         ";
	gotoXY(x - 32, y - 6); cout << "   8  88     888oooo88  888     888 888    88      888           888    88  888oooooo  ";
	gotoXY(x - 32, y - 5); cout << "  8oooo88    888    888 888o   o888 888    88      888           888    88         888 ";
	gotoXY(x - 32, y - 4); cout << "o88o  o888o o888ooo888    88ooo88    888oo88      o888o           888oo88  o88oooo888  ";

	gotoXY(x - 14, y); cout << "  PROJECT CROSSING ROAD - HCMUS - 21CLC1";

	gotoXY(x - 7, y + 2); cout << "ABOUT US:          " << endl;
	gotoXY(x - 7, y + 3); cout << "21127621 - Au Duong Khang" << endl;
	gotoXY(x - 7, y + 4); cout << "21127570 - Tran Minh Dat" << endl;
	gotoXY(x - 7, y + 5); cout << "21127596 - Bui Minh Duc" << endl;
	gotoXY(x - 7, y + 6); cout << "21127068 - Ngo Hoang Khang" << endl;
	gotoXY(x - 7, y + 7); cout << "Advisor: PhD. Truong Toan Thinh" << endl;
	gotoXY(x - 15, y + 12); cout << ".... Press any key to hide get back ...." << endl;

	if (_getch())
		ClearScreen();
}

void MENU::decorateMenu() {
	string side = u8"█";
	string line = u8"███████";
	SetTextColor((int)COLOR::YELLOW);
	for (int i = 3; i < 175; i += 11) {
		gotoXY(i, y + 7); cout << line;
	}
	SetTextColor((int)COLOR::BLACK);
	TRAFFIC_LIGHT(178, y + 2, 1, 1, false).Print();
	CAR(30, y + 2, true).Print();
	TRUCK(140, y + 2, true).Print();
	PIGTURTLE(40, y + 8, false).Print();
	ELEPHANT(125, y + 8, false).Print();
	for (int i = 0; i < 180; i++) {
		gotoXY(i, y + 1); cout << side;
		gotoXY(i, y + 13); cout << side;
	}
}

void MENU::getFilesSaved() {
	vector<string> file_path;
	vector<string> file_name;
	string temp = "1.txt"; 
	string name_file;
	ifstream file;
	file.open(temp);
	while (file.is_open()) {                  // mở 1.txt, 2.txt... cho đến khi không mở được nữa
		file_path.push_back(temp);
		getline(file, name_file, '\n');
		file_name.push_back(name_file);
		file.close();
		temp[0] += 1;
		file.open(temp);
	}
	game.setFiles(file_path, file_name);      // cài các danh sách đã đọc cho game
}

void MENU::showSavedFilesBoard() {
	vector<string> file_name = game.getFileName();     // lấy tên các file
	bool state = true;
	file_name.push_back("BACK");                // chèn thêm nhãn "BACK"
	bool input = true;
	int pos = 0;
	space = 1;

	// xóa các nhãn ở giao diện
	for (int k = y_board - 4; k < 40; k++) {
		gotoXY(x - 15, k);
		cout << "                                         ";
	}

	// in thông tin trong LOAD GAME
	gotoXY(x_board - 10, y_board - 4); cout << "=========================================";
	gotoXY(x_board + 4, y_board - 3); cout << "  SAVED FILES";
	gotoXY(x_board - 10, y_board - 2); cout << "=========================================";
	while (state) {
		if (input) {
			for (int i = 0; i < file_name.size(); i++) {
				if (i == pos)
					SetTextColor((int)COLOR::RED);
				else
					SetTextColor((int)COLOR::BLACK);
				if (i == file_name.size() - 1) {
					gotoXY(x_board + 6, y_board + i * space + 1);
					cout << "==========";
					gotoXY(x_board + 6, y_board + i * space + 3);
					cout << "==========";
					gotoXY(x_board + 9, y_board + i * space + 2);
				}
				else
				    gotoXY(x_board - 2, y_board + i * space);
				cout << file_name[i] << endl;
			}
		}
		input = false;
		switch (_getch()) {
		case 'w': case 'W':
			input = true;
			pos--;
			pos = (pos + file_name.size()) % file_name.size();
			break;
		case 's': case 'S':
			input = true;
			pos++;
			pos %= file_name.size();
			break;
		case 13:
			input = true;
			if (pos == file_name.size() - 1){
				// chọn "BACK"
				for (int k = 0; k < file_name.size(); k++) {
					gotoXY(x_board, y_board + k * space);
					cout << "                            ";
				}
			}
			else {
				// chọn file để tải
				game.LoadGame(pos);
				system("cls");
				game.PrintPersons();
				game.DrawFrame();
				game.drawScoreBoard();
				game.PrintOutLanes();
				game.OperateGame();
			}
			state = false;
			break;
		case 27:
			// nhấn 'Esc'
			input = true;
			state = false;
			break;
		}

	}

	// xóa thông tin trong LOAD GAME khi trở về giao diện chinh
	for (int k = y_board - 4; k < 43; k++) {
		gotoXY(x - 15, k);
		cout << "                                         ";
	}
}