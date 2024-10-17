#ifndef SVN_H
#define SVN_H

#include <string>

class SVN {
  public:
    // Get the state of every file in the local repository
    static std::string status();

    // Pull latest changes from remote repository
    static std::string update();

    // static std::string log();
    // static std::string diff();
    // etc
};

#endif
