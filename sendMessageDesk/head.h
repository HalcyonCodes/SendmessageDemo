#pragma once


//====定义一个消息====
#define acceptMsgCode WM_USER + 4321
//====定义回调函数====

//====定义功能模块====
//测试 0
#define msgTest1 0  //测试0，写入道具id
#define msgTest2 1  //测试2，记录当前坐标位置
#define msgTest3 3  //测试3

#define msgChannelWriteItemId 4 //跨进程通信写道具id
#define msgChannelWriteCoordinate 5 //跨进程通信写坐标