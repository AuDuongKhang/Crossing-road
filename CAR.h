#pragma once
#include "VEHICLE.h"

#define CAR_WIDTH 11        // độ rộng của xe ô tô

/*
  _______
 /____  |_                 // hỉnh ảnh khi in xe ô tô 
|         |
'=[]===[]='
*/
class CAR : public VEHICLE          // lớp CAR kế thừa lớp VEHICLE
{ 
	string shape[4] = { "_______",           // chuỗi chứa hình ảnh xe ô tô
		                "/____  |_" ,
		                "|         |" ,
		                "'=[]===[]='" };
	int space[4] = { 2, 1, 0 ,0 };           // số khoảng trống ở hai đầu của mỗi chuỗi trong shape
public:
	CAR() {};
	CAR(int Xmin, int Y, bool dir, int STEP = 1) : VEHICLE(Xmin, Y, dir, STEP) {
		this->width = CAR_WIDTH;
		this->x_max = this->x_min + this->width - 1;
		if (!dir)
			shape[1] = "_|  ____\\";
	}
	void Print();
	void Print(int xMIN, int xMAX);
	void RemoveTail(int xMIN, int xMAX);
	bool HitPerson(PERSON p);
	friend istream& operator>>(istream& in, CAR& p);          // nhập dữ liệu cho xe ô tô
};