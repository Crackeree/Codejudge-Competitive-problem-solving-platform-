#include"main.h"

using namespace std;

vector<prob_info_>vc;
string prob_no;
char *ch1;
char *ch2;









namespace copy
{

void copy_to_cpp(void)
{
    stack<int>st;
    ifstream ifs("submit_txt.txt");
    ofstream ofs("submit_cpp.cpp");
    string str;
    bool b=1,b1=0,k=1,m=1;
    ofs<<"#include<time.h>\n";
    ofs<<"#include<fstream>\n";
    ofs<<"#include<iomanip>\n";

    while(getline(ifs,str))
    {

        if(b)
        {
            int i = str.find("main");
            if(i!= string:: npos)
            {
                b=0;
                b1=1;


            }
        }
        if(b1)
        {
            int i = str.find("{");
            if(i!= string:: npos)
            {
                string s1(ch1);
                string s2(ch2);
                string s = "{ FILE* f1=freopen(\""+ s1 + prob_no +".txt\",\"r\",stdin) ;\n FILE* f2=freopen(\"temp_output.txt\",\"w\",stdout) ;\n ofstream offs(\"temp_time.txt\");\n double a__,b__,c__;\n while(!feof(f1)) { \na__=clock();";
                str.replace(i, 1, s);
                b1=0;
            }
        }

        if(b==0 && b1==0 && k)
        {
            int z = str.find("return");
            if(z!=string::npos)str="b__=clock();\n c__ =(double) (b__- a__)/CLOCKS_PER_SEC;\n offs<<fixed; \n offs<<setprecision(4);\n offs<<c__<<endl; continue;\n";
            int i = str.find("{");
            if(i!=string::npos)st.push(1);
            int j = str.find("}");
            if(j!=string::npos)st.pop();
            if(st.empty())
            {
                str.replace(j,1,"b__ = clock();\n c__ = (double)(b__ - a__)/CLOCKS_PER_SEC;\n offs<<fixed; \n offs<<setprecision(4);\n offs<<c__<<endl;\n}\n fclose(stdin);\n freopen(\"CONOUT$\",\"w\",stdout);\n offs.close(); \n}");
                k=0;
            }

        }


        ofs<<str;
        ofs<<"\n";
    }
    ofs.flush();
    ofs.close();
    ifs.close();

}
}




int main()
{


    ifstream ifss("prob_info.txt");
    string s;

    while(getline(ifss,s))
    {
        stringstream ss(s);
        ss>>fixed;
        ss>>setprecision(4);
        string no_;
        string name_;
        double time_limit_;
        int memory_limit_;
        int difficulty_;
        ss>>no_>>name_>>time_limit_>>memory_limit_>>difficulty_;
        prob_info_ temp((char*)no_.c_str(),(char*)name_.c_str(),time_limit_,memory_limit_,difficulty_);
        vc.push_back(temp);






    }
    ifss.close();





A:
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\n";
    cout<<"-----------------------------------------------------------Welcome TO Code judge--------------------------------------------------------------------";
    cout<<"\n\n\n\n\t\t\t\t\t\t1. Press 1 to Submit Code\n";
    cout<<"\t\t\tPress: ";

    int press;
    cin>>press;










    string input("input_");
    string output("output_");
    output.append(prob_no.begin(),prob_no.end());
    input.append(prob_no.begin(),prob_no.end());
    ch1 = (char*)input.c_str();
    ch2 = (char*)output.c_str();



    string sss;
    FILE* fp, *f;
    bool bo=1;
    ifstream iffs("error.txt");
    switch(press)
    {
    case 1:

        submit();
        copy::copy_to_cpp();
        system("cd C:\\Users\\HP\\Desktop\\CODEJUDGE\\");
        f= freopen("error.txt","w",stderr);
        system("g++ submit_cpp.cpp -o submit_cpp.exe");
        system("submit_cpp.exe");
        while(getline(iffs,sss))
        {
            int k = sss.find("error");
            if(k!= string:: npos)
            {
                bo=0;
                iffs.close();
                cout<<"Compilation Error\n";
                ifstream ifs("error.txt");
                string sstr;
                while(getline(ifs,sstr))
                {
                    cout<<sstr;

                }
                ifs.close();
                break;
            }
        }
        iffs.close();
        if(bo)
        {

            compare(prob_no);
        }





        fp = fopen("submit_cpp.cpp","w");
        fclose(fp);
        fp = fopen("temp_output.txt","w");
        fclose(fp);
        fp = fopen("temp_time.txt","w");
        fclose(fp);
        fp = fopen("error.txt","w");
        fclose(fp);

        break;
    default:
         goto A;
        break;

    }






}


