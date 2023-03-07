//#include<iostream>
//#include<list>
//#include<vector>
//#include<fstream>
//#include<conio.h>
//#include<string>
//#include<string.h>
//#include<cmath>
//#include <iomanip>
//#include <cstdio>
//#include<cstdlib>
//
//using namespace std;
//
//class Clock
//{
//public:
//	double hour, minute, second;
//public:
//	Clock();
//	Clock(double hour, double minute = 00, double second = 00);
//	void tick();
//	void adder(double hour, double minute, double second);
//	void displayTheCurrentTime();
//};
//Clock::Clock() : hour(00), minute(00), second(00) {}
//
//Clock::Clock(double hour, double minute, double second) : hour(hour), minute(minute), second(second) {}
//
//void Clock::tick() {
//
//	if (second < 59 && minute <= 59 && hour <= 23) {
//		second++;
//	}
//	else if (second >= 59 && minute < 59 && hour <= 23) {
//		second = 00;
//		minute++;
//	}
//	else if (second >= 59 && minute >= 59 && hour < 23) {
//		minute = 00;
//		second = 00;
//		hour++;
//	}
//	else {
//		minute = 00;
//		second = 00;
//		hour = 00;
//		cout << "We've got a new day, hopefully it's not monday!\n";
//	}
//}
//
//
//void Clock::displayTheCurrentTime() {
//	if (second <= 59 && minute <= 59 && hour <= 23)
//	{
//		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " - " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second + 05;
//	}
//}
//struct slot {
//	float price;
//	bool occupied;
//	string slottime;
//	int slotnumber;
//	Clock mytime;
//	string Date;
//	slot()
//	{
//		price = 2;
//		occupied = false;
//		slottime = "00:00:00";
//
//	}
//};
//class idkname {
//	int totalmins;
//	int totalslots;
//	vector<int> number;
//	vector<string> clientinfo;
//	Clock times;
//	//string date;
//	vector<slot> slotlist;
//public:
//	idkname()
//	{
//		clientinfo = vector<string>();
//		number = vector<int>();
//		totalslots = 0;
//		readslots();
//	}
//	void displayschedule()
//	{
//		cout << "\t\t\t\t SLOT SCHEDULE \n";
//
//		for (int i = 0; i < slotlist.size(); i++)
//		{
//			if (slotlist[i].occupied == false)
//			{
//				cout <<"\t\tDate : "<<slotlist[i].Date<< " Slot number : " << slotlist[i].slotnumber << " ";
//				cout << " Slot time: ";
//				slotlist[i].mytime.displayTheCurrentTime();
//				cout << " " << " Slot Price :" << slotlist[i].price;
//				if (slotlist[i].price == 50) {
//					cout << "  Peak time!!" << endl;
//				}
//				//cout << "  Slot status : " << slotlist[i].occupied;
//				cout << endl;
//
//
//			}
//		}
//	}
//
//	void readslots()
//	{
//		ifstream fin;
//		fin.open("input.txt", ios::in);
//		int line;
//		string date;
//		char tmp;
//		int count = 0;
//		int secs = 5;
//		while (!fin.eof())
//		{
//			times.tick();
//			slot nn;
//			fin >> line;
//
//			nn.slotnumber = line;
//			fin.get(tmp);
//			fin.get(tmp);
//
//			if (tmp == 35)
//			{
//				nn.occupied = true;
//			}
//			else {
//
//				nn.occupied = false;
//			}
//			fin.get(tmp);
//			fin >> line;
//			nn.price = line;
//			fin.get(tmp);
//			fin >> date;
//			nn.Date = date;
//			nn.mytime = times;
//			slotlist.push_back(nn);
//			totalslots++;
//			count++;
//			if (count == 12)
//			{
//				totalmins++;
//				count = 0;
//			}
//		}
//	}
//	bool valid(int num) {
//		for (int i = 0; i < slotlist.size(); i++)
//		{
//			if (num == slotlist[i].slotnumber && slotlist[i].occupied == false) {
//				return true;
//			}
//		}
//		return false;
//	}
//	void select_slot() {
//		system("cls");
//		
//		//cout << endl << endl;
//		displayschedule();
//		cout << "Enter the slot number/numbers you want to select and press enter to exit: " << endl;
//		char check = '\0';
//
//		int num = 0;
//		int i = 0;
//		bool exit = false;
//
//		while (check != 'e') {
//			cin >> num;
//			if (valid(num)) {
//				bool already_selected = false;
//
//				for (int i = 0; i < number.size(); i++)
//				{
//					if (num == number[i]) {
//						already_selected = true;
//						cout << "The slot is already selected" << endl;
//						break;
//					}
//				}
//				if (already_selected == false) {
//					number.push_back(num);
//					cout << "Selected" << endl;
//					cout << "Enter e to exit or any key to continue selecting : ";
//					cin >> check;
//					if (check == 'e') {
//						exit = true;
//					}
//				}
//			}
//			else {
//				cout << "Invalid slot number!" << " Enter again: " << endl;
//				
//			}
//			if (exit == true) {
//				break;
//			}
//		}
//		system("cls");
//		//cout << "\t\tYou have selected your slots that are: " << endl;
//		generate_ratecard();
//		cout << endl;
//		char opt;
//		cout << "\t\tPress Y to confirm your rate card and generate invoice." << endl;
//		cout << "\t\tPress X to change your ratecard" << endl;
//		cin >> opt;
//		if (opt == 'y' || opt == 'Y') {
//			//system("CLS");
//			generate_invoice();
//		}
//		if (opt == 'x' || opt == 'X') {
//			number.clear();
//			this->select_slot();
//			
//		}
//	}
//	void generate_ratecard() {
//		//system("cls");
//
//		cout << "\n\n\t\t\tYour Selected time slots with prices are as follows: " << endl;
//		for (int i = 0; i < number.size(); i++) {
//			for (int j = 0; j < slotlist.size(); j++) {
//				if (number[i] == slotlist[j].slotnumber) {
//					cout << "\t\tSlot number : " << slotlist[j].slotnumber << " ";
//					cout << " Slot time: ";
//					slotlist[j].mytime.displayTheCurrentTime();
//					cout << " Slot price :" << slotlist[j].price;
//					if (slotlist[j].price == 50) {
//						cout << "  Peak time!!" << endl;
//					}
//					cout << endl;
//				}
//			}
//		}
//	}
//
//	void package_ratecard(double price) {
//		system("cls");
//		int i = 0;
//		getclientinfo();
//		//generate_ratecard();
//		cout << "\tClient Information: " << endl;
//		cout << "\tCompany's name: " << clientinfo[i] << endl;
//		cout << "\tComapny's address: " << clientinfo[++i] << endl;
//		cout << "\tPhone number: " << clientinfo[++i] << endl;
//		cout << "\tEmail: " << clientinfo[++i] << endl;
//		cout << "\tInvoice Number: " << get_invoicenumber() << endl;
//
//		cout << "\n\n\t\t\tYour Selected time slots with prices are as follows: " << endl;
//		for (int i = 0; i < number.size(); i++) {
//			for (int j = 0; j < slotlist.size(); j++) {
//				if (number[i] == slotlist[j].slotnumber) {
//					cout << "\t\tSlot number : " << slotlist[j].slotnumber << " ";
//					cout << " Slot time: ";
//					slotlist[j].mytime.displayTheCurrentTime();
//					cout << endl;
//				}
//			}
//		}
//		cout << endl << "\t\t\t Slot price :" << price;
//	}
//
//	int get_invoicenumber() {
//		int i = 0;
//		int num = rand() % 1000 + (++i);
//		return num;
//	}
//	void getclientinfo() {
//		ifstream fin;
//		fin.open("Clientinfo.txt");
//
//		while (!fin.eof()) {
//			string temp;
//			fin >> temp;
//			clientinfo.push_back(temp);
//
//		}
//		fin.close();
//	}
//	void generate_invoice() {
//		system("cls");
//		int i = 0;
//		getclientinfo();
//
//		cout << "\t\tClient Information: " << endl;
//		cout << "\t\tCompany's name: " << clientinfo[i] << endl;
//		cout << "\t\tComapny's address: " << clientinfo[++i] << endl;
//		cout << "\t\tPhone number: " << clientinfo[++i] << endl;
//		cout << "\t\tEmail: " << clientinfo[++i] << endl;
//		cout << "\t\tInvoice Number: " << get_invoicenumber() << endl;
//		generate_ratecard();
//	}
//
//	void confirmation(double price) {
//		char opt;
//		cout << endl << endl;
//		cout << "\t\tPress Y to confirm your rate card and generate invoice." << endl;
//		cout << "\t\tPress X to change your ratecard" << endl;
//		cin >> opt;
//		if (opt == 'y' || opt == 'Y') {
//			package_ratecard(price);
//		}
//		if (opt == 'x' || opt == 'X') {
//			number.clear();
//			display_package();
//			
//		}
//	}
//
//	void premium_package() {
//		system("CLS");
//		cout << "\n\n\n\t\t\tPremium Package" << endl;
//		for (int i = 0,j=0; i < 4; i++,j++)
//		{
//			number.push_back(i);
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		double price= (slotlist[0].price + slotlist[1].price + slotlist[2].price + slotlist[3].price) - 20;
//		cout << "\t\t Package price :" << price;
//		confirmation(price);
//	}
//	void silver_package() {
//		system("CLS");
//		for (int i = 3; i < 5; i++)
//		{
//			number.push_back(i);
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		double price = (slotlist[3].price + slotlist[4].price) - 15;
//		cout << "\t\t Slot price :" << price;
//		confirmation(price);
//	}
//	void bronze_package() {
//		system("CLS");
//		cout << endl << endl << "\t\t\t\tBronze Package" << endl << endl;
//		for (int i = 8; i < 10; i++)
//		{
//			number.push_back(i);
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		double price = (slotlist[8].price + slotlist[9].price) - 10;
//		cout << "\t\t Slot price :" << price;
//		confirmation(price);
//	}
//	void display_package() {
//		int select_package;
//		system("CLS");
//		cout << "\t\t\t\tPremium Package" << endl << endl;
//		for (int i = 0; i < 4; i++)
//		{
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		cout << "\t\t Slot price :" << (slotlist[0].price + slotlist[1].price + slotlist[2].price+ slotlist[3].price) - 20;
//		cout << endl << endl << "\t\t\t\tSilver Package" << endl << endl;
//		for (int i = 3; i < 5; i++)
//		{
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		cout << "\t\t Slot price :" << (slotlist[3].price + slotlist[4].price) - 15;
//		cout << endl << endl << "\t\t\t\tBronze Package" << endl << endl;
//		for (int i = 8; i < 10; i++)
//		{
//			cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//			cout << " Slot time: ";
//			slotlist[i].mytime.displayTheCurrentTime();
//			cout << endl;
//		}
//		cout << "\t\t Slot price :" << (slotlist[8].price + slotlist[9].price ) - 10;
//		cout << endl << endl << "\t Press 1 for Premium Package" << "\t2 for Silver Package" << "\t3 for Bronze Package" << endl;
//		cout << "\t\t\t Press 4 to make your own Package" << endl;
//		cin >> select_package;
//		if (select_package == 1) {
//			premium_package();
//		}
//		else if (select_package == 2) {
//			silver_package();
//		}
//		else if (select_package == 3) {
//			bronze_package(); 
//		}
//		else if (select_package == 4) {
//			select_slot();
//		}
//	}
//
//	bool validin(int option) {
//		for (int i = 1; i < 4; i++)
//		{
//			if (option == i) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void getmenu() {
//		cout << "\n\n\n\t\t\t\tWelcome to airtime sales system!!" << endl;
//		cout << "\t\t\tPress 1 to get schedule of available slots." << endl;
//		cout << "\t\t\tPress 2 to select slots." << endl;
//		cout << "\t\t\tPress 3 to update slot prices." << endl;
//		int option;
//		cin >> option;
//		if(validin(option))
//		{
//
//			if (option == 1) {
//				system("cls");
//				displayschedule();
//
//			}
//			if (option == 2) {
//
//				display_package();
//			}
//			if (option == 3) {
//				Update_Prices();
//			}
//			if (option == 4) {
//				display_package();
//			}
//		}
//		else {
//			cout << "invalid entery!!";
//			system("CLS");
//			getmenu();
//		}
//		
//		
//
//	}
//
//	void Update_Prices() {
//		cout << endl << "------------------------------------" << endl;
//
//		string slot_number;
//		string exit;
//		bool check = false;
//		system("cls");
//		displayschedule();
//		//cout << slotlist.size();
//		while (!check)
//		{
//			cout << endl << "\t\tEnter the slot number you want to update price of" << " or " << "Press 'e' to exit" << endl;
//			cin >> slot_number;
//			if (slot_number == "e") {
//				break;
//			}
//			int int_slot_number = stoi(slot_number);
//			if (valid(int_slot_number)) {
//				cout << "\t\tEnter new Price" << endl;
//				double new_price = 0;
//				cin >> new_price;
//				int i = 0;
//				while (slotlist.size())
//				{
//
//					if (int_slot_number == slotlist[i].slotnumber) {
//						slotlist[i].price = new_price;
//						break;
//					}
//					i++;
//				}
//				if (slot_number == "e") {
//					check = true;
//				}
//				else {
//
//					cout << "\t\tThe price has been updated to" << endl;
//					cout << "\t\tSlot number : " << slotlist[i].slotnumber << " ";
//					cout << " Slot time: ";
//					slotlist[i].mytime.displayTheCurrentTime();
//					cout << " Slot price :" << slotlist[i].price << endl;
//				}
//			}
//			else {
//				cout << "\t\tInvalid slot number!" << " Enter again: " << endl;
//
//			}
//		}
//		displayschedule();
//	}
//};
//
//int main()
//{
//	idkname A;
//
//	A.getmenu();
//	system("pause");
//	return 0;
//}
//
