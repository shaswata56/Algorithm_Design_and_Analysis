#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

uint32_t m;

struct pr {
	char* word;
	uint32_t hash;
};

struct pr *hashmap;

void lower_string(char s[]) 
{
	int c = 0;
	while (s[c] != '\0') 
	{
		if (s[c] >= 'A' && s[c] <= 'Z') 
			s[c] = s[c] + 32;
		if(s[c] == '\n')
			s[c] = '\0';
		c++;
	}
}

uint32_t hx(char ch[])
{
	uint32_t i = 0, Id = 0;
	while(ch[i])
	{
		Id += ch[i] - 'a';
		Id <<= 2;
		i++;
	}
	return Id;
}

uint32_t hash(uint32_t key)
{
	uint32_t knuth = 2654435769;
	return (key * knuth) % m;
}

uint32_t h(uint32_t k, uint32_t i)
{
	 return (hash(k) + i * i + i) % m;
}

void insert(uint32_t key, char* value)
{
	uint32_t i = 0;
	uint32_t index = h(key, i);
	if(hashmap[index].hash == key)
		return;
	while(hashmap[index].word != NULL)
	{
		i++;
		index = h(key, i);
		if(hashmap[index].hash == key)
			return;
	}
	hashmap[index].word = value;
	hashmap[index].hash = key;
}

void tokenize(char str[])
{
	char *token = strtok(str, " ");
	while (token != NULL)
	{
		insert(hx(token), token);
		token = strtok(NULL, " ");
	} 
}

int main() 
{ 
	char str[100000], c;
	int n;
	printf("Enter table size = ");
	scanf("%zu", &m);
	hashmap = malloc(m * sizeof(struct pr));
	scanf("%c", &c);
	printf("Enter elements in one line: ");
	fgets(str, 100000, stdin);
	lower_string(str);
	tokenize(str);
	printf("The Hash Table:\n");
	for(int i = 0; i < m; i++)
	{
		if(hashmap[i].word)
			printf("hashmap[%d] = %s\n", i, hashmap[i].word);
	}
	return 0; 
}

