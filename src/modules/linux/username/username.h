#ifndef USERNAME_H
#define USERNAME_H

#include <iostream>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

namespace linux_branch {
namespace username {
std::string getUsername();
}
} // namespace linux_branch

#endif /* USERNAME_H */
