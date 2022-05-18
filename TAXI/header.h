#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<conio.h>
#include<windows.h>
//Several necessary header files
using namespace std;
void gotoxy(int x, int y);
void enter(char* temp, int i, int s);
int transf(char* temp);
void chart();
void per(int x, int y);
void exit_system();
int menu();
int admin_menu();
int drivers_menu();
int admin_login();
//Some necessary functions

class driver
{
public:
	string name_1;
	string name_2;
	string password;
	driver(){}
	~driver(){}
};
//Taxi information class
class taxi :public driver //Inherit driver class
{
public:
	int total_income;
	int rewards;
	int punishments;
	string car_id;
	string car_type;
	friend istream& operator>>(istream& in, taxi& t)//Overload >> symbol
	{
		in >>  t.name_1 >> t.name_2 >> t.password>> t.total_income 
			>> t.rewards >> t.punishments >> t.car_id >> t.car_type;
		return in;
	}
	friend ostream& operator<<(ostream& out, const taxi& t)//Overload << symbol
	{
		out << t.name_1 << "\t" << t.name_2 << "\t" << t.password 
			<< "\t" << t.total_income<< "\t" << t.rewards << "\t" 
			<< t.punishments << "\t" << t.car_id << "\t" << t.car_type << endl;
		return out;
	}
};

class admin //Main operation class functions
{
public:
	vector<taxi>tax;
	void show_car();//Show all information
	void add_car();//Add information
	void edit_car();//Edit information 
	void del_car();//Delete information
	void search_car();//Search information

	int driver_login(string& temp_id);//Driver login
	void add_records(string& temp_id);//Add records
	void show_info(string& temp_id);//Show personal information
	void show_records(string& temp_id);//Show rewards & punishments
	int read();//Read all information
	void save();//Save all intformation
};