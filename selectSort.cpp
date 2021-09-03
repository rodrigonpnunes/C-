#include <iostream>
#include <vector>

using namespace std;

vector<int> selectSort(vector<int> a){
	int posicao;
	for (int i=0; i<(a.size())-1; i++){
		posicao=i;
		for (int k=i+1; k<a.size(); k++){
		 	if (a[k]>a[posicao]){
		 		posicao=k;
		 	}
		}
		//swap
		int aux = a[i];
		a[i]=a[posicao];
		a[posicao]=aux;
	}
	return a;
}


vector<int> bubbleSort(vector<int> a){
	int posicao;
	for (int i=0; i<(a.size())-1; i++){
		posicao=i;
		for (int k=0; k<a.size()-i-1; k++){
		 	if (a[k]>a[k+1]){
		 		//swap
				int aux = a[k];
				a[k]=a[k+1];
				a[k+1]=aux;
		 	}
		}
		
	}
	return a;
}


int main() {

   vector<int> b;
   vector<int>::iterator it;

   b.push_back(10);
   b.push_back(5);
   b.push_back(20);
   b.push_back(50);
   //b=selectSort(b);
   b=bubbleSort(b);
   for (it=b.begin();it<b.end(); ++it){
   		cout << "VALORES:" << *it <<endl;
   }
}
