#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_NODE 100000

int node_idx = 0;

struct NODE {
    int val;
    NODE* ptr;
} node[MAX_NODE];

NODE* myalloc(void)
{
    return &node[node_idx++];
}

int main(void)
{
    NODE * pList = NULL; // 싱글 링크드 리스트의 시작
    NODE * p; 
 
    node_idx = 0;  // 배열 초기화 
 
    //첫번째 노드(1) 추가 
    p = myalloc();
    p->val = 1;
    p->ptr = pList; 
    pList = p;
  
    //두번째 노드(2) 추가
    p = myalloc();
    p->val = 2;
    p->ptr = pList;
    pList = p;
 
    //추가된 노드 확인 
    for(NODE * pp = pList; pp != NULL; pp = pp->ptr)
    {
        cout << pp->val << " ";
    }
 
    return 0;
}
