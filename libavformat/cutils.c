#include "avformat.h"

// strstart ʵ�ʵĹ��ܾ�����str�ַ���������val �ַ���ָʾ��ͷ������ȥ��ͷ����*ptr ���ء�
// �ڱ����У��ڲ������ļ�ʱ��������������ʱ���ܻ����ļ�·����ǰ��ǰ׺"file:", 
// Ϊ����ϵͳ��open��������Ҫ���⼸��ǰ���ַ�ȥ������������������Ч���ļ�·������
int strstart(const char *str, const char *val, const char **ptr)
{
    const char *p, *q;
    p = str;
    q = val;
    while (*q != '\0')
    {
	if (*p != *q)
	    return 0;
	p++;
	q++;
    }
    if (ptr)
	*ptr = p;
    return 1;
}

// �ַ��������������������ַ�����buf_size ָ��������ȫ���ַ�������������
void pstrcpy(char *buf, int buf_size, const char *str)
{
    int c;
    char *q = buf;

    if (buf_size <= 0)
	return;

    for (;;)
    {
	c = *str++;
	if (c == 0 || q >= buf + buf_size - 1)
	    break;
	*q++ = c;
    }
    *q = '\0';
}