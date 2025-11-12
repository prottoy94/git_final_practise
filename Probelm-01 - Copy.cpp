#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    map<pair<string, char>, string> transitions =
    {
        {{"A", 'a'}, "B"}, {{"A", 'b'}, "C"},
        {{"B", 'a'}, "D"}, {{"B", 'b'}, "E"},
        {{"C", 'a'}, "F"}, {{"C", 'b'}, "G"},
        {{"D", 'a'}, "D"}, {{"D", 'b'}, "E"},
        {{"E", 'a'}, "H"}, {{"E", 'b'}, "Ø"},
        {{"F", 'a'}, "I"}, {{"F", 'b'}, "J"},
        {{"G", 'a'}, "B"}, {{"G", 'b'}, "G"},
        {{"H", 'a'}, "K"}, {{"H", 'b'}, "Ø"},
        {{"I", 'a'}, "D"}, {{"I", 'b'}, "E"},
        {{"J", 'a'}, "L"}, {{"J", 'b'}, "G"},
        {{"K", 'a'}, "D"}, {{"K", 'b'}, "E"},
        {{"L", 'a'}, "M"}, {{"L", 'b'}, "J"},
        {{"M", 'a'}, "N"}, {{"M", 'b'}, "E"},
        {{"N", 'a'}, "D"}, {{"N", 'b'}, "E"},
        {{"dead", 'a'}, "Ø"}, {{"dead", 'b'}, "Ø"}
    };


    map<string, set<int>> dfaStates = {
        {"A", {1,2,4,5,6}},
        {"B", {7,8,9,11,22}},
        {"C", {3,5,6}},
        {"D", {8,9,10,11,21,22}},
        {"E", {12}},
        {"F", {2,4,5,6,7,8,9,11,22}},
        {"G", {5,6}},
        {"H", {13,14,15,17}},
        {"I", {7,8,9,10,11,21,22}},
        {"J", {3,5,6,12}},
        {"K", {18,19,20,21,22,8,9,11}},
        {"L", {2,4,5,6,7,8,9,11,22,13,14,15,17}},
        {"M", {7,8,9,10,11,18,19,20,21,22}},
        {"N", {8,9,10,11,19,20,21,22}},
        {"dead", {}}
    };


    set<string> acceptingStates;
    for (auto &p : dfaStates) {
        if (p.second.count(22)) {
            acceptingStates.insert(p.first);
        }
    }

    int flag = 1;
    while(flag == 1)
    {
        string currentState = "A";
        string input;
        cout << "Enter input string (only 'a' and 'b'): ";
        getline(cin, input);

        for(char ch : input)
        {
            if(ch != 'a' && ch != 'b')
            {
                cout << "Invalid character '" << ch << "'. Only 'a' and 'b' allowed.\n";
            }

            auto key = make_pair(currentState, ch);
            if(transitions.find(key) != transitions.end())
            {
                currentState = transitions[key];
            }
            else
            {
                cout<<"The string is REJECTED (no transition from state "<<currentState<<" on '"<<ch<<"')\n";
                goto ask_continue;
            }
        }

        if(acceptingStates.count(currentState))
        {
            cout<<"The string is ACCEPTED by the DFA (ended in state "<<currentState<<").\n";
        }
        else
        {
            cout<<"The string is REJECTED by the DFA (ended in state "<<currentState<<").\n";
        }

        ask_continue:
        while(true)
        {
            cout << "Do you want to continue? (1 for yes, 0 for no): ";
            cin >> flag;
            if(flag==0||flag==1)
            {
                cin.ignore();
                break;
            }
            else
            {
                cout << "Invalid input! Please enter 1 (yes) or 0 (no).\n";
            }
        }
    }
    cout<<"This is printed after the first commit is done"<<'\n';
    cout<<"This is printed after the first commit is done- v-2"<<'\n';
    cout<<"This is printed after the third commit is done- v-2"<<'\n';
    cout<<"Trying to do fourth commit [Third try]"<<'\n';
    cout<<"Trying to do fifht commit [Start working on second day]"<<'\n';
    return 0;
}
