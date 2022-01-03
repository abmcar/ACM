#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
/*
void count(int rate[])统计字符频数,得出权值 
void document(int rate[])文件中读取+
void decode_count(int data[])文件
void select(HuffmanTree HT,int i,int &s1,int &s2)选择函数选择两个最小的
void CreateHuffmanTree(HuffmanTree &HT,int n,int data[])哈夫曼树的建00立
void Huffmancode(HuffmanTree &HT,HuffmanCode &HC,int n)哈夫曼编码
void show (HuffmanCode &HC)显示函数
void save_count(int data[])//记录权值,方便解码
void decode_show(HuffmanTree &HT,HuffmanCode &HC,int n)解码
void range统计概率 
*/
using namespace std;
typedef struct  {
int weight;     
int parent;    
int rchild;     
int lchild;      
}*HuffmanTree,HTNode;
typedef char * *HuffmanCode;

void count(int rate[]){ //统计字符频数,得出权值 
	fstream out("data.txt",ios::out);
	char ch;

	ch=getchar();
	while(ch!='#')  
	{   
		if(ch==' ')
		rate[31]++;  
		if(ch==',')
		rate[27]++;  
		if(ch=='.')
		rate[28]++;  
		if(ch=='?')
		rate[29]++; 
		if(ch=='!')
		rate[30]++;   
		 
		if(ch>='A' && ch<='Z')  
		ch+=32;   //把大写转化为小写 
		if(ch>='a' && ch<='z')
		/*data[0]不用，从data[1]开始依次存取a,b,c...出现的频率*/ 
		rate[ch-'a'+1]++;   
		ch=getchar();
		out.put(ch);
	
	}

out.close();
	cout<<"\t\t\t\t\n统计完成!\a\a\a\a" ;
	system("pause");
	system("cls");//暂停清屏
} 
void document(int rate[]){
	char ch;
	fstream in("data.txt");
	ch=in.get();
	while(ch!='#')
{	if(ch==' ')
		rate[31]++;  
		if(ch==',')
		rate[27]++;  
		if(ch=='.')
		rate[28]++;  
		if(ch=='?')
		rate[29]++;  
		if(ch=='!')
		rate[30]++;  
		 
		if(ch>='A' && ch<='Z')  
		ch+=32;   //把大写转化为小写 
		if(ch>='a' && ch<='z')
		/*data[0]不用，从data[1]开始依次存取a,b,c...出现的频率*/ 
		rate[ch-'a'+1]++;   
	ch=in.get();
	}	
	cout<<"\n从data.txt文件中读取成功!!!\n";
	system("pause"); 
	in.close();
} 
//
void decode_count(int data[]){
	fstream iin("count.txt",ios::in);
	int c;

for(int i=1;i<=31;i++){
	iin>>c>>data[i];
}
iin.close();

}
void select(HuffmanTree HT,int i,int &s1,int &s2)
{
	int j,k=1;
	while(HT[k].parent!=0)
	k++;
	
	s1=k; //s1临时值 
	
	for(j=1;j<i;++j)
	{ 
	   if(HT[j].parent==0 && HT[j].weight<=HT[s1].weight)
	   { 
	    s1=j;
	   } 
	} 
	k=1;
	
	while((HT[k].parent!=0||k==s1))
    k++;
    
    s2=k;
	 
    for(j=1;j<=i;++j)
    if(HT[j].parent==0&&HT[j].weight<=HT[s2].weight&&j!=s1)
    s2=j;
}
void CreateHuffmanTree(HuffmanTree &HT,int n,int data[])
{
	int s1=0;
	int s2=0;
	int m=2*n-1;
	HT=new HTNode[m+1];  //0号单元不用
	int i;
	for(i=1;i<m;++i)  //1-m结点初始化 
	{
		HT[i].parent=0;
		HT[i].weight=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	 }
	for(i=1;i<=n;++i)
	{
		HT[i].weight=data[i];
	}
//初始化完毕
    for(i=n+1;i<=m;++i)
	{
		select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i; 
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight; 
		 
	 } 
}

