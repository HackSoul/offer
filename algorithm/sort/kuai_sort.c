#include <stdio.h>

#define length 10

/*
 *快排序，使用的归并法。
 快速排序稳定性
 快速排序是不稳定的算法，它不满足稳定算法的定义。
 算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！

 快速排序时间复杂度
 快速排序的时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*lgN)。
 这句话很好理解：假设被排序的数列中有N个数。遍历一次的时间复杂度是O(N)，需要遍历多少次呢？至少lg(N+1)次，最多N次。
 (01) 为什么最少是lg(N+1)次？快速排序是采用的分治法进行遍历的，我们将它看作一棵二叉树，它需要遍历的次数就是二叉树的深度，而根据完全二叉树的定义，它的深度至少是lg(N+1)。因此，快速排序的遍历次数最少是lg(N+1)次。
 (02) 为什么最多是N次？这个应该非常简单，还是将快速排序看作一棵二叉树，它的深度最大是N。因此，快读排序的遍历次数最多是N次。
 * */

void kuai_sort(int arr[],int l, int r){
		if (l < r){
				int i = l;
				int j = r;
				int x = arr[l];
				while(i < j){
						while(i < j && arr[j] < x){ //arr[j] < x用于从大到小排序， > 是从小到大，下个while倒过来
								j--;
						}		
						if (i < j){
								arr[i] = arr[j];
								i++;
						}
						while(i < j && arr[i] > x){
								i++;
						}
						if (i < j){
								arr[j] = arr[i];
								j--;
						}
				}
				arr[i] = x;
				kuai_sort(arr, l,i-1);
				kuai_sort(arr, i+1, r);
		}
}

int main(){
		int arr[length] = {0,1,2,3,4,5,6,7,8,9};
		kuai_sort(arr, 0, length-1);
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
