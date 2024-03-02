#pragma once
#include "domain.h"
#include<vector>
#include"subject.h"

class Repository : public Subject
{
private:
	vector<Driver> drivers;
	vector<Report> reports;
	vector<string> chat;
public:
	Repository()
	{
		read_from_file_drivers();
		read_from_file_reports();
	}
	vector<Driver>& get_drivers();
	vector<Report>& get_reports();
	vector<string>& get_chat();
	void read_from_file_drivers();
	void read_from_file_reports();
	void add_chat(string& msg);
	~Repository();
	void add_report(Report& r);
};