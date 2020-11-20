#include <iostream>
#include "CUDAUsefulFunciton.h"
using namespace std;
int main() {
    double time_start,time_end,time;
    time_start = get_time();
    warmup();
    cudaThreadSynchronize();
    time_end = get_time();
    time = time_end - time_start;
    cout << "time = " << time << endl;
    return 0;
}
