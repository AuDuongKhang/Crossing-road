#pragma once
#include "CAR.h"
#include "ELEPHANT.h"
#include "TRUCK.h"
#include "PIGTURTLE.h"
#include "AMBULANCE.h"

enum class ObjectType {          // danh sách các loại vật cản
	CAR,
	TRUCK,
	ELEPHANT,
	PIGTURTLE
};

class LANE
{
	int x_min{}, x_max{};                   // điểm đầu, điểm cuối làn đường
	int y{};                                // độ cao làn đường trong console
	bool direction{};                       // hướng đi của vật cản(true - phải, false - trái)
	int time_appear{};                      // khoảng thời gian xuất hiện giữa các vật cản 
	int time_run{};                         // biến đếm thời gian
	int speed{};                            // tốc độ vật cản
	ObjectType type{};                      // loại vật cản
	int step{};                             // số bước đi của vật cản 
	TRAFFIC_LIGHT tf;                       // đèn giao thông
	vector<ANIMAL*> animal;                 // danh sách con vật
	vector<VEHICLE*> vehicle;               // danh sách phương thiện
public:
	LANE() {};
	LANE(int Xmin, int Xmax, int Y, bool dir, int sp, int time_a, ObjectType TYPE, int st, int rt = 3, int gd = 3, bool lc = true) {
		x_min = Xmin; x_max = Xmax;
		y = Y; direction = dir;
		time_appear = time_a;
		speed = sp;
		time_run = rand() % time_appear;
		step = st;
		type = TYPE;
		if (type == ObjectType::CAR || type == ObjectType::TRUCK) {
			if (direction)
				tf = TRAFFIC_LIGHT(x_max - 1, y, (rt * 1000) / speed, (gd * 1000) / speed, lc);
			else 
				tf = TRAFFIC_LIGHT(x_min, y, (rt * 1000) / speed, (gd * 1000) / speed, lc);
		}
	}
	~LANE() {
		vehicle.clear();
		animal.clear();
	}
	void CreateObject();                   // tạo vật cản
	void ProcessDataObject();              // xử lý dữ liệu các vật cản
	void ProcessTrafficLight();            // xử lý dữ liệu đèn giao thông
	void Operate();                        // chạy làn đường
	void Print();                          // xuất hình ảnh làn đường, đèn và vật cản
	bool HasAccident(PERSON p);            // kiểm tra tai nạn với con người
	friend ostream& operator<<(ostream& ou, const LANE& p);        // xuất dữ liệu làn đường
	friend istream& operator>>(istream& in, LANE& p);              // nhập dữ liệu làn đường
};

