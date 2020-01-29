#include <stdio.h> 
#include <stdlib.h>


struct Stu *create(int n);
void print(struct Stu *head);


struct Stu{
	int data;
	struct Stu *next;
};


int main(){
	int n;
	struct Stu *head = NULL;   //创建头指针 
	printf("the number of node(s):\n");
	scanf("%d",&n);
	head = create(n);
	print(head);
}


struct Stu *create(int n){
	struct Stu *head,*node,*end;   						//定义头节点，普通节点，尾节点 
	head = (struct Stu *)malloc(sizeof(struct Stu)); 	//给头节点申请内存 
	end = head;        									//若是空表，则头尾地址一致 
	for(int i=0;i<n;i++){								//利用for循环向链表中添加数据 
		node = (struct Stu *)malloc(sizeof(struct Stu));//给普通节点申请内存空间 
        printf("Input data:");
		scanf("%d",&node->data);	//给数据域赋值 
		end->next = node;					//让上一个节点的数据域指向当前节点 
		end = node;     						//end指向当前节点，最终end指向尾节点 
	}
	end->next = NULL;                                   //给end的指针域置空 
	return head;                                        //返回头节点的地址 
}


void print(struct Stu *head){
	struct Stu *p = head;
	int i =1;
	p = p->next;  //不打印头节点的数据域中的值 
	while(p != NULL){
		printf("%d\t%d\t\n",i,p->data);
		p = p->next;
		i++;
	}
}