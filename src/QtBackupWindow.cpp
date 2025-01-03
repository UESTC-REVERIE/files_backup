#include "../include/QtBackupWindow.h"

std::string target_folder;
std::vector <std::string> cho;
int mode_flag = 1;
int aes_flag = 1;
int is_scheduled = 0;
int scheduled_mode = 0;

QtBackupWindow::QtBackupWindow(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setFixedSize(350, 450);
    this->setWindowTitle("Backup");

    // ����Grid����
    QGridLayout* mainLayout = new QGridLayout(this);

    // �ļ��а�ť
    folder_b = new QPushButton(this);
    folder_b->setText("Destination Folder: ");

    // �ļ���ť
    file_b = new QPushButton(this);
    file_b->setText("Target Files: ");

    // ִ�а�ť
    pack_b = new QPushButton(this);
    pack_b->setText("Done");

    // back��ť
    back_b = new QPushButton(this);
    back_b->setText("Back");

    // �ļ���Label
    label = new QLabel(this);
    label->setStyleSheet("color: black; font-size: 15px;");
    label->setAlignment(Qt::AlignLeft);
    label->setText("Destination Folder: ");
    // ����ʾ�ڿ�
    label->setStyleSheet("QLabel { background-color: transparent; color: black; }");
    label->setFrameShape(QFrame::NoFrame);  // ȥ���ڿ�

    // �ļ�Label
    label2 = new QLabel(this);
    label2->setStyleSheet("color: black; font-size: 12px;");
    label2->setAlignment(Qt::AlignLeft);
    label2->setText("Target Files: ");
    // ȥ�� label2 �ı߿�
    label2->setFrameShape(QFrame::NoFrame);
    // ��������
    scrolllabel2 = new QScrollArea(this);
    scrolllabel2->setWidget(label2);
    scrolllabel2->setFrameShape(QFrame::NoFrame);
    // ����ؼ�
    pack_mode_group = new QGroupBox(this);
    pack_mode_group->setTitle("Mode");

    // ��ѡ��
    mode1_b = new QRadioButton("duplicate", pack_mode_group);
    mode2_b = new QRadioButton(".tar", pack_mode_group);
    mode3_b = new QRadioButton(".tar.aes", pack_mode_group);
    mode1_b->setChecked(true);

    // ��������: ��ֱ����
    QVBoxLayout* modeLayout = new QVBoxLayout(pack_mode_group);
    modeLayout->addWidget(mode1_b);
    modeLayout->addWidget(mode2_b);
    modeLayout->addWidget(mode3_b);
    pack_mode_group->setLayout(modeLayout);

    // AES Key �����
    label3 = new QLabel(this);
    label3->setText("set password for .aes files: ");
    label3->setVisible(false);
    key_txt = new QLineEdit(this);
    key_txt->setVisible(false);
    key_txt->setEchoMode(QLineEdit::Password);

    // ��ʱ���ݷ���
    scheduled_group = new QGroupBox(this);
    scheduled_group->setTitle("Scheduled backup");
    scheduled_group->setCheckable(true);
    scheduled_group->setChecked(false);
    QRadioButton* once_b = new QRadioButton("Once", scheduled_group);
    QRadioButton* repeat_b = new QRadioButton("Repeatly", scheduled_group);
    QVBoxLayout* scheduledLayout = new QVBoxLayout;
    scheduledLayout->addWidget(once_b);
    scheduledLayout->addWidget(repeat_b);
    scheduled_group->setLayout(scheduledLayout);

    // �������ں�ʱ��
    datetimeEdit = new QDateTimeEdit(this);
    datetimeEdit->setVisible(false);
    datetimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    datetimeEdit->setDateTime(QDateTime::currentDateTime());

    dayEdit = new QLineEdit(this);
    dayEdit->setText("0");
    dayEdit->setValidator(new QIntValidator(dayEdit));
    dayEdit->setVisible(false);
    dayLabel = new QLabel(this);
    dayLabel->setText("Days");
    dayLabel->setVisible(false);

    timeEdit = new QTimeEdit(this);
    timeEdit->setVisible(false);
    timeEdit->setDisplayFormat("hh:mm:ss");

    timeLabel = new QLabel(this);
    timeLabel->setStyleSheet("color: black; font-size: 12px;");
    timeLabel->setAlignment(Qt::AlignLeft);
    timeLabel->setVisible(false);
    timeLabel->setFixedWidth(100);
    timeLabel->setFixedHeight(20);
    timeLabel->setText("hh:mm:ss");

    // ���ò��֣�Grid����
    mainLayout->addWidget(folder_b, 0, 0, 1, 1);
    mainLayout->addWidget(file_b, 0, 1, 1, 1);
    mainLayout->addWidget(label, 1, 0, 1, 2);
    mainLayout->addWidget(scrolllabel2, 2, 0, 1, 2);
    mainLayout->addWidget(pack_mode_group, 3, 0, 1, 2);
    mainLayout->addWidget(label3, 4, 0, 1, 1);
    mainLayout->addWidget(key_txt, 4, 1, 1, 1);
    mainLayout->addWidget(scheduled_group, 5, 0, 1, 2);
    mainLayout->addWidget(datetimeEdit, 6, 0, 1, 2);
    mainLayout->addWidget(dayEdit, 7, 0, 1, 1);
    mainLayout->addWidget(dayLabel, 7, 1, 1, 1);
    mainLayout->addWidget(timeEdit, 8, 0, 1, 1);
    mainLayout->addWidget(timeLabel, 8, 1, 1, 1);

    // �������������ӣ��� folder_b �� file_b ��ռһ��ռ�
    mainLayout->setColumnMinimumWidth(1,175);
    // ���ư�ťλ��
    mainLayout->addWidget(pack_b, 9, 0, 1, 1);
    mainLayout->addWidget(back_b, 9, 1, 1, 1);

    // ����������
    setLayout(mainLayout);

    // folder_b: mySlot1
    connect(folder_b, &QPushButton::released, this, &QtBackupWindow::choose_folder);
    // file_b: mySlot2
    connect(file_b, &QPushButton::released, this, &QtBackupWindow::choose_files);
    // pack_b: ִ��
    connect(pack_b, &QPushButton::released, this, &QtBackupWindow::excute);
    // back_b: ����
    connect(back_b, &QPushButton::released, this, &QtBackupWindow::back);
    // close_b: �رս���
    //connect(close_b, &QPushButton::pressed, this, &QtBackupWindow::close);

    connect(mode1_b, &QRadioButton::toggled, this, &QtBackupWindow::onMode1Toggled);
    connect(mode2_b, &QRadioButton::toggled, this, &QtBackupWindow::onMode2Toggled);
    connect(mode3_b, &QRadioButton::toggled, this, &QtBackupWindow::onMode3Toggled);

    //// AESģʽ
    //connect(aes128_b, &QRadioButton::toggled, this, &QtBackupWindow::onAes128Toggled);
    //connect(aes192_b, &QRadioButton::toggled, this, &QtBackupWindow::onAes192Toggled);
    //connect(aes256_b, &QRadioButton::toggled, this, &QtBackupWindow::onAes256Toggled);
    // �Ƿ�ѡ��ʱ����
    connect(scheduled_group, &QGroupBox::toggled, [=](bool isChecked) {
        if (isChecked == true) {
            is_scheduled = 1;
            scheduled_mode = 0;
            once_b->setChecked(true);

            // once�����ʾ
            //onceLabel->setVisible(true);
            datetimeEdit->setVisible(true);
            // repeat�������
            //repeatLabel->setVisible(false);
            dayEdit->setVisible(false);
            dayLabel->setVisible(false);
            timeEdit->setVisible(false);
            timeLabel->setVisible(false);
        }
        else {
            is_scheduled = 0;
            scheduled_mode = -1;
            once_b->setChecked(false);
            repeat_b->setChecked(false);

            // once�������
            //onceLabel->setVisible(false);
            datetimeEdit->setVisible(false);
            // repeat�������
            //repeatLabel->setVisible(false);
            dayEdit->setVisible(false);
            dayLabel->setVisible(false);
            timeEdit->setVisible(false);
            timeLabel->setVisible(false);
        }
        });
    // ��ȡonce_bֵ
    connect(once_b, &QRadioButton::toggled, [=](bool isChecked) {
        if (isChecked == true) {
            scheduled_mode = 0;
            // once�����ʾ
            //onceLabel->setVisible(true);
            datetimeEdit->setVisible(true);
            // repeat�������
            //repeatLabel->setVisible(false);
            dayEdit->setVisible(false);
            dayLabel->setVisible(false);
            timeEdit->setVisible(false);
            timeLabel->setVisible(false);
        }
        else {
            scheduled_mode = 1;
            // once�������
            //onceLabel->setVisible(false);
            datetimeEdit->setVisible(false);
            // repeat�����ʾ
            //repeatLabel->setVisible(true);
            dayEdit->setVisible(true);
            dayLabel->setVisible(true);
            timeEdit->setVisible(true);
            timeLabel->setVisible(true);
        }
        });

}

