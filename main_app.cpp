#include <bits/stdc++.h>
using namespace std;
int i = 1; // no. for the list of subjects
int second = 1;
// use [] to access data in maps.
map<string, vector<pair< string, char>> > sub_chap; //cotains subjects and chapters to revise
void View(){
    int rev_exi_ch;
    string rev_ch, rev_sub;
    while (true){
        i = second = 1;
        cout << "Items to Revise :" << setw(20) << "Status" << endl << endl;//10 spaces
        for(auto sub : sub_chap){
            cout << i << ") " << sub.first << endl << "    ";
            for(int j = 0 ; j < sub_chap[sub.first].size() ; j++){
                cout << second << ") " << sub_chap[sub.first][j].first << "      " << sub_chap[sub.first][j].second << endl;
                second ++;
            }
            i++;
        }
        /*sub_chap - variable name
        sub -> key value pair
        sub.first -> key 
        j -> position in vector
        .first -> 1st elemt (string / chapter ) of that pair at that position
        */
        cout << "Options :" << endl << "    ";
        cout << "1) Revise" << endl << "    " << "2) Exit" << "\n";
        cout << "Choose : ";
        cin >> rev_exi_ch;
        if(rev_exi_ch == 1) {
            cout << "Which Subject will you revise : " ;
            cin >> rev_sub;
            cout << endl;
            cout << "Which Chapter will you revise : " ;
            cin >> rev_ch;
            cout << endl;
            cout << "**********************************************" << endl ;
            int position = 0 ;//placeholder. needs to be changed
            sub_chap[rev_sub][position].second = 'Y';
        }
        else break;
    }
}
void Add(){
    i = 1;
    char new_sub;
    string sub_name;
    string chap_name; // TO CHANGE
    char exi_ch; 
    while (true){
        i = 1;
        cout << "Added Subjects : " << endl;
        for(auto sub : sub_chap){
            second = 1;
            cout << i << ") " << sub.first << endl << "    ";
            for(int j = 0 ; j < sub_chap[sub.first].size() ; j++){
                cout << second << ") " << sub_chap[sub.first][j].first << endl;
                second ++;
            }
            i++;
        } 
        cout << endl;
        cout << "Is it a New Subject (Y / N) : " ; 
        cin >> new_sub;
        if(new_sub == 'Y' or new_sub == 'y') {
            cout << "Enter Subject : ";
            cin >> sub_name;
            cout << "Enter Chapter : ";
            cin >> chap_name;
            sub_chap[sub_name].push_back({chap_name,'N'});
        }
        else {
            cout << "Which Subject : "; 
            cin >> sub_name;     //TO CHANGE
            cout << "Enter Chapter :  ";
            cin >> chap_name;
            sub_chap[sub_name].push_back({chap_name,'N'});
        }  
        cout << "Exit ? (Y / N) : " ;
        cin >> exi_ch;
        cout << endl;
        if((exi_ch == 'Y')||(exi_ch == 'y')){
            break;
        }
    }
}
int main(){
    while (true){
        //welcome screen
        int wel_ch = 0;
        cout << "               " <<"Spaced Repitition Helper" << endl;
        cout << "Options " << endl;
        cout << "     " << "1) View Subjects"<< endl;
        cout << "     " << "2) Add Subjects "<< endl;
        cout << "     " << "3) Exit"<< endl;
        cout << "Your choice : ";
        cin >> wel_ch;
        if(wel_ch == 1) View();
        else if(wel_ch == 2) Add();
        else if(wel_ch == 3) break;
        else cout << "Invalid Choice . Try Again" << "\n";
    }
}