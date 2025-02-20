#ifndef USERNAME_H
#define USERNAME_H

#include <iostream>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

namespace modules {
namespace username {
std::string getUsername();
}
} // namespace modules

#endif /* USERNAME_H */
