#include<bits/stdc++.h>
using namespace std;


int dp[1001][1001];
int MCM(int a[], int i, int j) {
    /*
    For the base condition think of the first invalid input. That will be it.
    Now talking about the for loop.
    In this we check for each k from i to j-1.
    Selecting i and j at the starting is also very crucial. It can be selected by taking
    an example and trial and error.
    In this case if you initially take i to be 0, we get an invalid matrix as,
    general matrix Ai=a[i-1]*a[i]. So i needs to be 1. Similarly j=n-1.
    In the loop we partition at each k and find the smallest answer.
    Now how does the last a[i - 1] * a[k] * a[j] thing come.
    This comes because say we have, ((AB)(CD)).
    After solving the inner braces we get (EF). It's answer should also be added to the
    final ans.
    How to find it?
    ->Observe A starts at index i and ends at k, C starts at k+1 and ends at j.
    So the dimensions are preserved for these entities...
    */
    if (i >= j)
        return 0LL;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int tempAns;
        tempAns = MCM(a, i, k) + MCM(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}
int main() {
    /*
    MATRIX CHAIN MULTIPLICATION(aka MCM)
    Given:
    An integer n denoting the size of the array
    a[i] is the ith array element.
    Let array be:
    40 20 30 10 30
    It represents n-1 2D matrices viz.
    A1= 40*20
    A2=20*30
    A3=30*10
    A4=10*30
    In short Ai= a[i-1]*a[i] size matrix.
    We need to given the minimum cost of multiplying these matrices.
    Cost Eg:
    40*20 and 20*30 matrix are to be multiplied
    -> Cost= 40*20*30
    The cost differs by how you multiply the matrices
    Eg:
    Let the matrices be ABCD.
    ((AB)(CD)) can have different cost than ((ABC)D).
    */
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 1, j = n - 1;
    memset(dp, -1, sizeof(dp));
    cout << MCM(a, i, j);

    /*
    SAMPLE INPUT:
    5
    1 2 3 4 3

    SAMPLE OUTPUT:
    30

    */


    return 0;
}
