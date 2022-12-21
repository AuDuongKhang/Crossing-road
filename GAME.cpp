#include "GAME.h"


void GAME::play_BackGroud_music() {
	PlaySound(TEXT("space_line-27593 (mp3cut.net).wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void GAME::playGameOver_Sound() {
	PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

char* GAME::enterFileName(const int k)        // truyền vào số lượng ký tự tối đa
{
	char* kq = new char[k + 1];       // cấp phát dữ liệu cho biến kq
	int n, index = 0;
	do
	{
	loop:;
		n = _getch(); 
		if ((n >= 32 && n <= 126) && index < k)
		{
			// nhập các kí tự theo cơ số dec từ 32 đến 126 trong bảng mã ASCII thì in ra
			cout << char(n); 
			kq[index++] = n;          // chèn kí tự vào kq
		}
		else if (n == '\b' && index > 0) 
		{
			// nhấn Backspace thì xóa kí tự liền sau
			cout << "\b \b"; 
			kq[--index] = 0;         // xóa bỏ kí tự cuối khỏi kq
		}
		if (n == 13 && index == 0) goto loop; 
	} while (n != 13);
	// khi số lượng ký tự lớn hơn 0 và nhấn enter thì kết thúc nhập chuỗi

	kq[index] = 0;     // gán NULL vào đuôi kq
	return kq;
}

void GAME::setFiles(vector<string> path, vector<string> name) {
	this->file_path = path;
	this->file_name = name;
}

vector<string> GAME::getFilePath() {
	return this->file_path;
}

vector<string> GAME::getFileName() {
	return this->file_name;
}

bool GAME::getBackGroundMusic() { 
	return BackGround_Music; 
}

void GAME::setBackGroundMusic(bool s) {
	BackGround_Music = s;
}

void GAME::DrawFrame() {
	SetBackGroundColor((int)COLOR::PURPLE);
	for (int i = x_min - 2; i <= x_max + 2; i++) {
		gotoXY(i, y_min); cout << " ";
		gotoXY(i, y_max); cout << " ";
	}
	for (int i = y_min; i <= y_max; i++)
	{
		gotoXY(x_min - 2, i); cout << "  ";
		gotoXY(x_max + 1, i); cout << "  ";
	}
	SetBackGroundColor(BACKGROUND_COLOR);
}

void GAME::UpdateScore() {
	gotoXY(x_max + 11, y_min + 8); cout << "Your score: " << score << endl;
	gotoXY(x_max + 11, y_min + 9); cout << "High score: " << high_score << endl;
}

void GAME::UpdateLevel() {
	level++;
	person_finish = 0;
	person.clear();
	CreatePerson();
	if (level == 2) {
		speed = 50;
		first_lane = LANE(x_min, x_max, y_first, true, speed, 80, ObjectType::ELEPHANT, 1);
		second_lane = LANE(x_min, x_max, y_second, false, speed, 80, ObjectType::CAR, 1, 4, 3, true);
		third_lane = LANE(x_min, x_max, y_third, false, speed, 100, ObjectType::TRUCK, 1, 3, 3, false);
		fourth_lane = LANE(x_min, x_max, y_fourth, true, speed, 85, ObjectType::PIGTURTLE, 1);
	}
	person[person_finish].Print();
}

void GAME::CreatePerson() {
	person.push_back(PERSON((x_max + x_min) / 2, Y_MAX - 3));
	person[person_finish].Print();
}

void GAME::PrintPersons() {
	for (int i = 0; i <= person_finish; i++)
		person[i].Print();
}

void GAME::Reset() {
	level = 1;
	score = 0;
	person_finish = 0;
	state = true;
	speed = 50;
	first_lane = LANE(x_min, x_max, y_first, true, speed, 75, ObjectType::CAR, 1, 3, 3, false);
	second_lane = LANE(x_min, x_max, y_second, true, speed, 90, ObjectType::PIGTURTLE, 1);
	third_lane = LANE(x_min, x_max, y_third, false, speed, 90, ObjectType::TRUCK, 1, 2, 5);
	fourth_lane = LANE(x_min, x_max, y_fourth, false, speed, 70, ObjectType::ELEPHANT, 1);
	person.clear();
}

void GAME::OperateLanes() {
	first_lane.Operate();
	second_lane.Operate();
	third_lane.Operate();
	fourth_lane.Operate();
}

void GAME::PrintOutLanes() {
	first_lane.Print();
	second_lane.Print();
	third_lane.Print();
	fourth_lane.Print();
}

bool GAME::AccidentHappens() {
	return first_lane.HasAccident(person[person_finish])
		|| second_lane.HasAccident(person[person_finish])
		|| third_lane.HasAccident(person[person_finish])
		|| fourth_lane.HasAccident(person[person_finish]);
}

void GAME::PauseGame() {
	state = false;

	SetBackGroundColor((int)COLOR::LIGHT_WHITE);                // xóa các đối tượng phía sau và vẽ khung nhỏ khi PAUSE GAME
	for (int i = x_min_small_frame; i <= x_max_small_frame; i++) {
		for (int j = y_min_small_frame; j <= y_max_small_frame; j++) {
			gotoXY(i, j); cout << " ";
		}
	}
	SetBackGroundColor((int)COLOR::GREEN);
	for (int i = x_min_small_frame; i <= x_max_small_frame; i++) {
		gotoXY(i, y_max_small_frame); cout << " ";
		gotoXY(i, y_min_small_frame); cout << " ";
	}
	for (int i = y_min_small_frame; i <= y_max_small_frame; i++) {
		gotoXY(x_min_small_frame - 1, i); cout << "  ";
		gotoXY(x_max_small_frame, i); cout << "  ";
	}


	SetBackGroundColor((int)COLOR::LIGHT_WHITE);             	// in các thông tin trong khung nhỏ
	SetTextColor((int)COLOR::RED);
	gotoXY(x_min_small_frame + 10, y_min_small_frame + 2);
	cout << "GAME PAUSED";
	SetTextColor(TEXT_COLOR);
	gotoXY(x_min_small_frame + 3, y_min_small_frame + 4);
	cout << "Press 'P' to continue";
	gotoXY(x_min_small_frame + 3, y_min_small_frame + 5);
	cout << "Press 'L' to save game";
	gotoXY(x_min_small_frame + 3, y_min_small_frame + 6);
	cout << "Press 'Esc' to exit game";


	char press;
	do {
		press = _getch();
	} while (press != 'p' && press != 'l' && press != 27);
	// chờ người chơi nhập đúng các ký tự 'P', 'L' và 'Esc'

	SetBackGroundColor(BACKGROUND_COLOR);
	switch (press) {
	case 'p':
		for (int i = x_min_small_frame - 1; i <= x_max_small_frame + 1; i++) {
			for (int j = y_min_small_frame; j <= y_max_small_frame; j++) {
				gotoXY(i, j); cout << " ";
			}
		}
		// xóa bỏ khung nhỏ
		person[person_finish].Print();
		state = true;
		// chạy tiếp trò chơi
		break;
	case 'l':
		SaveGame();
		state = true;
		// lưu trò chơi hiện tại và chạy tiếp trò chơi
		break;
	case 27:
		system("cls");
		// thoát trò chơi
		break;
	}
}

void GAME::OperateGame() {
	state = true;
	while (state) {
		if (AccidentHappens()) {                 // Khi tai nạn xảy ra
			person[person_finish].getHit();
			GameOver();
			// cho con người hiện tại bị tông và vào kết thúc trò chơi
		}
		else {
			Sleep(speed);                        // thời gian ngủ - tốc độ in chương trình
			OperateLanes();                      
			PrintOutLanes();
			// xử lý rồi in các làn xe
			if (_kbhit()) {
				// nhận các ký tự gõ bàn phím từ người chơi
				char kitu = _getch();
				if (kitu == 's' || kitu == 'a' || kitu == 'd' || kitu == 'w' || kitu == 'S' || kitu == 'A' || kitu == 'D' || kitu == 'W') {
					person[person_finish].Remove();    // xóa hình ảnh con người hiện tại
					if ((kitu == 's' || kitu == 'S') && person[person_finish].GetY() + 3 < y_max)        // xét các trường hợp ký tự được gõ   
						person[person_finish].GoDown();
					else if ((kitu == 'w' || kitu == 'W') && person[person_finish].GetY() > y_min)
						person[person_finish].GoUp();
					else if ((kitu == 'a' || kitu == 'A') && person[person_finish].GetX() > x_min + 2)
						person[person_finish].TurnLeft();
					else if ((kitu == 'd' || kitu == 'D') && person[person_finish].GetX() + 6 < x_max - 2)
						person[person_finish].TurnRight();

					person[person_finish].Print();   // in hình ảnh con người mới
				}
				else if (kitu == 'p' || kitu == 'P') {
					PauseGame();                     // nhấn 'P' thì dừng
				} 
				else if (kitu == 'l' || kitu == 'L') {
					SaveGame();                      // nhấn 'L' thì tiến hành lưu trò chơi
				}
				else if (kitu == 27) {
					state = false;                  // nhấn 'Esc' thì thoát trò chơi
					system("cls");
				}
			}
			if (person[person_finish].GetY() == y_min + 1) {    // khi con người hiện tại đến đích
				person[person_finish].Finish();                 // con người hiện tại đã hoàn thành
				person_finish++;                                // tăng biến đếm đến con người tiếp theo
				score++;
				if (score > high_score)
					high_score++;				            	// nếu phá ký lục thì tăng điếm số cao nhất theo kèm
				UpdateScore();                                  // cập nhật điểm số
				if (person_finish == QUALIFIED_PERSONS) {
					// khi đạt đủ số người cần vượt qua cấp độ
					if (level == MAX_LEVEL)
						// đạt cấp độ tối đa thì phá đảo game
						GameComplete();
					else {
						// không thì đi tiếp cấp độ tiếp theo
						ClearAllObject();
						UpdateLevel();
						drawScoreBoard();
					}
				}
				else
					// nếu chưa đạt thì chơi tiếp
					CreatePerson();
			}
		}
	}
}

void GAME::NewGame() {
	system(SYSTEM_COLOR);
	Reset();
	CreatePerson();
	DrawFrame();
	drawScoreBoard();
	OperateGame();
}

void GAME::GameComplete() {
	state = false;
	ClearAllObject();
	// giao dien khi pha dao game...
	while (1)
	{
		gotoXY(30, 18);
		SetTextColor((int)COLOR::LIGHT_RED);
		cout << u8"██    ██ ██  ██████ ████████  ██████  ██████  ██    ██";
		gotoXY(30, 19);
		cout << u8"██    ██ ██ ██         ██    ██    ██ ██   ██  ██  ██";
		gotoXY(30, 20);
		cout << u8"██    ██ ██ ██         ██    ██    ██ ██████    ████";
		gotoXY(30, 21);
		cout << u8" ██  ██  ██ ██         ██    ██    ██ ██   ██    ██";
		gotoXY(30, 22);
		cout << u8"  ████   ██  ██████    ██     ██████  ██   ██    ██";
	}
	system("cls");
}

void GAME::GameOver() {
	state = false;
	ClearAllObject();
	person[person_finish].Print();
	AMBULANCE amb(x_min - AMBULANCE_WTDTH, person[person_finish].GetY() - 2);        // tạo xe cứu thương
	playGameOver_Sound();                          // chạy nhạc thua trò chơi
	while (amb.GetXmin() <= x_max) {               
		// chạy xe cứu thương
		amb.Move();
		amb.Print(x_min, x_max);
		if (amb.GetXmin() == person[person_finish].GetX() - 1)
			// chạy đến con người thì dừng lại một lúc ~ đưa con người lên xe 
			Sleep(1300);
		Sleep(9);
	}
	// them giao dien khi game over...
	while (1)
	{
		gotoXY(25, 18);
		SetTextColor((int)COLOR::LIGHT_RED);
		cout << u8" ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████";
		gotoXY(25, 19);
		cout << u8"██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██";
		gotoXY(25, 20);
		cout << u8"██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████";
		gotoXY(25, 21);
		cout << u8"██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██";
		gotoXY(25, 22);
		cout << u8" ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██ ";
		gotoXY(55, 25);
		cout << "Your score: " << score;
		gotoXY(55, 26);
		char kitu = _getch();
		if (kitu == 'y' || kitu == 'Y')
		{
			NewGame();
		}
		else if (kitu == 'n' || kitu == 'N')
		{

		}
	}
	
	if (BackGround_Music == true)                 // kiểm tra nhạc nền có đang bật để chạy nhạc
		play_BackGroud_music();

	system("cls");
}

void GAME::ClearAllObject() {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min + 1; j <= y_max - 1; j++) {
			gotoXY(i, j); cout << " ";
		}
	}
}

void GAME::drawScoreBoard()
{
	gotoXY(x_min + 30, y_min - 6); cout << " __    _____ __    ___ _____ __    ";
	gotoXY(x_min + 30, y_min - 5); cout << "|  |  |   __|  \\  /  /|   __|  |   ";
	gotoXY(x_min + 30, y_min - 4); cout << "|  |__|   __|\\  \\/  / |   __|  |__ ";
	gotoXY(x_min + 30, y_min - 3); cout << "|_____|_____| \\____/  |_____|_____|";

	if (level == 1) {
		gotoXY(x_min + 70, y_min - 6); cout << " ___  ";
		gotoXY(x_min + 70, y_min - 5); cout << "|_  |  ";
		gotoXY(x_min + 70, y_min - 4); cout << " _| |_ ";
		gotoXY(x_min + 70, y_min - 3); cout << "|_____|";
	}
	else if (level == 2) {
		gotoXY(x_min + 70, y_min - 6); cout << " _____ ";
		gotoXY(x_min + 70, y_min - 5); cout << "|__   |";
		gotoXY(x_min + 70, y_min - 4); cout << "|   __|";
		gotoXY(x_min + 70, y_min - 3); cout << "|_____|";
	}

	gotoXY(x_max + 19, y_min); cout << "								";
	gotoXY(x_max + 19, y_min + 1); cout << " _____ _____ _____ _____ _____  ";
	gotoXY(x_max + 19, y_min + 2); cout << "|   __|     |     | __  |   __| ";
	gotoXY(x_max + 19, y_min + 3); cout << "|__   |   --|  |  |    -|   __| ";
	gotoXY(x_max + 19, y_min + 4); cout << "|_____|_____|_____|__|__|_____| ";
	gotoXY(x_max + 19, y_min + 5); cout << "                                ";


	gotoXY(x_max + 11, y_min + 8); cout << "Your score: " << score << endl;
	gotoXY(x_max + 11, y_min + 9); cout << "High score: " << high_score << endl;

	gotoXY(x_max + 7, y_min + 13); cout << " _____ _____ _ _ _    _____ _____    _____ __    _____ __ __ ";
	gotoXY(x_max + 7, y_min + 14); cout << "|  |  |     | | | |  |_   _|     |  |  _  |  |  |  _  |  |  |";
	gotoXY(x_max + 7, y_min + 15); cout << "|     |  |  | | | |    | | |  |  |  |   __|  |__|     |_   _|";
	gotoXY(x_max + 7, y_min + 16); cout << "|__|__|_____|_____|    |_| |_____|  |__|  |_____|__|__| |_|  ";


	gotoXY(x_max + 11, y_min + 19); cout << "Try not to get hit by any cars, trucks or birds.";
	gotoXY(x_max + 11, y_min + 20); cout << "You have to cross the street also.";
	gotoXY(x_max + 11, y_min + 21); cout << "Using 'W', 'A', 'S', 'D' to move";

	gotoXY(x_max + 11, y_min + 25);
	cout << "Pause press 'P'";
	gotoXY(x_max + 11, y_min + 27);
	cout << "Save press 'L'";
	gotoXY(x_max + 11, y_min + 29);
	cout << "Exit press 'Esc'";

}

void GAME::LoadGame(int index) {             // truyền vào index của file trong danh sách đường dẫn
	Reset();
	ifstream file;
	file.open(file_path[index]);             // mở file thứ index
	string temp;
	int n;
	if (file.is_open()) {
		getline(file, temp, '\n');           // bỏ qua tên file và nhập dữ liệu
		file >> level >> score >> speed;
		file >> n;
		person.resize(n);
		person_finish = n - 1;
		for (int i = 0; i < n; i++)
			file >> person[i];
		file >> first_lane;
		file >> second_lane;
		file >> third_lane;
		file >> fourth_lane;
		file.close();
	}
}

bool GAME::fileSameName(string name) {
	for (string temp : file_name) {
		if (temp == name)
			return true;
	}
	return false;
}

void GAME::SaveGame() {
	ShowCur(true);

	SetBackGroundColor((int)COLOR::LIGHT_WHITE);                // xóa các đối tượng phía sau và vẽ khung nhỏ khi SAVE GAME
	for (int i = x_min_small_frame; i <= x_max_small_frame; i++) {
		for (int j = y_min_small_frame; j <= y_max_small_frame; j++) {
			gotoXY(i, j); cout << " ";
		}
	}
	SetBackGroundColor((int)COLOR::GREEN);
	for (int i = x_min_small_frame; i <= x_max_small_frame; i++) {
		gotoXY(i, y_max_small_frame); cout << " ";
		gotoXY(i, y_min_small_frame); cout << " ";
	}
	for (int i = y_min_small_frame; i <= y_max_small_frame; i++) {
		gotoXY(x_min_small_frame - 1, i); cout << "  ";
		gotoXY(x_max_small_frame, i); cout << "  ";
	}


	SetBackGroundColor((int)COLOR::LIGHT_WHITE);            	// in thông tin trong khung nhỏ
	SetTextColor((int)COLOR::RED);
	gotoXY(x_min_small_frame + 10, y_min_small_frame + 2);
	gotoXY(x_min_small_frame + 10, y_min_small_frame + 2);
	cout << "  SAVE FILE  ";
	SetTextColor(TEXT_COLOR);
	gotoXY(x_min_small_frame + 3, y_min_small_frame + 5);
	cout << "Enter file's name:";


	string text; // tên file
	do {
		gotoXY(x_min_small_frame + 3, y_min_small_frame + 6); cout << "                          ";
		gotoXY(x_min_small_frame + 3, y_min_small_frame + 6);
		text = enterFileName(24);
		if (text == "BACK") {
			gotoXY(x_min_small_frame + 3, y_min_small_frame + 4); 
			cout << "Invalid name          ";
		}
		else if (fileSameName(text)) {
			gotoXY(x_min_small_frame + 3, y_min_small_frame + 4);
			cout << "This name has existed      ";
		}
	} while (text == "BACK" || text.find_first_not_of(' ') == string::npos || fileSameName(text));
	// chờ người chơi nhập đúng tên file

	string fp = to_string(file_path.size() + 1).append(".txt");   // tạo đường dẫn file mới
	file_path.push_back(fp);                                      // thêm đường dẫn file vào danh sách                                    
	file_name.push_back(text);                                    // thêm tên file vào danh sách
	ofstream file;
	file.open(fp);
	if (file.is_open()) {
		file << text << endl;                                     // nhập tên file và dữ liêu vào
		file << level << " " << score << " " << speed << endl;
		file << person.size() << endl;
		for (int i = 0; i < person.size(); i++)
			file << person[i] << endl;
		file << first_lane;
		file << second_lane;
		file << third_lane;
		file << fourth_lane;
		file.close();
	}
	ShowCur(false);


	SetTextColor((int)COLOR::BLUE);                              // thông báo lưu file thành công
	gotoXY(x_min_small_frame + 10, y_min_small_frame + 7);
	cout << "File saved";
	Sleep(1000);
	 
	SetTextColor(TEXT_COLOR);                                    // xóa bỏ khung nhỏ và chơi tiếp
	SetBackGroundColor(BACKGROUND_COLOR);
	for (int i = x_min_small_frame - 1; i <= x_max_small_frame + 1; i++) {
		for (int j = y_min_small_frame; j <= y_max_small_frame; j++) {
			gotoXY(i, j); cout << " ";
		}
	}
	person[person_finish].Print();
}