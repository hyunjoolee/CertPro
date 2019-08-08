#include <stdio.h>
#include <string.h>
#include <iostream>

#define TOTAL_TEST_CASE 100
#define MAX_NODE 100000 // 노드 수
#define MAX_TABLE 10000
using namespace std;

int node_idx = 0;
struct NODE {
	char key[7];
	char val[7];
	NODE * next;
}node[MAX_NODE];

NODE* myalloc(void)
{
	return &node[node_idx++];
}

NODE *hTable[MAX_TABLE];  //Hash Table 입니다.

unsigned long myhash(const char *str)
{
	//unsigned long hash = 50021;
	unsigned long hash = 5381;
	int c;

	while(c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}

void init() {

 	node_idx = 0;	// NODE 초기화
	
	// 해시테이블 초기화
	for (int i = 0; i < MAX_TABLE; ++i) {
		hTable[i] = NULL;
	}	
}

void my_str_cpy(char * dest, const char * src) {

	while (*src != '\0') {
		*dest = *src;
		dest++; src++;
	}
	*dest = '\0';

}

int my_str_cmp(const char * str1, const char * str2) {

	while (*str1 != '\0' && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *str1 - *str2;

}

void add(const char * key, char* value) {

	int idx = myhash(key);
	NODE* n = myalloc();
	NODE* cur = hTable[idx];
	while(cur != NULL){
		// 중복이면 값 변경 후 return
		if(my_str_cmp(cur->key, key) == 0) {
			my_str_cpy(cur->val, value);
			return;
		}
		cur = cur->next;
	}
	n->next = hTable[idx];
	hTable[idx] = n;
}

bool find(const char * key, int * val) {


	return false;

}

bool destroy(const char * key) {
	int idx = myhash(key);
	if(hTable[idx] == NULL)
		return false;

	NODE** cur = &hTable[idx];
	while(*cur != NULL){
		// key가 같으면 출력 후 삭제
		if(my_str_cmp((*cur)->key, key) == 0) {
			printf("key: %s, value: %s\n", (*cur)->key, (*cur)->val);
			*cur = (*cur)->next;
			return true;
		}
	}
	return true;
}

void print_hash() {

}

int main() {

	int key;
    char key[7] = "aaaaaa"; 
	char value[10] = "hjlee98";

	add(key, value);

	return 0;
}