//-------------------------------------
// Task Name : Bridge
// Author : Geun-Woo Bae
//-------------------------------------

#include<stdio.h>
#include<algorithm>
#include<queue>
#define abs2(a) ((a)<0?-(a):(a))
#define MX 100010
using namespace std;

typedef long long lld;

struct routes {
	lld s, e;
	bool operator< (const routes& c) const {
		return s+e < c.s+c.e;
	}
}arr[MX];

struct hset {
	priority_queue<lld> mxheap, miheap;
	lld mxsum, misum;
	void clear(){
		mxsum=misum=0;
		while(!mxheap.empty())mxheap.pop();
		while(!miheap.empty())miheap.pop();
	}
	void ins(lld a, lld b){
		if(mxheap.empty()){
			mxheap.push(a), mxsum+=a;
			miheap.push(-b), misum+=b;
			return;
		}
		lld mx=mxheap.top();
		lld mi=-miheap.top(); // mx < mi
		if(b <= mx){
			mxheap.pop(), mxsum-=mx;
			mxheap.push(a), mxsum+=a;
			mxheap.push(b), mxsum+=b;
			miheap.push(-mx), misum+=mx;
		}
		else if(a >= mi){
			miheap.pop(), misum-=mi;
			miheap.push(-a), misum+=a;
			miheap.push(-b), misum+=b;
			mxheap.push(mi), mxsum+=mi;
		}
		else{
			mxheap.push(a), mxsum+=a;
			miheap.push(-b), misum+=b;
		}
	}
	lld getsum(){
		return misum-mxsum;
	}
}hs;

int b, n, cnt;
lld prev_sum, heap_sum[MX], rev_sum[MX], ans;

int main(){
	int i;
	scanf("%d%d", &b, &n);
	for(i=0; i<n; i++){
		char Tsi, Tei;
		lld Psi, Pei;
		scanf("\n%c %lld %c %lld", &Tsi, &Psi, &Tei, &Pei);
		if(Tsi == Tei)prev_sum += abs2(Psi-Pei);
		else{
			prev_sum++;
			arr[cnt].s=Psi, arr[cnt].e=Pei;
			if(arr[cnt].s > arr[cnt].e)swap(arr[cnt].s, arr[cnt].e);
			cnt++;
		}
	}
	sort(arr, arr+cnt);

	for(i=0; i<cnt; i++){
		hs.ins(arr[i].s, arr[i].e);
		heap_sum[i]=hs.getsum();
	}
	hs.clear();
	for(i=cnt-1; i>=0; i--){
		hs.ins(arr[i].s, arr[i].e);
		rev_sum[i]=hs.getsum();
	}

	ans=heap_sum[cnt-1];
	if(b==2){
		for(i=0; i<cnt-1; i++){
			if(ans > heap_sum[i]+rev_sum[i+1])ans = heap_sum[i]+rev_sum[i+1];
		}
	}
	printf("%lld\n", prev_sum+ans);
	return 0;
}
