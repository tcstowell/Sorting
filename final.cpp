//create the use link list//
//grade <69 must take final exam//
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "sort.h"
using namespace std;
int menu();
const int  bubble = 0, heap = 1, insertion = 2, merge3 = 3, shell = 4;
int main(){
  int choice;
  int itr, swap, order;
  int* a;
  int left = 0, size = 5, right = 5;
  Sort<int> sort;
  choice = menu();
  while(choice == bubble || choice == heap || choice == insertion || choice == merge3 || choice == shell){
      cout << "input size of array\n";
  	  cin >> size;
  	  a = new int [size];
  	  right = size;
    if(choice == bubble){
      cout << "Bubble Sort\nThe time complexity:\n\x1b[32;1m1.Best: Ω(n)\n\x1b[33;1m2.Average: Θ(n^2)\n\x1b[31;1m3.Worst: O(n^2)\n";
      cout << "\x1b[30;0mEnter case:\n";
  	  cin >> order;
  	  sort.fill(a, order, size);
      time_t ss = time(0);//second start
      clock_t mss = clock();//millisecond start
      sort.bubble(a, size, itr, swap);
      clock_t mse = clock();//millisecond end
    	time_t se = time(0);//second end
    	double mst = (mse - mss)/(double) CLOCKS_PER_SEC;//millisecond time
    	time_t st = se - ss;//second time
    	double Seconds = st + mst;
      for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
      cout << endl << itr << " iterations\n";
	  cout << Seconds << " Seconds to sort\n";
  }else if(choice == heap){
      cout << "Heap Sort\nThe time complexity:\n\x1b[32;1m1.Best: Ω(n log(n))\n\x1b[33;1m2.Average: Θ(n log(n))\n\x1b[31;1m3.Worst: O(n log(n))\n";
      cout << "\x1b[30;0mEnter case:\n";
  	  cin >> order;
  	  sort.fill(a, order, size);
      time_t ss = time(0);//second start
      clock_t mss = clock();//millisecond start
      sort.heap(a, size, itr, swap);
      clock_t mse = clock();//millisecond end
    	time_t se = time(0);//second end
    	double mst = (mse - mss)/(double) CLOCKS_PER_SEC;//millisecond time
    	time_t st = se - ss;//second time
    	double Seconds = st + mst;
      for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
      cout << endl << itr << " iterations\n";
	  cout << Seconds << " Seconds to sort\n";
    }else if(choice == insertion){
      cout << "Insertion Sort\nThe time complexity:\n\x1b[32;1m1.Best: Ω(n)\n\x1b[33;1m2.Average: Θ(n^2)\n\x1b[31;1m3.Worst: O(n^2)\n";
      cout << "\x1b[30;0mEnter case:\n";
  	  cin >> order;
  	  sort.fill(a, order, size);
      time_t ss = time(0);//second start
      clock_t mss = clock();//millisecond start
	    sort.insertion(a, size, itr, swap);
      clock_t mse = clock();//millisecond end
    	time_t se = time(0);//second end
    	double mst = (mse - mss)/(double) CLOCKS_PER_SEC;//millisecond time
    	time_t st = se - ss;//second time
    	double Seconds = st + mst;
      for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
      cout << endl << itr << " iterations\n";
      cout << Seconds << " Seconds to sort\n";
    }else if(choice == merge3){
      cout << "Merge Sort\nThe time complexity:\n\x1b[32;1m1.Best: Ω(n log(n))\n\x1b[33;1m2.Average: Θ(n log(n))\n\x1b[31;1m3.Worst: O(n log(n))\n";
      cout << "\x1b[30;0mEnter case:\n";
  	  cin >> order;
  	  sort.fill(a, order, size);
  	  itr = 0;
  	  swap = 0;
      time_t ss = time(0);//second start
      clock_t mss = clock();//millisecond start
  	  sort.mergeS(a, left, (right-1), itr, swap);
      clock_t mse = clock();//millisecond end
    	time_t se = time(0);//second end
    	double mst = (mse - mss)/(double) CLOCKS_PER_SEC;//millisecond time
    	time_t st = se - ss;//second time
    	double Seconds = st + mst;
      for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
      cout << endl << itr << " iterations\n";
      cout << Seconds << " Seconds to sort\n";
    }else if(choice == shell){
      cout << "Shell Sort\nThe time complexity:\n\x1b[32;1m1.Best: Ω(n log(n))\n\x1b[33;1m2.Average: Θ(n^2)\n\x1b[31;1m3.Worst: O(n log(n))\n";
      cout << "\x1b[30;0mEnter case:\n";
  	  cin >> order;
  	  sort.fill(a, order, size);
      time_t ss = time(0);//second start
      clock_t mss = clock();//millisecond start
  	  sort.shell(a, size, itr, swap);
      clock_t mse = clock();//millisecond end
    	time_t se = time(0);//second end
    	double mst = (mse - mss)/(double) CLOCKS_PER_SEC;//millisecond time
    	time_t st = se - ss;//second time
    	double Seconds = st + mst;
      for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
      cout << endl << itr << " iterations\n";
      cout << Seconds << " Seconds to sort\n";
    }
    choice = menu();
    delete [] a;
  }
  cout << "\x1b[30;0m";
  return 0;
}
int menu(){
  int choice;
  cout << "\x1b[30;4mSorting Algorithms\x1b[30;0m\n";
  cout << "\x1b[31;1m0. Bubble Sort\n";
  cout << "\x1b[32;1m1. Heap Sort\n";
  cout << "\x1b[33;1m2. Insertion Sort\n";
  cout << "\x1b[34;1m3. Merge Sort\n";
  cout << "\x1b[35;1m4. Shell Sort\n";
  cout << "\x1b[31;1m5. Quit\x1b[30;0m\n";
  cin >> choice;
  return choice;
}
