#include <iostream>
#include "simulator.h"
using namespace std;
int main() {
    simulator sim;
    cout<<"平均等待时间："<<sim.avgWaitTime()<<endl;
    return 0;
}