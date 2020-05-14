#include<bits/stdc++.h>
#include"submit.h"
#include"compare.h"
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
using namespace std;
class prob_info_
{
    char* no;
    char* name;
    double time_limit;
    int memory_limit;
    int difficulty;
public:
    char* get_no(void){return no;}
    void  set_no(char* ch){no=ch;}
    char* get_name(void){return name;}
    void set_name(char* ch){name = ch;}
    double get_t(void){return time_limit;}
    void set_t(double d){time_limit = d;}
    int get_m(void){return memory_limit;}
    void set_m(int d){memory_limit = d;}
    int get_d(void){return difficulty;}
    void set_d(int d){difficulty = d;}

    prob_info_();

    prob_info_(char* no , char* name , double time_limit , int memory_limit, int difficulty);

    prob_info_(const prob_info_  &x);


    prob_info_& operator=(prob_info_& x );


   virtual ~prob_info_()
   {
       delete [] no;
       delete [] name;
    }






};
 extern vector<prob_info_>vc;

 extern string prob_no;
 extern char *ch1;
 extern char *ch2;


#endif // MAIN_H_INCLUDED

