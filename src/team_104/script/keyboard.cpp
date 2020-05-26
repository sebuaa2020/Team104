#include <stdio.h>
#include <termios.h>           
#include <unistd.h>     
#include <bits/stdc++.h>
using namespace std;
int main()
{
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    system("stty -echo");


    puts("\tu\ti\to\n\n\tj\tk\tl\n");
    puts("u: turn left\no: turn right\ni: go forward\nj: go left\nk: go backward\nl: go right\nq: quit");
    char ch;
    while (1) {
        ch = getchar();
        if(ch=='q')break;
        const string p="rosrun team_104 move ";
        if(ch=='u')
        {
            const string pp=p+"rotate_l 90";
            system(pp.data());
        }
        if(ch=='i')
        {
            const string pp=p+"forward 2";
            system(pp.data());
        }
        if(ch=='o')
        {
            const string pp=p+"rotate_r 90";
            system(pp.data());
        }
        if(ch=='j')
        {
            const string pp=p+"left 2";
            system(pp.data());
        }
        if(ch=='k')
        {
            const string pp=p+"backward 2";
            system(pp.data());
        }
        if(ch=='l')
        {
            const string pp=p+"right 2";
            system(pp.data());
        }
    }
    system("stty echo");
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}