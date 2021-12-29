#include <stdio.h>
#include<stdlib.h>
#include <string.h>
//A~Z 65-90
//a~z 97~122
#define TEXTLENGH 100 //텍스트 사이즈는 일단 이렇게 만들어 놨다. 시작을 위해서
#define MAX_SIZE 100
//허프만 트리 생성
typedef struct Node
{
	char c;
	int freq;
	struct Node* left;
	struct Node* right;
	char Code[MAX_SIZE];
	int depth;
}Node;

//허프만 트리 노드 생성
Node* createQueueNode(char c, int freq);
Node* HuffmanTree();
void Encoding(Node* node, char c);
void printTree(Node* node);
void depthcheck(Node* node);
void findindex(Node* node, char str);
void freeTree(Node* node);
void Decoding(char str[]);

int i = 0;
//큐 생성
#define MAX_QUEUE_SIZE		52           //알파벳 종류가 52개 이므로 일단 52로 설정
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;
Node* deQueue();
void enQueue(Node* temp);

int Alpabat[26] = { 0, }; //대문자
int alpabat[26] = { 0, }; //소문자

Node* headnode = NULL;
Node* temp = NULL;
int main(void)
{
	char text[TEXTLENGH] = { 0, };
	printf("텍스트를 입력하세요 : ");
	scanf("%s", text);
	//알파벳에 대한 개수 세기
	for (int i = 0; i < strlen(text); i++)
	{
		if (97 <= text[i])
		{
			alpabat[text[i] - 97]++;
		}
		else
		{
			Alpabat[text[i] - 65]++;
		}
	}
	//큐에 해당 알파벳이랑 빈도수 값 넣기
	for (int i = 0; i < 26; i++)
	{
		if (Alpabat[i] != 0)
		{
			enQueue(createQueueNode(i + 65, Alpabat[i]));
		}
		if (alpabat[i] != 0)
		{
			enQueue(createQueueNode(i + 97, alpabat[i]));
		}
	}
	headnode = HuffmanTree();
	Encoding(headnode, NULL);
	printTree(headnode);

	char fullcode[MAX_SIZE] = { 0, };
	for (int i = 0; i < strlen(text); i++)
	{
		findindex(headnode, text[i]);
		strcat(fullcode, temp->Code);
	}
	printf("%s\n", fullcode);
	Decoding(fullcode);
	freeTree(headnode);
	return 0;
}
//허프만 트리 노드 생성
Node* createQueueNode(char c, int freq)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->c = c;
	temp->freq = freq;
	temp->left = NULL;
	temp->right = NULL;
	temp->depth = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		temp->Code[i] = NULL;
	}
	return temp;
}
Node* HuffmanTree()
{
	int n = 0; //알파벳이 한개 나왔을 경우를 제외하기위해서 선언
	while (1)
	{
		Node* first = deQueue();  //최소힙을 통한 우선순위가 작은 노드 팝-> 추가적으로 구현
		Node* second = deQueue();
		if (second == 0)  //노드가 1개 남았을때 그것이 마지막 루트노드
		{
			if (n != 0) //알파벳이 한개 나왔을때도 temp를 만들어 bit를 주어야하기 때문에 선언
			{
				return first;
			}
		}
		Node* temp = (Node*)malloc(sizeof(Node));
		for (int i = 0; i < MAX_SIZE; i++)
		{
			temp->Code[i] = NULL;
		}
		if (second != 0) //알파벳이 두개이상일때
		{
			temp->c = 0;
			temp->depth = 0;
			temp->left = first;
			temp->right = second;
			temp->freq = first->freq + second->freq;
			depthcheck(first);
			depthcheck(second);
			headnode = temp; //새로 생긴 노드를 트리의 루트 노드로 지정
			enQueue(temp); //우선순위 큐에 새로 생긴 노드를 추가
		}
		else //알파벳이 하나만 나왔을때
		{
			temp->c = 0;
			temp->depth = 0;
			temp->left = first;
			temp->right = 0;
			temp->freq = first->freq;
			depthcheck(first);
			headnode = temp; //새로 생긴 노드를 트리의 루트 노드로 지정
			enQueue(temp); //우선순위 큐에 새로 생긴 노드를 추가
		}
		n++; //n이 1이상 넘어가게되면 알파벳이 최소2개이다.
	}

}

Node* deQueue()               //queue-dequeue
{
	if (rear == front)            //rear과 front가 같으면 데이터가 없는것이므로
	{
		return NULL;           //NULL리턴
	}
	return queue[++front];     //데이터가 있으면 front의 시작이 -1 이기때문에 ++front가 가리키는 인덱스의 주소를 리턴
}

void enQueue(Node* temp)
{
	if (rear >= MAX_QUEUE_SIZE - 1)      //rear 배열의크기를 넘어가는 경우 에러메세지 출력
	{
		printf("full\n");
	}
	else                            //배열의 크기를 넘어가지 않았다면 데이터 저장
	{
		queue[++rear] = temp;
	}

}

void printTree(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	printTree(node->left);
	//if((node->c)!=0)
	printf("%c %d %s\n", node->c, node->freq, node->Code);
	printTree(node->right);
}
void findindex(Node* node, char str)
{
	if (node == NULL)
	{
		return;
	}
	if ((node->c) == str)
	{
		temp = node;
	}
	findindex(node->left, str);
	findindex(node->right, str);
}

void Encoding(Node* node, char c)
{
	if (node == NULL)
	{
		return;
	}
	if (node != headnode)
	{
		node->Code[node->depth - 1] = c;
		if (node->left != NULL)
		{
			strcpy(node->left->Code, node->Code);
		}
		if (node->right != NULL)
		{
			strcpy(node->right->Code, node->Code);
		}
	}
	Encoding(node->left, '0');
	Encoding(node->right, '1');
}
void depthcheck(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	depthcheck(node->left);
	node->depth++;
	depthcheck(node->right);
}
void freeTree(Node* node)                              //이진탐색트리 동적할당해제
{
	if (node)                         //후위순위(recursive)로 탐색하면서 노드 동적할당해제
	{
		freeTree(node->left);
		freeTree(node->right);
		free(node);
	}
}

void Decoding(char str[])
{
	Node* head = headnode;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0')
		{
			head = head->left;
		}
		else if (str[i] == '1')
		{
			head = head->right;
		}

		if (head->c != 0)
		{
			printf("%c", head->c);
			head = headnode;
		}
	}
}