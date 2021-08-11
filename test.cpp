#include <iostream>
#include <ctime>
using namespace std;
int main(){
	time_t ss = time(0);//second start
	clock_t mss = clock();//millisecond start
	cin.ignore();
	clock_t mse = clock();//millisecond end
	time_t se = time(0);//second end
	double mst = (mse - mss)/(double)CLOCKS_PER_SEC;//millisecond time
	double st = se - ss;//second time
	double Seconds = st + mst;
	cout << Seconds << " Seconds to sort\n";
return 0;
}
