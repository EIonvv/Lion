#include "root.h"

bool linux_branch::root::is_root() {
  // create a system call to check if the user is root
  bool root = false;

  // get the user id
  uid_t uid = getuid();

  // check if the user id is 0
  if (uid == 0) {
    root = true;
  }

  // return the result
  return root;
}

int linux_branch::root::check_root() {
  bool rootCheck = root::is_root();
  if (rootCheck) {
    std::cout << "You are running as root!" << std::endl;
    return 1;
  } else {
    std::cout << "You are not running as root!" << std::endl;
    return 0;
  }
  return 0;
}
