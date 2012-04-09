// 编程珠玑，column1
#include <iostream>
#include <bitset>
#include <fstream>

#define BITNUM	10000000

using namespace std;

int main()
{
	ifstream infile;
	infile.open("source.txt");
	if(!infile){
		cerr << "error: unable to open input file: "
			<< infile << endl;
		return -1;
	}
	
	int lineInt;
	bitset<BITNUM> bits;
	
	while(infile >> lineInt){
		bits[lineInt] = 1;
	}
	
	for(int pos = 0; pos < BITNUM; pos ++)
	{
		if(bits[pos]==1)
			cout << pos << endl;
	}

	infile.close();
	return 0;
}
