#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"


class OrderFile
{
    public:
        OrderFile();

        void updateOrder();

        int mSize;

        std::map<int, std::map<std::string, std::string>> mOrderData;
};
