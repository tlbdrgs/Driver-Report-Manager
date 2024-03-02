#include"repository.h"
#include<fstream>
#include<sstream>
#include<algorithm>

vector<Driver>& Repository::get_drivers()
{
	return this->drivers;
}

vector<Report>& Repository::get_reports()
{
	return this->reports;
}

void Repository::read_from_file_drivers()
{
	ifstream drivers("drivers.txt");
	string line;
	while (getline(drivers, line))
	{
		stringstream ss(line);
		string name;
		int latitude, longitude,score;
		ss >> name >> latitude >> longitude>>score;
		Driver d(name,latitude,longitude,score );
		this->drivers.push_back(d);
	}
}

void Repository::read_from_file_reports()
{
	ifstream reports("reports.txt");
	string line;
	while (getline(reports, line))
	{
		stringstream ss(line);
		string description,name;
		int latitude, longitude;
		string status;
		ss >> description >> name >> latitude >> longitude >> status;
		Report r(description,name, latitude, longitude, status);
		this->reports.push_back(r);
	}
}

Repository::~Repository()
{
	ofstream output("reports.txt");
	vector<Report> reports = this->get_reports();
	for (auto report : reports)
	{
		output << report.get_desc() << " " << report.get_name() << " " << report.get_lat() << " " << report.get_long() << " " << report.get_status()<< '\n';
	}
}

void Repository::add_report(Report& r)
{
	reports.push_back(r);
	notify();
}

void Repository::add_chat(string& msg)
{
		chat.push_back(msg);
		notify();
}

vector<string>& Repository::get_chat()
{
	return this->chat;
}