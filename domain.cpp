#include"domain.h"

Driver::Driver(string name, int lat, int longit, int score)
{
	this->name = name;
	this->latitude = lat;
	this->longitude = longit;
	this->score = score;
}

string Driver::get_name()
{
	return this->name;
}

int Driver::get_lat()
{
	return this->latitude;
}

int Driver::get_long()
{
	return this->longitude;
}

int Driver::get_score()
{
	return this->score;
}

int Report::get_lat()
{
	return this->latitude;
}

int Report::get_long()
{
	return this->longitude;
}

string Report::get_name()
{
	return this->name;
}

string Report::get_desc()
{
	return this->description;
}

string Report::get_status()
{
	return this->status;
}


Report::Report(string desc, string name, int lat, int longit, string status)
{
	this->description = desc;
	this->name = name;
	this->latitude = lat;
	this->longitude = longit;
	this->status = status;
}

string Report::tostring()
{
	string result = "";
	result += this->get_desc();
	result += " ";
	result += this->get_name();
	result += " ";
	result += to_string(this->get_lat());
	result += " ";
	result += to_string(this->get_long());
	result += " ";
	result += this->get_status();
	return result;
}

void Report::set_status()
{
	this->status = "true";
}