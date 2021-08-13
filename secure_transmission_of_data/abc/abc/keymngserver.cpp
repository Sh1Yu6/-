
#include <iostream>

using namespace std;

//#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
//#include <sys/wait.h>


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
//#include <pthread.h>
#include "poolsocket.h"

#include "keymngserverapp.h" 
#include "keymngserverabsop.h"
#include "keymngserverop_lisi.h"


#define INIT_DAEMON \
{ \
	if(fork() >0) exit(0); \
	setsid(); \
	if(fork()>0) exit(0); \
}

int main()
{
	cout << "keymngserver hello...\n";
	
	INIT_DAEMON
	
	//业务流类
	KeyMngServerApp   	keyMngServerApp;
	
	/* 
	//定义业务流类  注入到app中	
	if (1)
	{
		new 王五
	}
	else 
	{
		new lisi
	}
	*/
	//定义一个父类指针调用 子类对象
	KeyMngServerAbsOp  * keyMngServerOp = new KeyMngServerOp_LiSi;
	MngServer_Info		mngServer_Info;
	
	
	keyMngServerApp.setServerOp(keyMngServerOp);
	keyMngServerApp.setInfo(&mngServer_Info);
	
	
	keyMngServerApp.init();
	keyMngServerApp.run();   //====>run(&keyMngServerApp);
	keyMngServerApp.exit();
	
	delete keyMngServerOp;
	return 0;
}
