#pragma once
#include "CONSOLE.h"
#include "PERSON.h"
#include "TRAFFIC_LIGHT.h"

class VEHICLE               // lớp trừu tượng VEHICLE
{
protected:
	int x_min{}, y{};        // điểm đầu phương tiện - vị trí theo hướng y của phương tiện
	int x_max{};             // điểm cuối phương tiện
	int width{};             // độ rộng phương tiện
	bool state{};            // trạng trái của phương tiẹn(true - di chuyển, false - dừng)
	bool direction{};        // hướng đi của phương tiện(true - phải, false - trái)
	int step{};              // bước nhảy - số ô phương tiện di chuyển
	string remove = "";      // số khoảng trống để xóa phần đuôi
public:
	VEHICLE() {};
	VEHICLE(int Xmin, int Y, bool dir, int STEP = 1) {
		x_min = Xmin;
		y = Y;
		direction = dir;
		step = STEP;
		state = true;
		for (int i = 0; i < step; i++)
			remove += " ";
	}
	int GetXmin();                       // lấy điểm đầu
	int GetXmax();                       // lấy điểm cuối
	void Left();                         // di chuyển trái
	void Right();                        // di chuyển phải
	void Move();                         // di chuyển
	void Stop();                         // dừng
	void Run();                          // chạy
	int DistanceToVehicle(VEHICLE *p);   // tính khoảng cách hai phương tiện
	int DistanceToTrafficLight(TRAFFIC_LIGHT tf);           // tính khoảng cách phương tiện tới đèn giao thông
	virtual void Print() = 0;                               // in tự nhiên
	virtual void Print(int xMIN, int xMAX) = 0;             // in phương tiện trong khoảng nhất định
	virtual void RemoveTail(int xMIN, int xMAX) = 0;        // xóa bỏ phần đuôi sau khi in
	virtual bool HitPerson(PERSON p) = 0;                   // kiểm tra va chạm người chơi
	friend ostream& operator<<(ostream& ou, const VEHICLE& p);     // xuất dữ liệu phương tiện
};

