#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 20000000;

int main(){
    int A, B, C, X;

    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    int counter = 0;

    for (int i = 0; i < A; i++){
        for (int j = 0; j < B; j++){
            for(int k = 0; k < C; k++){
                int sum = 500 * i + 100 * j + 50 * k;
                if (sum == X) counter++;
            }
        }
    }

    cout << counter << endl;
}

