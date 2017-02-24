/* bubnov_function.c	230217
 * ������ ���� ��������� � ����� ���������� � ��� ������� ����������������� ��� ����������������.
 * ������� ����������� �� ����� C
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "bubnov_function.h"

 // decomposition into bit components
 // ������� ������������ ������� ����� �� ��������� ���������
 // 12345 -> |1|2|3|4|5|
 // -12345 -> |-1|2|3|4|5|
 // 0 -> |0|
 // �� ����� ����� �����, �� ������ ������ ���������� �������� �������� 
 // ��������� ���������
void decomposIntoBitComponents(int num, int *m) {
	int i = 1;					// ����� ��� ���������
	int n = 1;					// ������� ��������
	if (num >= 0) {
		while (n <= num) {
			n *= 10;
			i++;
		} // while
	} // if
	else {
		while (n <= abs(num))
		{
			n *= 10;
			i++;
		} // while
	} // else
	if(num >= 0) {
		i = i - 1;
		m[0] = i;						// ������ ������� ������� ��� ������
		while(i >= 1) {
			n /= 10;
			m[i] = num / n;
			num -= (n * m[i]);
			i--;
		} // while
	} // if
	else {	
		i = i - 1;
		m[0] = i;						// ������ ������� ������� ��� ������
		if (i > 0) {					// ������ �������� ���������� � ��������� ������ ������������� �����
			n /= 10;
			m[i] = num / n;
			num = -num;					// ����� ����� ��������� �������������� �����
			num -= (n * -m[i]);
			i--;
		}
		while (i >= 1) {
			n /= 10;
			m[i] = num / n;
			num -= (n * m[i]);
			i--;
		} // while
	} // else
} // decomposIntoBitComponents

// ������� ������� �� ����� ������� �������� �������
// ������ ������� ������� ����� ��� �������
// �� ����� ������ ����� ����� ����� ������� �������� ������ �������
void printArray(int *m)
{
	printf("[");
	for(int i = 1; i <= m[0]; i++)
	{
		printf("%d, ", m[i]);
	}
	printf("\b\b]\n");
} // printArray

// ������� ���������� ������ �������
// ������ ������� ������� ����� ��� ������� � �������� �� ����� �����
void reversArray(int m[])
{
	if (m[0] <= 0) return;					// ���� ������ ������ ��� ����� ����, �� ����� �� �������
	int temp = 0,
		size_m = m[0],						// ������ ������ �������
		size_m_2 = m[0] / 2;				// �������� �������
	// ���� size_m = 5 �� ����� 2; ���� size_m = 6 �� ����� 3
	for(int i = 1; i <= size_m_2; i++)
	{
		temp = m[i];
		m[i] = m[size_m];
		m[size_m] = temp;
		size_m--;
	} // for
} // reversArray


  // ������� ��������� ������ �� �������������� (���������) �
  // � ������ �������������� ���������� ���������� true
  // ���� ������ �� ����������� � ������� �� ������ �������� ���������� false
_Bool palindromeArray(int m[])
{
	//_Bool palindrome = false;
	if (m[0] <= 0 || m[0] == 1) return false;		// ���� ������ ������ ��� ����� ���� ��� ����� 1, 
													// �� ����� �� ������� �� ��������� false
	int size_m = m[0],						// ������ ������ �������
		size_m_2 = m[0] / 2;				// �������� �������
											// ���� size_m = 5 �� ����� 2; ���� size_m = 6 �� ����� 3
	for (int i = 1; i <= size_m_2; i++)
	{
		if(m[i] != m[size_m]) return false;
		size_m--;
	} // for
	return true;
} // polindromArray

//-----------------------------------------------------------------------------------
// ������� ��� ������ � ��������� ��� ������� ������ �06

// ������� �������� �������
// ������ ������� ���������� ������� ����� �������� ���������� ��� ���������

// ���� �� ������� ����������� �� ������� ������������� ������ ������
// ��� ������������� ������������ ��������

//void createArray(int *m, unsigned int size_m)
//{
//	static int array_m[size_m + 1];
//
//}

// ������� ���������� ������� ���������� �������
// ������ ������� ������� ����� �������� ���������� ��� ���������
void generatorArray(int m[], int size_m, int range)
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	m[0] = size_m - 1;								// ������ ������� ������� � ������ ������� ����� ���� ������� ��� ������
	for (int i = 1; i < size_m; i++) {
		m[i] = rand() % (range + 1);
	}
} // generatorArray


// ���������� ������������� �������� � �������
// numMaxElemen - ����� ������������� �������� � �������
int maxElementArray(int m[], int *numMaxElemen)
{
	int max = m[1];						// ���������� ���������� max �������� ������� �������� �������
	*numMaxElemen = 1;
	for(int i = 2; i < m[0]; i++)
	{
		if (m[i] > max) {
			max = m[i];
			*numMaxElemen = i;
		} // if
	} // for
	return max;
} // maxElementArray


// ���������� ������������ �������� � �������
int minElementArray(int m[], int *numMinElemen)
{
	int min = m[1];						// ���������� ���������� min �������� ������� �������� �������
	*numMinElemen = 1;
	for (int i = 2; i < m[0]; i++)
	{
		if (m[i] < min) {
			min = m[i];
			*numMinElemen = i;
		} // if
	} // for
	return min;
} // minElementArray

// ���������� ������� �� ������ ���������
void sortArray(int m[])
{
	int max, num_max, temp, currentSize_m = m[0];
	// 1. ������� ��������
	max = maxElementArray(m, &num_max);
	// 2. ��������� ��� �� ����� ����������� ��������
	for(int i = m[0]; i >= 1; )
	{
		temp = m[i];			// ���������� �� ��������� ���������� �������� ���������� ��������
		m[i] = max;				// ���������� ������������ �������� ������� � ��������� �������
		m[num_max] = temp;		// �� ����� �������� � ����. ��������� ��������� �������� ���������� ��������
		m[0] = i--;				// ���������� �������� � ������������ ������������ ������� �������
		max = maxElementArray(m, &num_max);
	}
	// 3. ��������� � ���� �1 � ����������� ��������� ������
	m[0] = currentSize_m;		// ������ ��������� �������� �������
}


// �������� ����� �������� � �������
_Bool searchElementArray(int elem, int m[], int *numElem)
{
	for(int i = 1; i < m[0]; i++)
	{
		if(m[i] == elem)
		{
			*numElem = i;
			return true;
		} // if
	} // for
	numElem = NULL;					// � ������ ���������� �������� ��������� ��������� � ������� �����
	return false;
}
