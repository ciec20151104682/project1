#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
	char*str;
	char date[20];
	char time[20];
	char lat[20];
	char lon[20];
	str=(char*)malloc(sizeof(char));
	FILE*fp1=fopen("C:\\Users\\gx\\Desktop\\软件\\export.gpx","r");
	FILE*fp2=fopen("C:\\Users\\gx\\Desktop\\软件\\ch.csv","w");
	int i=0,n,j=1;
	if(fp1==NULL)
	{
		printf("wrong!");
		return-1;
	}	
	else
	{
		fseek(fp1,SEEK_SET,SEEK_END);
	    n=ftell(fp1);
	    fseek(fp1,0,SEEK_SET);
	    str=new char[n+1];
	    fread(str,sizeof(char),n,fp1);
	    str[n]='\0';
	}
	fprintf(fp2,"number,lat,lon,date,time\n");
	while(!(str[i]=='<'&&str[i+1]=='/'&&str[i+2]=='t'&&str[i+3]=='r'&&str[i+4]=='k'&&str[i+5]=='s'&&str[i+6]=='e'&&str[i+7]=='g'&&str[i+8]=='>'))
	{
		if(str[i]==' '&&str[i+1]=='l'&&str[i+2]=='a'&&str[i+3]=='t')
		{
			strncpy(lat,&str[i+6],9);
		    strncpy(lon,&str[i+22],10);
		    strncpy(date,&str[i+44],10);
		    strncpy(time,&str[i+55],8);
		    lat[9]='\0';
		    lon[10]='\0';
		    date[10]='\0';
		    time[8]='\0';
		    printf("%s %s %s %s\n",lat,lon,date,time);
		    fprintf(fp2,"%d,%s,%s,%s,%s\n",j,lat,lon,date,time); 
		    j++;
		}
		i++;	
	}	
	fclose(fp1);
	fclose(fp2);
	free(str);
	return 0;
}
