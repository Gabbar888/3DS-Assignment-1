#include <iostream>
#include <vector>
#include <set>
typedef  long long int ll;
using namespace std;
int main(){
    ll n , a , b;
    cin >> n >> a >> b;
    vector<ll> pfxSum(n+1,0);
    ll inp;
    for(ll i = 1 ; i <= n ; i++){
        cin >> inp;
        pfxSum[i] = pfxSum[i-1] + inp;
    }
    multiset<ll> minSet;
    ll maxSum = INT64_MIN;
    for(ll i = a ; i < n + 1 ; i++){
        minSet.insert(pfxSum[i-a]);
        if(i > b){
            minSet.erase(minSet.find(pfxSum[i-b-1]));
        }
        maxSum = max(maxSum , pfxSum[i] - *minSet.begin());
    }
    cout << maxSum << endl;
    return 0;
}
