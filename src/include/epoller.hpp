#ifndef EPOLLER
#define EPOLLER

#include <sys/epoll.h> //epoll_ctl()
#include <fcntl.h>  // fcntl()
#include <unistd.h> // close()
#include <assert.h> // close()
#include <vector>
#include <errno.h>

/**
 * @brief wrap epoll API up
 */

class Epoller {
public:
    explicit Epoller(int maxEvent = 1024);

    ~Epoller();

    bool AddFd(int fd, unsigned int events);

    bool ModFd(int fd, unsigned int events);

    bool DelFd(int fd);

    int Wait(int timeoutMs = -1);

    int GetEventFd(size_t i) const;

    unsigned int GetEvents(size_t i) const;
        
private:
    int epollFd_;

    std::vector<struct epoll_event> events_;    
};

#endif //EPOLLER