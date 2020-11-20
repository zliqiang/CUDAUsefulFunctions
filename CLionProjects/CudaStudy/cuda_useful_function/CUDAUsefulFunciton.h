#ifndef __CUDAUSEFULFUNCTION_H__
#define __CUDAUSEFULFUNCTION_H__
#include <stdio.h>
#include <iostream>
#include <cuda.h>
#include <sys/time.h>
#include <time.h>
//获取线程ID
#define GetThreadId (blockDim.x * (blockIdx.x + blockIdx.x * blockIdx.y) + threadIdx.x)
//获取块ID
#define GetBlockId  (blockIdx.x + blockIdx.y * gridDim.x)

//预热GPU
void warmup();
double get_time();


__global__ void warmup_kenerl()
{
    int i,j;
    i = 1;
    j = 1;
    i = i+j;
}

double get_time(void)
{
    struct timeval tv;
    double t;

    gettimeofday(&tv, (struct timezone *)0);
    t = tv.tv_sec + (double)tv.tv_usec * 1e-6;

    return t;
}

void warmup()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        warmup_kenerl<<<1,256>>>();
    }
}
#endif