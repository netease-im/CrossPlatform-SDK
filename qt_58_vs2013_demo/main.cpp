#include "mainwindow.h"
#include <QApplication>
#include "nim_cpp_api.h"
#include "nim_chatroom_cpp_api.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	bool ret = nim::Client::Init("test_appkey", "test_qt", "", nim::SDKConfig());
	ret = nim_chatroom::ChatRoom::Init("");

	nim_chatroom::ChatRoom::Cleanup();
	nim::Client::Cleanup();

    return a.exec();
}
