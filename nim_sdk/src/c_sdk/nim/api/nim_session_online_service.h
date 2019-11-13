/** @file nim_session_online_service.h
  * @brief �Ự����online �ӿ�ͷ�ļ�
  * @copyright (c) 2015-2019, NetEase Inc. All rights reserved
  * @author cqu227hk
  * @date 2019/10/21
  */
#ifndef NIM_SDK_DLL_API_NIM_SESSION_ONLINE_SERVICE_H_
#define NIM_SDK_DLL_API_NIM_SESSION_ONLINE_SERVICE_H_

#include "public_define/defines/nim_sdk_dll.h"
#include "public_define/defines/nim_define/nim_session_online_service_def.h"

#ifdef __cplusplus
extern"C"
{
#endif
	/** @fn void nim_session_online_service_query_session_list(uint64_t min_time,uint64_t max_time,bool need_last_msg,int limit,nim_session_online_service_query_session_list_cb_func cb, const void *user_data);
	  * �Ự���� ��ѯ�Ự�б�
	  * @param[in] min_time ��Сʱ���,δ֪������0,��ʾ������ʱ��
	  * @param[in] max_time ���ʱ���,δ֪������0,��ʾ�ӵ�ǰʱ��
	  * @param[in] need_last_msg �Ƿ���ҪlastMsg��Ĭ��true
	  * @param[in] limit �����limit�����100��ȱʡֵ100
	  * @param[in] cb ����ص�  �ɲ鿴nim_session_online_service_query_session_list_cb_func����
	  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
	  * @return void �޷���ֵ
	  */
	NIM_SDK_DLL_API void nim_session_online_service_query_session_list(uint64_t min_time,uint64_t max_time,bool need_last_msg,int limit,nim_session_online_service_query_session_list_cb_func cb, const void *user_data);

	/** @fn void nim_session_online_service_query_session(int to_type,char* session_id, nim_session_online_service_query_session_cb_func cb, const void *user_data)
	  * �Ự���� ��ѯ�Ự
	  * @param[in] to_type �Ự����
	  * @param[in] session_id �ỰID
	  * @param[in] cb ����ص�  �ɲ鿴nim_session_online_service_query_session_cb_func����
	  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
	  * @return void �޷���ֵ
	  */
	NIM_SDK_DLL_API void nim_session_online_service_query_session(int to_type,char* session_id, nim_session_online_service_query_session_cb_func cb, const void *user_data);

	/** @fn void nim_session_online_service_update_session(int to_type, char* session_id, char* ext, nim_session_online_service_update_session_cb_func cb, const void *user_data)
	  * �Ự���� ���»Ự
	  * @param[in] to_type �Ự����
	  * @param[in] session_id �ỰID
	  * @param[in] ext ��չ�ֶ�
	  * @param[in] cb ����ص�  �ɲ鿴nim_session_online_service_update_session_cb_func����
	  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
	  * @return void �޷���ֵ
	  */
	NIM_SDK_DLL_API void nim_session_online_service_update_session(int to_type, char* session_id, char* ext, nim_session_online_service_update_session_cb_func cb, const void *user_data);

	/** @fn void nim_session_online_service_delete_session(char* session_list, nim_session_online_service_delete_session_cb_func cb, const void *user_data)
	  * �Ự���� ɾ���Ự
	  * @param[in] session_list Ҫɾ���ĻỰ�б� json array
	  * @param[in] cb ����ص�  �ɲ鿴nim_session_online_service_delete_session_cb_func����
	  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
	  * @return void �޷���ֵ
	  */
	NIM_SDK_DLL_API void nim_session_online_service_delete_session(char* session_list, nim_session_online_service_delete_session_cb_func cb, const void *user_data);

	/** @fn void nim_session_online_service_reg_session_changed(nim_session_online_service_session_changed_cb_func cb, const void *user_data)
	  * �Ự���� ע��Ự����ص�
	  * @param[in] cb ����ص�  �ɲ鿴nim_session_online_service_session_changed_cb_func����
	  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
	  * @return void �޷���ֵ
	  */
	NIM_SDK_DLL_API void nim_session_online_service_reg_session_changed(nim_session_online_service_session_changed_cb_func cb, const void *user_data);

	
#ifdef __cplusplus
};
#endif //__cplusplus

#endif //NIM_SDK_DLL_API_NIM_DATA_SYNC_H_
