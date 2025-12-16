#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct processor {
	char name[20];
	int с_core;
	long int c_flow;
	double p_memory;
	char socket[10];
	char company[10];
	float frequency;
	short int graphics;
};
typedef struct processor processor;

void fill_array(processor* proc, int size) {
	processor* pr;
	pr = (processor*)malloc(size * sizeof(processor));
	for (int i = 0; i < size; i++) {
		printf("процессор № %d\n", i + 1);
		printf("введите название компании (пробел заменяется знаком '_'):");
		scanf("%10s", &pr[i].company);		
		printf("введите название процессора (пробел заменяется знаком '_'):");
		scanf("%10s", &pr[i].name);
		printf("введите кол-во ядер (целое число):");
		scanf("%d", &pr[i].с_core);
		int k = pr[i].с_core;
		while (k <= 0) {
			printf("данные введены не корректно, введите кол-во ядер снова:");
			scanf("%d", &pr[i].с_core);
			k = pr[i].с_core;
		}
		printf("введите кол-во потоков (целое число):");
		scanf("%d", &pr[i].c_flow);
		int k3 = pr[i].c_flow;
		while (k3 <= 0) {
			printf("данные введены не корректно, введите кол-во потоков снова:");
			scanf("%d", &pr[i].c_flow);
			k3 = pr[i].c_flow;
		}
		printf("введите пропускную способность памяти:");
		scanf("%lf", &pr[i].p_memory);
		double k1 = pr[i].p_memory;
		while (k1 <= 0) {
			printf("данные введены не корректно, введите пропускную способность памяти снова:");
			scanf("%lf", &pr[i].p_memory);
			k1 = pr[i].p_memory;
		}
		printf("введите сокет:");
		scanf("%10s", &pr[i].socket);		
		printf("введите частоту ядра:");
		scanf("%f", &pr[i].frequency);
		float k2 = pr[i].frequency;
		while (k2 <= 0) {
			printf("данные введены не корректно, введите частоту ядра снова:");
			scanf("%f", &pr[i].frequency);
			k2 = pr[i].frequency;
		}
		printf("наличие интегрированной графики(да - 1,нет - 0):");
		scanf("%d", &pr[i].graphics);
	    short int s = pr[i].graphics;
		while (s < 0 || s > 1) {
			printf("данные введены не корректно, укажите наличие интегрированной графики снова:");
			scanf("%d", &pr[i].graphics);
			s = pr[i].graphics;
		}
	}
	for (int i = 0; i < size; i++) {
		proc[i] = pr[i];
	}
	return 0;
}

void print_proc(processor play) {
	printf("| %13s | %8s | %11d | %14d | %13.1lf Гб/с | %7s | %3.1f Гц | %15d |\n",
		play.company,
		play.name,
		play.с_core,
		play.c_flow,
		play.p_memory,
		play.socket,
		play.frequency,
		play.graphics);
	return 0;
}

void print_array(processor* play, int size) {
	puts(" ");
	printf("| Производитель | Название | Кол-во ядер | Кол-во потоков | Пропускная способ. |  Сокет  |  Частота | Интегр. графика |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < size; i++)
		print_proc(play[i]);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	return 0;
}

processor* search_proc_c_core(processor* pr, int size, int* ind) {
	for (int i = 0; i < size; i++) {
		if (pr[i].с_core == ind)
			print_proc(pr[i]);
	}
	return NULL;
}

processor* search_proc_socket(processor* pr, int size, char* ind) {
	for (int i = 0; i < size; i++) {
		if (strcmp(pr[i].socket, ind) == 0)
			print_proc(pr[i]);
	}
	return NULL;
}

int compare_freqency(const void* a, const void* b) {
	const processor* A = (const processor*)a;
	const processor* B = (const processor*)b;
	int areA = A->frequency;
	int areB = B->frequency;
	if (areA < areB) return -1;
	if (areA > areB) return 1;
	return 0;
}

int compare_graphics(const void* a, const void* b) {
	const processor* A = (const processor*)a;
	const processor* B = (const processor*)b;
	int areA = A->graphics;
	int areB = B->graphics;
	if (areA < areB) return -1;
	if (areA > areB) return 1;
	return 0;
}

void sort_freqency(processor* year, int size) {
	qsort(year, size, sizeof(processor), compare_freqency);
	return 0;
}

void sort_graphics(processor* year, int size) {
	qsort(year, size, sizeof(processor), compare_graphics);
	return 0;
}

void sort_global(processor* pr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (pr[j].frequency - pr[j + 1].frequency > 0 || (pr[j].frequency - pr[j + 1].frequency == 0 && pr[j].graphics > pr[j + 1].graphics)) {
				processor box = pr[j];
				pr[j] = pr[j + 1];
				pr[j + 1] = box;
			}
		}
	}
	return 0;
}

