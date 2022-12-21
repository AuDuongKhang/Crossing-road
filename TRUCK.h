#pragma once
#include "VEHICLE.h"
 
#define TRUCK_WIDTH 21          // độ rộng xe tải

/*
.============.____
|  GROUP 10  |  []|_             // hình ảnh in của xe tải 
|            |      |
'=(0)====(0)='==(0)='
*/

class TRUCK : public VEHICLE                      // lớp TRUCK kế thừa lớp VEHICLE
{                                                          // các thuộc tính, phương thức tương tự như xe ô tô
	string shape[4] = {".============.____",
	                   "|  GROUP 10  |  []|_",
	                   "|            |      |",
	                   "'=(0)====(0)='==(0)='"};
	pair<int, int> space[4] = { {0, 3}, {0,1}, {0, 0}, {0, 0} };
public:
	TRUCK() {};
	TRUCK(int Xmin, int Y, bool dir, int STEP = 1) : VEHICLE(Xmin, Y, dir, STEP) {
		this->width = TRUCK_WIDTH;
		this->x_max = this->x_min + this->width - 1;
		if (!dir) {
			shape[0] = "____.===========-.";
			shape[1] = "_|[]  |  GROUP 10  |";
			shape[2] = "|      |            |";
			shape[3] = "'=(0)=='=(0)====(0)='";
		}
	}
	void Print();
	void Print(int xMIN, int xMAX);
	void RemoveTail(int xMIN, int xMAX);
	bool HitPerson(PERSON p);
	friend istream& operator>>(istream& in, TRUCK& p);
};
