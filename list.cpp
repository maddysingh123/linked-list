#include<bits/stdc++.h>
#include<list>
using namespace std;
void explainList(){
    list <int> l;
    list <int> n(5,100);
    for (auto i : n){
        cout<<i<<" ";
    }
    cout<<endl;
    l.push_back(1);
    l.push_back(4);
    l.push_front(5);
    l.erase(l.begin());
    //rest of operation same as vector
}

int main (){
 explainList();
 return 0;

}    