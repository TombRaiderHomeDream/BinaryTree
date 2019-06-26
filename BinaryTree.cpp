#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_TREE_SIZE 100   // 二叉树最大节点数

typedef char TElemType;
typedef int Status;

typedef struct BiThrNode
{
    TElemType data;

    struct BiThrNode *lchild;	// 左孩子
    struct BiThrNode *rchild;	// 右孩子
}BiThrNode, *BiThrTree;

BiThrTree T;

void Pause()
{
    cout << "Enter any keys to continue...";
    int get = getch();

    return;
}

Status InitCreateTree_T(BiThrTree &T)
{
    TElemType data;

    cin >> data;

    if (data == '#') T = NULL;

    else
    {
	T = (BiThrTree) malloc (sizeof(BiThrNode));
	if (!T) return ERROR;
	
	T->data = data;

	InitCreateTree_T(T->lchild);
	InitCreateTree_T(T->rchild);
    }

    return OK;
}

Status PreOrderTreeShow_T(BiThrTree T)
{
    if (T)
    {
	cout << T->data << " ";

	PreOrderTreeShow_T(T->lchild);
	PreOrderTreeShow_T(T->rchild);
    }

    return OK;
}

Status InOrderTreeShow_T(BiThrTree T)
{
    if (T)
    {
	InOrderTreeShow_T(T->lchild);

	cout << T->data << " ";

	InOrderTreeShow_T(T->rchild);
    }

    return OK;
}

Status PostOrderTreeShow_T(BiThrTree T)
{
    if (T)
    {
	
	PostOrderTreeShow_T(T->lchild);
	PostOrderTreeShow_T(T->rchild);

	cout << T->data << " ";
    }

    return OK;
}

int main()
{
	cout << "data: ";
	InitCreateTree_T(T);
	
	cout << endl;
	cout << "data: ";
	PreOrderTreeShow_T(T);
	cout << endl;
	
	cout << endl;
	cout << "data: ";
	InOrderTreeShow_T(T);
	cout << endl;
	
	cout << endl;
	cout << "data: ";
	PostOrderTreeShow_T(T);
	cout << endl;
		
    Pause();
    return 0;
}
