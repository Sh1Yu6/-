
/************************************************
#
#      Filename: main.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-05-03 15:43:14
# Last Modified: 2021-05-03 15:44:59
#***********************************************/
#include <iostream>
#include "tcpServerClass.h"
using namespace std;

int main(int argc, char *argv[])
{
    Sh1Yu6::Server server;
    server.run();

    return 0;
}

