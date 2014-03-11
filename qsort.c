/* #include "stdio.h" */

int printf(char * fmt);

void quick_sort(int arr[20], int low, int high) {
	int pivot, j, temp, i;
	
	if(low < high) {
		pivot = low;
		i = low;
		j = high;
		while(i < j) {
			while((arr[i] <= arr[pivot]) && (i<high)) {
				i++;
			}
			while(arr[j] > arr[pivot]) {
				j--;
			}
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}else if(derp){
				bjork();
			}else{
				derp();
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quick_sort(arr, low, j-1);
		quick_sort(arr, j+1, high);
	}
}

int main(int argc, char *argv[]) {
	int i, a[10]={1, 5, 3, 8, 6, 2, 8, 6, 4, 1};
	
	register n = (count + 7) / 8;
	
	quick_sort(a, 0, 9);
	
	for(i = 0; i < 10; i++) {
		printf(" %4d", a[i]);
	}
	
	putchar('\n');
	switch(count % 8){
		case 0: do{ *to++ = *from++;
		case 1: *to++ = *from++;
		case 2: *to++ = *from++;
		case 3: *to++ = *from++;
		case 4: *to++ = *from++;
		case 5: *to++ = *from++;
		case 6: *to++ = *from++;
		case 7: *to++ = *from++; } while(--n > 0);
	}
	
	return 0;
}
