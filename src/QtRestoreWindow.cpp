#include "../include/QtRestoreWindow.h"

std::string target_folder2;
std::vector <std::string> cho2;
int file_format = 0;
int aes_flag2 = 1;

QtRestoreWindow::QtRestoreWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(350, 450);
	this->setWindowTitle("Restore");
	// ����Grid����
	QGridLayout* mainLayout = new QGridLayout(this);

	// �ļ���ť
	file_b = new QPushButton(this);
	file_b->setText("File");

	// �ļ��а�ť
	folder_b = new QPushButton(this);
	folder_b->setText("Folder");

	// ִ�а�ť
	restore_b = new QPushButton(this);
	restore_b->setText("Restore");

	// ���ذ�ť
	back_b = new QPushButton(this);
	back_b->setText("Back");

	// �رհ�ť
	/*close_b = new QPushButton(this);
	close_b->setText("close");*/

	// �ļ���Label
	label = new QLabel(this);
	label->setStyleSheet("color: black; font-size: 15px;");
	label->setAlignment(Qt::AlignLeft);
	label->setText("Destination Folder: ");
	label->setStyleSheet("QLabel{background-color:transparent;color:black;}");
	//label->setFrameShape(QFrame::Box);
	//label->setFixedHeight(20);
	label->setFrameShape(QFrame::NoFrame);  // ȥ���ڿ�
	label->setMaximumHeight(50);
	// �ļ�Label
	label2 = new QLabel(this);
	label2->setStyleSheet("color: black; font-size: 12px;");
	label2->setAlignment(Qt::AlignLeft);
	label2->setText("Target File: ");
	label2->setVisible(true);
	label2->setFrameShape(QFrame::NoFrame);  // ȥ���ڿ�
	//label2->setMinimumHeight(250);

	// ��������
	scrolllabel2 = new QScrollArea(this);
	scrolllabel2->setWidget(label2);
	scrolllabel2->setFixedHeight(100);
	scrolllabel2->setFrameShape(QFrame::NoFrame);  // ȥ���ڿ�

	// AES Key Label
	label3 = new QLabel(this);
	label3->setText("the password of .aes files:");
	label3->setStyleSheet("color: black; font-size: 12px;");
	label3->setAlignment(Qt::AlignLeft);

	// ����key_txt�ı���
	key_txt = new QLineEdit(this);
	key_txt->setEchoMode(QLineEdit::Password); // ������Բ�����


	// ���ò��֣�Grid����
	mainLayout->addWidget(file_b, 0, 0, 1, 1);
	mainLayout->addWidget(folder_b, 0, 1, 1, 1);
	mainLayout->addWidget(label, 1, 0, 1, 2);
	mainLayout->addWidget(scrolllabel2, 2, 0, 1, 2);
	mainLayout->addWidget(label3, 4, 0, 1, 1);
	mainLayout->addWidget(key_txt, 4, 1, 1, 1);
	//mainLayout->addWidget(aes_mode_group, 4, 0, 1, 2);
	mainLayout->addWidget(restore_b, 5, 0, 1, 1);
	mainLayout->addWidget(back_b, 5, 1, 1, 1);

	// ����������
	setLayout(mainLayout);

	// ���Ӱ�ť
	connect(file_b, &QPushButton::released, this, &QtRestoreWindow::choose_files);
	connect(folder_b, &QPushButton::released, this, &QtRestoreWindow::choose_folder);
	connect(restore_b, &QPushButton::released, this, &QtRestoreWindow::excute);
	connect(back_b, &QPushButton::released, this, &QtRestoreWindow::back);
	//connect(close_b, &QPushButton::pressed, this, &QtRestoreWindow::close);
}

void QtRestoreWindow::choose_folder() {
	target_folder2 = CSelectFolderDlg::Show();
	std::string label_txt = "Destination Folder: \n" + target_folder2;
	label->setText(QString::fromStdString(label_txt));
}

void QtRestoreWindow::choose_files() {
	cho2 = chooseFiles();
	std::string file_name;
	for (auto path : cho2) {
		file_name += path + "\n";
	}
	std::string label2_txt = "Target File: \n" + file_name;
	label2->setText(QString::fromStdString(label2_txt));
	label2->adjustSize();
}

void QtRestoreWindow::excute() {
	QString name = key_txt->text();
	std::string s = name.toStdString();
	const char* key = s.c_str();
	qDebug() << key << "\n";
	my_restore(target_folder2, cho2, key, aes_flag2);
}

void QtRestoreWindow::back() {
	this->close();
	QtMainWindow* pic = new QtMainWindow();
	pic->show();
}

QtRestoreWindow::~QtRestoreWindow() {}
