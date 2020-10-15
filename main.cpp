#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 20000000;

int main(){
    int N, A, B;
    cin >> N;
    cin >> A;
    cin >> B;
    int counter = 0;

    for (int i = 0; i < N; i++){
        int tmp = 0;
        if (tmp > 10){
            tmp += i % 10 * 10;
        }
        tmp += i;

        if (tmp >= A && tmp <= B) counter += tmp;
    }

    cout << counter << endl;
}