void Huffmancode(HuffmanTree &HT,HuffmanCode &HC,int n)
{    int i,temp,start;
	HC=(char**)malloc((n+1)*sizeof(char*)); 
	char *cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0'; 
    for(i=1;i<=n;i++)
    {
	    start=n-1; 
        for(int c=i,temp=HT[i].parent;temp!=0;c=temp,temp=HT[temp].parent)
        { 
		    start--; 
            if(HT[temp].lchild==c) 
            {
                cd[start]='0';
            }
            else 
            {
                cd[start]='1';
            }	
        }
        HC[i]=(char*)malloc((n-start)*sizeof(char)); 
        strcpy(HC[i],&cd[start]);//复制cd到HC 
        cout<<"\nHT["<<i<<"]节点的哈夫曼编码是 :"<<HC[i]<<"对应权值为： "<<HT[i].weight;
    }
 
}
void show (HuffmanCode &HC){
	fstream in("data.txt",ios::in);
	char ch;
	ch=in.get();

	fstream out("data_code.txt",ios::out);

	while(ch!='#'){

		if(ch==' '){
			cout<<" :"<<HC[31];
			out<<HC[31]<<endl;
		}
		
		if(ch==','){
				cout<<",:"<<HC[27];
				out<<HC[27]<<endl;
		}
	
		if(ch=='.'){
				cout<<".:"<<HC[28];
				out<<HC[28]<<endl;
		}
	
		if(ch=='!'){
				cout<<"!:"<<HC[30];
				out<<HC[30]<<endl;
		}
	
		if(ch=='?'){
			cout<<"?:"<<HC[29];
			out<<HC[29]<<endl;	
		}
	
		if(ch>='a' && ch<='z'){
				cout<<ch<<":"<<HC[(ch-'a')+1];
				out<<HC[(ch-'a')+1]<<endl;
		}
	
		cout<<"\t";
	ch=in.get();	
		 
	}
	cout<<"\n";
	in.close();
	out.close();
} 
void save_count(int data[]){//记录权值,方便解码
fstream out("count.txt");
for(int i=1;i<=31;i++){
	out<<i<<" "<<data[i]<<endl;
} 
out.close();	
}
void decode_show(HuffmanTree &HT,HuffmanCode &HC,int n){
	int i,temp,start;
	HC=(char**)malloc((n+1)*sizeof(char*)); 
	char *cd=(char*)malloc(n*sizeof(char));
	//动态分配内存
    cd[n-1]='\0';//在cd[n-1]处设置结束符 
	//构造编码
    for(i=1;i<=n;i++)
    {
	    start=n-1; 
        for(int c=i,temp=HT[i].parent;temp!=0;c=temp,temp=HT[temp].parent)
        { 
		    start--; 
            if(HT[temp].lchild==c) 
            {
                cd[start]='0';
            }
            else 
            {
                cd[start]='1';
            }	
        }
        HC[i]=(char*)malloc((n-start)*sizeof(char)); 
        strcpy(HC[i],&cd[start]); 
       
    }
	//从文件中读取
	fstream in("data_code.txt");
	char a[32];
		while(in>>a){
		for(int i=1;i<=31;i++){
			if(strcmp(a,HC[i])==0){
				if(i==31)
				cout<<' ';
				if(i==27)
				cout<<',';
				if(i==28)
				cout<<'.';
				if(i==29)
				cout<<'?';
				if(i==30)
				cout<<'!';
				if(i<27&&i>0)
				cout<<char(96+i);
			}
		}
	
	}
	in.close();
}
void range(int * rate,int n){
	double sum=0;
	double sum_a=0;
	for(int i=1;i<n;i++)
		sum+=rate[i];//统计字符数目
	for(int i=1;i<n;i++){
		cout<<(char)(97+i-1)<<" 概率为："<<rate[i]/sum<<endl;

	}
}
int main(){
    int len=31;
	int rate[len+1]={0};
	HuffmanTree HT;
	HuffmanCode HC;	
	int n;   
	while(1) {
		 	cout<<"\t\t\t\t[Huffman Coding]"
	      "\n---------------------------------------------------------------------------------\n";
		cout<<"1.从键盘中录入短文\n"
		      "2.从文档中读取短文\n"		    
		      "3.显示Huffman编码\n"
			  "4.解Huffman码\n" 
			  "5.统计字符概率\n" ;
			cout<<"\n---------------------------------------------------------------------------------\n";	  
		cout<<"请输入指令数字:";
		cin>>n;	  
		switch(n){
			case 1:
				system("cls");
				cout<<"功能:[从键盘中录入短文]\n确保程序正常运行,请以#为结束字符\n";
				count(rate);
				save_count(rate); 
				break;
			case 2:
				system("cls");cout<<"功能:[从文件中录入短文]\n";
				
				document(rate);
				save_count(rate); 
				// range(rate,len+1);
				break;
			case 3:
				system("cls");
				cout<<"功能:[显示Huffman编码]\n";
				CreateHuffmanTree(HT,len,rate); 
				Huffmancode(HT,HC,len); 
				cout<<"\n[编码表如上所示]\n------\n------\n------\n[内容编码]如下:\n";
				show(HC); 
				break; 
			case 4:
				system("cls");
				decode_count(rate);
				CreateHuffmanTree(HT,len,rate); 
				cout<<"\n[解码后的内容为]\n"; 
				decode_show(HT,HC,len);
				cout<<"\n";
				system("pause");
				break;
			case 5:
				system("cls");
				cout<<"功能:显示统计结果\n";
				range(rate,len+1);
				cout<<"\n[编码表如上所示]\n------\n------\n------\n[内容编码]如下:\n";
				show(HC); 
				break; 
			
		}
		
	} 
	
	
	return 0;
} 


