#ifndef THREAD_POOL_H
#define THREAD_POOL_H

class ThreadApi;

class ThreadPool
{
  private:
    ThreadApi& api_;

  public:
    ThreadPool( ThreadApi& api );
    virtual ~ThreadPool();

};
#endif
