#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void shuffle(int *arr,int s,int e){

	srand(time(NULL));

	for(int i=e;i>0;i--){
		int j=rand()%i;
		swap(arr[i],arr[j]);
	}
}

int partition(int *arr,int s,int e){
	int i=s-1;
	int j=s;
	int pivot=arr[e];

	for(;j<e;j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}

void quicksort(int *arr,int s,int e){

	if(s<e){
		int p=partition(arr,s,e);
		quicksort(arr,s,p-1);
		quicksort(arr,p+1,e);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;
	int t;

	cin >> t;

	while(t--)
	{
		cin >> n;

		int arr[n];

		for(i=0;i<n;i++){
			cin >> arr[i];
		}

		shuffle(arr,0,n-1);

		quicksort(arr,0,n-1);

		for(i=0;i<n;i++){
			cout << arr[i] << " " ;
		}
		cout << endl;
	}


	return 0;
}
