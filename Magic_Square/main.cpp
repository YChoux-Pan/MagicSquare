#include "Magic_Square.h"
#include <QtWidgets/QApplication>
#include <Global.h>
#include <thread>

std::string texturePaths[6] = {"","","","","",""};

initializationVTK* m_initializationVTK = NULL;
Magic_Square* m_Magic_Square = NULL;

void InitialVTK()
{
	if(!m_initializationVTK)
	{
		m_initializationVTK = new initializationVTK();
	}
}

void systemLoadThread()
{
	
	m_Magic_Square->loadingOK();
}
int main(int argc, char *argv[])
{
   

    QApplication app(argc, argv);

	InitialVTK();
	
	m_Magic_Square = new Magic_Square();

	std::thread t(systemLoadThread);
	
	int ret = app.exec();
	if (t.joinable()) t.join();  // 主线程退出前等他跑完
    return app.exec();
}
