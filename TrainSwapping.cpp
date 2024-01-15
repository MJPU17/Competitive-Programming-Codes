#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int T,N,aux;
vi arr;

ll merge(vi& arr, int l, int m, int r) {
    vi left(arr.begin() + l, arr.begin() + m + 1);
    vi right(arr.begin() + m + 1, arr.begin() + r + 1);

    ll inversions = 0;
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

ll mergeSort(vi& arr, int l, int r) {
    ll inversions = 0;
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
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d",&N);
        for (int j = 0; j < N; j++){
            scanf("%d",&aux);
            arr.emplace_back(aux);
        }
        printf("Optimal train swapping takes %d swaps.\n",mergeSort(arr,0,N-1));   
        arr.clear();
    }
    
    return 0;
}
