#include<stdio.h>
#define __cplusplus
//about the macro define: __LINE__,__FILE__,__DATE__,__TIME__,__cplusplus__,__FUNCTION__,__func__,__STDC__
void main(void){
	printf("the number of line%d\n",__LINE__);
	printf("the number of line%d\n",__LINE__);
	printf("the number of line%d\n",__LINE__);

	printf("The file is %s\n",__FILE__);

	printf("Date is %s\n",__DATE__);
	printf("Time is %s\n",__TIME__);


	#ifdef __cplusplus
	printf("the compiler is C++\n");
	#endif

#ifdef __STDC__
	printf("the compiler is C\n");
#endif


	printf("function is %s\n",__FUNCTION__);
	printf("function is %s\n",__func__);
}
