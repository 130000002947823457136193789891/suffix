#include <stdio.h> 
#include <iostream.h> 
#include <stdlib.h>
#define stacksize 100 
#define queuesize 100 
 
/*  ���е���ز���*/
 typedef char datatype;
 typedef struct { 
	 char data[100];
	 int front,rear;
 }seqqueue;        //����������� 
 
/* ����ջ  */ 
 typedef struct
 {
	 datatype data[100];
	 int top;
 }seqstack;        //����ջ������ 
 
//��ʼ������
 void InitQueue(seqqueue *q) 
 {               
	 q->front=0;            
	 q->rear=0; 
 } 
 
//�пն��� 
 int QueueEmpty(seqqueue  *q)  
 {              
	 return (q->front==q->rear?1:0);
 } 
 
//����� 
 void EnQueue(seqqueue *q,datatype x) 
 {  
	 if ((q->rear>99 ))   
		 cout<<"queue overflow"<<endl; 
	 else 
	 {               
		 q->data[q->rear]=x;             
		 q->rear++; 
	 } 
 } 
 //������
 datatype DeQueue(seqqueue  *q)
 {
	  return q->data[q->front++]; 
 } 
 
//��ʼ��ջ
 void InitStack(seqstack *s) 
 {           
	 s->top=0; 
 } 
 
//��ջ
 void Push(seqstack *s,datatype x) 
 { 
	 if (    s->top>=100        )     
		 cout<<"stack overflow"<<endl; 
	 else  
	 {                 
		 s->data[s->top]=x;              
		 s->top++;    
	 }
 } 
 
//��ջ
 datatype Pop(seqstack *s) 
 {   
	 return s->data[--s->top]; 
 } 
 
//ȡջ��Ԫ��
 datatype GetTop(seqstack *s) 
 {   
	 if (  !s->top) 
		 cout<<"stack empty"<<endl; 
	 else                  
		 return s->data[s->top-1]; 
 } 
 
//����������ȼ����� 
 int Priority(datatype op) 
 {    
	 switch(op)   
	 {      
	 case '(':   
	 case ')': 
	 case '#':
		 return  1;      
	 case '-':    
	 case '+': 
		 return  2;    
	 case '*':     
	 case '/':
		 return  3;   
	 } 
 } 
 
//��׺���ʽת��Ϊ��׺���ʽ
 void IntoPostExp(seqqueue *q) 
 { 
	 seqstack os;   
	 //�����ջ 
	 char c,t; 
	 seqstack *s;     
	 s=&os;
	 InitStack(s);  
	 //��ʼ��ջ 
	 Push(s,'#');   
	 //ѹ��ջ��Ԫ��'#'
	 fflush(stdin);
	 //ɨ����׺���ʽ  
	 do   
	 {    
		 c=getchar();  
		 switch(c)  
		 {  
			 case ' ':   
				 break;//ȥ���ո�  
			 case '0':  
			 case '1': 
			 case '2':  
			 case '3':   
			 case '4': 
			 case '5':  
			 case '6': 
			 case '7':  
			 case '8': 
			 case '9':   
				 EnQueue(q,c);
				 break;
			 case '(': 
				 Push(s,c);
				 break;
		     case ')':
		     case '#':
		    	 do    
				 {
				    t=Pop(s);
				    if (t!='(' && t!='#')
				    EnQueue(q,t);
				 } while(s ->top &&t!='(' && t!='#' );     		         
				 break;
			 case '+':
			 case '-': 
			 case '*': 
			 case '/': 
				 while( Priority(c)<=Priority(GetTop(s)))
				 {   if(GetTop(s)!='(')          
						EnQueue(q,Pop(s));
				
				 }
				 Push(s,c);
				 break;
			} //endswitch
	 }while(c!='#');
 }
void main()
 { 
	seqqueue *q;  
	seqqueue postq;  
	//������У���ź�׺���ʽ  
	q=&postq;
	InitQueue(q);
    //��ʼ������  
	IntoPostExp(q); 
    //��׺���ʽת��Ϊ��׺���ʽ  
	while (!QueueEmpty(q)            )  
	//�����׺���ʽ   
	cout<<DeQueue(q)<<"  "; 
}
