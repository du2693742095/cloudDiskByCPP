/***********************************************************
  > File Name: NonCopyable.hh
  > Author: dsy
  > Mail: dushiyang68@gmail.com
  > Created Time: 2022年09月05日 星期一 16时18分38秒
  > Modified Time:2022年09月05日 星期一 16时18分38秒
 *******************************************************/
#ifndef __NONCOPYALBE_HH__
#define __NONCOPYALBE_HH__

class NonCopyalbe
{
protected:
    NonCopyalbe(){}

public:
    virtual ~NonCopyalbe(){}
    NonCopyalbe(const NonCopyalbe &) = delete ;
    NonCopyalbe & operator=(const NonCopyalbe &) = delete;
};

#endif

