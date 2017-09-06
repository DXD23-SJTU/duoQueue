//
// Created by 徐达丁 on 2017/9/6.
//

#ifndef SIMULATORQUEUE_SIMULATOR_H
#define SIMULATORQUEUE_SIMULATOR_H

#include <iostream>
#include "linkQueue.h"
#include "priorityQueue.h"
using namespace std;
class simulator {
    int noOfSever;//服务台个数
    int arrivalLow;//到达间隔时间的下届
    int arrivalHigh;//到达间隔时间的上届
    int serviceTimeLow;//服务间隔时间的下届
    int serviceTimeHigh;//服务间隔时间的上届
    int customNum;//模拟的顾客数

    struct evenT {
        int time;//事件发生时间
        int type; //事件类型。0为到达,1为离开
        bool operator<(const evenT &e) const { return time < e.time; }
    };

public:
    simulator();
    int avgWaitTime();
};

#endif //SIMULATORQUEUE_SIMULATOR_H
