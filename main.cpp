#include <iostream>
#include <vector>
using namespace std;

int GCD(int m, int n) {
    if (n == 0) return m;

    return GCD(n, m % n);
}


// todo鳥簿なっち
int toribo(int N){
    if (N == 0){
        return 0;
    } else if (N == 1){
        return 1;
    } else if (N == 2){
        return 2;
    }
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


int main(){
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}


//int main(){
//    cout << GCD(51, 15) << endl;
//    cout << GCD(15, 51) << endl;
//
//    fibo(6);
//    fibo_array();
//
//    memo.assign(50, -1);
//    fibo_memo(49);
//    for (int N = 2; N < 50; ++N){
//        cout << N << " 項目: " << memo[N] << endl;
//    }
//}






//int main() {
//    int N, W;
//    cin >> N >> W;
//    vector<int>a(N);
//    for (int i = 0; i < N; ++i) cin >> a[i];
//
//    bool exist = false;
//    for (int bit = 0; bit < (1 << N); ++bit)
//    {
//        int sum = 0;
//        for (int i = 0; i < N; ++i){
//            if (bit & (1 << i)){
//                sum += a[i];
//            }
//        }
//
//        if (sum == W) exist = true;
//    }
//
//    if (exist) cout << "Yes" << endl;
//    else cout << "No" << endl;
//}
