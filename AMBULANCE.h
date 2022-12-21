#pragma once
#include "VEHICLE.h"

#define AMBULANCE_WTDTH 18      // độ rộng xe cứu thương

/*

.=========. +__+  
|    #    |------.
|  #####  |   [] |               // hình ảnh in xe cứu thương
|    #    |      |
'=(0)====='==(0)='

*/
class AMBULANCE : public VEHICLE                   // lớp AMBULANCE kế thừa VEHICLE
{                                                     
	string shape[5] = {".=========. +__+  ",           // hình ảnh xe trong các chuỗi
	                   "|    #    |------.",
		               "|  #####  |   [] |",
	                   "|    #    |      |",
	                   "'=(0)====='==(0)='"};
public:
	AMBULANCE() {};
	AMBULANCE(int Xmin, int Y) : VEHICLE(Xmin, Y, true, 1) {
		this->width = AMBULANCE_WTDTH;
		this->x_max = this->x_min + this->width - 1;
	}
	void Print();                        // không sử dụng phương thức 
	void Print(int xMIN, int xMAX);           
	void RemoveTail(int xMIN, int xMAX);
	bool HitPerson(PERSON p);            // không sử dụng phương thức 
};

