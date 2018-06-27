#include "mainwindow.h"
#include <QApplication>
#include "nim_cpp_api.h"
#include "nim_chatroom_cpp_api.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	nim::Client::Init("test_appkey", "test_qt", "", nim::SDKConfig());
	nim_chatroom::ChatRoom::Init("");

    MainWindow w;
    w.show();

	int ret = a.exec();

	nim_chatroom::ChatRoom::Cleanup();
	nim::Client::Cleanup();
	return ret;
}
