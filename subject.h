#pragma once
#include"observer.h"
#include<vector>

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	void add_observer(Observer* o)
	{
		observers.push_back(o);
	}
	void remove_observer(Observer* o)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
	}
	void notify()
	{
		for (auto& x : observers)
			x->update();
	}
};