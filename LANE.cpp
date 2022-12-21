#include "LANE.h"

void LANE::CreateObject() {
	switch (type)                                        // xét các loại vật cản để tạo
	{ 
	case ObjectType::CAR:
		if (direction)
			vehicle.push_back(new CAR(x_min - CAR_WIDTH , y + 1, direction, step));
		else
			vehicle.push_back(new CAR(x_max + 1, y + 1, direction, step));
		break;
	case ObjectType::TRUCK:
		if (direction)
			vehicle.push_back(new TRUCK(x_min - TRUCK_WIDTH, y + 1, direction, step));
		else
			vehicle.push_back(new TRUCK(x_max + 1, y + 1, direction, step));
	   break;
	case ObjectType::ELEPHANT:
		if (direction)
			animal.push_back(new ELEPHANT(x_min - ELEPHANT_WIDTH, y, direction, step));
		else
			animal.push_back(new ELEPHANT(x_max + 1, y, direction, step));
		break;
	case ObjectType::PIGTURTLE:
		if (direction)
			animal.push_back(new PIGTURTLE(x_min - PIGTURTLE_WIDTH, y, direction, step));
		else
			animal.push_back(new PIGTURTLE(x_max + 1, y, direction, step));
		break;
	}
}

void LANE::ProcessDataObject() {
	if (type == ObjectType::CAR || type == ObjectType::TRUCK) {
		// khi vật cản là phương tiện
		if (tf.GetLightColor() == false && vehicle[0]->DistanceToTrafficLight(tf) == 1) // xét khi đèn đỏ và tính khoảng cách phương tiện đi đầu với đèn giao thông
			vehicle[0]->Stop();       //  nếu đèn đỏ và khoảng cách phương tiện đi đầu với đèn giao thông = 1 thì dừng
		else
			vehicle[0]->Run();        //  đèn xanh thì tiếp tục chạy

		for (int i = 1; i < vehicle.size(); i++) {                      // xử lý các phương tiện trên làn đường
			int dis = vehicle[i]->DistanceToVehicle(vehicle[i - 1]);        // tính khoảng cách giữa hai phương tiện kề nhau
			if (dis <= 3) 
				vehicle[i]->Stop();      // khoảng cách giữa hai phương tiện kề nhau <= 3 thì phương tiện đi sau dừng lại
			else
				vehicle[i]->Run();       // không thì tiếp tục chạy
		}

		for (int i = 0; i < vehicle.size(); i++)          //   xử lý dữ liệu tọa độ của các phương tiện
			vehicle[i]->Move();

		if ((direction && vehicle[0]->GetXmin() > x_max + 1) || (!direction && vehicle[0]->GetXmax() < x_min - 1)) {
			vehicle.erase(vehicle.begin());             // khi phương tiện đi đầu hoàn toàn rời khỏi làn đường thì xóa phương tiện đầu khỏi danh sách
		}                                               // lúc này index của các phương tiện còn lại trong danh sách được dồn lên
	}
	else {
		// khi vật cản là con vật
		for (int i = 0; i < animal.size(); i++)         //   xử lý dữ liệu tọa độ của các con vật
			animal[i]->Move();

		if ((direction && animal[0]->GetXmin() > x_max + 1) || (!direction && animal[0]->GetXmax() < x_min - 1)) {
			animal.erase(animal.begin());               // khi con vật đi đầu hoàn toàn rời khỏi làn đường thì xóa con vật đầu khỏi danh sách
		}                                               // lúc này index của các con vật còn lại trong danh sách được dồn lên
	}
}

void LANE::ProcessTrafficLight() {
	if (type == ObjectType::CAR || type == ObjectType::TRUCK)
		// khi vật cản là phương tiện thì xử lý dữ liệu đèn giao thông
		tf.CountDown();
}

void LANE::Operate() {
	ProcessTrafficLight();                 // xử lý dữ liệu đèn giao thông
	if (time_run % time_appear == 0) {
		CreateObject();                    // chạy biến đếm thời gian, bằng thời gian xuất hiện thì tạo một vật cản
		time_run = 0;                      // khôi phục lại biến đếm thời gian
	}
	time_run++;              // tăng biến đếm

	if (vehicle.size() > 0 || animal.size() > 0)
		// khi có vật cản thì xử lý dữ liệu
		ProcessDataObject();
}

void LANE::Print() {
	//  in ra hình ảnh các vật cản
	for (int i = 0; i < vehicle.size(); i++) {
		vehicle[i]->Print(x_min, x_max);
	}
	for (int i = 0; i < animal.size(); i++)
		animal[i]->Print(x_min, x_max);

	if (type == ObjectType::CAR || type == ObjectType::TRUCK)
		// nếu vật cản là phương tiện thì in ra hình ảnh đèn giao thông
		tf.Print();
}

bool LANE::HasAccident(PERSON p) {
	if (p.GetY() > y + 4 || p.GetY() + 2 < y)
		// khi con người không nằm trong làn đường thì khỏi xét
		return false;
	else {
		// xét con người với từng vật cản trên làn đường
		for (int k = 0; k < vehicle.size(); k++) {
			if (vehicle[k]->HitPerson(p))
				return true;
		}	
		for (int k = 0; k < animal.size(); k++) {
			if (animal[k]->HitPerson(p))
				return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& ou, const LANE& p) {
	ou << p.x_min << " " << p.x_max << " " << p.y << " " << p.direction << " " << p.time_appear << " " << p.time_run << " " << p.speed << " " << p.step << " " << (int)p.type << endl;
	if (p.type == ObjectType::CAR || p.type == ObjectType::TRUCK) {
		ou << p.tf << endl;
		ou << p.vehicle.size() << endl;
		for (int i = 0; i < p.vehicle.size(); i++) {
			ou << *p.vehicle[i] << endl;
		}
	}
	else {
		ou << p.animal.size() << endl;
		for (int i = 0; i < p.animal.size(); i++) {
			ou << *p.animal[i] << endl;
		}
	}
	return ou;
}

istream& operator>>(istream& in, LANE& p) {
	int t;
	in >> p.x_min >> p.x_max >> p.y >> p.direction >> p.time_appear >> p.time_run >> p.speed >> p.step >> t;
	p.type = (ObjectType)t;
	if (p.type == ObjectType::CAR || p.type == ObjectType::TRUCK) {
		in >> p.tf;
		in >> t;
		for (int i = 0; i < t; i++) {
			if (p.type == ObjectType::CAR) {
				CAR car;
				in >> car;
				p.vehicle.push_back(new CAR(car));
			}
			else {
				TRUCK truck;
				in >> truck;
				p.vehicle.push_back(new TRUCK(truck));
			}
		}
	}
	else {
		in >> t;
		for (int i = 0; i < t; i++) {
			if (p.type == ObjectType::ELEPHANT) {
				ELEPHANT ele;
				in >> ele;
				p.animal.push_back(new ELEPHANT(ele));
			}
			else {
				PIGTURTLE pigturtle;
				in >> pigturtle;
				p.animal.push_back(new PIGTURTLE(pigturtle));
			}
		}
	}
	return in;
}