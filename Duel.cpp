#include<cstdio>
#include<vector>
using namespace std;

long long merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    long long inversions = 0;
    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (m - l + 1 - i);
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, int l, int r) {
    long long inversions = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);
        inversions += merge(arr, l, m, r);
    }
    return inversions;
}

int main(int argc, char const *argv[])
{
    int len;
    scanf("%d",&len);
    int aux;
    vector <int> arr;
    for(int i=0;i<len;i++){
        scanf("%d",&aux);
        arr.emplace_back(aux);
    }
    if(mergeSort(arr,0,len-1)%2==1)printf("Smokin Joe!\n");
    else printf("Oh No!\n");
    
    return 0;
}
