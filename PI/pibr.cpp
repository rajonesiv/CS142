//Andrew Jones
// This version uses broadcast and reduce (instead of send and receive) 
//to compute pi. This program also uses striping.
#include<iostream>
#include<cmath>
#include "mpi.h"
using namespace std;
/*
thomas:$ module load openmpi-x86_64
thomas:$ mpicxx multihello.cpp
thomas:$ mpirun -np 5 a.out
*/

double dosum(int id, int np, int n) //striping method. each processor will 
//compute every nth process
{	
	double sum=0;
	for(int k=id+1; k<=n; k=k+np)
	{
		sum=sum+1.0/pow(k,2); //squaring the reciprocals and adding them up
	}
	
	cout << "id=" << id
	<< " sum=" << sum << endl;
	
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	int np,id; //I didn't add 'b' since I wasn't blocking
	MPI_Status status; 
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Comm_size(MPI_COMM_WORLD,&np);
	
	if(id==0) //our process is 0
	{
		cout << "Please enter \"large\" n: ";
		cin >> n;	
	}
	MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD); //broadcast to the world: don't need to 
	//get processor id.
	
	double sum=dosum(id,np,n);
	
	double bigsum; //the sum of all the sums that each processor produces
	
	MPI_Reduce(&sum,&bigsum,1,MPI_DOUBLE, //obtain answers from the world.
	  MPI_SUM,0,MPI_COMM_WORLD);
	
	if(id==0)
	{
		double pi=sqrt(6*bigsum); //solve for pi
		cout << "pi="<<pi<<endl;
	}
	
	MPI_Finalize();
	return 0;
}

/* sample run:
thomas% module load openmpi-x86_64
thomas% mpicxx pibr.cpp
thomas% mpirun -np 10 a.out
Please enter "large" n: 1000
id=8 sum=0.0191258
id=9 sum=0.0163498
id=0 sum=1.01423
pi=3.14064
id=1 sum=0.262573
id=2 sum=0.122353
id=3 sum=0.0726535
id=4 sum=0.049248
id=5 sum=0.0362622
id=6 sum=0.0282407
id=7 sum=0.022895
thomas% mpirun -np 10 a.out
Please enter "large" n: 1000000
id=5 sum=0.036362
id=7 sum=0.0229946
id=8 sum=0.0192253
id=2 sum=0.122454
id=3 sum=0.0727535
id=4 sum=0.0493479
id=6 sum=0.0283404
id=9 sum=0.0164492
id=0 sum=1.01433
id=1 sum=0.262674
pi=3.14159
thomas%
*/