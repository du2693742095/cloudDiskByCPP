/***********************************************************
  > File Name: Thread.hh
  > Author: dsy
  > Mail: dushiyang68@gmail.com
  > Created Time: 2022年09月05日 星期一 10时14分21秒
  > Modified Time:2022年09月05日 星期一 10时14分21秒
 *******************************************************/
#ifndef __THREAD_HH__
#define __THREAD_HH__

#include "NonCopyable.hh"
#include <pthread.h>
#include <stdio.h>

class Thread: public NonCopyalbe {
public:
    Thread(): _threadNo(0), _isRunning(false) {}

    virtual ~Thread()
    {
        if(_threadNo){
            pthread_detach(_threadNo);  //线程分离函数
            _isRunning = false;
        }
    }

    //开始创建线程
    void start(void)
    {
        if(pthread_create(&_threadNo, nullptr, Thread::threadFunc, this) != 0)
        {
            perror("pthread_create()");
            return ;
        }
        _isRunning = true;
    }

    //等待 回收函数
    void join(void)
    {
        if(_isRunning){
            if(pthread_join(_threadNo, nullptr) != 0){
                perror("pthread_join");
                return ;
            }
            _isRunning = false;
        }
    }

    bool isRunning(void)
    {
        return _isRunning;
    }

protected:
    //线程处理函数，在类中时必须申明为静态函数，否则pthread_create报错
    static void *threadFunc(void *t)
    {
        //把this指针当作参数传进来，调用对象的方法。
        Thread * thread = (Thread *)t;
        if(thread){
            thread->run();
        }
        return nullptr;
    }

    virtual void run() = 0;   //实现任务

protected:
    pthread_t _threadNo;
    bool _isRunning;
};


#endif
