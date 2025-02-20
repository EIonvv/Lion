#ifndef ROOT_H
#define ROOT_H

#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>

namespace modules {
namespace root {
bool is_root();
int check_root();
} // namespace root
} // namespace modules

#endif /* ROOT_H */
