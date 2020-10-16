#include <bits/stdc++.h>
using namespace std;
class Closure
{
    char alpha;
    vector <char> alphabets;
    vector <vector<int>> epsilonClosure;
    vector <char> transitionTableRow;
    vector <vector<char>> transitionTable;
    map <char,vector<char>> closure;
    int noAlpha;
    int noStates;
    int noTransitions;
    
    public:
    void alphaNumber()
    {   
        cin>>noAlpha;
        this->noAlpha = noAlpha;

    }
    void alphaUsed()
    {
        while(this->noAlpha)
        {
            cin>>this->alpha;
            alphabets.push_back(this->alpha);
            this->noAlpha--;
        }
    }
    void stateNumber()
    {   
        cin>>noStates;
        this->noStates = noStates;

    }   
    void transitionNumber()
    {   
        cin>>noTransitions;
        this->noTransitions = noTransitions;

    }   
    void transitionTableCreate()
    {  char transit;
       int flag  = 0; 
       for(int i =0;i<noTransitions;i++)
        {
            for(int i=0;i<3;i++)
            {
                cin>>transit;
                if(i==1 && transit!='e')
                flag = 1;
                if(i!=1)
                transitionTableRow.push_back(transit);
            }
            if(flag == 0)
            {transitionTable.push_back(transitionTableRow);
            transitionTableRow.clear();}
            else
            {
                transitionTableRow.clear();
                flag = 0;
            }
            
            
           
        }

    } 
    void closureFunction()
    {
        set <char> s;
        for(int i =0;i<transitionTable.size();i++)
        {
            s.insert(transitionTable[i][0]);
        }
        set <char> :: iterator itr;
        for(int i =0;i<transitionTable.size();i++)
        {
           closure[transitionTable[i][0]].push_back(transitionTable[i][1]);
            
        }
        for(itr = s.begin();itr!=s.end();itr++)
        {
            closure[*itr].push_back(*itr);
        }

    }  
    void transitionPrint()
    {   //int noTransit = noTransitions;
        cout<<"Table:"<<endl;
        map <char,vector<char>> :: iterator itr;
        for(itr = closure.begin();itr!= closure.end();itr++)
        {
            cout<<itr->first<<" ";
            for(auto it2 = itr->second.begin(); it2 != itr->second.end();it2++)
            cout << *it2 << " ";
            cout<<endl;
        }

   }   


};


int main()
{

    Closure epsilon;
    
    //initialise number of alphabets
    cout<<"Enter the number of alphabets used for transition"<<endl;
    epsilon.alphaNumber();

    //get the alphabets used
    cout<<"Enter the alphabets used for transition(use 'e' for epsilon)"<<endl;
    epsilon.alphaUsed();

    //no of states
    cout<<"Enter the number of states"<<endl;
    epsilon.stateNumber();

    //no of transitions
    cout<<"Enter the number of transitions"<<endl;
    epsilon.transitionNumber();

    //enter transition
    cout<<"Enter the transition in the form 'state alpha state'"<<endl;
    epsilon.transitionTableCreate();
    epsilon.closureFunction();
    epsilon.transitionPrint();




    return 0;
}