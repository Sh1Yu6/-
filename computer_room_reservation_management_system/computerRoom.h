#pragma once

#include <iostream>

class ComputerRoom
{
    public:
        void setId(int id);
        int getId() const;

        void setMaxNum(int num);
        int getMaxNum() const;
    private:
        int mComputerRoomID;
        int mMaxNum; 
};
