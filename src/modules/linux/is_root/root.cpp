#include "root.h"

bool linux_branch::root::is_root() {
  // create a system call to check if the user is root
  bool root = false;

  if (getpid() == 0) {
    root = true;
  }

  return root;
}

int linux_branch::root::check_root() {
  bool rootCheck = root::is_root();
  if (rootCheck) {
    std::cout << "You are running as root!" << std::endl;
  } else {
    std::cout << "You are not running as root!" << std::endl;
  }
  return 0;
}
