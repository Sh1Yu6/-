#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "speaker.h"


class SpeechManager
{
    public:
        SpeechManager();
        ~SpeechManager();

        void showMenu();

        void exitSystem();

        void test();

        void startSpeech();

    private:

        void initSpeech();

        void createSpeaker();

        void speechDraw();

        void speechContest();

        void showScore();






        std::vector<int> mV1;
        std::vector<int> mV2;
        std::vector<int> mVictory;
        std::map<int, Speaker> mSpeaker;
        int mIndex;

};

