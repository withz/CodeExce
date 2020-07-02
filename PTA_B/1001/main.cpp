#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int> > list;

int main()
{
    int x, y;
    while(cin>>x&&cin>>y){
        list.push_back(make_pair(x, y));
    }
    for(auto iter = list.begin(); iter != list.end(); iter++){
        int a, b;
        a = ((iter->first) * (iter->second));
        if (iter->second != 0){
            b = (iter->second - 1);
        }else{
            continue;
        }
        

        cout << a << " " << b;
        if(iter + 1 != list.end()){
            cout << " ";
        }
    }
}
