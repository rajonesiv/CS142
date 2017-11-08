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
	char sign;
	for(int k=id; k<=n; k=k+np)
	{
		if(k%2==0) //determine whether the numerator is positive or negative
		{
			sign=1;
		}
		else
		{
			sign=-1;
		}
		sum=sum+sign/((2*k)+1); //Leibniz series formula for pi
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
	
	double bigsum; //the sum of all the sums that each processor produces.
	
	MPI_Reduce(&sum,&bigsum,1,MPI_DOUBLE, //obtain answers from the world.
	  MPI_SUM,0,MPI_COMM_WORLD);
	
	if(id==0)
	{
		double pi=4*bigsum; //solve for pi
		cout << "pi="<<pi<<endl;
	}
	
	MPI_Finalize();
	return 0;
}