#ifndef USERNAME_H
#define USERNAME_H

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

namespace linux_branch {
    namespace username {
        std::string getUsername();
    }
}

#endif /* USERNAME_H */
