#include "convert.h"

double inv_precision_map[] = {
	1,
	0.1,
	0.01,
	0.001,
	0.0001,
	0.00001,
	0.000001,
	0.0000001,
	0.00000001,
	0.000000001,
	0.0000000001,
};


long precision_map[] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000,
	100000000000,
	1000000000000,
	10000000000000
};


int p_todigit( char ch)
{
	return (ch-'0');
}

int f_precision(char a[], int len )
{
	int precision = 0;
	int i;
	for(i=0;i<len && a[i] != '\0' && a[i] != ' ' ;i++){
		if (a[i] == '.'){
			printf(". found\n");
			break;
		} else {
			precision++;
		}
	}

	precision += (precision > 0 ) ? -1:0;
	return precision;
}

double p_atof(char a[], int len ) 
{
	int i = 0 ;
	int precision = f_precision(a, len );

	double num = 0.0;
	for(i=0;i<len && a[i] != '\0' && a[i] != ' '; i++ ){
		if (precision >= 0 ) {
			num += p_todigit(a[i]) * precision_map[precision];
		} else if (a[i] == '.') {
			// pass.. avoiding todigit
			precision += 1;
		} else {
			num += p_todigit(a[i]) * inv_precision_map[-precision];
		}
		precision -= 1;
	}
	return num;
}

long p_atoi( char a[], int len) 
{
	int precision = f_precision(a, len );
	int i = 0;	
	long num;
        for(i=0;i<len && a[i] != '\0' && a[i] != ' ' && a[i] != '.'; i++ ){
                if (precision >= 0 ) {
			num += p_todigit(a[i]) * precision_map[precision];
		}
		precision -=1;
	}

	return num;
}

