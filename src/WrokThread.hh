/***********************************************************
  > File Name: WrokThread.hh
  > Author: dsy
  > Mail: dushiyang68@gmail.com
  > Created Time: 2022年09月06日 星期二 10时13分03秒
  > Modified Time:2022年09月06日 星期二 10时13分03秒
 *******************************************************/
#ifndef __WORKTHREAD_HH__
#define __WORKTHREAD_HH__

#include "Thread.hh"
#include "ThreadPoll.hh"

class WorkThread: public Thread
{
public:
    WorkThread(ThreadPoll & poll)
        : _poll(poll)
    {}

    ~WorkThread() {}

    //线程实际要做的事
    void run() override
    {
        _poll.threadFunc();
    }
private:
    ThreadPoll & _poll;
};

#endif
