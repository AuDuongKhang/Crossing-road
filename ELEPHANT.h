#pragma once
#include "ANIMAL.h"

/*
	.=======.    
   /     { 0 \_  
.-{     {     _\            // hình ảnh in con voi 
|  \   __   _/ \\
'   |_|  |_|    "
*/

#define ELEPHANT_WIDTH 17        // độ rộng con voi

class ELEPHANT : public ANIMAL          // lớp  ELEPHANT kế thừa lớp ANIMAL
{
	string shape[5] = {".=======.",                    // chuỗi chứa hình ảnh con voi
					   "/     { 0 \\_",     
					   ".-{     {     _\\",
					   "|  \\   __   _/ \\\\",
					   "'   |_|  |_|    \"" };
	pair<int, int> space[5] = { {4, 4}, {3, 2}, {0, 1}, {0, 0}, {0, 0} };     // số khoảng trống ở hai đầu của mỗi chuỗi trong shape
public:
	ELEPHANT() {};
	ELEPHANT(int Xmin, int Y, bool dir, int STEP = 1) : ANIMAL(Xmin, Y, dir, STEP) {
		this->width = ELEPHANT_WIDTH;
		this->x_max = this->x_min + this->width - 1;
		if (!dir) {                                     
			shape[1] = "_/ 0 }     \\";
			shape[2] = "/_     }     }-.";
			shape[3] = "// \\_   __   /  |";
			shape[4] = "\"    |_|  |_|   '";
		}
	}
	void Print();
	void Print(int xMIN, int xMAX);
	void RemoveTail(int xMIN, int xMAX);
	bool HitPerson(PERSON p);
	friend istream& operator>>(istream& in, ELEPHANT& p);              // nhập dữ liệu cho con voi
};

