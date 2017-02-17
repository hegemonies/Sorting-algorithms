#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

int digit(int n, int j) 
{ 
	return (n /((int)(pow(10,j))) % 10);
} 

int main() 
{ 
	int i, j, k = 10, n = 10; 
	int a[n], b[n], c[k]; 
	srand(time(0)); 
	//
	for (i = 0; i < n; i++) 
		a[i] = rand() % 1000; 
	for (i = 0; i < 3; i++){ 

		for (j = 0; j < k; j++)//обнуление доп массива с 
			c[j] = 0; 

		for(j = 0; j < k; j++) //подсчет кол-ва опред-го разряда
			c[digit(a[j],i)]++; 

		for(j = 1; j < k; j++) 
			c[j] += c[j - 1]; //подсчет места каждого элемента в массиве по возрастанию

		for(j = n-1; j >= 0; j--) 
			b[--c[digit(a[j],i)]] = a[j];//заполнение массива b по i разряду

		for (j = 0; j < n; j++)//заполнение массива а 
			a[j] = b[j]; 
	} 
	//
	return 0; 
}
