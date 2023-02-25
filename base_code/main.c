#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"
#include "base_struct.c"
#include "list_functions.c"


//int x = 10 -> valores normales
//&x -> puntero de la variable
//int *dirX = &x -> para guardar solo direcciones
// *dirX -> para acceder al valor de ese puntero
 
const int SIZE = 150000;

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	item_t element;
	int line_number = 0;
	t_node *node = initializeNode(node);
	item_t items[SIZE];
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line_number > 0)
		{
			char *token;
			char *s = NULL;
			int i = 0;
			
			while ((token = strtok_r(line, ",", &line)))
			{
				city_t result_city;
				gender_t result_gender;
				bool_t result_illness;
				switch (i)
				{
				case 0:		

					element.id = atoi(token);
					break;
				case 1:
					result_city = get_city_t(token);
					if (result_city == E)
						printf("City not defined\n");
					element.city = result_city;
					break;
				case 2:
					result_gender = get_gender_t(token);
					if (result_gender == NO)
						printf("Gender not defined\n");
					element.gender = result_gender;
					break;
				case 3:
					element.age = atoi(token);
					break;
				case 4:
					element.income = atoi(token);
					break;
				case 5:
					s = token;
					while (*s != '\n')
					{
						++s;
					}
					*s = '\0';
					result_illness = get_illness_t(token);
					if (result_illness == fuzzy)
						printf("Value not defined \n");
					element.illness = result_illness;
					break;
				}
				i++;
			}
			node = addNode(node, element);
			items[line_number - 1] = element;

		}
		
		line = NULL;
		line_number++;
	}
	// LISTAS LIGADAS
	// ----EJERCICIO 1----
	//int numero = 0;
	//count_people_by_city(node, &numero);

	// ----EJERCICIO 2----
	// char *city_char = "Dallas";
	// city_t city = get_city_t(city_char);
	// get_average_income_by_city_and_age(node, city, 32,60);

	// ---EJERCICIO 3-----
	//get_probability_illness_by_age(node, 32);

	// ---EJERCICIO 4-----
	//t_node *nodeEncontrado = get_node_by_id(node, 12);
	//printf("nodo encontrado con id %d y con edad %d\n", nodeEncontrado->item.id, nodeEncontrado->item.age);


	

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}


