#include"main.h"
void compare(string prob_no)
{
    string ifs1_file = "output_"+prob_no+".txt";
    string ifs2_file = "temp_output.txt";
    string time_file = "temp_time.txt";
    stringstream ss;
    ss<<prob_no;
    int problem_no ;
    ss>>problem_no;
    double time_limit = vc[problem_no-1].get_t();
    ifstream ifs1((char*)ifs1_file.c_str());
    ifstream ifs2((char*)ifs2_file.c_str());
    ifstream ifst((char*)time_file.c_str());
    string j_ans,output;
    double time;
    int i=1;
    bool a=0,t=0,w=0;
    while(ifst>>time && ifs2>>output)
    {
        if(time>time_limit)
        {
            cout<<"Time Limit Exceeded On Test Case "<<i<<endl<<"Time Taken "<<time<<endl<<"Time Limit "<<time_limit<<endl;;
            t=1;
            break;
        }
        if(ifs1>>j_ans)
        {

            if(j_ans != output)
            {
                cout<<"Wrong Ans On Test Case "<<i<<endl;
                w=1;
                break;
            }
            i++;
        }
        else
        {
            cout<<"Wrong Ans On Test Case "<<i<<endl;
            w=1;
            break;
        }

    }
    if(w || t);
    else
    {
        ifs1>>j_ans;
        if(ifs1.eof())cout<<"Accepted\n";
        else cout<<"Wrong Ans On Test Case "<<i<<endl;
    }

}
