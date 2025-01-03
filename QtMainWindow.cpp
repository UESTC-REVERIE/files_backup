#include "QtMainWindow.h"

QtMainWindow::QtMainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Files Backup");
	this->setFixedSize(350, 450);

	// ����ͼƬ
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
	bkg->setAlignment(Qt::AlignCenter);  // ͼƬ����

	// ������ť
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

	// ������ֱ���ֲ�����ť��ֱ����
	Layout = new QVBoxLayout;

	// ���ð�ť��ֱ���в�����
	Layout->addStretch();  // ����Ŀհײ���
	Layout->addWidget(bkg, 0, Qt::AlignHCenter);  // ͼƬ����
	Layout->addSpacing(50);  // ��ť֮��ļ��
	Layout->addWidget(backup_button, 0, Qt::AlignHCenter);  // Backup��ť����
	Layout->addSpacing(10);  // ��ť֮��ļ��
	Layout->addWidget(restore_button, 0, Qt::AlignHCenter);  // Restore��ť����
	Layout->addStretch();  // ����Ŀհײ���

	// ���ô��ڵĲ���
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

