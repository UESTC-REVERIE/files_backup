#pragma once

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_QtMainWindow.h"
#include "QtMainWindow.h"
#include "QtBackupWindow.h"
#include "QtRestoreWindow.h"

class QtMainWindow : public QWidget
{
	Q_OBJECT

public:
	QtMainWindow(QWidget* parent = nullptr);
	~QtMainWindow();
	void next(int flag);
	//void close();

private:
	Ui::QtMainWindowClass ui;
	QLabel* bkg;
	QGroupBox* Group;
	QPushButton* backup_button;
	QPushButton* restore_button;
	QVBoxLayout* Layout;
};
