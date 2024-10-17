#ifndef SVN_CPP
#define SVN_CPP

#include <string>

#include "include/SVN.h"
#include "include/ShellCmd.h"

std::string SVN::status() {
    std::string svn_status_result = ShellCmd::shell_cmd_exec("svn status");
    return svn_status_result;
}

std::string SVN::update() {
    std::string svn_update_result = ShellCmd::shell_cmd_exec("svn update");
    return svn_update_result;
}


#endif
