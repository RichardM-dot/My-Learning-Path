#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_students 100
#define max_name_length 50
#define filename "students.dat"
typedef struct
{
    int id;
	char name[max_name_length];
	float score;
}student;
student students[max_students];
int studentcount=0;
void displaymenu();
void addstudent();
void displayallstudents();
void searchstudent();
void updatestudent();
void deletestudent();
void sortstudents();
void calculatestatistics();
void savetofile();
void loadfromfile();
int findstudentbyid(int id);
int main()
{
	loadfromfile();
	int choice;
	do
	{
		displaymenu();
		printf("请输入你的选择：");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:addstudent();break;
		case 2:displayallstudents();break;
		case 3:searchstudent();break;
		case 4:updatestudent();break;
		case 5:deletestudent();break;
		case 6:sortstudents();break;
		case 7:calculatestatistics();break;
		case 8:savetofile();printf("数据已储存，程序退出。");break;
		case 0:printf("程序退出。\n");break;
		default:printf("无效选择，请重新输入。\n");
		}
	}
	while(choice!=0 && choice!=8);
	return 0;
}
void displaymenu()
{
	printf("\n=========学生成绩管理系统=========\n");
	printf("1.添加学生\n");
	printf("2.显示所有学生\n");
	printf("3.查找学生\n");
	printf("4.修改学生信息\n");
	printf("5.删除学生\n");
	printf("6.按成绩排序\n");
	printf("7.统计信息\n");
	printf("8.退出并保存\n");
	printf("0.退出（不保存）\n");
	printf("=====================================\n");
}
void addstudent()
{
	if(studentcount>=max_students)
	{
		printf("学生数量已达上限，无法添加新学生。\n");
		return;
	}
	student newstudent;
	printf("请输入学号：");
	scanf("%d",&newstudent.id);
	if(findstudentbyid(newstudent.id)!=-1)
	{
		printf("该学号已存在，添加失败。\n");
		return;
	}
	printf("请输入姓名:");
	scanf("%s",newstudent.name);
	printf("请输入成绩：");
	scanf("%f",&newstudent.score);
	if(newstudent.score<0 || newstudent.score>100)
	{
		printf("成绩无效应在0～100之间。\n");
		return;
	}
	students[studentcount]=newstudent;
	studentcount++;
	printf("学生添加成功！");
}
void displayallstudents()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	printf("\n学号\t姓名\t成绩\n");
	printf("---------------------\n");
	for(int i=0;i<studentcount;i++)
	{
		printf("%d\t%s\t%.2f\n",students[i].id,students[i].name,students[i].score);
	}
}
void searchstudent()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	int choice;
	printf("请选择查找方式：\n1.按学号查找\n2.按姓名查找\n请输入你的选择：");
	scanf("%d",&choice);
	if(choice==1)
	{
		int id;
		printf("请输入要查找的学生号:");
		scanf("%d",&id);
		int index=findstudentbyid(id);
		if(index!=-1)
		{
			printf("\n学号\t姓名\t成绩\n");
			printf("---------------------\n");
			printf("%d\t%s\t%.2f\n",students[index].id,students[index].name,students[index].score);
		}
		else 
		{
		    printf("未找到学号为%d的学生。\n",id);
		}
	}
		else if(choice==2)
		{
			char name[max_name_length];
			printf("请输入要查找的姓名:");
			scanf("%s",name);
			int found=0;
			printf("\n学号\t姓名\t成绩\n");
			printf("---------------------\n");
			for(int i=0;i<studentcount;i++)
			{
				if(strcmp(students[i].name,name)==0)
				{
				    printf("%d\t%s\t%.2f\n",students[i].id,students[i].name,students[i].score);
					found=1;
				}
			}
			if(!found)
			{
				printf("未找到为%s姓名的学生。\n",name);
			}
		}
		else
		{
			printf("无效选择。\n");
		}
}
void updatestudent()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	int id;
	printf("请输入要修改学生的学号：");
	scanf("%d",&id);
	int index=findstudentbyid(id);
	if(index==-1)
	{
		printf("未找到学号为%d的学生。\n",id);
		return;
	}
	printf("当前信息：学号%d,姓名：%s，成绩%.2f\n",students[index].id,students[index].name,students[index].score);
	printf("请输入新的姓名（当前：%s）：",students[index].name);
	scanf("%s",students[index].name);
	printf("请输入新的成绩（当前：%.2f）：",students[index].score);
	scanf("%f",&students[index].score);
	if(students[index].score<0 || students[index].score>100)
	{
		printf("成绩无效，应在0～100之间。修改失败。\n");
		return;
	}
	printf("学生信息修改成功！\n");
}
void deletestudent()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	int id;
	printf("请输入要删除的学生的学号：");
	scanf("%d",&id);
	int index=findstudentbyid(id);
	if(index==-1)
		{
			printf("未找到学号为%d的学生。\n",id);
		    return;
		}
	printf("将要删除的学生的信息：学号%d，姓名：%s，成绩:%.2f\n",students[index].id,students[index].name,students[index].score);
	char confirm;
	printf("确认要删除吗？(y/n):");
	getchar();
	scanf("%c",&confirm);
	if(confirm=='y' ||confirm=='Y')
	{
		for(int i=index;i<studentcount-1;i++)
		{
			students[i]=students[i+1];
		}
		studentcount--;
		printf("学生删除成功！\n");
	}
	else
	{
	    printf("取消删除操作。\n");	
	}
}
void sortstudents()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	int choice;
	printf("请选择排序方式：\n1.按成绩升序\n2.按成绩降序\n请输入您的选择：");
	scanf("%d",&choice);
	for(int i=0;i<studentcount-1;i++)
	{
		for(int j=0;j<studentcount-1-i;j++)
		{
			int shouldswap=0;
			if(choice==1)
			{
				shouldswap=students[j].score>students[j+1].score;
			}
			else if(choice==2)
			{
				shouldswap=students[j].score<students[j+1].score;
			}
			else
			{
			    printf("无效选择。\n");
				return;
			}
			if(shouldswap)
			{
				student temp=students[j];
				students[j]=students[j+1];
				students[j+1]=temp;
			}
		}
	}
	printf("排序完成\n");
	displayallstudents();
}
void calculatestatistics()
{
	if(studentcount==0)
	{
		printf("没有学生记录。\n");
		return;
	}
	float sum=0;
	float maxscore=students[0].score;
	float minscore=students[0].score;
	int passcount=0;
	for(int i=0;i<studentcount;i++)
	{
		sum+=students[i].score;
		if(students[i].score>maxscore)
		{
			maxscore=students[i].score;
		}
		if(students[i].score>=60)
		{
			passcount++;
		}
	}
	float average=sum/studentcount;
	float passrate=(float)passcount/studentcount*100;
	printf("\n=========统计信息=========\n");
	printf("学生总数：%d\n",studentcount);
	printf("平均成绩：%.2f\n",average);
	printf("最高分：%.2f\n",maxscore);
	printf("最低分：%.2f\n",minscore);
	printf("及格人数：%d\n",passcount);
	printf("及格率：%.2f%%\n",passrate);
	printf("============================\n");
}
void savetofile()
{
	FILE *file=fopen(filename,"wb");
	if(file==NULL)
	{
		printf("无法打开文件进行储存。\n");
		return;
	}
	fwrite(&studentcount,sizeof(int),1,file);
	fwrite(students,sizeof(student),studentcount,file);
	fclose(file);
	printf("数据已保存到%s\n",filename);
}
void loadfromfile()
{
	FILE *file=fopen(filename,"rb");
	if(file==NULL)
	{
		printf("无法找到数据文件，将创建新的文件夹。\n");
		return;
	}
	fread(&studentcount,sizeof(int),1,file);
	fread(students,sizeof(student),studentcount,file);
	fclose(file);
	printf("已从文件%s加载%d条学生记录。\n",filename,studentcount);
}
int findstudentbyid(int id)
{
	for(int i=0;i<studentcount;i++)
	{
		if(students[i].id==id)
		{
			return i;
		}
	}
	return -1;
}


