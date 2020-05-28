﻿/** @file nim_tools_http_def.h
* @brief NIM HTTP提供的http传输相关接口的定义
* @copyright (c) 2015-2016, NetEase Inc. All rights reserved
* @author towik, Oleg
* @date 2015/4/30
*/
#ifndef NIM_TOOLS_HTTP_DEF_H
#define NIM_TOOLS_HTTP_DEF_H
#ifdef __cplusplus
extern"C"
{
#endif

/** @enum NIMProxyType 代理类型 */
enum NIMProxyType
{
	kNIMProxyNone		= 0,	/**< 不使用代理*/
	kNIMProxyHttp11		= 1,	/**< HTTP 1.1 Proxy*/
	kNIMProxySocks4		= 4,	/**< Socks4 Proxy*/
	kNIMProxySocks4a	= 5,	/**< Socks4a Proxy*/
	kNIMProxySocks5		= 6,	/**< Socks5 Proxy*/
    kNIMProxySocks5HostName = 7,	/**< Socks5 host name Proxy*/
};

/** @typedef void* HttpRequestHandle
  * http任务句柄
  */
typedef void* HttpRequestHandle;
#define INVALID_HTTPREQUESTHANDLE (0)
/** @typedef int HttpRequestID
* http任务ID，当请求发送后会生成此ID，取消任务或读取应答头都使用该ID
*/
typedef int HttpRequestID;
#define INVALID_HTTPREQUESTID (0xFFFFFFFF)
/** @typedef void (*nim_http_request_completed_cb)(const void *user_data, bool, int)
  * nim callback function that has been registered in nim_http_create_*** API
  * @param[out] user_data		回传的自定义数据
  * @param[out] result			传输结果，true代表传输成功，false代表传输失败
  * @param[out] response_code	http响应码
  * @return void				无返回值
  */
typedef void (*nim_http_request_completed_cb)(const void *user_data, bool result, int response_code);

/** @typedef void (*nim_http_request_response_cb)(const void *user_data, bool result, int response_code, const char *response_content)
  * nim callback function that has been registered in nim_http_create_*** API
  * @param[out] user_data			回传的自定义数据
  * @param[out] result				传输结果，true代表传输成功，false代表传输失败
  * @param[out] response_code		http响应码
  * @param[out] response_content	http响应实体内容
  * @return void					无返回值
  */
typedef void (*nim_http_request_response_cb)(const void *user_data, bool result, int response_code, const char *response_content);

/** @typedef void (*nim_http_request_response_ex_cb)(const void *user_data, bool result, int response_code, const char *response_content, const char *response_header)
  * nim callback function that has been registered in nim_http_create_*** API
  * @param[out] user_data			回传的自定义数据
  * @param[out] result				传输结果，true代表传输成功，false代表传输失败
  * @param[out] response_code		http响应码
  * @param[out] response_content	http响应实体内容
  * @param[out] response_header	    http响应头
  * @return void					无返回值
  */
typedef void(*nim_http_request_response_ex_cb)(const void *user_data, bool result, int response_code, const char *response_content, const char *response_header);

/** @typedef void (*nim_http_request_progress_cb)(const void* user_data, double total_upload_size, double uploaded_size, double total_download_size, double downloaded_size)
  * nim callback function that has been registered in nim_http_set_request_progress_cb API
  * @param[out] user_data				回传的自定义数据
  * @param[out] total_upload_size		总的待上传的字节数
  * @param[out] uploaded_size			已经上传的字节数
  * @param[out] total_download_size		总的待下载的字节数
  * @param[out] downloaded_size			已经下载的字节数
  * @return void						无返回值
  */
typedef void(*nim_http_request_progress_cb)(const void *user_data, double total_upload_size, double uploaded_size, double total_download_size, double downloaded_size);

/** @typedef void (*nim_http_request_transfer_cb)(const void *user_data, double total_upload_size, double uploaded_size, double total_download_size, double downloaded_size)
  * nim callback function that has been registered in nim_http_set_request_transfer_cb API
  * @param[out] user_data				回传的自定义数据
  * @param[out] actual_upload_size		实际上传的字节数
  * @param[out] upload_speed			平均上传速度（字节每秒）
  * @param[out] actual_download_size	实际下载的字节数
  * @param[out] download_speed			平均下载速度（字节每秒）
  * @return void						无返回值
  */
typedef void(*nim_http_request_transfer_cb)(const void *user_data, double actual_upload_size, double upload_speed, double actual_download_size, double download_speed);

/** @typedef void (*nim_http_request_speed_cb)(const void *user_data, double, double)
  * nim callback function that has been registered in nim_http_set_request_speed_cb API
  * @param[out] user_data		回传的自定义数据
  * @param[out] upload_speed	实时上传速度（字节每秒）
  * @param[out] download_speed	实时下载速度（字节每秒）
  * @return void				无返回值
  */
typedef void(*nim_http_request_speed_cb)(const void *user_data, double upload_speed, double download_speed);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif//NIM_TOOLS_HTTP_DEF_H
