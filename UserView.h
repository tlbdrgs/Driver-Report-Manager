#pragma once

#include <QMainWindow>
#include "ui_UserView.h"
#include"repository.h"
#include"observer.h"

class UserView : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	UserView(Repository& repo,Driver& driver,QWidget *parent = nullptr);
	~UserView();

private:
	Ui::UserViewClass ui;
	Repository& repo;
	Driver& driver;
	void update();
	void connectButtons();
	int index;
};
