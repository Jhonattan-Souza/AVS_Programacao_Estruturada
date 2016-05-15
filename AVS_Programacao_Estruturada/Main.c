#include <stdio.h>

#define PATH "C:\Dados.txt"

int fatorial(int num);
int fibonacci(int num);
int ehPrimo(int num);
int alocarMatrizes();
void escreverDados();
void lerDados();
void lerMatriz(int *mat, int m, int n);
void somarMatrizes(int *a, int *b, int *c, int m, int n);
void escreverMatriz(int *mat, int m, int n);

struct EPonto
{
	float x;
	float y;
};

typedef struct EPonto A;
typedef struct EPonto B;

int main()
{
}

int fatorial(int num)
{
	return num * fatorial(num - 1);
}

int fibonacci(int num)
{
	if (num == 1 || num == 2) return 1;
	else return fibonacci(num - 1) + fibonacci(num - 2);
}

int ehPrimo(int num)
{
	if (num < 2) return 0;

	for (int i = (int)num / 2; i >= 2; i--)
		if ((num%i) == 0) return 0;

	return 1;
}

void escreverDados()
{
	FILE *arq;

	int i;
	A p;

	printf("\nOperacao de Escrita\n");

	arq = fopen(PATH, "ab");

	for (i = 0; i < 3; i++)
	{
		printf("\n");
		printf("Digite o a:");
		scanf("%s", p.x);
		printf("Digite a idade:");
		scanf("%d", &p.y);
		fwrite(&p, sizeof(A), 1, arq);
	}
	fclose(arq);
}

void lerDados()
{
	FILE *arq;
	A p;

	printf("\nOperacao de Leitura\n");

	arq = fopen(PATH, "rb");

	while (fread(&p, sizeof(A), 1, arq) != 0)
		printf("Nome: %s  -  Idade: %d\n", p.x, p.y);

	fclose(arq);
}

void lerMatriz(int *mat, int m, int n)
{
	for (int i = 0; i < m; i = i + 1)
		for (int j = 0; j < n; j = j + 1) scanf("%d", &mat[i * n + j]);
}

void somarMatrizes(int *a, int *b, int *c, int m, int n)
{
	int i, j, k;
	for (i = 0; i < m; i = i + 1)
	{
		for (j = 0; j < n; j = j + 1)
			c[k + j] = a[k + j] + b[k + j];
	}
}

void escreverMatriz(int *mat, int m, int n)
{
	int i, j, k;
	for (i = 0; i < m; i = i + 1)
	{
		k = i * n;
		for (j = 0; j < n; j = j + 1) printf("%3d", mat[k + j]);
		printf("\n");
	}
}

int alocarMatrizes()
{
	int m, n, *m1, *m2, *m3;
	scanf("%d", &m);
	scanf("%d", &n);
	m1 = (int *)malloc(sizeof(int) * m * n);
	m2 = (int *)malloc(sizeof(int) * m * n);
	m3 = (int *)malloc(sizeof(int) * m * n);
	lerMatriz(m1, m, n);
	escreverMatriz(m1, m, n);
	lerMatriz(m2, m, n);
	escreverMatriz(m2, m, n);
	printf("\n");
	somarMatrizes(m1, m2, m3, m, n);
	escreverMatriz(m3, m, n);
	return 0;
}