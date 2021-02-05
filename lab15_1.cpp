#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *input,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(input+i);
        if(i%M == M-1) cout << endl;
        else cout << " ";
    }
}

void randData(double *input,int N,int M){
    for(int i = 0; i < N*M; i++){
        input[i] = (double)(rand()%101)/100;
    }
}

void findRowSum(const double *input,double *sum,int N,int M){
  double ans =0;
  int count = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      ans += *input;
      input++;
    }
    sum[i] = ans;
    ans =0;
  }
  while(count != 0){
    input--;
    count--;
  }
  return;
}

void findColSum(const double *a,double *b,int N,int M){
for (int i=0 ; i<M ; i++) b[i] = 0; 
  for(int i=0;i<M*N;i++){
    b[i%M] += *(a+i);
  }
  return;
}
