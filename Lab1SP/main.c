#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int max_Lenght = 0;
	char longest_words[100][30];
	int id_max_word = 0;
	char current_word[30];
	int i, k;

	FILE* f;
	f = fopen("test1.txt", "r");
	if (f == NULL)
	{
		printf("The file is not found!");
		return 1;
	}

	while (fscanf(f, "%s", current_word) != EOF)
	{
		for (i = 0, k = 0; i < strlen(current_word); i++)
		{
			if (isalpha(current_word[i]))
			{
				current_word[k] = current_word[i];
				k++;

			}
		}
		current_word[k] = '\0';

		int duplicate = 0;
		for (i = 0; i < id_max_word; i++)
		{
			if (strcmp(current_word, longest_words[i]) == 0)
			{
				duplicate = 1;
				break;
			}
		}
		if (!duplicate) 
		{
			if (strlen(current_word) > max_Lenght)
			{
				max_Lenght = strlen(current_word);
				id_max_word = 1;
				strcpy(longest_words[0], current_word);
			}

			else if (strlen(current_word) == max_Lenght && id_max_word < 100)
			{
				strcpy(longest_words[id_max_word], current_word);
				id_max_word++;
			}
		}
	}


	fclose(f);

	printf("The longest word/words: ");
	for (i = 0; i < id_max_word; i++)
	{
		printf("%s ", longest_words[i]);
	}
	printf("\n");
	printf("The num of letters in words: %d\n", max_Lenght);

	return 0;
}

