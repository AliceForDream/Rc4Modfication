// RC4MODY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include "Crypt.h"

int main(int argc, char* argv[])
{
	CCrypt MyEncrypt,MyDecrypt;
	char Key[]="testkey!";
	char PlainText[]="Hello world!";
	char PlainText2[]="This is another test!";
	char Mod[]="Hello world!";
	char Mod2[]="This is another test!";
	int len=strlen(PlainText);
	int len1=strlen(PlainText2);

	MyEncrypt.Rc4_Init(Key);
	MyEncrypt.Rc4_Crypt(PlainText);
	printf("RC4 Result:");
	for (int i=0;i<len;i++)
	{
		printf("%02x",(unsigned char)PlainText[i]);
		Mod[i]^=PlainText[i];
	}
	printf("\n");
	MyDecrypt.Rc4_Init(Key);
	MyDecrypt.Rc4_Crypt((unsigned char *)PlainText,len);
	printf("Decrypt result:%s\n",PlainText);
	printf("Random Data:");
	for (i=0;i<len;i++)
	{
		printf("%02x",(unsigned char)Mod[i]);
		Mod[i]=PlainText[i];
	}
	printf("\n\n");

	MyEncrypt.Rc4_Init(Key);
	MyEncrypt.Rc4m_Encrypt(PlainText);
	printf("RC4m Result:");
	for (i=0;i<len;i++)
	{
		printf("%02x",(unsigned char)PlainText[i]);
		Mod[i]^=PlainText[i];
	}
	printf("\n");
	MyDecrypt.Rc4_Init(Key);
	MyDecrypt.Rc4m_Decrypt((unsigned char *)PlainText,len);
	printf("Decrypt result:%s\n",PlainText);
	printf("Random Data:");
	for (i=0;i<len;i++)
		printf("%02x",(unsigned char)Mod[i]);
	printf("\n\n");
	

	MyEncrypt.Rc4_Init(Key);
	MyEncrypt.Rc4_Crypt(PlainText2);
	printf("RC4 Result:");
	for (i=0;i<len1;i++)
	{
		printf("%02x",(unsigned char)PlainText2[i]);
		Mod2[i]^=PlainText2[i];
	}
	printf("\n");
	MyDecrypt.Rc4_Init(Key);
	MyDecrypt.Rc4_Crypt((unsigned char *)PlainText2,len1);
	printf("Decrypt result:%s\n",PlainText2);
	printf("Random Data:");
	for (i=0;i<len1;i++)
	{
		printf("%02x",(unsigned char)Mod2[i]);
		Mod2[i]=PlainText2[i];
	}
	printf("\n\n");

	MyEncrypt.Rc4_Init(Key);
	MyEncrypt.Rc4m_Encrypt(PlainText2);
	printf("RC4m Result:");
	for (i=0;i<len1;i++)
	{
		printf("%02x",(unsigned char)PlainText2[i]);
		Mod2[i]^=PlainText2[i];
	}
	printf("\n");
	MyDecrypt.Rc4_Init(Key);
	MyDecrypt.Rc4m_Decrypt((unsigned char *)PlainText2,len1);
	printf("Decrypt result:%s\n",PlainText2);
	printf("Random Data:");
	for (i=0;i<len1;i++)
		printf("%02x",(unsigned char)Mod2[i]);
	printf("\n");
	return 0;
}

