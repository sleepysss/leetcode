void ReHeapDown(int nums[], int root, int last)
{
	int leftchild, rightchild, biggest_index = root;
	if ((2 * root + 1) <= last) //leftchild exist
	{
		leftchild = 2 * root + 1;
		biggest_index = nums[leftchild] > nums[biggest_index] ? leftchild : biggest_index;
	}
	if ((2 * root + 2) <= last) //rightchild exist
	{
		rightchild = 2 * root + 2;
		biggest_index = nums[rightchild] > nums[biggest_index] ? rightchild : biggest_index;
	}
	if (root != biggest_index)  //exchange
	{
		int temp = nums[biggest_index];
		nums[biggest_index] = nums[root];
		nums[root] = temp;
		ReHeapDown(nums, biggest_index, last);
	}
}


void BuildHeapFromArray(int nums[], int last)
{
	for (int i = (last - 1) / 2; i >= 0; --i)
		ReHeapDown(nums, i, last);
}


void pop(int nums[], int *last, int k, int *count)
{
	int val = nums[0];
	nums[0] = nums[*last];
	(*last)--;
	ReHeapDown(nums, 0, *last);
	(*count)++;
	if (*count == k) //kth biggest
		*count = val;
}


int findKthLargest(int* nums, int numsSize, int k) {

	int count = 0; //count now is ith biggest
	BuildHeapFromArray(nums, numsSize - 1);
	int last = numsSize - 1;
	for (int i = 0; i < k; ++i)
		pop(nums, &last, k, &count);
	return count;

}
