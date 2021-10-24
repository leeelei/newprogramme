#include<stdio.h>
#include<assert.h>
double GetMin(double *dbData,int iSize){
	double dbMin;
	int i;
	assert(iSize>0);
	dbMin=dbData[0];
	for(i=1;i<iSize;i++){
		if(dbMin>dbData[i])
			dbMin=dbData[i];
	}
	return dbMin;
}
double GetMax(double *dbData,int iSize){
	double dbMax;
	int i;
	assert(iSize>0);
	dbMax=dbData[0];
	for(i=1;i<iSize;i++){
		if(dbMax<dbData[i])
			dbMax=dbData[i];
	}
	return dbMax;
}

double GetAverage(double *dbData,int iSize){
	double dbSum=0;
	int i;
	assert(iSize>0);
	for(i=0;i<iSize;i++){
		dbSum+=dbData[i];
	}
	return dbSum/iSize;
}

double UnKnown(double *dbData,int iSize){
	return 0;
}

typedef double (*PF)(double* dbData,int iSize);

PF GetOperation(char c){
	switch(c){
		case 'd':
			return GetMax;
		case 'x':
			return GetMin;
		case 'p':
			return GetAverage;
		default:
			return UnKnown;

	}
}


int main(void){
	double dbData[]={3.1415926,1.4142,-0.5,999,-313,365};
	int iSize=sizeof(dbData)/sizeof(dbData[0]);
	char c;
	double ret;
	printf("please input the Operation: \n");
	c=getchar();
	ret=GetOperation(c)(dbData,iSize);
	if(ret==0)
		printf("Operation %c is unknown!\n",c);
	else
		printf("result is %1f\n",ret);	
}
