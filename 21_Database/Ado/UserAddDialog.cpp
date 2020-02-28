// UserAddDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "Ado.h"
#include "UserAddDialog.h"
#include "afxdialogex.h"
#include "AdoView.h"
// UserAddDialog 对话框

IMPLEMENT_DYNAMIC(UserAddDialog, CDialogEx)

UserAddDialog::UserAddDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_USER, pParent)
	, m_name(_T(""))
	, m_age(0)
	, m_score(0)
{

}

UserAddDialog::~UserAddDialog()
{
}

void UserAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
}


BEGIN_MESSAGE_MAP(UserAddDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &UserAddDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &UserAddDialog::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// UserAddDialog 消息处理程序

//添加用户
void UserAddDialog::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
	if (m_name.IsEmpty() || m_age == 0 || m_score < 0)
	{
		AfxMessageBox(_T("存在校验未通过项目"));
		return;
	}
	SaveStudentInfo();
}


void UserAddDialog::SaveStudentInfo()
{

# if region test
	//*1、定义_ConnectionPtr对象
//2、创建_ConnectionPtr对象
//3、连接数据库
//4、定义_CommandPtr变量
//5、创建Command对象 CreateInstance
//6、创建并添加参数
//7、执行修改
//8、判断是否修改成功
//9、关闭数据库
#endif

	_CommandPtr pCommand;
	pCommand.CreateInstance(__uuidof(Command));
	pCommand->ActiveConnection = m_connection;
	pCommand->CommandTimeout = 5;
	pCommand->CommandText = "insert into student ([name],[age],[score]) values (?,?,?)";

	//创建参数
	_ParameterPtr p1 = pCommand->CreateParameter(_bstr_t("name"), adBSTR, adParamInput, m_name.GetLength(), _variant_t(m_name));
	_ParameterPtr p2 = pCommand->CreateParameter(_bstr_t("age"), adInteger, adParamInput, sizeof(m_age), _variant_t(m_age));
	_ParameterPtr p3 = pCommand->CreateParameter(_bstr_t("score"), adInteger, adParamInput, sizeof(m_score), _variant_t(m_score));

	//添加参数
	pCommand->Parameters->Append(p1);
	pCommand->Parameters->Append(p2);
	pCommand->Parameters->Append(p3);

	_variant_t _v;
	//执行语句
	pCommand->Execute(&_v,NULL,adCmdText);
	if (_v.intVal == 1)
	{
		m_name.Empty();
		m_age = 0;
		m_score = 0;
		UpdateData(FALSE);
		AfxMessageBox(_T("添加成功"));
	}
	else
	{
		AfxMessageBox(_T("添加失败"));
	}
}

void UserAddDialog::OnBnClickedButtonClose()
{
	/*CAdoView* mainView = (CAdoView*)AfxGetMainWnd();
	mainView->OnBnClickedButtonQuery();*/
	CDialogEx::OnOK();
}


BOOL UserAddDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetWindowText(_T("添加用户"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void UserAddDialog::SetConnection(_ConnectionPtr connection)
{
	this->m_connection = connection;
}
