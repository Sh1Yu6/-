
/************************************************
#
#      Filename: computerRoom.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-28 22:20:18
# Last Modified: 2020-06-28 22:25:45
#***********************************************/
#include "computerRoom.h"

int ComputerRoom::getId() const
{
    return mComputerRoomID;
}

int ComputerRoom::getMaxNum() const
{
    return mMaxNum;
}

void ComputerRoom::setMaxNum(int num)
{        
    mMaxNum = num;
}

void ComputerRoom::setId(int id)
{
    mComputerRoomID = id;
}
