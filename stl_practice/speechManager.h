#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "speaker.h"
#include <string>


class SpeechManager
{
    public:
        SpeechManager();
        ~SpeechManager();

        void showMenu();

        void exitSystem();

        void test();

        void startSpeech();

        void showRecord();

        void clearRecord();

    private:

        void initSpeech();

        void createSpeaker();

        void speechDraw();

        void speechContest();

        void showScore();

        void saveRecord();

        void loadRecord();

        void waitInput();





        std::vector<int> mV1;
        std::vector<int> mV2;
        std::vector<int> mVictory;
        std::map<int, Speaker> mSpeaker;
        int mIndex;

        bool mFileIsEmpty;
        std::map<int, std::vector<std::string>> mRecord; 


};

