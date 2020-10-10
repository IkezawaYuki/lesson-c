#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

long long rec(int i){
    if (i == 0) return 0;

    long long res = INF;

    chmin(res, rec(i-1) + abs(h[i] - h[i-1]));

    if (i > 1) chmin(res, rec(i - 2) + abs(h[i]- h[i-2]));

    return res;
}

int main(){
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    vector<long long> dp(N, INF);

    dp[0] = 0;

//    for (int i = 1; i < N; ++i){
//        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
//        if (i > 1){
//            chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
//        }
//    }

    for (int i = 0; i < N; ++i){
        if (i + 1 < N){
            chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        }
        if (i + 2 < N){
            chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
        }
    }

    cout << dp[N - 1] << endl;
    return 0;
}


//int main(){
//    int N;
//    cin >> N;
//    vector<long long>h(N);
//    for (int i = 0; i < N; ++i) cin >> h[i];
//
//    vector<long long> dp(N, INF);
//
//    dp[0] = 0;
//
//    for (int i = 1; i < N; ++i) {
//        if (i == 1) dp[i] = abs(h[i]-h[i-1]);
//        else dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),
//                         dp[i-2] + abs(h[i] - h[i-2]));
//    }
//
//    cout << dp[N-1] << endl;
//}

int GCD(int m, int n) {
    if (n == 0) return m;

    return GCD(n, m % n);
}

int toribo(int N);


vector<long long> cache;

//int main(){
//    int N = 10;
//    cache.assign(11, -1);
//    int A = toribo(N);
//    cout << A << endl;
//}


// todo鳥簿なっち
int toribo(int N){
    if (N == 0){
        return 0;
    } else if (N == 1){
        return 1;
    } else if (N == 2){
        return 2;
    }

    if (cache[N] != -1) return cache[N];

    return cache[N] = toribo(N-2) + toribo(N-1) + N;
}


int fibo(int N){
    cout << "fibo(" << N << ")を呼び出しました" << endl;
    if (N == 0) return 0;
    else if (N == 1) return 1;

    int result = fibo(N-1) + fibo(N-2);

    cout << N << " 項目 = " << result << endl;

    return result;
}

int fibo_array(){
    vector<long long>F(50);
    F[0] = 0, F[1] = 1;
    for (int N = 2; N < 50; ++N){
        F[N] = F[N-1] + F[N-2];
        cout << N << " 項目: " << F[N] << endl;
    }
}

vector<long long> memo;

long long fibo_memo(int N){
    if (N == 0) return 0;
    else if (N == 1) return 1;

    if (memo[N] != -1) return memo[N];

    return memo[N] = fibo_memo(N - 1) + fibo_memo(N - 2);
}

bool func(int i, int w, const vector<int> &a){
    if (i == 0){
        if (w == 0) return true;
        else return false;
    }

    if (func(i - 1, w, a)) return true;

    if (func(i - 1, w - a[i], a)) return true;

    return false;
}


