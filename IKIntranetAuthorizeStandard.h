#pragma once

#include "IKIntranetAuthorize.h"

struct IKIntranetAuthorizeStandard : virtual public IKIntranetAuthorize {
    virtual ~IKIntranetAuthorizeStandard() = default;

    // ========================================================================
    // [0..14] 继承自 IKIntranetAuthorize（虚继承）
    // ========================================================================

    // ========================================================================
    // [15..18] 普通版专用（override基类的[15-18]）
    // ========================================================================

    /// 获取授权时间范围
    /// @param param 参数（通常为0或功能ID）
    /// @param startTime 输出开始时间（Unix时间戳）
    /// @param endTime 输出结束时间（Unix时间戳）
    /// @return 0=成功, 3=错误
    virtual int GetTimeRange(int param, unsigned int* startTime, unsigned int* endTime) = 0;

    /// 检查授权状态
    /// @return true=已授权, false=未授权
    virtual bool CheckStatus() = 0;

    /// 获取默认字符串
    /// @param out 输出字符串
    /// @return 输出字符串指针
    virtual void* GetDefaultString(QString* out) = 0;

    /// 空函数（原版无实现）
    virtual void EmptyFunction() = 0;
};
