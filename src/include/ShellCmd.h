#ifndef SHELL_CMD_H
#define SHELL_CMD_H

#include <string>

class ShellCmd {
  public:
    // Execute a shell command
    static std::string shell_cmd_exec(const char* cmd);
};

#endif
