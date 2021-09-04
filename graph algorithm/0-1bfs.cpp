include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility>
#include <algorithm>
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#define endl "\n"
using namespace std;
 
struct node{
	int x;
	int y;
};
 
int r, c;
string ar[1111];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
void bfs(){
	deque<node> q;
	q.push_front((node){0,0});
	int dp[r][c];
	for( int i = 0; i < r; i++ ){
		for( int j = 0; j < c; j++ ){
			dp[i][j] = 1111111;
		}
	}
	dp[0][0] = 0;
	while( !q.empty() ){
		node cur = q.front();
		q.pop_front();
		int x = cur.x, y = cur.y;
		for( int i = 0; i < 4; i++ ){
			int X = x + dx[i];
			int Y = y + dy[i];
			if( X < 0 || Y < 0 || X >= r || Y >= c )continue;
			int add = 1;
			if( ar[x][y] == ar[X][Y] )add = 0;
			if( dp[X][Y] > dp[x][y] + add ){
				dp[X][Y] = dp[x][y] + add;
				if( add == 0 ){
					q.push_front((node){X,Y});
				}
				else{
					q.push_back((node){X,Y});
				}
			}
		}
	}
	cout << dp[r-1][c-1] << endl;
}
 
int main(){
	int t;
	cin >> t;
	while( t-- ){
		cin >> r >> c;
		for( int i = 0; i < r; i++ ){
			cin >> ar[i];
		}
		bfs();
	}
}
