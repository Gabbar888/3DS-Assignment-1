#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n , q;
    cin >> n >> q;
    vector<int> v;
    int inp , XOR;
    vector<int> pfxXOR;
    cin >> XOR;
    v.push_back(XOR);
    pfxXOR.push_back(XOR);
    for(int i = 1 ; i < n ; i++){
        cin >> inp;
        XOR ^= inp;
        v.push_back(inp);
        pfxXOR.push_back(XOR);
    }
    int a , b;
    for(int i = 0 ; i < q ; i++){
        cin >> a >> b;
        int l = pfxXOR[a-1];
        int r = pfxXOR[b-1];
        cout << (v[a-1]^(l^r))<< endl;
    }
    return 0;
}