void revers(processor* pr, int ind, int size) {
	if (ind < 0 || ind >= size) {
		printf("такого поля нет\n");
		return;
	}
	printf("введите новую запись\n");
	printf("компания (пробел заменяется знаком '_'): ");
	scanf("%10s", &pr[ind].company);
	printf("название процессора (пробел заменяется знаком '_'):");
	scanf("%10s", &pr[ind].name);
	printf("кол-во ядер (целое число):");
	scanf("%2d", &pr[ind].с_core);
	int k = pr[ind].с_core;
	while (k <= 0) {
		printf("данные введены не корректно, введите кол-во ядер снова:");
		scanf("%d", &pr[ind].с_core);
		k = pr[ind].с_core;
	}
	printf("кол-во потоков (целое число):");
	scanf("%2d", &pr[ind].c_flow);
	int k3 = pr[ind].c_flow;
	while (k3 <= 0) {
		printf("данные введены не корректно, введите кол-во потоков снова:");
		scanf("%d", &pr[ind].c_flow);
		k3 = pr[ind].c_flow;
	}
	printf("пропускная способность:");
	scanf("%lf", &pr[ind].p_memory);
	double k1 = pr[ind].p_memory;
	while (k1 <= 0) {
		printf("данные введены не корректно, введите пропускную способность памяти снова:");
		scanf("%lf", &pr[ind].p_memory);
		k1 = pr[ind].p_memory;
	}
	printf("сокет:");
	scanf("%10s", &pr[ind].socket);
	printf("частота:");
	scanf("%f", &pr[ind].frequency);
	float k2 = pr[ind].frequency;
	while (k2 <= 0) {
		printf("данные введены не корректно, введите частоту ядра снова:");
		scanf("%f", &pr[ind].frequency);
		k2 = pr[ind].frequency;
	}
	printf("наличие интегрированной графики (да - 1,нет - 0):");
	scanf("%1d", &pr[ind].graphics);
	short int s = pr[ind].graphics;
	while (s < 0 || s > 1) {
		printf("данные введены не корректно, укажите наличие интегрированной графики снова:");
		scanf("%d", &pr[ind].graphics);
		s = pr[ind].graphics;
	}
	return 0;
}

int output(char* name, processor* pr, int n) {
	FILE* file = fopen(name, "w");
	if (file == NULL) {
		printf("Ошибка открытия файла!\n");
		return 1;
	}
	fprintf(file, "| Производитель | Название | Кол-во ядер | Кол-во потоков | Пропускная способ. |  Сокет  |  Частота | Интегр. графика |\n");
	for (int i = 0; i < n; i++) {
		fprintf(file, "| %13s | %8s | %11d | %14d | %13.1lf Гб/с | %7s | %3.1f Гц | %15d |\n", pr[i].company, pr[i].name, pr[i].с_core, pr[i].c_flow, pr[i].p_memory, pr[i].socket, pr[i].frequency, pr[i].graphics);
	}
	fclose(file);
	printf("Данные успешно записаны в файл!\n");
	return 0;
}

int input(char* name, processor* pr, int n) {
	FILE* file = fopen(name, "r");
	if (file == NULL) {
		printf("Ошибка открытия файла!\n");
		return 0;
	}
	int c = -1;
	char sa[256];
	while (fgets(sa, sizeof(sa), file)) {
		printf(sa);
		c++;
	}
	fclose(file);
	printf("количество прочитанных записей: %d\n", c);
	return 0;
}

