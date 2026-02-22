#include <QtCore/QDateTime>
#include "Logger.h"
#include "KIntranetAuthorize.h"

// ============================================================================
// 构造/析构
// ============================================================================
KIntranetAuthorize::KIntranetAuthorize(QObject* parent) : QObject(parent) {
    Logger::instance().writer().stream() << "[AuthBypass] KIntranetAuthorize created.";
}

// ============================================================================
// [0..9] 核心授权功能实现
// ============================================================================
bool KIntranetAuthorize::IsAuthorizedReady() {
    Logger::instance().writer().stream() << "[AuthBypass] IsAuthorizedReady() => true";
    return true;
}

bool KIntranetAuthorize::IsActivated() {
    Logger::instance().writer().stream() << "[AuthBypass] IsActivated() => true";
    return true;
}

bool KIntranetAuthorize::RequestAuthorization(bool async) {
    Logger::instance().writer().stream() << "[AuthBypass] RequestAuthorization(Async = " << async << ") => true";
    return true;
}

bool KIntranetAuthorize::CheckFeatureExists(const wchar_t* feature) {
    QString featureStr = QString::fromWCharArray(feature);
    Logger::instance().writer().stream() << "[AuthBypass] CheckFeatureExists(Feature = " << featureStr << ") => true";
    return true;
}

bool KIntranetAuthorize::IsAuthorized(const wchar_t* feature, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    Logger::instance().writer().stream() << "[AuthBypass] IsAuthorized(Feature = " << featureStr << ") => true";
    return true;
}

bool KIntranetAuthorize::IsAccountAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    QString auth1Str = QString::fromWCharArray(auth1);
    QString auth2Str = QString::fromWCharArray(auth2);
    Logger::instance().writer().stream() << "[AuthBypass] IsAccountAuthorized(Feature = " << featureStr << ", Auth1 = " << auth1Str << ", Auth2 = " << auth2Str << ") => true";
    return true;
}

bool KIntranetAuthorize::IsSerialAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    QString auth1Str = QString::fromWCharArray(auth1);
    QString auth2Str = QString::fromWCharArray(auth2);
    Logger::instance().writer().stream() << "[AuthBypass] IsSerialAuthorized(Feature = " << featureStr << ", Auth1 = " << auth1Str << ", Auth2 = " << auth2Str << ") => true";
    return true;
}

int KIntranetAuthorize::GetStatusCode() {
    Logger::instance().writer().stream() << "[AuthBypass] GetStatusCode() => 2";
    return 2;
}

QString* KIntranetAuthorize::GetLicenseInfo(QString* out) {
    new (out) QString("WPS Premium License");
    Logger::instance().writer().stream() << "[AuthBypass] GetLicenseInfo() =>" << *out;
    return out;
}

bool KIntranetAuthorize::ProbeNetworkAuth() {
    Logger::instance().writer().stream() << "[AuthBypass] ProbeNetworkAuth() => true";
    return true;
}

// ============================================================================
// [10..14] 监听器和事件管理
// ============================================================================
char KIntranetAuthorize::AddListener(bool enable) {
    Logger::instance().writer().stream() << "[AuthBypass] AddListener(Enable = " << enable << ")";
    return 1;
}

char KIntranetAuthorize::RemoveListener(void* listener) {
    Logger::instance().writer().stream() << "[AuthBypass] RemoveListener(Listener = " << listener << ")";
    return 1;
}

int KIntranetAuthorize::DispatchEvent(void* eventStruct) {
    Logger::instance().writer().stream() << "[AuthBypass] DispatchEvent(EventStruct = " << eventStruct << ")";
    return 0;
}

char KIntranetAuthorize::SendNetworkLog(void* logStruct) {
    Logger::instance().writer().stream() << "[AuthBypass] SendNetworkLog() => suppressed";
    return 0;
}

QString* KIntranetAuthorize::GetVersionString(QString* out) {
    new (out) QString("11.1.0.15120 Premium");
    Logger::instance().writer().stream() << "[AuthBypass] GetVersionString() => " << *out;
    return out;
}

// ============================================================================
// [15..18] 专用实现
// ============================================================================
int KIntranetAuthorize::GetAuthorizedTimeRange(int featureId, time_t* startTime, time_t* endTime) {
    Logger::instance().writer().stream() << "[AuthBypass] GetAuthorizedTimeRange(FeatureId = " << featureId << ")";

    if (startTime && endTime) {
        *startTime = 0xFFFFFFFFull;
        *endTime = 0xFFFFFFFFull;
        return 0;
    }

    return 3;
}

bool KIntranetAuthorize::RefreshAuthorization() {
    Logger::instance().writer().stream() << "[AuthBypass] RefreshAuthorization() => true";
    return true;
}

QString* KIntranetAuthorize::GetAccountInfo(QString* out) {
    new (out) QString("Authorized Premium User");
    Logger::instance().writer().stream() << "[AuthBypass] GetAccountInfo() => " << *out;
    return out;
}

void KIntranetAuthorize::VerifyAuthorization() {
    Logger::instance().writer().stream() << "[AuthBypass] VerifyAuthorization()";
}
