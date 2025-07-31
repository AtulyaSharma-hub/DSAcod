#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<int,string> m;
    m.insert(make_pair(23,"Amit"));
    m.insert(make_pair(42,"John"));
    m.insert(make_pair(23,"Amia"));
    auto range = m.equal_range(23);
    cout << "Elements with key 23:" << endl;
    for(auto it = range.first; it != range.second; ++it){
        cout << it->second << endl;
    }
    cout << "All elements in the multimap:" << endl;
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    cout << "Size of multimap: " << m.size() << endl;
    cout << "Is multimap empty? " << (m.empty() ? "Yes" : "No") << endl;
    cout << "Removing elements with key 23." << endl;
    m.erase(23);
    cout << "All elements in the multimap after removal:" << endl;
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    cout << "Size of multimap after removal: " << m.size() << endl;
    cout << "Is multimap empty? " << (m.empty() ? "Yes" : "No") << endl;
    return 0;
}