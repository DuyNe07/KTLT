#include <stdio.h>
#include <stdlib.h>
void ghifile(int n);
void docfile(int n);
void ghifile(int n)
{
	FILE *f;
	f = fopen("songuyen.txt", "wt");
	for (int i = 1; i <= n; i++)
	{
		fprintf(f, "%6d", rand());
		if (i % 10 == 0)
			fprintf(f, "\n");
	}
	fclose(f);
}
void docfile(int n)
{
	FILE *f;

	n = 0;
	int a[1000];
	f = fopen("songuyen.txt", "rt");
	while (!feof(f))
	{
		n++;
		fscanf(f, "%d", &a[n]);
	}
	fclose(f);
}
void main()
{
	int n;
	ghifile(1000);
	docfile(n);
}