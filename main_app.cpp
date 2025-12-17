#include <bits/stdc++.h>
using namespace std;
bool break_value = false;
bool break_add = false;
int i = 1; // no. for the list of subjects
int j = 1;
map<string, pair< string, char> > sub_chap; //cotains subjects and chapters to revise
void View(){
    string rev_ch, rev_sub;
    cout << "Items to Revise :" << "          " << "Status" << endl;//10 spaces
    for(auto sub : sub_chap){
        cout << i << ") " << sub.first << endl << "    ";
        for(auto chap : sub_chap){
            cout << j << ") " << chap.second.first << "      " << chap.second.second << endl;
            j ++;
        }
        i++;
    }
    cout << "Which Subject will you revise : " ;
    cin >> rev_sub;
    cout << endl;
    cout << "Which Chapter will you revise : " ;
    cin >> rev_ch;
    cout << endl;
    cout << "**********************************************" << endl ;
    sub_chap[rev_sub] = {rev_ch,'Y'};
    for(auto sub : sub_chap){
        cout << i << ") " << sub.first << endl << "    ";
        for(auto chap : sub_chap){
            cout << j << ") " << chap.second.first << "      " << chap.second.second << endl;
            j ++;
        }
        i++;
    }
}
void Add(){
    i = 1;
    char new_sub;
    string sub_name;
    string chap_name; // TO CHANGE
    char exi_ch; 
    while (true){
        cout << "Added Subjects : " << endl;
        for(auto sub : sub_chap){
        cout << i << ") " << sub.first << endl << "    ";
            for(auto chap : sub_chap){
                cout << j << ") " << chap.second.first << endl;
                j ++;
            }
            i++;
        }
        cout << "Is it a New Subject (Y / N) : " ; 
        cin >> new_sub;
        if(new_sub == 'Y' or new_sub == 'y') {
            cout << "Enter Subject : ";
            cin >> sub_name;
            sub_chap[sub_name] = {"",'N'};
            cout << "Enter Chapter :  ";
            cin >> chap_name;
            sub_chap[sub_name] = {chap_name,'N'};
        }
        else {
            cout << "Which Subject : "; 
            cin >> sub_name;     //TO CHANGE
            cout << "Enter Chapter :  ";
            cin >> chap_name;
            sub_chap[sub_name] = {chap_name,'N'};
        }  
        cout << "Exit ? (Y / N) : " ;
        cin >> exi_ch;
        cout << endl;
        if(exi_ch == 'Y'){
            break_add = true;
            break;
        }
    }
}
int main(){
    while (true){
        //welcome screen
        int wel_ch;
        cout << "               " <<"Spaced Repitition Helper" << endl;
        cout << "Options " << endl;
        cout << "     " << "1) View Subjects"<< endl;
        cout << "     " << "2) Add Subjects "<< endl;
        cout << "     " << "3) Exit"<< endl;
        cout << "Your choice : ";
        cin >> wel_ch;
        if(wel_ch == 1) View();
        else if(wel_ch == 2) Add();
        else break;
        // 2 and 3 break
        if((break_value == true ) || (break_add = true )){
            break;
        }
    }
}