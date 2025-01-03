#include "QtMainWindow.h"

QtMainWindow::QtMainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Files Backup");
	this->setFixedSize(350, 450);

	// 设置图片
	bkg = new QLabel(this);
	QPixmap pixmap(":/src/img/bkg.png");

	if (pixmap.isNull()) {
		qDebug() << "Failed to load image!";
	}
	else {
		qDebug() << "Image loaded successfully.";
	}

	bkg->setPixmap(pixmap);
	bkg->setScaledContents(true);
	bkg->setFixedSize(125, 125);
	bkg->setAlignment(Qt::AlignCenter);  // 图片居中

	// 创建按钮
	backup_button = new QPushButton(this);
	backup_button->setText("Backup");
	backup_button->setFixedSize(150, 30);
	connect(backup_button, &QPushButton::released, this, [this]() {
		this->next(0);
		});

	restore_button = new QPushButton(this);
	restore_button->setText("Restore");
	restore_button->setFixedSize(150, 30);
	connect(restore_button, &QPushButton::released, this, [this]() {
		this->next(1);
		});

	// 创建垂直布局并将按钮垂直排列
	Layout = new QVBoxLayout;

	// 设置按钮垂直排列并居中
	Layout->addStretch();  // 上面的空白部分
	Layout->addWidget(bkg, 0, Qt::AlignHCenter);  // 图片居中
	Layout->addSpacing(50);  // 按钮之间的间距
	Layout->addWidget(backup_button, 0, Qt::AlignHCenter);  // Backup按钮居中
	Layout->addSpacing(10);  // 按钮之间的间距
	Layout->addWidget(restore_button, 0, Qt::AlignHCenter);  // Restore按钮居中
	Layout->addStretch();  // 下面的空白部分

	// 设置窗口的布局
	this->setLayout(Layout);
}

QtMainWindow::~QtMainWindow()
{
}

void QtMainWindow::next(int flag)
{
	if (flag == 0) {
		qDebug() << "backup";
		this->close();
		QtBackupWindow* pic = new QtBackupWindow();
		pic->show();
	}

	else if (flag == 1) {
		this->close();
		QtRestoreWindow* pic = new QtRestoreWindow();
		pic->show();
		qDebug() << "restore";
	}

	else qDebug() << "error";
}

