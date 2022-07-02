#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int comp_int(void* p1, void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int comp_flo(void* p1, void* p2)
{
	if (*(float*)p1 > *(float*)p2&&fabs(*(float*)p1- *(float*)p2) > 1e-6)
	{
		return 1;
	}
	else if (*(float*)p1 < *(float*)p2&&fabs(*(float*)p1- *(float*)p2) > 1e-6)
	{
		return -1;
	}
	else return 0;
}


/******************************   主体  *****************************************/
//交换元素的每个字节
void Swap(char* buf1, char* buf2, int width)  
{
	char tmp;
	int i;
	for (i = 0; i < width; i++)
	{
		tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int (*comp)(void* p1, void* p2))
{
	int i, j;
	int flag;
	for (i = 0; i < sz - 1; i++)
	{
		flag = 1;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (comp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
/******************************   主体  *****************************************/


//测试
int main()
{
	int i;
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0 };
	float arr2[] = { 2.3,1.2,1.1,5.4 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	bubble_sort(arr1, sz1, sizeof(arr1[0]), comp_int);
	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	bubble_sort(arr2, sz2, sizeof(arr2[0]), comp_flo);
	for (i = 0; i < sz2; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	printf("\n");
	return 0;
    return 0;
}