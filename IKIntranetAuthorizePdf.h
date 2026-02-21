#pragma once

#include "IKIntranetAuthorize.h"

struct IKIntranetAuthorizePdf : virtual public IKIntranetAuthorize {
    virtual ~IKIntranetAuthorizePdf() = default;

    // ========================================================================
    // [0..14] 继承自 IKIntranetAuthorize（虚继承）
    // ========================================================================

    // ========================================================================
    // [15..18] PDF版专用（override基类的[15-18]）
    // ========================================================================

    /// 获取PDF授权时间范围（PDF专用）
    /// @param featureId 功能ID
    /// @param startTime 输出开始时间（Unix时间戳）
    /// @param endTime 输出结束时间（Unix时间戳）
    /// @return 0=成功
    virtual int GetAuthorizedTimeRange(int featureId, unsigned int* startTime, unsigned int* endTime) = 0;

    /// 刷新PDF授权状态
    /// @return true=刷新成功
    virtual bool RefreshAuthorization() = 0;

    /// 获取PDF账户信息
    /// @param out 输出字符串
    /// @return 输出字符串指针
    virtual void* GetAccountInfo(QString* out) = 0;

    /// 验证PDF授权
    virtual void VerifyAuthorization() = 0;
};
