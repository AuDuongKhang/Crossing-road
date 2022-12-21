#pragma once
#include "LANE.h"

#define X_MIN 6          // điểm đầu khung chơi
#define X_MAX 111        // điểm cuối khung chơi
#define Y_MIN 7          // độ cao đầu khung chơi
#define Y_MAX 38         // độ cao cuối khung chơi
#define MAX_LEVEL 2           // cấp độ tối đa     
#define QUALIFIED_PERSONS 3   // số người cần hoàn thành để qua cấp độ mới


class GAME
{
	int high_score = 0;              // điểm số cao nhất
	int x_min = X_MIN, x_max = X_MAX;
	int y_min = Y_MIN, y_max = Y_MAX;
	int x_min_small_frame = X_MIN + (X_MAX - X_MIN) / 2 - 12, x_max_small_frame = x_min_small_frame + 30;  // điểm đầu, điểm cuối của con khung nhỏ
	int y_min_small_frame = Y_MIN + (Y_MAX - Y_MIN) / 2 - 6, y_max_small_frame = y_min_small_frame + 9;    // độ cao đầu, độ cao cuối của một khung nhỏ
	int y_first = Y_MIN + 4, y_second = Y_MIN + 10, y_third = Y_MAX - 14, y_fourth = Y_MAX - 8;        // độ cao đầu của các làn đường
	int level{};                   // cấp độ 
	int score{};                   // điểm số
	int person_finish{};           // biến đếm số người hoàn thành
	int speed{};                   // tốc độ các vật cản
	bool state{};                  // trạng thái trò chơi(true - đang chạy, false - dừng lại)
	bool BackGround_Music = true;                           // trạng thái nhạc nền(true - đang bật, false - đã tắt)
	vector<PERSON> person;                                  // danh sách con người
	vector<string> file_path;                               // danh sách đường dẫn các file
	vector<string> file_name;                               // danh sách tên các file
	LANE first_lane, second_lane, third_lane, fourth_lane;  // 4 làn đường
	char* enterFileName(const int k);                       // nhập tên file 
	bool fileSameName(string name);                         // kiểm tra file trùng lặp
	void playGameOver_Sound();                              // chạy nhạc khi thua trò chơi
public:
	GAME() {
		ifstream file("high_score.txt");
		if (file.is_open()) {
			file >> high_score;
			file.close();
		}
	};
	~GAME() {
		ofstream file("high_score.txt");
		if (file.is_open()) {
			file << high_score;
			file.close();
		}
	};
	vector<string> getFilePath();                             // trả về danh sách các đường dẫn file
	vector<string> getFileName();                             // trả về tên các file
	bool getBackGroundMusic();                                // trả về trạng thái nhạc nền 
	void setBackGroundMusic(bool s);                          // cài trạng thái nhạc nền 
	void play_BackGroud_music();                              // chạy nhạc nền
	void setFiles(vector<string> path, vector<string> name);  // cài các đường dẫn file, tên file
	void DrawFrame();                                         // vẽ khung trò chơi
	void UpdateScore();                                       // cập nhật điểm số
	void UpdateLevel();                                       // cập nhật dữ liệu cấp độ mới
	void NewGame();                                           // trò chơi mới
	void Reset();                                             // đặt lại dữ liệu trò chơi
 	void CreatePerson();                                      // tạo con người
	void PrintPersons();                                      // in hình ảnh các con người
	void OperateLanes();                                      // xử lý dữ liệu các làn đường
	void PrintOutLanes();                                     // in hình ảnh các làn đường
	void OperateGame();                                       // vận hành trò chơi
	bool AccidentHappens();                                   // kiểm tra tai nạn
	void drawScoreBoard();                                    // vẽ thông tin điểm, hướng dẫn bên khung chơi
	void SaveGame();                                          // lưu trò chơi hiện tại
	void LoadGame(int index);								  // tải trò chơi
	void GameOver();                                          // thua trò chơi
	void GameComplete();                                      // hoàn thành trò chơi
	void ClearAllObject();                                    // xóa toàn bộ đối đượng trong khung
	void PauseGame();                                         // dừng trò chơi
};

