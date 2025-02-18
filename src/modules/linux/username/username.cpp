#include "username.h"

std::string linux_branch::username::getUsername()
{
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(getuid());
    if (pw){
        return std::string(pw->pw_name);
    } else {
        return std::string("unknown");
    }
}
