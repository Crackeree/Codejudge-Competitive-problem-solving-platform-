#include "main.h"




void submit(void)
{
    cout<<"\n\nProblem No: ";
    cin>>prob_no;
    bool k=1;
    for(int i=0;i<vc.size();i++)
    {
        if(vc[i].get_no()==(char*)prob_no.c_str()){k=0;break;}
    }
    if(k){cout<<"No Such Problem\n"; return;}
    cout<<"\n\nPaste your code below:\n\n";
    ofstream ofs;
    ofs.open("submit_txt.txt");
    string str;
    cin.ignore();
    while(getline(cin,str))
    {
        ofs<<str;
        ofs<<"\n";
    }
    ofs.close();
}

