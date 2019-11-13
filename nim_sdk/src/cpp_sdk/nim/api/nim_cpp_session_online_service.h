/** @file nim_cpp_session_online_service.h
  * @brief �Ự����
  * @copyright (c) 2015-2019, NetEase Inc. All rights reserved
  * @date 2019/10/22
  */

#ifndef _NIM_CPP_SESSION_ONLINE_SERVICE_H_
#define _NIM_CPP_SESSION_ONLINE_SERVICE_H_

#include <string>
#include <functional>
#include "src/cpp_sdk/nim/helper/nim_session_online_service_helper.h"
#include "src/cpp_sdk/nim/nim_sdk_cpp_wrapper_dll.h"
  /**
  * @namespace nim
  * @brief namespace nim
  */
namespace nim
{
	class NIM_SDK_CPPWRAPPER_DLL_API SessionOnLineService
	{
	public:
		typedef std::function<void(nim::NIMResCode, const SessionOnLineServiceHelper::SessionInfo&)> QuerySessionInfoCallback;	/**< ��ѯ�Ự�ص�ģ�� */
		typedef std::function<void(const SessionOnLineServiceHelper::QureySessionListResult&)> QuerySessionListCallabck;		/**< ��ѯ�Ự�б�ص�ģ�� */
		typedef std::function<void(nim::NIMResCode)> UpdateSessionInfoCallback;	/**< ���»Ự�ص�ģ�� */
		typedef std::function<void(nim::NIMResCode)> DeleteSessionInfoCallback;	/**< ɾ���Ự�ص�ģ�� */
		typedef std::function<void(const SessionOnLineServiceHelper::SessionInfo&)> SessionChangedCallback;	/**< �Ự����ص�ģ�� */

		/** @fn static void QuerySessionList(uint64_t min_time, uint64_t max_time, bool need_last_msg, int limit, const QuerySessionListCallabck& cb)
	  * �Ự���� ��ѯ�Ự�б�
	  * @param[in] min_time ��Сʱ���,δ֪������0,��ʾ������ʱ��
	  * @param[in] max_time ���ʱ���,δ֪������0,��ʾ�ӵ�ǰʱ��
	  * @param[in] need_last_msg �Ƿ���Ҫ����lastMsg��Ĭ��true
	  * @param[in] limit �����limit�����100��ȱʡֵ100
	  * @param[in] cb ����ص�  �ɲ鿴QuerySessionListCallabck����
	  * @return void �޷���ֵ
	  */
		static void QuerySessionList(uint64_t min_time, uint64_t max_time, bool need_last_msg, int limit, const QuerySessionListCallabck& cb);

		/** @fn static void QuerySession(nim::NIMSessionType to_type, const std::string& session_id, const QuerySessionInfoCallback& cb)
		  * �Ự���� ��ѯ�Ự
		  * @param[in] to_type �Ự����
		  * @param[in] session_id �ỰID
		  * @param[in] cb ����ص�  �ɲ鿴QuerySessionInfoCallback����
		  * @return void �޷���ֵ
		  */
		static void QuerySession(nim::NIMSessionType to_type, const std::string& session_id, const QuerySessionInfoCallback& cb);

		/** @fn static void UpdateSession(nim::NIMSessionType to_type, const std::string& session_id, const std::string& ext, const UpdateSessionInfoCallback& cb)
		  * �Ự���� ���»Ự
		  * @param[in] to_type �Ự����
		  * @param[in] session_id �ỰID
		  * @param[in] ext �Ự����չ�ֶ�
		  * @param[in] cb ����ص�  �ɲ鿴UpdateSessionInfoCallback����
		  * @return void �޷���ֵ
		  */
		static void UpdateSession(nim::NIMSessionType to_type, const std::string& session_id, const std::string& ext, const UpdateSessionInfoCallback& cb);

		/** @fn static void DeleteSession(const DeleteSessionParam& param, const DeleteSessionInfoCallback& cb)
		  * �Ự���� ɾ���Ự
		  * @param[in] param Ҫɾ���ĻỰ��
		  * @param[in] cb ����ص�  �ɲ鿴DeleteSessionInfoCallback����
		  * @param[in] user_data APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
		  * @return void �޷���ֵ
		  */
		static void DeleteSession(const SessionOnLineServiceHelper::DeleteSessionParam& param, const DeleteSessionInfoCallback& cb);

		/** @fn static void RegSessionChanged(const SessionChangedCallback& cb)
		  * �Ự���� ע��Ự����ص�
		  * @param[in] cb ����ص�  �ɲ鿴SessionChangedCallback����
		  * @return void �޷���ֵ
		  */
		static void RegSessionChanged(const SessionChangedCallback& cb);

		/** @fn void UnregSessionOnLineServiceCb()
		* ��ע�� SessionOnLineService ���лص�
		* @return void �޷���ֵ
		*/
		static void UnregSessionOnLineServiceCb();
	};
};
#endif//_NIM_CPP_SESSION_ONLINE_SERVICE_H_