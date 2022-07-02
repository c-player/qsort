#define _CRT_SECURE_NO_WARNINGS 1

//����qsort������ʹ��

/*
void qsort (void* base, size_t num, size_t size,
			int (*compar)(const void*,const void*));
qsort�����ܹ������������飬�������͡������͵ȡ�

��һ������base:�������������Ԫ�ص�ַ
�ڶ�������num�������Ԫ�ظ���
����������size������ÿ��Ԫ�ش�С���ֽڣ�
���ĸ�����compar������ָ�룬�ȽϺ����ĵ�ַ������ȽϺ���ʹ�����ֽڱ�д�����������Ǵ��Ƚ�����Ԫ�ص�ַ
��1��Ԫ��>��2��Ԫ�أ����� >0 ����
��1��Ԫ��=��2��Ԫ�أ����� 0 
��1��Ԫ��<��2��Ԫ�أ����� <0 ����
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

//��������ıȽϺ���
int comp_int(const void* p1, const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}

//����������ıȽϺ���
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

//�ṹ�尴��������ıȽϺ���
int comp_stu_by_age(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
}

//�ṹ�尴��������ıȽϺ���
int comp_stu_by_name(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

//��qsort������������Ĳ���
void test1()
{
	int i;
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("ԭ���飺");
	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr1[i]);
	}
	qsort(arr1, sz1, sizeof(arr1[0]), comp_int);
	printf("\n�����");
	for (i = 0; i < sz1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

//��qsort���и���������Ĳ���
void test2()
{
	int i;
	float arr2[] = { 3.4,1.5,6.3,1.2,9.9,7.5 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("\nԭ���飺");
	for (i = 0; i < sz2; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	qsort(arr2, sz2, sizeof(arr2[0]), comp_flo);
	printf("\n�����");
	for (i = 0; i < sz2; i++)
	{
		printf("%.1f ", arr2[i]);
	}
	printf("\n");
}

//��qsort���нṹ�尴��������Ĳ���
void test3()
{
	int i;
	struct Stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",10} };
	int sz3 = sizeof(s) / sizeof(s[0]);
	printf("\nԭ�ṹ�壺\n");
	for (i = 0; i < sz3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
	qsort(s, sz3, sizeof(s[0]), comp_stu_by_age);
	printf("\n�����������\n");
	for (i = 0; i < sz3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
	printf("\n");
}

//��qsort���нṹ�尴��������Ĳ���
void test4()
{
	int i;
	struct Stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",10} };
	int sz3 = sizeof(s) / sizeof(s[0]);
	qsort(s, sz3, sizeof(s[0]), comp_stu_by_name);
	printf("�����������\n");
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