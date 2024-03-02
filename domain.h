#pragma once
#include<string>
using namespace std;


class Driver
{
private:
	string name;
	int score;
	int latitude, longitude;
public:
	Driver() {};
	Driver(string name, int lat, int longit , int score);
	string get_name();
	int get_score();
	int get_lat();
	int get_long();
};

class Report
{
private:
	string description;
	string name;
	int latitude, longitude;
	string status;
public:
	Report(string desc, string name, int lat, int longit, string status);
	string get_desc();
	string get_name();
	int get_lat();
	int get_long();
	string get_status();
	string tostring();
	void set_status();
};
