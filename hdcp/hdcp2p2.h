/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#pragma once
// AUTOGENERATED FILE: DO NOT EDIT

#include <linux/types.h>
#include "smcinvoke_object.h"

#define HDCP2P2_PROVISION_KEY 0
#define HDCP2P2_VERIFY_KEY 1
#define HDCP2P2_TX_INIT 2
#define HDCP2P2_TX_DEINIT 3
#define HDCP2P2_RCVD_MSG 4
#define HDCP2P2_SEND_TIMEOUT 5
#define HDCP2P2_SET_HW_KEY 6
#define HDCP2P2_QUERY_STREAM_TYPE 7
#define HDCP2P2_INIT 8
#define HDCP2P2_DEINIT 9
#define HDCP2P2_VERSION 10
#define HDCP2P2_SESSION_INIT 11
#define HDCP2P2_SESSION_DEINIT 12
#define HDCP2P2_START_AUTH 13
#define HDCP2P2_SESSION_OPEN_STREAM 14
#define HDCP2P2_SESSION_CLOSE_STREAM 15
#define HDCP2P2_FORCE_ENCRYPTION 16
#define HDCP2P2_DELETE_PAIRING_INFO 17

static inline int32_t hdcp2p2_release(struct Object self)
{
	return Object_invoke(self, Object_OP_release, 0, 0);
}

static inline int32_t hdcp2p2_retain(struct Object self)
{
	return Object_invoke(self, Object_OP_retain, 0, 0);
}

static inline int32_t hdcp2p2_provision_key(struct Object self, const void *key_ptr,
		 size_t key_len,
		 const void *dps_ptr,
		 size_t dps_len)
{
	union ObjectArg a[2] = {{{0, 0}}};

	a[0].bi = (struct ObjectBufIn) {key_ptr, key_len * 1};
	a[1].bi = (struct ObjectBufIn) {dps_ptr, dps_len * 1};

	return Object_invoke(self, HDCP2P2_PROVISION_KEY, a,
		 ObjectCounts_pack(2, 0, 0, 0));
}

static inline int32_t hdcp2p2_verify_key(struct Object self)
{
	return Object_invoke(self, HDCP2P2_VERIFY_KEY, 0, 0);
}

static inline int32_t hdcp2p2_tx_init(struct Object self, uint32_t sessionid_val,
		   uint32_t *ctxhandle_ptr)
{
	union ObjectArg a[2] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&sessionid_val, sizeof(uint32_t)};
	a[1].b = (struct ObjectBuf) {ctxhandle_ptr, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_TX_INIT, a,
						 ObjectCounts_pack(1, 1, 0, 0));
}

static inline int32_t hdcp2p2_tx_deinit(struct Object self, uint32_t ctxhandle_val)
{
	union ObjectArg a[1] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_TX_DEINIT, a,
		 ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t hdcp2p2_rcvd_msg(
	struct Object self, const void *reqMsg_ptr, size_t reqMsg_len,
	uint32_t ctxhandle_val, void *resMsg_ptr, size_t resMsg_len,
	size_t *resMsg_lenout, uint32_t *timeout_ptr, uint32_t *flag_ptr, uint32_t *state_ptr)
{
	union ObjectArg a[4] = {{{0, 0}}};
	int32_t result = 0;
	struct {
		uint32_t m_timeout;
		uint32_t m_flag;
		uint32_t m_state;
	} o = {0, 0, 0};
	a[2].b = (struct ObjectBuf) {&o, 12};
	a[0].bi = (struct ObjectBufIn) {reqMsg_ptr, reqMsg_len * 1};
	a[1].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};
	a[3].b = (struct ObjectBuf) {resMsg_ptr, resMsg_len * 1};

	result = Object_invoke(self, HDCP2P2_RCVD_MSG, a,
			ObjectCounts_pack(2, 2, 0, 0));

	*resMsg_lenout = a[3].b.size / 1;
	*timeout_ptr = o.m_timeout;
	*flag_ptr = o.m_flag;
	*state_ptr = o.m_state;

	return result;
}

static inline int32_t hdcp2p2_send_timeout(struct Object self, uint32_t ctxhandle_val,
		void *resMsg_ptr, size_t resMsg_len,
		size_t *resMsg_lenout,
		uint32_t *timeout_ptr)
{
	union ObjectArg a[3] = {{{0, 0}}};
	int32_t result = 0;

	a[0].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};
	a[1].b = (struct ObjectBuf) {resMsg_ptr, resMsg_len * 1};
	a[2].b = (struct ObjectBuf) {timeout_ptr, sizeof(uint32_t)};

	result = Object_invoke(self, HDCP2P2_SEND_TIMEOUT, a,
		   ObjectCounts_pack(1, 2, 0, 0));

	*resMsg_lenout = a[1].b.size / 1;

	return result;
}

static inline int32_t hdcp2p2_set_hw_key(struct Object self, uint32_t ctxhandle_val)
{
	union ObjectArg a[1] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_SET_HW_KEY, a,
		 ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t hdcp2p2_query_stream_type(
	struct Object self, uint32_t ctxhandle_val, void *resMsg_ptr, size_t resMsg_len,
	size_t *resMsg_lenout, uint32_t *timeout_ptr)
{
	union ObjectArg a[3] = {{{0, 0}}};
	int32_t result = 0;

	a[0].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};
	a[1].b = (struct ObjectBuf) {resMsg_ptr, resMsg_len * 1};
	a[2].b = (struct ObjectBuf) {timeout_ptr, sizeof(uint32_t)};

	result = Object_invoke(self, HDCP2P2_QUERY_STREAM_TYPE, a,
		   ObjectCounts_pack(1, 2, 0, 0));

	*resMsg_lenout = a[1].b.size / 1;

	return result;
}

