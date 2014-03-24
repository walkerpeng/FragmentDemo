#define MAXSIZE 100
typedef struct
{
	int data[100];
	int front,rear;
	int num;// 用来实时记录队中的元素个数
}c_SeqQue;


//置空队
c_SeqQue *Init_SeqQue()
{
	c_SeqQue *q;
	q = (c_SeqQue*)malloc(sizeof(c_SeqQue));
	q->front = q->rear = -1;
	q->num = 0;
	return q;
}


//创建队
c_SeqQue *creat()
{
	c_SeqQue *q;
	int i = 1,n;
	q = Init_SeqQue();
	printf("请输入数据，以0结束\n");
	scanf("%d",&n);
	while(n != 0 && q->rear < MAXSIZE)
 	{
		q->data[i] = n;
		i = i++;
		q->rear++;
		scanf("%d",&n);	
	}
	return q;
}



//入队操作
int In_SeqQue(c_SeqQue *q,int e)
{
	int num;
	if(num = MAXSIZE)
	       {	
		    printf("队满");
		    return -1;
		}
	else {
		q->rear = (q->rear + 1)%MAXSIZE;
		q->data[q->rear] = e;
		num++;
		return 1;
	      } 
}


//出队
int Out_SeqQue(c_SeqQue *q , int *e)
{
	int num;
	if(num == 0)
	{ 
	  print("队空");
	  return -1;
	}
	else
	   {
		q->front = (q->front + 1 )%MAXSIZE;
		*e = q->data[q->front];
		num --;
		return 1;
	   }
}


//判队空

int Empty_SeqQue(c_SeqQue *q)
{
	int num;
	if(num == 0)
	{
		print("队空");
	    return 1;
	}
	else
		return 0;
}

//求队长
int Length(c_SeqQue *q)
{
	return(q->rear);
}

//打印队
void print(c_SeqQue *q)
{
	int i,*rear;
	for( i = 1; i < q->rear; i++)
		printf("%d ", q->data[i]);
}

int main()
{
	int num,length;
	int value;
	int flag;
	int i,j;
	int e;
	
	c_SeqQue *q;
	q = creat();
	length = Length(q);
	printf("队的长度为%d\n",length);

//入队
	printf("你想把哪个数放入队中？\n");
	scanf("%d", &i);	
	value = In_SeqQue(q,i);
	if(value != 0)
	printf("完成!\n");
	print(q);

//出队
    printf("你想进行出队操作吗？\n");
	flag = Out_SeqQue(q,e);
	if(flag == 1)
	 {
		printf("完成！\n");
		print(q);
	  }
	else
		printf("失败！\n");


//判队空
	printf("是否判断队为空? \n");
	j = Empty_SeqQue(q);
	if(j == 1)
	   printf("队为空!\n");
	else
	   printf("队不为空！\n");

}