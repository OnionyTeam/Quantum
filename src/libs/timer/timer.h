#ifndef _QUANTUM_TIMER_H__
#define _QUANTUM_TIMER_H__
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

class Timer
{
public:
    template <class callable, class... arguments>
    Timer(int after, bool async, callable &&f, arguments &&...args)
    {
        std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

        if (async)
        {
            std::thread([after, task]()
                        {
                std::this_thread::sleep_for(std::chrono::milliseconds(after));
                task(); })
                .detach();
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(after));
            task();
        }
    }
};
#endif //_QUANTUM_TIMER_H__