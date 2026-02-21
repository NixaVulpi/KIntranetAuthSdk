#pragma once

#include <QtCore/QList>
#include <QtCore/QString>
#include "IKIntranetAuthorize.h"

extern "C" {
    __declspec(dllexport) void GetSNPrivileges(QList<QString>& outList);
    __declspec(dllexport) IKIntranetAuthorize& _kintranetauthsdk_GetAuthObject();
}
