
// ********** Begin Bubblesort **********
void bubblesort(int a[], int size, int& iteration, int& swap)
{
	iteration = 0;
  swap = 0;
  int i, j, temp;
  for (i = (size - 1); i > 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
		swap++;
		cout << "swaps in progress" << endl;
		cout << swap << " ";
      if (a[j-1] > a[j])
      {
        temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
		iteration++;
		cout << "iterations in progress" <<endl;
		cout << iteration << " ";
      }
    }
  }
}
// ********** End Bubblesort **********
// ********** Begin Heapsort **********
void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
/*heapify*/
void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}
/*heapsort*/
void heapsort(int* arr, int size, int& iteration, int& swap)
{
   iteration = 0;
   swap = 0;

    /*This will put max element in the index 0*/
    heapify(arr, 0, size-1);
    int high = size - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        int tmp = arr[high];
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
		iteration++;
		cout << "iterations in progress" <<endl;
	    cout << iteration << " ";
        /*Ensure heap property on remaining elements*/
        shiftRight(arr, 0, high);
		swap++;
		cout << "swaps in progress" << endl;
	    cout << swap << " ";
    }
    return;
}
// ********** End Heapsort **********
// ********** Begin Quicksort **********
void quicksort(int a[], int left, int right, int& iteration, int& swap)
{
	  int i = left, j = right;
	  iteration = 0;
      swap = 0;
      int temp;

      int pivot = a[(left + right) / 2];

      /* partition */

      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {

                  temp = a[i];

                  a[i] = a[j];

                  a[j] = temp;

                  i++;

                  j--;
            }
      };
      /* recursion */
      if (left < j)

            quicksort(a, left, j, iteration, swap);
				iteration++;
				cout << "iterations in progress" <<endl;
				cout << iteration << " ";

      if (i < right)

            quicksort(a, i, right, iteration, swap);
				swap++;
				cout << "swaps in progress" << endl;
				 cout << swap << " ";
}
// ********** End Quicksort **********
// ********** Begin Selectionsort **********
void selectionsort(int a[], int size, int& iteration, int& swap)
{
	int i,j,imin,temp;
   iteration = 0;
   swap = 0;
   //cnt++;
   for(j=0;j<size;j++)
   {
       //cnt+=2;
       imin=j;
	   iteration++;
	   cout << "iterations in progress" <<endl;
       cout << iteration << " ";
       for(i=j+1;i<size;i++)
       {
           //cnt+=2;
		   swap++;
		   cout << "swaps in progress" << endl;
            cout << swap << " ";
          if(a[i]<a[imin])
          {
             //cnt++;
             imin=i;
          }
        }
        if(imin!=j)
        {
            //cnt+=3;
            temp=a[j];
            a[j]=a[imin];
            a[imin]=temp;
         }
    }
}
// ********** End Selectionsort **********
// ********** Begin Insertionsort **********
void insertionsort(int a[], int size, int& iteration, int& swap)
{
	int i, j ,temp;
 iteration = 0;
 swap = 0;
 for (i = 1; i < size; i++) {
 j = i;
 iteration++;
 cout << "iterations in progress" <<endl;
 cout << iteration << " ";
	while (j > 0 && a[j - 1] > a[j]) {
	temp = a[j];
	a[j] = a[j - 1];
	a[j - 1] = temp;
	j--;
	swap++;
	cout << "swaps in progress" << endl;
	cout << swap << " ";
	}
 }
}
// ********** End Insertionsort **********
// ********** Begin Shellsort **********
void shellsort(int a[], int size, int& iteration, int& swap)
{
	int j;

  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
		iteration++;
		cout << "iterations in progress" <<endl;
		cout << iteration << " ";
      int temp = a[i];
      for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
      {
        a[j] = a[j - gap];
		swap++;
		cout << "swaps in progress" << endl;
		cout << swap << " ";
      }
      a[j] = temp;
    }
  }
}
// ********** End Shellsort **********
// ********** Begin Mergesort **********
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there
    //  are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there
    //   are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
//  sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
// ********** End Mergesort **********
// ********** Begin Binary Search **********
int binarysearch(int a[], int searchkey, int size)
{
    int low=0;
    int high=size-1;
    int middle;
    while (low <= high)
    {
        middle = low + (high - low)/2; // find middle of the array
        if (searchkey > a[middle]) // if searched number lower than middle value, look after the middle value
        low = middle + 1;
        else if (searchkey < a[middle])
        high = middle - 1;
        else
        return middle;
    }
    return -1;
}
// ********** End Binary Search **********
