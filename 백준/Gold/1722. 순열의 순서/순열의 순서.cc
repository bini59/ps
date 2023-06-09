//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
//#include <cmath>
//#include <algorithm>
//#include <string>

using namespace std;

/*
scanf, printf 쓰기.

cout 을 쓸때는 꼭 endl 말고 \n 쓰기.

아니면 밑에꺼 꼭 쓰기, 시간 개걸림.

*/



/*
범위 때문에 문제 안풀릴때는, 

index 0은 무시하고 1부터 시작해보기.. 은근 저거때문에 화날때가 많은거같음...
*/



/*
꼭 데이터 범위 확인하기!!
long long 범위 잘 확인해서 풀기.
*/
typedef long long ll;


//자주 쓸 데이터들
//vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)

template <typename T>
ostream &operator<<(ostream &out, vector<T> arr){
    FOR(arr.size()) out << arr[i] << " ";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, pair<T *, int>arr){
    FOR(arr.second) out << arr.first[i] << " ";
    return out;
}

ll fact(ll n){
    if (n <= 1) return 1;
    return n*fact(n - 1);
}

#define SWAP(n, m) {int t = n;n = m;m = t;}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n, p;
    ll k;
    int arr[20] = {0};

    cin >> n;
    cin >> p;
    ll tmp = fact(n - 1);

    if(p == 1) {
        cin >> k;
        k -= 1;

        int *res = new int[n];
        for (int i = 0; i < n; i++) res[i] = i + 1;
        int i = 0;
        while((n-1-i > 0) && (tmp)){
            // cout << k / tmp << " " << n-1-i<< " " <<  tmp<<" a \n";
            if(k / tmp){
                for (int j = i + (k / tmp); j > i; j--) SWAP(res[j], res[j-1]);
            }
            k -= (k/tmp)*tmp;
            tmp /= (n - 1 - i);
            i++;
        }
        cout << make_pair(res, n);
    }
    else {
        ll res = 1; 
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n-1; i++){
            res += abs(arr[i] - i-1)*tmp;
            for (int j = i+1; j < n; j++){
                if(arr[j] < arr[i]) arr[j]++;
            }
            tmp /= n - i - 1;
            // cout << make_pair(arr, n) << "\n";
        }
        cout << res;
    }

    
}