#include <Windows.h>
#include "Logger.h"

BOOL APIENTRY DllMain(HMODULE module, DWORD reasonForCall, LPVOID reserved) {
    switch (reasonForCall) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(module);
            Logger::instance().writer().stream() << "[AuthBypass] DLL Loaded - Process ID: " << GetCurrentProcessId();
            break;
        case DLL_PROCESS_DETACH:
            Logger::instance().writer().stream() << "[AuthBypass] DLL Unloaded";
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
