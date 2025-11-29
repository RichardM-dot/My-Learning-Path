#include <stdio.h>
int main()
{
    FILE *file;
    char filename[]="exmple.txt";
    char buffer[100];
    //1.创建并写入文件"w"模式
    printf("===1.创建并写入文件===");
    file=fopen(filename,"w");
    if(file==NULL)
    {
        perror("文件创建失败");
        return 1;
    }
    fprintf(file,"这是第一行文本\n");
    fputs("这是第二行文本\n",file);
    fclose(file);
    printf("文件创建和写入成功\n");
    //2.读取文件内容
    printf("===2.读取文件内容===\n");
    file=fopen(filename,"r");
    if(file==NULL)
    {
        perror("文件打开失败");
        return 1;
    }
    printf("文件内容\n");
    while(fgets(buffer,sizeof(buffer),file)!=NULL)
    {
        printf("%s",buffer);
    }
    fclose(file);
    //3.追加内容到文件"a"
    printf("\n===3.追加内容到文件===\n");
    file=fopen(filename,"a");
    if(file==NULL)
    {
        perror("文件打开失败");
        return 1;
    }
    fprintf(file,"这是追加的第三行文本\n");
    fclose(file);
    printf("内容追加成功\n");
    //4.再次读取显示更新后的内容
    printf("===4.更新后的文件内容===\n");
    file=fopen(filename,"r");
    if(file==NULL)
    {
        perror("打开文件失败");
        return 1;
    }
    while(fgets(buffer,sizeof(buffer),file)!=NULL)
    {
        printf("%s",buffer);
    }
    fclose(file);
    //5.二进制文件读写示例
    printf("\n===5.二进制文件操作===");
    FILE *binfile;
    int number[]={10,20,30,40,50};
    int readnumbers[5];
    //写入二进制文件
    binfile=fopen("data,bin","wb");
    if(binfile!=NULL)
    {
        fwrite(number,sizeof(int),5,binfile);
        fclose(binfile);
        printf("二进制写入文件成功\n");
    }
    //读取二进制文件
    binfile=fopen("data.bin","rb");
    if(binfile!=NULL)
    {
        fread(readnumbers,sizeof(int),5,binfile);
        fclose(binfile);
        printf("读取的数:\n");
        for(int i=0;i<5;i++)
        {
            printf("%d",readnumbers[i]);
        }
        printf("\n");
    }
    //6.文件位置操作示例
    printf("\n===6.文件位置操作示例===\n");
    file=fopen(filename,"r");
    if(file!=NULL)
    {
        fseek(file,0,SEEK_END);
        long filesize=ftell(file);
        rewind(file);
        printf("文件大小:%ld\n",filesize);
        //读取第一行
        fgets(buffer,sizeof(buffer),file);
        printf("第一行内容:%s",buffer);
        fclose(file);
    }
    return 0;
}