static inline int32_t hdcp2p2_init(struct Object self, uint32_t clientVersion_val,
		uint32_t *appversion_ptr)
{
	union ObjectArg a[2] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&clientVersion_val, sizeof(uint32_t)};
	a[1].b = (struct ObjectBuf) {appversion_ptr, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_INIT, a,
						 ObjectCounts_pack(1, 1, 0, 0));
}

static inline int32_t hdcp2p2_deinit(struct Object self)
{
	return Object_invoke(self, HDCP2P2_DEINIT, 0, 0);
}

static inline int32_t hdcp2p2_version(struct Object self, uint32_t *appversion_ptr)
{
	union ObjectArg a[1] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {appversion_ptr, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_VERSION, a,
		 ObjectCounts_pack(0, 1, 0, 0));
}

static inline int32_t hdcp2p2_session_init(struct Object self, uint32_t deviceId_val,
		uint32_t *sessionId_ptr)
{
	union ObjectArg a[2] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&deviceId_val, sizeof(uint32_t)};
	a[1].b = (struct ObjectBuf) {sessionId_ptr, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_SESSION_INIT, a,
		 ObjectCounts_pack(1, 1, 0, 0));
}

static inline int32_t hdcp2p2_session_deinit(struct Object self,
		  uint32_t sessionId_val)
{
	union ObjectArg a[1] = {{{0, 0}}};

	a[0].b = (struct ObjectBuf) {&sessionId_val, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_SESSION_DEINIT, a,
		ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t hdcp2p2_start_auth(struct Object self, uint32_t ctxhandle_val,
		  void *resMsg_ptr, size_t resMsg_len,
		  size_t *resMsg_lenout,
		  uint32_t *timeout_ptr,
		  uint32_t *flag_ptr,
		  uint32_t *tzctxhandle_ptr)
{
	union ObjectArg a[3] = {{{0, 0}}};
	int32_t result = 0;
	struct {
		uint32_t m_timeout;
		uint32_t m_flag;
		uint32_t m_tzctxhandle;
	} o = {0, 0, 0};

	a[1].b = (struct ObjectBuf) {&o, 12};
	a[0].b = (struct ObjectBuf) {&ctxhandle_val, sizeof(uint32_t)};
	a[2].b = (struct ObjectBuf) {resMsg_ptr, resMsg_len * 1};

	result = Object_invoke(self, HDCP2P2_START_AUTH, a,
		   ObjectCounts_pack(1, 2, 0, 0));

	*resMsg_lenout = a[2].b.size / 1;
	*timeout_ptr = o.m_timeout;
	*flag_ptr = o.m_flag;
	*tzctxhandle_ptr = o.m_tzctxhandle;

	return result;
}

static inline int32_t hdcp2p2_session_open_stream(struct Object self,
		   uint32_t sessionid_val,
		   uint32_t vcpayloadid_val,
		   uint32_t stream_number_val,
		   uint32_t streamMediaType_val,
		   uint32_t *resStreamId_ptr)
{
	union ObjectArg a[2] = {{{0, 0}}};
	struct {
		uint32_t m_sessionid;
		uint32_t m_vcpayloadid;
		uint32_t m_stream_number;
		uint32_t m_streamMediaType;
	} i = {0, 0, 0, 0};

	a[0].b = (struct ObjectBuf) {&i, 16};
	i.m_sessionid = sessionid_val;
	i.m_vcpayloadid = vcpayloadid_val;
	i.m_stream_number = stream_number_val;
	i.m_streamMediaType = streamMediaType_val;
	a[1].b = (struct ObjectBuf) {resStreamId_ptr, sizeof(uint32_t)};

	return Object_invoke(self, HDCP2P2_SESSION_OPEN_STREAM, a,
		 ObjectCounts_pack(1, 1, 0, 0));
}

static inline int32_t hdcp2p2_session_close_stream(struct Object self,
		uint32_t sessionid_val,
		uint32_t streamId_val)
{
	union ObjectArg a[1] = {{{0, 0}}};
	struct {
		uint32_t m_sessionid;
		uint32_t m_streamId;
	} i = {0, 0};

	a[0].b = (struct ObjectBuf) {&i, 8};
	i.m_sessionid = sessionid_val;
	i.m_streamId = streamId_val;

	return Object_invoke(self, HDCP2P2_SESSION_CLOSE_STREAM, a,
		 ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t hdcp2p2_force_encryption(struct Object self,
		uint32_t ctxhandle_val,
		uint32_t enable_val)
{
	union ObjectArg a[1] = {{{0, 0}}};
	struct {
		uint32_t m_ctxhandle;
		uint32_t m_enable;
	} i = {0, 0};

	a[0].b = (struct ObjectBuf) {&i, 8};
	i.m_ctxhandle = ctxhandle_val;
	i.m_enable = enable_val;

	return Object_invoke(self, HDCP2P2_FORCE_ENCRYPTION, a,
		 ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t hdcp2p2_delete_pairing_info(struct Object self)
{
	return Object_invoke(self, HDCP2P2_DELETE_PAIRING_INFO, 0, 0);
}
