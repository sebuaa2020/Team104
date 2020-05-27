#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int main(int argc, char** argv)
{
    if (argc != 2) {
        puts("Need an argument");
        assert(0);
    }
    int x = argv[1][0] - '0';
    if (x == 1) {
        puts("move.cpp test 1 starting!");
        string pp = "rosrun team_104 move ";
        system((pp + "forward 1").data());
        puts("test 1 finished");
        usleep(0.5);

        system((pp + "backward 1").data());
        puts("test 2 finished");
        usleep(0.5);

        system((pp + "forward 2").data());
        puts("test 3 finished");
        usleep(0.5);

        system((pp + "backward 2").data());
        puts("test 4 finished");
        usleep(0.5);

        system((pp + "forward 3").data());
        puts("test 5 finished");
        usleep(0.5);

        system((pp + "backward 3").data());
        puts("test 6 finished");
        usleep(0.5);

        system((pp + "forward 4").data());
        puts("test 7 finished");
        usleep(0.5);

        system((pp + "backward 4").data());
        puts("test 8 finished");
        usleep(0.5);

        system((pp + "forward 5").data());
        puts("test 9 finished");
        usleep(0.5);

        system((pp + "backward 5").data());
        puts("test 10 finished");
        usleep(0.5);

        system((pp + "left 1").data());
        puts("test 11 finished");
        usleep(0.5);

        system((pp + "right 1").data());
        puts("test 12 finished");
        usleep(0.5);

        system((pp + "left 2").data());
        puts("test 13 finished");
        usleep(0.5);

        system((pp + "right 2").data());
        puts("test 14 finished");
        usleep(0.5);

        system((pp + "left 3").data());
        puts("test 15 finished");
        usleep(0.5);

        system((pp + "right 3").data());
        puts("test 16 finished");
        usleep(0.5);

        system((pp + "left 4").data());
        puts("test 17 finished");
        usleep(0.5);

        system((pp + "right 4").data());
        puts("test 18 finished");
        usleep(0.5);

        system((pp + "left 5").data());
        puts("test 19 finished");
        usleep(0.5);

        system((pp + "right 5").data());
        puts("test 20 finished");
        usleep(0.5);

        system((pp + "rotate_l 90").data());
        puts("test 21 finished");
        usleep(0.5);

        system((pp + "rotate_r 90").data());
        puts("test 22 finished");
        usleep(0.5);

        system((pp + "rotate_l 180").data());
        puts("test 23 finished");
        usleep(0.5);

        system((pp + "rotate_r 180").data());
        puts("test 23 finished");
        usleep(0.5);
    }
    else 
    {
        puts("move.cpp test 2 starting!");
        string pp = "rosrun team_104 move ";
        system((pp + "forward -1").data());
        puts("test 1 finished");
        usleep(0.5);
        
        system((pp + "backward 6").data());
        puts("test 2 finished");
        usleep(0.5);
        
        system((pp + "left -1").data());
        puts("test 3 finished");
        usleep(0.5);
        
        system((pp + "right -1").data());
        puts("test 4 finished");
        usleep(0.5);
        
        system((pp + "rotate_l -1").data());
        puts("test 5 finished");
        usleep(0.5);
        
        system((pp + "rotate 181").data());
        puts("test 6 finished");
        usleep(0.5);
        
        system((pp + "rotate_r -1").data());
        puts("test 7 finished");
        usleep(0.5);
        
        system((pp + "rotate_r 181").data());
        puts("test 8 finished");
        usleep(0.5);
    }
    return 0;
}