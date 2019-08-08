#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_NODE 100000
#define NUM_ALPHA 26

int node_idx = 0;
struct NODE{
    NODE* child[NUM_ALPHA];
    bool finish;
} node[MAX_NODE];

NODE * myalloc(void)
{
    for(int i = 0; i < NUM_ALPHA; i++)
        node[node_idx].child[i] = NULL;
    node[node_idx].finish = false;

    return &node[node_idx++];
}

void insert(NODE* root, const char *str)
{
    NODE* now = root;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        if(!now->child[str[i] - 'a'])
            now->child[str[i] - 'a'] = myalloc();
        now = now->child[str[i] - 'a'];
    }

    now->finish = true;    
}

int search(NODE* root, const char* str){
	int len = strlen(str);
	NODE* now = root;

	for (int i=0; i<len; i++){ 
		if (!now->child[str[i]-'a']) 
            return 0;
		now=now->child[str[i]-'a'];
	}
	return now->finish;
}

int delete(NODE* now, const char* str, int i){
	if (i == strlen(str)){
		int chk=0;
		for (int i=0; i<26; i++){
			if (now->child[i]) chk=1;
		}
		if (chk) return 0;
		return 1;
	}

	if ( now->child[str[i]-'a']){
		if (delete(now->child[str[i]-'a'], str, i+1)){
			free(now->child[str[i]-'a']);
			now->child[str[i]-'a']=0;

			int chk=0; 
			for (int i=0; i<26; i++){
				if (now->child[i]) chk=1;
			}

			if (chk) return 0;
			return 1;
		}
	}
	return 0;
}	