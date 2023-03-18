//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
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


// print Vector<int>
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// print Array<int>
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int map[150][150] = {0};

int check(int n, int m, int &ch){
    int temp = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 2){
                ch++;
                map[i][j] = 0;
            }
            else if(map[i][j] == 1)
                temp = 1;
        }
    }

    return temp;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int result = 0;
    int cheese = 0;

    while (check(n, m, cheese)){
        int visited[101][101] = {0};
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(!visited[nx][ny]){
                        visited[nx][ny] = 1;
                        if(map[nx][ny] == 1){
                            map[nx][ny] = 2;
                        }
                        else if(map[nx][ny] == 0){
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        result++;
        cheese = 0;
    }

    cout << result << "\n" << cheese;
}