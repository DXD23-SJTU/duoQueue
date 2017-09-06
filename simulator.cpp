//
// Created by 徐达丁 on 2017/9/6.
//
#include "simulator.h"

simulator::simulator() {
    cout << "请输入柜台数：";
    cin >> noOfSever;
    cout << "请输入到达时间间隔的上下界（最小间隔时间 最大间隔时间）：";
    cin >> arrivalLow >> arrivalHigh;
    cout << "请输入服务时间的上下界（最小间隔时间 最大间隔时间）：";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "请输入模拟的顾客数：";
    cin >> customNum;
    srand(time(NULL));//随机数发生器初始化
}

int simulator::avgWaitTime() {
    int serverBusy = 0;//正在工作的服务台数
    int currentTime;//记录模拟过程中的时间
    int totalWaitTime = 0;//模拟过程中所有顾客的等待时间的总和
    linkQueue<evenT>waitQueue;//顾客等待队列
    priorityQueue<evenT> eventQueue;//事件队列

    evenT currentEvent;

    //生成初始的事件队列
    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for(i=0;i<customNum;++i){
        currentEvent.time += arrivalLow+rand()%(arrivalHigh-arrivalLow+1);
        eventQueue.enQueue(currentEvent);
    }
    //模拟过程
    while(!eventQueue.isEmpty()){
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch(currentEvent.type){
            case 0:
                if(serverBusy!= noOfSever){
                    ++serverBusy;
                    currentEvent.time += serviceTimeLow+rand()%(serviceTimeHigh-serviceTimeLow+1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                }else waitQueue.enQueue(currentEvent);
                break;
            case 1:
                if(!waitQueue.isEmpty()){
                    currentEvent = waitQueue.deQueue();
                    totalWaitTime += currentTime - currentEvent.time;
                    currentEvent.time = currentTime +serviceTimeLow+rand()%(serviceTimeHigh-serviceTimeLow+1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                }else --serverBusy;
        }
    }
    return totalWaitTime/customNum;
}

