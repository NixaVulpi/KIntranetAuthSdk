#include <QtCore/QDateTime>
#include "Logger.h"
#include "KIntranetAuthorizeStandard.h"

// ============================================================================
// 构造/析构
// ============================================================================
KIntranetAuthorizeStandard::KIntranetAuthorizeStandard(QObject* parent) : QObject(parent) {
    Logger::instance().writer().stream() << "[AuthBypass] KIntranetAuthorizeStandard created.";
}

// ============================================================================
// [0..9] 核心授权功能实现
// ============================================================================
bool KIntranetAuthorizeStandard::IsAuthorizedReady() {
    Logger::instance().writer().stream() << "[AuthBypass] IsAuthorizedReady(Standard) => true";
    return true;
}

bool KIntranetAuthorizeStandard::IsActivated() {
    Logger::instance().writer().stream() << "[AuthBypass] IsActivated(Standard) => true";
    return true;
}

bool KIntranetAuthorizeStandard::RequestAuthorization(bool async) {
    Logger::instance().writer().stream() << "[AuthBypass] RequestAuthorization(Standard, Async = " << async << ") => true";
    return true;
}

bool KIntranetAuthorizeStandard::CheckFeatureExists(const wchar_t* feature) {
    QString featureStr = QString::fromWCharArray(feature);
    Logger::instance().writer().stream() << "[AuthBypass] CheckFeatureExists(Standard, Feature = " << featureStr << ") => true";
    return true;
}

bool KIntranetAuthorizeStandard::IsAuthorized(const wchar_t* feature, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    Logger::instance().writer().stream() << "[AuthBypass] IsAuthorized(Standard, Feature = " << featureStr << ") => true";
    return true;
}

bool KIntranetAuthorizeStandard::IsAccountAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    QString auth1Str = QString::fromWCharArray(auth1);
    QString auth2Str = QString::fromWCharArray(auth2);
    Logger::instance().writer().stream() << "[AuthBypass] IsAccountAuthorized(Standard, Feature = " << featureStr << ", Auth1 = " << auth1Str << ", Auth2 = " << auth2Str << ") => true";
    return true;
}

bool KIntranetAuthorizeStandard::IsSerialAuthorized(const wchar_t* feature, const wchar_t* auth1, const wchar_t* auth2, int reserved) {
    QString featureStr = QString::fromWCharArray(feature);
    QString auth1Str = QString::fromWCharArray(auth1);
    QString auth2Str = QString::fromWCharArray(auth2);
    Logger::instance().writer().stream() << "[AuthBypass] IsSerialAuthorized(Standard, Feature = " << featureStr << ", Auth1 = " << auth1Str << ", Auth2 = " << auth2Str << ") => true";
    return true;
}

int KIntranetAuthorizeStandard::GetStatusCode() {
    Logger::instance().writer().stream() << "[AuthBypass] GetStatusCode(Standard) => 2";
    return 2;
}

QString* KIntranetAuthorizeStandard::GetLicenseInfo(QString* out) {
    new (out) QString(QStringLiteral("WPS Office Professional License"));
    Logger::instance().writer().stream() << "[AuthBypass] GetLicenseInfo(Standard) => " << *out;
    return out;
}

bool KIntranetAuthorizeStandard::ProbeNetworkAuth() {
    Logger::instance().writer().stream() << "[AuthBypass] ProbeNetworkAuth(Standard) => true";
    return true;
}

// ============================================================================
// [10..14] 监听器和事件管理
// ============================================================================
char KIntranetAuthorizeStandard::AddListener(bool enable) {
    Logger::instance().writer().stream() << "[AuthBypass] AddListener(Standard, Enable = " << enable << ")";
    return 1;
}

char KIntranetAuthorizeStandard::RemoveListener(void* listener) {
    Logger::instance().writer().stream() << "[AuthBypass] RemoveListener(Standard, Listener = " << listener << ")";
    return 1;
}

int KIntranetAuthorizeStandard::DispatchEvent(void* eventStruct) {
    Logger::instance().writer().stream() << "[AuthBypass] DispatchEvent(Standard, EventStruct = " << eventStruct << ")";
    return 0;
}

char KIntranetAuthorizeStandard::SendNetworkLog(void* logStruct) {
    Logger::instance().writer().stream() << "[AuthBypass] SendNetworkLog(Standard) => suppressed";
    return 0;
}

QString* KIntranetAuthorizeStandard::GetVersionString(QString* out) {
    new (out) QString(QStringLiteral("11.1.0.15120 Professional"));
    Logger::instance().writer().stream() << "[AuthBypass] GetVersionString(Standard) => " << *out;
    return out;
}

// ============================================================================
// [15..18] 扩展功能（普通版专用）
// ============================================================================
int KIntranetAuthorizeStandard::GetAuthorizedTimeRange(int param, time_t* startTime, time_t* endTime) {
    Logger::instance().writer().stream() << "[AuthBypass] GetAuthorizedTimeRange(Standard, Param = " << param << ")";

    if (startTime && endTime) {
        *startTime = 0xFFFFFFFFull;
        *endTime = 0xFFFFFFFFull;
        return 0;
    }

    return 3;
}

bool KIntranetAuthorizeStandard::RefreshAuthorization() {
    Logger::instance().writer().stream() << "[AuthBypass] RefreshAuthorization(Standard) => false";
    return true;
}

QString* KIntranetAuthorizeStandard::GetAccountInfo(QString* out) {
    new (out) QString(QStringLiteral("Authorized Standard Premium User"));
    Logger::instance().writer().stream() << "[AuthBypass] GetAccountInfo(Standard) => " << *out;
    return out;
}

void KIntranetAuthorizeStandard::VerifyAuthorization() {
    Logger::instance().writer().stream() << "[AuthBypass] VerifyAuthorization(Standard) [do nothing]";
}
