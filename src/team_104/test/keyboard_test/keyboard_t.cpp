#include <stdio.h>
#include <termios.h>           
#include <unistd.h>     
#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
int main()
{
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    system("stty -echo");
	puts("46");

    puts("\tu\ti\to\n\n\tj\tk\tl\n");
    puts("u: turn left\no: turn right\ni: go forward\nj: go left\nk: go backward\nl: go right\nq: quit");
    char ch;
    double last=clock()/1000.;
    //cerr<<last<<"\n";
    while (1) {
	puts("54");
        while(1)
        {
	puts("57");
            if(kbhit())break;
            if(clock()/1000.-last>0.3)
            {
	puts("61");
                system("rosrun team_104 move stop 0");
            }
        }
        ch = getchar();
        if(clock()/1000.-last<0.29)
		{
			
	puts("68");
			continue;
		}
        //cerr<<clock()/1000.-last<<"\n";
        last=clock()/1000.;
        if(ch=='q'){
	puts("75");break;}
        const string p="rosrun team_104 move ";
        if(ch=='u')
        {
	puts("79");
            const string pp=p+"rotate_l 90";
            system(pp.data());
        }
        if(ch=='i')
        {
	puts("85");
            const string pp=p+"forward 2";
            system(pp.data());
        }
        if(ch=='o')
        {
	puts("90");
            const string pp=p+"rotate_r 90";
            system(pp.data());
        }
        if(ch=='j')
        {
	puts("97");
            const string pp=p+"left 2";
            system(pp.data());
        }
        if(ch=='k')
        {
	puts("103");
            const string pp=p+"backward 2";
            system(pp.data());
        }
        if(ch=='l')
        {
	puts("108");
            const string pp=p+"right 2";
            system(pp.data());
        }
    }
	puts("114");
    system("rosrun team_104 move stop 0");
    system("stty echo");
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
