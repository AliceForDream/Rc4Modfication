#if !defined(CRYPT_H__7620591F_C79B_BBA0_2AA3_B04C4A8A5DXX__INCLUDED_)
#define CRYPT_H__7620591F_C79B_BBA0_2AA3_B04C4A8A5DXX__INCLUDED_
class CCrypt
{
public:
	void Rc4_Init(char *key);
	void Rc4_Init(unsigned char *key, unsigned long Len);
	void Rc4_Crypt(char *Data);
	void Rc4_Crypt(unsigned char *Data, unsigned long Len);
	void Rc4m_Encrypt(char *Data);
	void Rc4m_Encrypt(unsigned char *Data, unsigned long Len);
	void Rc4m_Decrypt(unsigned char *Data, unsigned long Len);
private:
	unsigned char SBox[256];
};

#endif