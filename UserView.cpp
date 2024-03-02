#include "UserView.h"
#include"algorithm"
#include<math.h>
#include"qmessagebox.h"

UserView::UserView(Repository& repo,Driver& driver,QWidget *parent) : repo(repo),driver(driver),QMainWindow(parent)
{
	ui.setupUi(this);
	repo.add_observer(this);
	this->update();
	connectButtons();
}

UserView::~UserView()
{}

void UserView::update()
{
	ui.listWidget->clear();
	QFont f;
	f.setBold(true);
	for (auto x : repo.get_reports())
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(x.tostring()) };
		if (x.get_status() == "true")
			item->setFont(f);
		if (sqrt((x.get_lat() - driver.get_lat()) * (x.get_lat() - driver.get_lat()) + (x.get_long() - driver.get_long()) * (x.get_long() - driver.get_long()))  <= 10)
			ui.listWidget->addItem(item);
	}
	ui.latLabel->setText(QString::fromStdString(to_string(driver.get_lat())));
	ui.longLabel->setText(QString::fromStdString(to_string(driver.get_long())));
	ui.scoreLabel->setText(QString::fromStdString(to_string(driver.get_score())));
	ui.chatWidget->clear();
	for (auto x : repo.get_chat())
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(x) };
		ui.chatWidget->addItem(item);
	}
}

void UserView::connectButtons()
{
	ui.chatWidget->clear();
	QObject::connect(ui.sendButton, &QPushButton::clicked, [&]() {
		string text = driver.get_name();
		text += ": ";
		text += ui.chatLine->text().toStdString();
		QListWidgetItem* chatmsg = new QListWidgetItem{QString::fromStdString(text)};
		ui.chatWidget->addItem(chatmsg);
		repo.add_chat(text);
		update();
		});
	QObject::connect(ui.addButton, &QPushButton::clicked, [&]() {
		string desc = ui.descLine->text().toStdString();
		int lat = ui.latLine->text().toInt();
		int longit = ui.longLine->text().toInt();
		string name = driver.get_name();
		string status = "false";
		Report r{ desc,name, lat,longit,status };
		if (desc == "")
			QMessageBox::critical(this, "error", "no input description");
		else if (sqrt((lat-driver.get_lat())* (lat - driver.get_lat()) + (longit - driver.get_long()) * (longit - driver.get_long()) > 20))
			QMessageBox::critical(this, "error", "too far away");
		else
			repo.add_report(r);
		update();
		});
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, [&]() {
		index = ui.listWidget->currentIndex().row();
		ui.pushButton->setDisabled(true);
		if (repo.get_reports()[index].get_status() == "false")
			ui.pushButton->setEnabled(true);
		});
	QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
		repo.get_reports()[index].set_status();
		repo.notify();
		});
}