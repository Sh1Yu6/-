
// keymngserverop_lisi.h

#pragma once 

#include "keymng_msg.h"
#include "keymngserverabsop.h"


//ҵ������ ����
class  KeyMngServerOp_LiSi : public KeyMngServerAbsOp  
{
public:
	//��ʼ�������� ȫ�ֱ���
	virtual int MngServer_InitInfo(MngServer_Info *svrInfo);
	
	
	
	//����� ��ԿЭ��Ӧ������
	virtual int MngServer_Agree(MngServer_Info *svrInfo, MsgKey_Req *msgkeyReq, unsigned char **outData, int *datalen);
	//int keymngserver_agree(MngServer_Info  *pmngServerInfo,   MsgKey_Req *pMsgKeyReq ,  unsigned char **pMsgKey_ResData, int *iMsgKey_ResDataLen);
	

	virtual int MngServer_Check(MngServer_Info *svrInfo, MsgKey_Req *msgkeyReq, unsigned char **outData, int *datalen);
	
	virtual int MngServer_Revoke(MngServer_Info *svrInfo, MsgKey_Req *msgkeyReq, unsigned char **outData, int *datalen);
	
	virtual int MngServer_view(MngServer_Info *svrInfo, MsgKey_Req *msgkeyReq, unsigned char **outData, int *datalen);
	
	virtual int MngServer_Quit(MngServer_Info *svrInfo, MsgKey_Req *msgkeyReq, unsigned char **outData, int *datalen);
	
};






