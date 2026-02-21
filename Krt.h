#pragma once

namespace krt {
    namespace product {
        /// @brief 检查当前产品是否为企业版本
        /// @return true 表示是企业版，false 表示不是企业版
        bool isEnterprise();

        /// @brief 检查当前产品是否为独立PDF版本
        /// @return true 表示是独立PDF版，false 表示不是独立PDF版
        bool IsPDFStandAloneVersion();
    } // namespace product
} // namespace krt
