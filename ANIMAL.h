#pragma once
#pragma once
#include "CONSOLE.h"
#include "PERSON.h"

class ANIMAL                 // lớp trừu tượng animal 
{
protected:
	int x_min{}, y{};             // điểm đầu con vật - vị trí theo hướng y của con vật
 	int x_max{};                  // điểm cuối con vật
	int width{};                  // độ rộng của con vật
	bool direction{};             // hướng đi của con vật(true - phải, false - trái)
	int step{};                   // bước nhảy - số ô phương tiện di chuyển 
	string remove = "";           // số khoảng trống để xóa phần đuôi
public:
	ANIMAL() {};
	ANIMAL(int Xmin, int Y, bool dir, int STEP = 1) {
		x_min = Xmin; y = Y;
		direction = dir;
		step = STEP;
		for (int i = 0; i < step; i++)
			remove += " ";
	}
	int GetXmin();                                         // lấy điểm đầu
	int GetXmax();                                         // lấy điểm cuối
	void Left();                                           // di chuyển trái
	void Right();                                          // di chuyển phải
	void Move();                                           // di chuyển
	virtual void Print() = 0;                              // in tự nhiên
	virtual void Print(int xMIN, int xMAX) = 0;            // in con vật trong khoảng nhất định
	virtual void RemoveTail(int xMIN, int xMAX) = 0;       // xóa bỏ phần đuôi sau khi in
	virtual bool HitPerson(PERSON p) = 0;                  //  kiểm tra va chạm người chơi
	friend ostream& operator<<(ostream& ou, const ANIMAL& p);      // xuất con vật
};

