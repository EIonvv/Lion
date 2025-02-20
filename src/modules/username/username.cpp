#include "username.h"

std::string modules::username::getUsername() {
  struct passwd *pw = getpwuid(getuid());
  if (pw) {
    return std::string(pw->pw_name);
  } else {
    return std::string("unknown");
  }
}
