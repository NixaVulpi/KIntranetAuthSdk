#pragma once

#include <QtCore/QObject>
#include "IKIntranetAuthorize.h"

class KIntranetAuthorizeStandard : public QObject, public IKIntranetAuthorize {
    Q_OBJECT
public:
    explicit KIntranetAuthorizeStandard(QObject* parent = nullptr);
    // ========================================================================
    // IKIntranetAuthorize 接口实现
    // ========================================================================
    // [0..9] 核心授权功能
    bool __stdcall IsAuthorizedReady() override;
    bool __stdcall IsActivated() override;
    bool __stdcall RequestAuthorization(bool async) override;
    bool __stdcall CheckFeatureExists(const wchar_t* feature) override;
    bool __stdcall IsAuthorized(const wchar_t* feature, int reserved) override;
    bool __stdcall IsAccountAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) override;
    bool __stdcall IsSerialAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) override;
    int __stdcall GetStatusCode() override;
    QString* __stdcall GetLicenseInfo(QString* out) override;
    bool __stdcall ProbeNetworkAuth() override;
    // [10..14] 监听器和事件管理
    char __stdcall AddListener(bool enable) override;
    char __stdcall RemoveListener(void* listener) override;
    int __stdcall DispatchEvent(void* eventStruct) override;
    char __stdcall SendNetworkLog(void* logStruct) override;
    QString* __stdcall GetVersionString(QString* out) override;
    // [15..18] 扩展功能
    int __stdcall GetAuthorizedTimeRange(int param, time_t* startTime, time_t* endTime) override;
    bool __stdcall RefreshAuthorization() override;
    QString* __stdcall GetAccountInfo(QString* out) override;
    void __stdcall VerifyAuthorization() override;
};
