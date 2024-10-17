#ifndef SHELL_CMD_CPP
#define SHELL_CMD_CPP

#include <string>
#include <memory>
#include <stdexcept>
#include <array>

#include "include/ShellCmd.h"

// Credits: https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
// TODO improve error handling and message
std::string ShellCmd::shell_cmd_exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

#endif
