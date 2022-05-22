#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

class Timer
{
private:
    std::unique_ptr<std::thread> t;
public:
    template <class callable, class... arguments>
    Timer(int after, bool async, callable&& f, arguments&&... args)
    {
        std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

        if (async)
        {
            t = std::unique_ptr<std::thread>(new std::thread([after, task]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(after));
                task();
            }));
            t->detach();
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(after));
            task();
        }
    }


};