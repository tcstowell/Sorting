template<class datatype>
void Sort<datatype>::fill(int* a, int arrange, int size)
{
	cout << "unsorted array\n";
	switch(arrange){
		case 1:
		for(int i = 0; i < size; i++){
			a[i] = i;
			cout << a[i] << ", ";
		}
		break;
		case 3:
		for(int i = (size - 1); i >= 0; i--){
			a[i] = i;
			cout << a[i] << ", ";
		}
		break;
		default:
		for(int i = 0; i < size; i++){
			srand(time(NULL)+i);
			a[i] = rand()%size;
			cout << a[i] << ", ";
		}
	}
	cout << "\n";
}
template<class datatype>
void Sort<datatype>::bubble(int* a, int size, int& iteration, int& swap)
{
  iteration = 0;
  swap = 0;
  int i, j, temp, k = 0;
  for (i = (size - 1); i > k; i--)
  {
		iteration++;
		cout << "\x1b[34;1miterations in progress ";
		cout << iteration << "\x1b[30;0m\n ";
    for (j = 1; j <= i; j++)
    {
      if (a[j-1] > a[j])
      {
		swap++;
		cout << "\x1b[33;1mswaps in progress ";
		cout << swap << "\x1b[30;0m\n ";
        temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
		k++;
      }
    }
	if(k == 0 && i > 1){
		i = 1;
	}
	  k = 0;
  }
}
template<class datatype>
void Sort<datatype>::insertion(int* a, int size, int& iteration, int& swap)
{
	int i, j ,temp;
 iteration = 0;
 swap = 0;
 for (i = 1; i < size; i++) {
 	j = i;
 	iteration++;
 	cout << "\x1b[34;1miterations in progress ";
 	cout << iteration << "\x1b[30;0m\n ";
	while (j > 0 && a[j - 1] > a[j]) {
		temp = a[j];
		a[j] = a[j - 1];
		a[j - 1] = temp;
		j--;
		swap++;
		cout << "\x1b[33;1mswaps in progress ";
		cout << swap << "\x1b[30;0m\n ";
	}
 }
}
template<class datatype>
void Sort<datatype>::merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;// create temp arrays
    int L[n1], R[n2];// Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];// Merge the temp arrays back into arr[l..r]
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
template<class datatype>// l is for left index and r is right index of the sub-array of arr to be Sorted
void Sort<datatype>::mergeS(int* a, int l, int r, int& iteration, int& swap)
{
    if (l < r)
    {
		iteration++;
	 	cout << "\x1b[34;1miterations in progress ";
	 	cout << iteration << "\x1b[30;0m\n ";
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeS(a, l, m, iteration, swap);
        mergeS(a, m+1, r, iteration, swap);
        Sort<datatype>::merge(a, l, m, r);
    }
}
template<class datatype>
void Sort<datatype>::shiftRight(int* a, int left, int right)
{
    int root = left;
    while ((root*2)+1 <= right)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        //Check if root is less than left child
        if (a[swapIdx] < a[leftChild])
        {
            swapIdx = leftChild;
        }
        //If right child exists check if it is less than current root
        if ((rightChild <= right) && (a[swapIdx] < a[rightChild]))
        {
            swapIdx = rightChild;
        }
        //Make the biggest element of root, left and right child the root
        if (swapIdx != root)
        {
            int tmp = a[root];
            a[root] = a[swapIdx];
            a[swapIdx] = tmp;
            //Keep shifting right and ensure that swapIdx heap property aka left and right child of it is smaller itself
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
template<class datatype>
void Sort<datatype>::heapify(int* a, int left, int right)
{
    //Start with middle element. Middle element is chosen such a way that the last element of array is either left child or right child
    int midIdx = (right - left -1)/2;
    while (midIdx >= 0)
    {
        Sort<datatype>::shiftRight(a, midIdx, right);
        --midIdx;
    }
    return;
}
template<class datatype>
void Sort<datatype>::heap(int* a, int size, int& iteration, int& swap)
{
   iteration = 0;
   swap = 0;
    //This will put max element in the index 0
    Sort<datatype>::heapify(a, 0, size-1);
    int right = size - 1;
    while (right > 0)
    {
        //Swap max element with high index in the array
        int tmp = a[right];
        a[right] = a[0];
        a[0] = tmp;
        --right;
				iteration++;
				cout << "\x1b[34;1miterations in progress ";
		    cout << iteration << "\n";
        //Ensure heap property on remaining elements
        Sort<datatype>::shiftRight(a, 0, right);
			swap++;
			cout << "\x1b[33;1mswaps in progress ";
	    cout << swap << "\x1b[30;0m\n";
    }
    return;
}
template<class datatype>
void Sort<datatype>::shell(int* a, int size, int& iteration, int& swap)
{
	int j;

  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
		iteration++;
		cout << "\x1b[34;1miterations in progress ";
		cout << iteration << "\x1b[30;0m\n";
      int temp = a[i];
      for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
      {
        a[j] = a[j - gap];
		swap++;
		cout << "\x1b[33;1mswaps in progress ";
		cout << swap << "\x1b[30;0m\n";
      }
      a[j] = temp;
    }
  }
}
/*template<class datatype>
Sort<datatype>::quickSort(int a[], int left, int right, int& iteration, int& swap)
{
	  int i = left, j = right;
	  iteration = 0;
      swap = 0;
      int temp;

      int pivot = a[(left + right) / 2];

      //partition

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
      //recursion
      if (left < j)

            quickSort(a, left, j, iteration, swap);
				iteration++;
				cout << "iterations in progress" <<endl;
				cout << iteration << " ";

      if (i < right)

            quickSort(a, i, right, iteration, swap);
				swap++;
				cout << "swaps in progress" << endl;
				 cout << swap << " ";
}*/
/*template<class datatype>
Sort<datatype>::selectionSort(int a[], int size, int& iteration, int& swap)
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
}*/