processor* addData(processor* pr, int size, int n) {
	processor* newCountOfElements;
	int number_of_elements = size + n;

	newCountOfElements = (processor*)malloc(number_of_elements * sizeof(processor));

	for (int i = 0; i < size; i++)
		newCountOfElements[i] = pr[i];

	for (int i = size; i < number_of_elements; i++) {
		printf("процессор № %d\n", i + 1);
		printf("введите название компании (пробел заменяется знаком '_'):");
		scanf("%10s", &pr[i].company);
		printf("введите название процессора (пробел заменяется знаком '_'):");
		scanf("%10s", &pr[i].name);
		printf("введите кол-во ядер (целое число):");
		scanf("%d", &pr[i].с_core);
		int k = pr[i].с_core;
		while (k <= 0) {
			printf("данные введены не корректно, введите кол-во ядер снова:");
			scanf("%d", &pr[i].с_core);
			k = pr[i].с_core;
		}
		printf("введите кол-во потоков (целое число):");
		scanf("%d", &pr[i].c_flow);
		int k3 = pr[i].c_flow;
		while (k3 <= 0) {
			printf("данные введены не корректно, введите кол-во потоков снова:");
			scanf("%d", &pr[i].c_flow);
			k3 = pr[i].c_flow;
		}
		printf("введите пропускную способность памяти:");
		scanf("%lf", &pr[i].p_memory);
		double k1 = pr[i].p_memory;
		while (k1 <= 0) {
			printf("данные введены не корректно, введите пропускную способность памяти снова:");
			scanf("%lf", &pr[i].p_memory);
			k1 = pr[i].p_memory;
		}
		printf("введите сокет:");
		scanf("%10s", &pr[i].socket);
		printf("введите частоту ядра:");
		scanf("%f", &pr[i].frequency);
		float k2 = pr[i].frequency;
		while (k2 <= 0) {
			printf("данные введены не корректно, введите частоту ядра снова:");
			scanf("%f", &pr[i].frequency);
			k2 = pr[i].frequency;
		}
		printf("наличие интегрированной графики(да - 1,нет - 0):");
		scanf("%d", &pr[i].graphics);
		short int s = pr[i].graphics;
		while (s < 0 || s > 1) {
			printf("данные введены не корректно, укажите наличие интегрированной графики снова:");
			scanf("%d", &pr[i].graphics);
			s = pr[i].graphics;
		}
	}
	for (int i = size; i < number_of_elements; i++) {
		newCountOfElements[i] = pr[i];
	}
	return newCountOfElements;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	puts("введите длину массива:");
	int size;
	scanf("%d", &size);
	int ks = size;
	while (ks <= 0) {
		printf("данные введены не корректно, введите длину массива снова:");
		scanf("%d", &size);
		ks = size;
	}
	processor* processors = NULL;
	int k;
	char name[20];
	int target;
	char target1[20];
	processor* pr;
	pr = (processor*)malloc(size * sizeof(processor));
	do {
		puts("МЕНЮ:\n");
		puts("1 - загрузка данных");
		puts("2 - поиск записи по полю");
		puts("3 - сортировка массива по полю");
		puts("4 - изменение записи");
		puts("5 - сохранение массива в файл");
		puts("6 - чтение файла");
		puts("7 - добавление записей в массив");
		puts("0 - завершение программы\n");
		puts("выберите функцию:");

		scanf("%d", &k);
		switch (k)
		{
		case 1: {
			fill_array(pr, size);
			print_array(pr, size);
			break;
		}
		case 2: {
			puts("ПАРАМЕТРЫ ПОИСКА:\n");
			puts("1 - кол-во ядер");
			puts("2 - сокет");
			puts("3 - общий поиск\n");
			puts("выберите параметр поиска");
			int p;
			scanf("%d", &p);
			switch (p) {
			case 1: {
				puts("введите кол-во ядер для поиска:");
				scanf("%d", &target);
				processor* found1 = search_proc_c_core(pr, size, target);
				if (found1) {
					printf("найдена запись с кол-вом ядер %d\n", target);
					print_proc(*found1);
				}
				else {
					printf("запись не найдена\n");
				}
				break;
			}
			case 2: {
				puts("введите название сокета для поиска:");
				scanf("%s", &target1);
				processor* found2 = search_proc_socket(pr, size, target1);
				if (found2) {
					printf("найдена запись с сокетом %s\n", target1);
					print_proc(*found2);
				}
				else {
					printf("запись не найдена\n");
				}
				break;
			}
			case 3:
				puts("введите кол-во ядер для поиска:");
				scanf("%d", &target);
				puts("введите название сокета для поиска:");
				scanf("%s", &target1);
				processor* found1 = search_proc_c_core(pr, size, target);
				processor* found2 = search_proc_socket(pr, size, target1);
				if (found1 && found2) {
					printf("найдена запись с кол-вом ядер %d и сокетом %s\n", target, target1);
					print_proc(*found2);
				}
				else {
					printf("запись не найдена\n");
				}
				break;
			}			
			break;
		}
		case 3: {
			puts("выберите тип сортировки:\n");
			puts("1 - сортировка по частоте");
			puts("2 - сортировка по графике");
			puts("3 - общая сортировка");
			int sr;
			scanf("%d", &sr);
			switch (sr) {
			case 1: {
				sort_freqency(pr, size);
				printf("массив отсортирован по частоте\n");
				print_array(pr, size);
				break;
			}
			case 2: {
				sort_graphics(pr, size);
				printf("массив отсортирован по графике\n");
				print_array(pr, size);
				break;
			}
			case 3: {
				sort_global(pr, size);
				printf("массив отсортирован по частоте и графике\n");
				print_array(pr, size);
				break;
			}
			}
			break;
		}
		case 4: {
			int ind;
			printf("введите индекс поля записи (отсчет от 0):");
			scanf("%d", &ind);
			revers(pr, ind, size);
			print_array(pr, size);
			break;
		}
		case 5: {
			printf("введите имя файла:");
			scanf("%s", name);
			if (output(name, pr, size))
				printf("данные сохранены\n");
			break;
		}
		case 6: {
			printf("введите имя файла:");
			scanf("%s", name);
			input(name, pr, size);
			break;
		}
		case 7: {
			printf("введите число записей: ");
			int number_of_elements;
			while (1) {
				scanf("%d", &number_of_elements);
				if (number_of_elements < 0)
					printf("введено неверное значение: ");
				else break;
			}
			processors = addData(pr, size, number_of_elements);
			size = size + number_of_elements;
			print_array(processors, size);
			break;
		}
		}
	} while (k != 0);
	return 0;
}