#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n , x;
    cin >> n >> x;
    int inp;
    vector < pair<int,int> > vec;
    for(int i = 0 ; i < n ; i++){
        cin >> inp;
        vec.push_back(make_pair(inp, i+1));
    }
    sort(vec.begin(),vec.end());
    int found = 0;
    for(int i = 0 ; i < n ; i++){
        if(found) break;
        for(int j = i + 1 ; j < n ; j++){
            if(found) break;
            int l = j + 1 , r = n - 1;
            while(l <= r){
                int mid = (l+r)/2;
                int t = x - vec[i].first - vec[j].first;
                if(vec[mid].first == t){
                    found = 1;
                    cout << vec[i].second << " "
                         << vec[j].second << " "
                         << vec[mid].second << " ";
                    break;
                }
                else if(vec[mid].first > t){
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
    return 0;
}
