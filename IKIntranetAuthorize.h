#pragma once

#include <QtCore/QString>

struct IKIntranetAuthorize {
    virtual bool __stdcall IsAuthorizedReady() = 0;
    virtual bool __stdcall IsActivated() = 0;
    virtual bool __stdcall RequestAuthorization(bool async) = 0;
    virtual bool __stdcall CheckFeatureExists(const wchar_t* feature) = 0;
    virtual bool __stdcall IsAuthorized(const wchar_t* feature, int reserved) = 0;
    virtual bool __stdcall IsAccountAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) = 0;
    virtual bool __stdcall IsSerialAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) = 0;
    virtual int __stdcall GetStatusCode() = 0;
    virtual QString* __stdcall GetLicenseInfo(QString* out) = 0;
    virtual bool __stdcall ProbeNetworkAuth() = 0;

    virtual char __stdcall AddListener(bool enable) = 0;
    virtual char __stdcall RemoveListener(void* listener) = 0;
    virtual int __stdcall DispatchEvent(void* eventStruct) = 0;
    virtual char __stdcall SendNetworkLog(void* logStruct) = 0;
    virtual QString* __stdcall GetVersionString(QString* out) = 0;

    virtual int __stdcall GetAuthorizedTimeRange(int featureId, time_t* startTime, time_t* endTime) = 0;
    virtual bool __stdcall RefreshAuthorization() = 0;
    virtual QString* __stdcall GetAccountInfo(QString* out) = 0;
    virtual void __stdcall VerifyAuthorization() = 0;
};
