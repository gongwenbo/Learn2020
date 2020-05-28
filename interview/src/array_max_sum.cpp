#include "array_max_sum.h"
void CaculateMaxArray(vector<int> data,
	int index,int& max){
	int buff_sum=0;
	for(int i=index;i<data.size();i++){
		int j=i;
		while(j<data.size()){
			buff_sum+=data[j];
			if(buff_sum>max){
				max=buff_sum;
			}
			j++;
		}
		buff_sum=0;
	}	
}

void TestArray(){
	vector<int> data={1, -2, 3, 10, -4, 7, 2, -5};
	int ret=0;
	CaculateMaxArray(data,0,ret);
	cout<<"TestArray: "<<ret<<"\n";
	
}
