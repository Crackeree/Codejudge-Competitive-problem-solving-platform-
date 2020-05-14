#include "main.h"
#include<bits/stdc++.h>
using namespace std;


prob_info_::prob_info_()
    {
       no = new char[100];
       name = new char[100];
    }
   prob_info_:: prob_info_(char* no , char* name , double time_limit , int memory_limit, int difficulty)
    {

        this->no = new char[100];
        strcpy(this->no,no);
        this->name = new char[100];
        strcpy(this->name,name);
        this->time_limit = time_limit;
        this->memory_limit = memory_limit;
        this->difficulty = difficulty;

    }
    prob_info_::prob_info_(const prob_info_  &x)
    {
        no = new char[100];
        name= new char[100];

        strcpy(no,x.no);
        strcpy(name,x.name);

        time_limit = x.time_limit;
        memory_limit= x.memory_limit;
        difficulty = x.difficulty;
    }

    prob_info_&  prob_info_::operator=(prob_info_& x )
    {
        strcpy(no,x.get_no());
        strcpy(name,x.get_name());

        time_limit = x.time_limit;
        memory_limit=x.memory_limit;
        difficulty = x.difficulty;
        return x;
    }