void QtBackupWindow::onMode1Toggled(bool isChecked) {
    if (isChecked == true) {
        mode_flag = 1;
        label3->setVisible(false);
        //label4->setVisible(false);
        key_txt->setVisible(false);
        //aes128_b->setVisible(false);
        //aes192_b->setVisible(false);
        //aes256_b->setVisible(false);
        //aes_mode_group->setStyleSheet("QGroupBox {border: 0px solid transparent;}");
        //aes_mode_group->setTitle("");
    }
}
void QtBackupWindow::onMode2Toggled(bool isChecked) {
    if (isChecked == true) {
        mode_flag = 2;
        label3->setVisible(false);
        //label4->setVisible(false);
        key_txt->setVisible(false);
        //aes128_b->setVisible(false);
        //aes192_b->setVisible(false);
        //aes256_b->setVisible(false);
        //aes_mode_group->setStyleSheet("QGroupBox {border: 0px solid transparent;}");
        //aes_mode_group->setTitle("");
    }
}
void QtBackupWindow::onMode3Toggled(bool isChecked) {
    if (isChecked == true) {
        mode_flag = 3;
        label3->setVisible(true);
        key_txt->setVisible(true);

    }
}



void QtBackupWindow::choose_folder() {  //�ļ���

    target_folder = CSelectFolderDlg::Show();
    //b2->setText(QString::fromStdString(target_folder));
    std::string label_txt = "Destination Folder: \n" + target_folder;
    label->setText(QString::fromStdString(label_txt));

}

