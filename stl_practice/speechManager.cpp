
/************************************************
#
#      Filename: speechManager.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-25 19:51:38
# Last Modified: 2020-07-18 15:55:09
#***********************************************/
#include "speechManager.h"
#include "speaker.h"
#include <algorithm>
#include <ctime>
#include <deque>
#include <functional>
#include <iterator>
#include <numeric>
#include <fstream>
using namespace std;

SpeechManager::SpeechManager()
{
    initSpeech();
    createSpeaker();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::test()
{
    for(auto index = mSpeaker.begin(); index != mSpeaker.end(); ++index)
    {
        cout << "aa: " << index->first << " bb: " << index->second.mName 
             << " cc: " << index->second.mScore[0] 
             << " dd: " << index->second.mScore[1] << endl;
    }
}

void SpeechManager::showMenu()
{
    cout << "-------- SpeechManager System --------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) 开始演讲比赛" << endl;
    cout << "2) 查看往届记录" << endl;
    cout << "3) 清空比赛记录" << endl;
    cout << "0) 退出比赛程序" << endl;
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManager::initSpeech()
{
    mV1.clear();
    mV2.clear();
    mVictory.clear();
    mSpeaker.clear();
    mIndex = 1;
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for(int index = 0; index < nameSeed.size(); ++index)
    {
        string name = "选手";
        name += nameSeed[index];

        Speaker sp;
        sp.mName = name;

        for(int scoreIndex = 0; scoreIndex < 2; ++scoreIndex)
        {
            sp.mScore.push_back(0);
        }

        mV1.push_back(index + 10001);

        mSpeaker.insert(make_pair(index + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    srand(static_cast<unsigned int>(time(NULL)));
    speechDraw();
    speechContest();
    showScore();

    ++mIndex;

    speechDraw();
    speechContest();
    showScore();

    saveRecord();

    initSpeech();
    createSpeaker();
    loadRecord();

    cout << "本届比赛结束\n" << endl;
}
        
void SpeechManager::speechDraw()
{
    cout << "第 <<" << mIndex << ">> 轮比赛选手正在抽签" << endl;
    cout << "-------------------" << endl;
    cout << "抽签后演讲顺序:" << endl;
    
    if(mIndex == 1)
    {
        random_shuffle(mV1.begin(), mV1.end());
        for(auto iter = mV1.begin(); iter != mV1.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(mV2.begin(), mV2.end());
        for(auto iter = mV2.begin(); iter != mV2.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    cout << "-------------------" << endl;
    cout << endl;
    waitInput();
    
}

void SpeechManager::speechContest()
{
    cout << "第 <<" << mIndex << ">> 轮比赛开始" << endl;

    multimap<double, int, greater<double>> groupScore;
    int num = 0;

    vector<int> src;
    if(mIndex == 1)
    {
        src = mV1;
    }
    else
    {
        src = mV2;
    }

    for(auto iter = src.begin(); iter != src.end(); ++iter)
    {
        ++num;

        deque<double> d;
        for(int index = 0; index < 10; ++index)
        {
            double score = (rand() % 401 + 600) / 10.f;
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / static_cast<double>(d.size());

        mSpeaker[*iter].mScore[mIndex-1] = avg;

        groupScore.insert(make_pair(avg, *iter));

        if(num % 6 == 0)
        {
            int count = 0;
            cout << "第" << num / 6 << "小组比赛名次: " << endl;
            for(auto inIter = groupScore.begin(); inIter != groupScore.end();
                ++inIter)
            {
                cout << "编号: " << inIter->second
                     << "姓名: " << mSpeaker[inIter->second].mName
                     << "得分: " << mSpeaker[inIter->second].mScore[mIndex-1]
                     << endl;

                if(mIndex == 1)
                {
                    if(count < 3)
                    {
                        ++count;
                        mV2.push_back(inIter->second);
                    }
                }
                else
                {
                    if(count < 3)
                    {
                        ++count;
                        mVictory.push_back(inIter->second);
                    }
                }
            }
            groupScore.clear();
        }
    }

    cout << "第 <<" << mIndex << ">> 轮比赛结束" << endl;
    cout << endl;
    waitInput();

}

void SpeechManager::showScore()
{
    cout << "第 <<" << mIndex << ">> 轮晋级选手信息如下:" << endl;
    vector<int> temp;

    if(mIndex == 1)
    {
        temp = mV2;
    }
    else
    {
        temp = mVictory;
    }

    for(auto iter = temp.begin(); iter != temp.end(); ++iter)
    {
        cout << "编号: " << *iter
             << "姓名: " << mSpeaker[*iter].mName
             << "得分: " << mSpeaker[*iter].mScore[mIndex-1]
             << endl;
    }
    cout << endl;
    waitInput();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    for(auto iter = mVictory.begin(); iter != mVictory.end(); ++iter)
    {
        ofs << *iter << "," << mSpeaker[*iter].mScore[1] << ",";
    }
    ofs << endl;

    ofs.close();

    cout << "记录已经保存" << endl;
    mFileIsEmpty = false;
    waitInput();
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv");

    if(!ifs.is_open())
    {
        mFileIsEmpty = true;
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空" << endl;
        mFileIsEmpty = true;
        ifs.close();
        return;
    }

    mFileIsEmpty = false;

    ifs.putback(ch);

    int index = 0;
    string data;
    while(ifs >> data)
    {
        vector<string> v;
        int pos = -1;
        int start = 0;

        while(true)
        {
            pos = data.find(",", start);
            if(pos == -1)
            {
                break;
            }
            string temp = data.substr(start, pos - start);

            v.push_back(temp);

            start = pos + 1;
        }

        mRecord.insert(make_pair(index, v));
        ++index;
    }

    ifs.close();
}

void SpeechManager::showRecord()
{
    if(mFileIsEmpty)
    {
        cout << "打开文件失败!" << endl;
        return ;
    }

    for(int index = 0; index < mRecord.size(); ++index)
    {
        cout << "第" << index + 1 << "届:"
             << "\n冠军: " << mRecord[index][0] << " 得分: " << mRecord[index][1]
             << "\n亚军: " << mRecord[index][2] << " 得分: " << mRecord[index][3]
             << "\n季军: " << mRecord[index][4] << " 得分: " << mRecord[index][5]
             << endl;
    }
    waitInput();
}

void SpeechManager::waitInput()
{
    cout << "请按回车键继续......." << endl;
    cin.ignore();
    cin.get();
}

void SpeechManager::clearRecord()
{
    cout << "是否确认清空记录?(1. YES  2. NO)" << endl;

    int choice = 0;
    cin >> choice;

    if(choice == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        initSpeech();
        createSpeaker();
        mRecord.clear();
        loadRecord();
        
        cout << "清空成功!" << endl;
    }
    waitInput();


}
