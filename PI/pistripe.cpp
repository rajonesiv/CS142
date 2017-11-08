//Andrew Jones
//This program is designed to compute the value of pi.
#include<iostream>
#include<cmath>
#include "mpi.h"
using namespace std;

double dosum(int id, int np, int n) //striping method. each processor will compute
//every n^th process
{
	double sum=0;
	for(int k=id+1; k<=n; k=k+np)
	{
		sum=sum+1.0/(pow(k,2)); //squaring the reciprocals and adding them up
	}
	
	cout << "id=" << id
	<< " sum=" << sum << endl;
	
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	int np,id;
	MPI_Status status; 
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Comm_size(MPI_COMM_WORLD,&np);
	
	if(id==0)
	{
		cout << "Please enter \"large\" n: ";
		cin >> n;
		for(int target=1; target<np; target=target+1)
		{
		  MPI_Send(&n,1,MPI_INT,target,
		    0,MPI_COMM_WORLD);
		}
	}
	else
	{
		MPI_Recv(&n,1,MPI_INT,0,0,
		  MPI_COMM_WORLD,&status); //get message from id 0
	}
	
	double sum=dosum(id,np,n);
	
	double pi=0;
	double sum;
	for(int k=left; k<=right; k=k+1)
	{
		pi=sqrt(6*sum); //need to add up the reciprocals of the squares
		//and solve for pi.
	}
	
	cout << "id=" << id << " sum=" << sum << endl;

	
	if(id>0)  // send our sum to proc. 0
	{
		MPI_Send(&sum,1,MPI_DOUBLE,0,
		    0,MPI_COMM_WORLD);
	}
	else // proc. 0
	{
		double bigsum=sum;
		for(int source=1; source<np; source=source+1)
		{
			MPI_Recv(&sum,1,MPI_DOUBLE,
			source,0,MPI_COMM_WORLD,&status);
			bigsum=bigsum+sum;
		}
		cout << "pi="<<pi<<endl;
	}
	
	MPI_Finalize();
	return 0;
}