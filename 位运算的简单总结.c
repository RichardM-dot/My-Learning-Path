#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define read_perm 0x01//00000001-读权限
#define write_perm 0x02//000000010-写权限
#define exec_prem 0x04//00000100-执行权限
#define delete_prem 0x08//00001000-删除权限
void comprehensivebitwisedemo(char testchar,char key)
{
	printf("===位运算===\n");
	printf("测试字符:'%c'(ascll:%d)\n",testchar,testchar);
	printf("加密密钥:0x%02X\n\n",(unsigned char)key);
	//1.先分析字符二进制
	printf("1.字符二进制分析:\n");
	printf("二进制:");
	for(int i=7;i>0;i--)
	{
		printf("%d",(testchar>>i)&0x01);
		if(i==4) printf(" ");//每四位加一个空格便于观察
	}
	printf("\n 高四位0x%X,低4位:0x%X\n\n",(testchar>>4)&0x0F,testchar&0x0F);
	//2.大小写转换演示
	printf("2.大小写转换:\n");
	printf("转小写:'%c'->'%c'\n",testchar,testchar|0x20);
	printf("转大写:'%c'->'%c'\n\n",testchar,testchar&(~0x20));
	printf("大小写转换:'%c'->'%c'->'%c'\n\n",testchar,testchar^0x20);
	//3.字符属性判断
	unsigned char uc=(unsigned char)testchar;
	bool isalpha=((uc|0x20)-'a'<25);//字母判断
	printf("是否是字母: %s\n", isalpha ? "是" : "否");
	bool isupper=((uc&0x20)==0&&(uc>='A'&&uc<='z'));//大写字母判断
	printf("是否是大写字母:%s\n",isupper?"是":"否");
	bool islower=((uc&0x20)!=0&&(uc>'a'&&uc<='z'));//小写字母判断
	printf("是否是小写字母:%s\n\n",islower?"是":"否");
	bool isdigit=(uc>='0'&&uc<='9');//数字判断
	printf("是否为数字:%s\n\n",isdigit?"是":"否");
    bool needsencoding=(uc<0x20||uc>0x7E);//URL编码检测
	printf("是否需要URL编码:%s\n\n",needsencoding?"是":"否");
	//4.加密解密演示
	printf("4.加密解密演示:\n");
	char encrypted=testchar^key;
	char decrypted=encrypted^key;
	printf("原字符:'%c'(0x%02X)\n",testchar,(unsigned char)testchar);
	printf("加密后:'%c'(0x%02X)\n",encrypted,(unsigned char)encrypted);
	printf("解密后:'%c'(0x%02X)\n\n",decrypted,(unsigned char)decrypted);
	//5.权限管理系统演示
	printf("5.权限管理系统演示:\n");
    char userpermissions=0x00;//初始无权限
    //设置权限
	userpermissions |= read_perm | write_perm;//设置读写权限
    printf("   设置读、写权限: 0x%02X\n", (unsigned char)userpermissions);
	//检查权限
    printf("有读权限:%s\n",(userpermissions&read_perm)?"是":"否");
	printf("有写权限:%s\n",(userpermissions&write_perm)?"是":"否");
    //添加执行权限
	userpermissions|=exec_prem;
	printf("添加执行权限后:0x%02X\n",(unsigned char)userpermissions);
	//移除写权限
	userpermissions&=~write_perm;
	printf("移除写权限后:0x%02X\n",(unsigned char)userpermissions);
	printf("有写权限:%s\n",(userpermissions&write_perm)?"是":"否");
	//6.位操作技巧演示
	int number=42;
	printf("\n6.位操作技巧演示:\n");
	printf("原始数字:%d\n",number);
	printf("数字%d的奇偶判断:\n",number);
	printf("传统方法:%s\n",(number%2==0)?"偶数":"奇数");
	printf("位操作方法:%s\n",(number&0x01)?"奇数":"偶数");
	//快速乘除二的幂
	printf("数字%d乘以8:%d\n",number,number<<3,number);
	printf("数字%d除以8:%d\n",number,number>>3,number);
	//7.使用位运算函数
	printf("7.实用位运算函数");
	//统计1的个数
	int count=0;
	unsigned char temp=(unsigned char)testchar;
	while(temp)
	{
		count++;
		temp&=(temp-1);//清除最低位1
	}
	printf("字符中1的个数:%d\n",count);
	//判断是否为2的幂
	bool ispoweroftwo=(number>0)&&((number&(number-1)==0));
	printf("数字是否为2的幂:%s\n",ispoweroftwo?"是":"否");
	//提取最低位的1
	int lowestbit=number&(-number);
	printf("%d的最低有效位:%d\n\n",number,lowestbit);
}
void performancecomparison()
{
	printf("===性能比较===\n");
	int testnum=123456789;
	int iterations=100000000;//1亿次迭代
	clock_t start,end;
	//传统方法
	start=clock();
	int traditionalresult=0;
	for(int i=0;i<iterations;i++)
	{
		traditionalresult+=(testnum+i)%2;
	}
	end=clock();
	double traditionaltime=(double)(end-start)/CLOCKS_PER_SEC;//标准库常量
	//位运算方法
	start=clock();
	int bitwiseresult=0;
	for(int i=0;i<iterations;i++)
	{
		bitwiseresult+=(testnum+i)&1;
	}
	end=clock();
	double bitwisetime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("传统方法(取模):%.4f秒\n",traditionaltime);
	printf("位运算(与操作):%.4f秒\n",bitwisetime);
}
void interativetest()
{
    printf("===交互式测试===\n");
	printf("请输入一个字符:");
	char inputchar=getchar();
	//清空输入缓冲区
	while(getchar()!='\n');
	printf("请输入密钥(0-255)");
	int keyinput;
	scanf("%d",&keyinput);
	comprehensivebitwisedemo(inputchar,(char)keyinput); 
}
int main()
{
	// 基础演示
    comprehensivebitwisedemo('A', 0x55);
    comprehensivebitwisedemo('z', 0xAA);
    comprehensivebitwisedemo('9', 0x33);
    // 性能对比
    performancecomparison();
    // 交互式测试（取消注释即可使用）
    // interactiveTest();
    printf("=== 位运算优势总结 ===\n");
    printf("1. 极致性能 - CPU原生指令级支持\n");
    printf("2. 内存高效 - 直接操作，无临时变量\n"); 
    printf("3. 代码简洁 - 一行完成复杂逻辑\n");
    printf("4. 硬件控制 - 嵌入式系统必备技能\n");
    return 0;
}