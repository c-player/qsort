#define _CRT_SECURE_NO_WARNINGS 1

//关于qsort函数的使用

/*
void qsort (void* base, size_t num, size_t size,
			int (*compar)(const void*,const void*));
qsort函数能够排序任意数组，无论整型、浮点型等。

第一个参数base:待排序数组的首元素地址
第二个参数num：数组的元素个数
第三个参数size：数组每个元素大小（字节）
第四个参数compar：函数指针，比较函数的地址，这个比较函数使用者字节编写，函数参数是待比较两个元素地址
第1个元素>第2个元素，返回 >0 的数
第1个元素=第2个元素，返回 0 
第1个元素<第2个元素，返回 <0 的数
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Stu
{
	char name[20];
	int age;
};

//整型排序的比较函数
int comp_int(const void* p1, const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}

//浮点型排序的比较函数
int comp_flo(const void* p1, const void* p2)
{
	if (*(float*)p1 > *(float*)p2&&fabs(*(float*)p1 - *(float*)p2) > 1e-6)
	{
		return 1;
	}
	else if (*(float*)p1 < *(float*)p2&&fabs(*(float*)p1 - *(float*)p2) > 1e-6)
	{
		return -1;
	}
	else return 0;
}

//结构体按年龄排序的比较函数
int comp_stu_by_age(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
}

//结构体按姓名排序的比较函数
int comp_stu_by_name(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

//用qsort进行整型排序的测试
void test1()
{
	int i;
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("原数组：");
	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr1[i]);
	}
	qsort(arr1, sz1, sizeof(arr1[0]), comp_int);
	printf("\n排序后：");
	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

//用qsort进行浮点型排序的测试
void test2()
{
	int i;
	float arr2[] = { 3.4,1.5,6.3,1.2,9.9,7.5 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("\n原数组：");
	for (i = 0; i < sz2; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	qsort(arr2, sz2, sizeof(arr2[0]), comp_flo);
	printf("\n排序后：");
	for (i = 0; i < sz2; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	printf("\n");
}

//用qsort进行结构体按年龄排序的测试
void test3()
{
	int i;
	struct Stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",10} };
	int sz3 = sizeof(s) / sizeof(s[0]);
	printf("\n原结构体：\n");
	for (i = 0; i < sz3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
	qsort(s, sz3, sizeof(s[0]), comp_stu_by_age);
	printf("\n按年龄排序后：\n");
	for (i = 0; i < sz3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
	printf("\n");
}

//用qsort进行结构体按姓名排序的测试
void test4()
{
	int i;
	struct Stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",10} };
	int sz3 = sizeof(s) / sizeof(s[0]);
	qsort(s, sz3, sizeof(s[0]), comp_stu_by_name);
	printf("按姓名排序后：\n");
	for (i = 0; i < sz3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
	printf("\n");
}


int main()
{
	int i = 0;
	void (*arr[4])() = { test1,test2,test3,test4 };
	for (i = 0; i < 4; i++)
	{
		arr[i]();
	}
    return 0;
}