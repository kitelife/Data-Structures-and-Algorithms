#include <stdio.h>
#include <string.h>

#define NHASH	29989
#define MULT	31
#define WORDLEN	32
typedef struct node *nodeptr;
typedef struct node {
	char *word;
	int count;
	nodeptr next;
} hashnode;

nodeptr bin[NHASH];

unsigned int hash(char *p)
{
	unsigned int h = 0;
	for(; *p; p++)
		h = MULT * h + *p;

	return h % NHASH;
}

void incword(char *s)
{
	unsigned int h = hash(s);
	nodeptr p;
	for(p = bin[h]; p != NULL; p = p->next)
		if(strcmp(s, p->word) == 0)
		{
			(p->count)++;
			return;
		}
	p = (nodeptr)malloc(sizeof(hashnode));
	p->count = 1;
	p->word = malloc(strlen(s) + 1);
	strcpy(p->word, s);
	p->next = bin[h];
	bin[h] = p;
}

int main(void)
{
	int i;
	nodeptr p;
	char* buf = (char *)malloc(sizeof(char) * (WORDLEN + 1));
	for(i = 0; i < NHASH; i++)
		bin[i] = NULL;
	while(scanf("%s" , buf) != EOF)
		incword(buf);
	for(i = 0; i < NHASH; i++)
		for(p = bin[i]; p != NULL; p = p->next)
			printf("p->word: %s, p->count: %d\n", p->word, p->count);

	return 0;
}
