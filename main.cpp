#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 20000000;

int main(){
    int N;
    cin >> N;
    vector<long long> h(N);

    for (int i = 0; i < N; ++i) cin >> h[i];

    int counter = 0;
    while (true){
        for (int i = 0; i < N; ++i) {
            if (h[i] % 2 == 0) counter++;
            else break;
        }
        break;
    }
    cout << counter << endl;
}