

#include <locale.h>
#include <iostream>
#include <string>
#include <conio.h>	//������ȡ
#include "..\..\ͼ��ʶ��\ͼ��ʶ��\loc.h"	//����λ��

#include "..\CnComm.h"	//Com��h��
using namespace std;


//! ��������0
class HelloComm : public CnComm
{	//! \sa CnComm::OnReceive()
	void OnReceive()
	{
		TCHAR buffer[1024];
		setlocale(LC_ALL, "chs");// Unicode��������ʾ���� ����һ�� CBC ��֧�� "chs"
		_tprintf(_T("\nRecv:%s\n"), ReadString(buffer, 1024));
	}
};
//! Main()  COM1 ---�ַ���----> COM4 (������9600)
int main()
{
	HelloComm Com;//! Ĭ��ģʽ �ص�IO �����߳�
	int CP = 6;	//COM��
	Com.Open(CP, 9600);

	std::cout << "Com:" << CP <<"�Ѵ�"<< std::endl;
	system("pause");//��ͣ
	while (1) {
		/*
		 *��char[]��arduino
		 *�����ʽ��("ˮƽ�Ƕ�","��ֱ�Ƕ�","ˮ������","У��λ(ǰ����֮��)") 
		 */
		string str ;
		cout << endl << endl;
		str =to_string(Fx)		+ ","
			+ to_string(Fy)		+ ","
			+ to_string(Pump)	+ ","
			+ to_string(CE)		;


		cout<<"�������"<<str << endl;
		char c[20];
		const char *c_str();
		strcpy_s(c,str.c_str());

	
		if (_kbhit()) {if (_getch() == 27) { break; }}		//��סesc�˳�
		
		Com.Write(_T(c));
		
		Sleep(1000);
		
	}
	cout << "Com:" << CP << "�����ر�" <<endl;
	system("pause");//��ͣ

	return 0;
}

