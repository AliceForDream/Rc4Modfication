#include "StdAfx.h"
#include "Crypt.h"
#include <string.h>


void CCrypt::Rc4_Init(char *key)
{
	Rc4_Init((unsigned char *)key,strlen(key));
}

void CCrypt::Rc4_Init(unsigned char *key, unsigned long Len)
{
	unsigned short i;
	unsigned char j = 0, k[256] = {0};
	unsigned char tmp = 0;
	for(i=0;i<256;i++)
	{
		SBox[i]=(unsigned char)i;
		k[i]=key[i%Len];
	}
	for (i=0; i<256; i++)
	{
		j=(j+SBox[i]+k[i]);
		tmp = SBox[i];
		SBox[i] = SBox[j];     
		SBox[j] = tmp;
	}
}
void CCrypt::Rc4_Crypt(char *Data)
{
	Rc4_Crypt((unsigned char *)Data,strlen(Data));
}

void CCrypt::Rc4_Crypt(unsigned char *Data, unsigned long Len)
{
	unsigned char x = 0, y = 0, t = 0;
	unsigned char tmp;
	unsigned long i;
	for(i=0;i<Len;i++)
	{
		x=(x+1);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t=(SBox[x]+SBox[y]);
		Data[i] ^= SBox[t];
	} 
}

void CCrypt::Rc4m_Encrypt(char *Data)
{
	Rc4m_Encrypt((unsigned char *)Data,strlen(Data));
}

void CCrypt::Rc4m_Encrypt(unsigned char *Data, unsigned long Len)
{
	unsigned char x = 0, y = 0, t = 0,t1=0,t2=0;
	unsigned char tmp,plain;
	unsigned long i;
	for(i=0;i<Len;i++)
	{
		x=(x+1);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t=(SBox[x]+SBox[y]);
		plain=Data[i];
		Data[i] ^= SBox[t];
		
		x=(x+Data[i]);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t1=(SBox[x]+SBox[y]);

		x=(x+plain);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t2=(SBox[x]+SBox[y]);

		tmp = SBox[t1];
		SBox[t1] = SBox[t2];     
		SBox[t2] = tmp;

	} 
}

void CCrypt::Rc4m_Decrypt(unsigned char *Data, unsigned long Len)
{
	unsigned char x = 0, y = 0, t = 0,t1=0,t2=0;
	unsigned char tmp,cipher;
	unsigned long i;
	for(i=0;i<Len;i++)
	{
		x=(x+1);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t=(SBox[x]+SBox[y]);
		cipher=Data[i];
		Data[i] ^= SBox[t];

		x=(x+cipher);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t1=(SBox[x]+SBox[y]);
		
		x=(x+Data[i]);
		y=(y+SBox[x]);
		tmp = SBox[x];
		SBox[x] = SBox[y];     
		SBox[y] = tmp;
		t2=(SBox[x]+SBox[y]);
		
		tmp =SBox[t1];
		SBox[t1] = SBox[t2];     
		SBox[t2] = tmp;
	} 
}