void QtBackupWindow::choose_files() {  //�ļ�
    cho = chooseFiles();
    std::string file_name;
    for (auto path : cho) {
        file_name += path + "\n";
    }
    std::string label2_txt = "Target Files: \n" + file_name;
    label2->setText(QString::fromStdString(label2_txt));
    label2->adjustSize();
}

void QtBackupWindow::excute() {
    // void setEchoMode(EchoMode)


    QString name = key_txt->text();
    std::string s = name.toStdString();
    const char* key = s.c_str();
    // qtimer = new QTimerEvent();


    if (is_scheduled == 0) {
        my_packup(target_folder, cho, key, aes_flag, mode_flag);
    }
    else
    {
        if (scheduled_mode == 0)
        {
            QDateTime dateTime1 = QDateTime::currentDateTime();
            QDateTime dateTime2 = datetimeEdit->dateTime();
            int seconds = dateTime1.secsTo(dateTime2);
            seconds += 1;
            qDebug() << dateTime1 << " " << dateTime2 << " " << seconds << "\n";
            if (seconds > 0) {
                qDebug() << target_folder << " " << key << " " << aes_flag << " " << mode_flag << "\n";
                qtimer = new QTimer();
                qtimer->singleShot(seconds * 1000, this, [=] {
                    my_packup(target_folder, cho, key, aes_flag, mode_flag);
                    });
            }
        }
        else
        {

            QString dTime_QS = dayEdit->text();
            std::string dTime_s = dTime_QS.toStdString();
            int dTime = atoi(dTime_s.c_str());
            int htime = timeEdit->time().hour(), mtime = timeEdit->time().minute(), stime = timeEdit->time().second();
            int seconds = (int)(86400 * dTime * +3600 * htime + 60 * mtime + stime);
            qDebug() << dTime << " " << htime << " " << mtime << " " << stime << " " << seconds << "\n";
            if (seconds > 0) {
                timer_id = startTimer(seconds * 1000);
            }
        }
    }
}

void QtBackupWindow::back() {
    this->close();
    QtMainWindow* pic = new QtMainWindow();
    pic->show();
}

void QtBackupWindow::timerEvent(QTimerEvent* event) {
    if (event->timerId() == timer_id) {
        QString name = key_txt->text();
        std::string s = name.toStdString();
        const char* key = s.c_str();
        my_packup(target_folder, cho, key, aes_flag, mode_flag);
    }
}

QtBackupWindow::~QtBackupWindow()
{
}
