// MedicSet.h : CMedicSet ������

#pragma once

// ���������� 2020��3��1��, 11:35

class CMedicSet : public CRecordset
{
public:
	CMedicSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMedicSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CString	m_id;
	CString	m_name;
	CString	m_classification;
	CTime	m_produceDate;
	CString	m_producePlace;
	CString	m_discription;
	CString	m_produceCompany;
	long	m_quelityAssurance;
	long	m_unitPrice;
	long	m_number;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


