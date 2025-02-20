#ifndef ROOT_H
#define ROOT_H

#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>

namespace linux_branch {
namespace root {
bool is_root();
int check_root();
} // namespace root
} // namespace linux_branch

#endif /* ROOT_H */
