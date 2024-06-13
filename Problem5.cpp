#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;

int min_table[100001][17];
int max_table[100001][17];

int log_(int n)
{
    return 32 - __builtin_clz(n) - 1;
}
int min_query(int l , int r){
    int m = INF;
    int len = r - l + 1;
    int Hpow = log_(len);
    m = min(m,min_table[l][Hpow]);
    m = min(m,min_table[r - (1<<Hpow) + 1][Hpow]);
    return m;
}
int max_query(int l , int r){
    int M = 0;
    int len = r - l + 1;
    int Hpow = log_(len);
    M = max(M,max_table[l][Hpow]);
    M = max(M,max_table[r-(1<<Hpow)+1][Hpow]);
    return M;
}
int main()
{
    int N;
    cin >> N;
    vector<int> BurnTimes;
    for(int i = 0 ; i < N ; i++){
        int x;
        cin >> x;
        BurnTimes.push_back(x);
    }
    int LOG = log_(N);
    for(int i = 0 ; i < N ; i++){
        min_table[i][0] = BurnTimes[i];
        max_table[i][0] = BurnTimes[i];
    }
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 0 ; i + (1<<(j-1)) - 1 < N ; i++){
            min_table[i][j] = min(min_table[i][j-1] , min_table[i + (1<<(j-1))][j-1]);
            max_table[i][j] = max(max_table[i][j-1] , max_table[i + (1<<(j-1))][j-1]);
        }
    }
     int Q;
     cin >> Q;
     for(int i = 0 ; i < Q ; i++){
         int l , r;
         cin >> l >> r;
         int m = min_query(l,r);
         int M = max_query(l,r);
         double t_in = (M - m)/2.0;
         int leftMax = (l == 0) ? 0 : max_query(0,l-1);
         int rightMax = (r == N - 1) ? 0 : max_query(r+1,N-1);
         double t_out = max(leftMax,rightMax);
         double time = m + max(t_in , t_out);
         printf("%0.01lf\n",time); // If i used cout it was not getting accepted I have no idea why this worked , i just did it coz i could not think of anything else
     }
    return 0;
}
