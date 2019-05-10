#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

int arp_scan(){
    int x=system("arp.bat");
    //int x=WinExec("C://windows/system32/arp.exe -a>./result.txt",SW_HIDE);
    if(x){
        cout<<"ARP ERROR "<<x<<endl;
        return 1;
    }
    x=system("arp2.py");
    if(x){
        cout<<"FILE OPEN ERROR"<<x<<endl;
        return 1;
    }
    
}