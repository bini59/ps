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
//typedef long long ll;


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

int *arr;

int find_root(int n) {
    if(arr[n] == n){
        return n;
    }
    return arr[n] = find_root(arr[n]);
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if(x != y) {
        arr[x] = y;
    }
}

bool find_friend(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = i;
    }

    int x, a, b;

    for (int i = 0; i < m; i++) {
        cin >> x >> a >> b;
        if(x == 0) {
            union_root(a, b);
        }
        else{
            cout << (find_friend(a, b) ? "YES\n" : "NO\n");
        }
    }
}