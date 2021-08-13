
/************************************************
#
#      Filename: more.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-05-06 08:37:33
# Last Modified: 2021-05-10 14:33:44
#***********************************************/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

constexpr int kPageLen = 24;
constexpr int kLineLen = 1024;

class More{
    public:
        More() = default;

        More( int fileFd ): mFileFd{ fileFd }{

        }

        More( string fileName ){
            mFileFd = open( fileName.c_str(), O_RDONLY );
            if( mFileFd == -1 ){
                perror( "open error" );
                exit(1);
            }
        }

        ~More(){
            if( mFileFd != STDIN_FILENO ){
                cout << "a" << endl;
                close( mFileFd );
            }
        }

        void doMore( ){
            char line[kLineLen];
            memset(line, 0, kLineLen);
            int numOfLines = 0;
            while(read(mFileFd, line, kLineLen)){
                if(numOfLines == kPageLen){
                    int reply = seeMore();
                    if( reply == 0 ){
                        break;
                    }
                    numOfLines -= reply;
                }
                cout << line << endl;
                memset(line, 0, kLineLen);
                ++numOfLines;
                cout << "------" << numOfLines << endl;
            }
        }

        int seeMore(){
            int c;
            cout << "\033[7m more?\033[" << endl;
            while( (c = cin.get()) != EOF){
                if ( c == 'q' ){
                    return 0;
                }
                if ( c == ' ' ){
                    return kPageLen;
                }
                if ( c == '\n' ){
                    return 1;
                }
            }
            return 0;
        }
    private:
        int mFileFd;
};

int main(int argc, char *argv[])
{
    if( argc == 1 ){
        More more(STDIN_FILENO);
    }else{
        while(--argc){
            More more( argv[1] );
            more.doMore();
        }
    }
    return 0;
}

