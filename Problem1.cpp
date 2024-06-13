#include <iostream>
#include <vector>
#include <deque>
#include <climits>
typedef long long int ll;
using namespace std;
int main(){
    ll n , a , b;
    cin >> n >> a >> b;
    vector<ll> array;
    ll x;
    for(ll i = 0 ; i < n ; i++){
        cin >> x;
        array.push_back(x);
    }
    vector<ll> prefixSum(n+1,0);
    prefixSum[1] = array[0];
    for(ll i = 2 ; i < n + 1 ; i++){
        prefixSum[i] = prefixSum[i-1] + array[i-1];
    }
    vector<ll> maxSum;
    deque<ll> minQueue;
    ll maxsum = INT64_MIN;
    for(ll i = a ; i < n + 1 ; i++){
        if(!minQueue.empty() && minQueue.front() < i - b ){
            minQueue.pop_front();
        }
        while(!minQueue.empty() && prefixSum[minQueue.back()] >= prefixSum[i-a]){
            minQueue.pop_back();
        }
        minQueue.push_back(i-a);
        ll curr = prefixSum[i] - prefixSum[minQueue.front()];
        maxsum = max(maxsum , curr);
    }
    cout << maxsum << endl;
    return 0;
}
/* The below method is the solution that mentor gave me and from that i found out mistake in my approach*/
// #include <iostream
// #include <vector>
// #include <set>
// typedef  long long int ll;
// using namespace std;
// int main(){
//     ll n , a , b;
//     cin >> n >> a >> b;
//     vector<ll> pfxSum(n+1,0);
//     ll inp;
//     for(ll i = 1 ; i <= n ; i++){
//         cin >> inp;
//         pfxSum[i] = pfxSum[i-1] + inp;
//     }
//     multiset<ll> minSet;
//     ll maxSum = INT64_MIN;
//     for(ll i = a ; i < n + 1 ; i++){
//         minSet.insert(pfxSum[i-a]);
//         if(i > b){
//             minSet.erase(minSet.find(pfxSum[i-b-1]));
//         }
//         maxSum = max(maxSum , pfxSum[i] - *minSet.begin());
//     }
//     cout << maxSum << endl;
//     return 0;
// }
