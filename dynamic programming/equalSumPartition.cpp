bool isSubsetSum (int arr[], int n, int sum)  
{  
    // Base Case  
    if (sum == 0)  
        return true;  
    if (n == 0 && sum != 0)  
        return false;  
    if (arr[n-1] > sum)  
       return isSubsetSum (arr, n-is1, sum);  
    return isSubsetSum (arr, n-1, sum) ||  
        isSubsetSum (arr, n-1, sum-arr[n-1]);  
}  
bool Partiion (int arr[], int n)  
{  
    // Calculate sum of the elements in array  
    int sum = 0;  
    for (int i = 0; i < n; i++)  
    sum += arr[i];  
    if (sum%2 != 0)  
    return false;   
    return isSubsetSum (arr, n, sum/2);  
}  
