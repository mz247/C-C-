
#import"c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")
#include <icrsint.h>
#include<iostream>
using namespace std;


_ConnectionPtr m_pConnection = NULL;
_RecordsetPtr m_pRecordset = NULL;

//连接SQL
void Connect()
  {
	  try{
		  ::CoInitialize(NULL);  //初始化COM环境
		  m_pConnection.CreateInstance(__uuidof(Connection));  //创建连接对象
		  //通过DSN数据源对任何支持ODBC的数据库进行连接
		  //m_pConnection->ConnectionString="Provider=SQLOLEDB.1; Persist Security Info=True; User ID=sa; Password=a1!; Initial Catalog=InTouch; Data Source=WIN-P6OLLUM9PDM"; //请将数据库相应ID与Password更改
          //不通过DSN对SQL SERVER数据库进行连接
		  m_pConnection->ConnectionString="driver={SQL Server};Server=127.0.0.1;DATABASE=InTouch;UID=sa;PWD=a1!";
		  //连接服务器和数据库
          HRESULT hr=m_pConnection->Open("", "", "", 0);
		  if(hr!=S_OK)
			    cout<<"Can not connect to the specified database!"<<endl;

	  }
	  catch(_com_error e){

		  cout<<e.Description()<<endl;
	  }
          
}
//断开连接
void ExitConnect(void)
{
	if(m_pRecordset!=NULL){
		m_pRecordset->Close();
		m_pConnection->Close();
	}
	::CoUninitialize();  //释放环境
}

_RecordsetPtr& GetRecordset(_bstr_t SQL)
{
	m_pRecordset=NULL;
	try{
		if(m_pConnection==NULL)
			//连接
			Connect();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open((_bstr_t)SQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e){
		cout<<e.Description()<<endl;
        m_pRecordset=NULL;
        return m_pRecordset;
	}
	return m_pRecordset;
}
   void main()
  {
	  string sql;
      _RecordsetPtr m_pRecordset;
      sql="select * from testDB";
      _bstr_t bstr_t(sql.c_str());
      m_pRecordset= GetRecordset(bstr_t);
      m_pRecordset->AddNew();
      m_pRecordset->PutCollect("ID", _variant_t("3"));
      m_pRecordset->PutCollect("Name", _variant_t("edward"));
      m_pRecordset->PutCollect("Age", _variant_t("18"));
      m_pRecordset->Update();
	  cout<<"添加成功"<<endl;
      ExitConnect();
  }