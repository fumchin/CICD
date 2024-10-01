#include <CUnit/Basic.h>
#include "../src/main.h"

void test_add(void) {
    CU_ASSERT(add(5, 3) == 8);
    CU_ASSERT(add(-1, 1) == 0);
    CU_ASSERT(add(0, 0) == 0);
}

int main() {
        // 初始化 CUnit 測試的註冊表，用來跟踪測試套件和測試用例
    CU_initialize_registry();

    // 添加一個新的測試套件 "add_test_suite"，這個套件可以包含多個測試用例
    // 第一個參數是套件的名稱，第二、三個參數是初始化和清理函數（如果不需要，設為 0）
    CU_pSuite suite = CU_add_suite("add_test_suite", 0, 0);

    // 將測試函數 "test_add" 添加到套件中，這個測試用例將會測試 add() 函數
    CU_add_test(suite, "test of add()", test_add);

    // 設置 CUnit 的運行模式，這裡設置為 "CU_BRM_VERBOSE"，會打印出詳細的測試過程和結果
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // 執行所有的測試用例，包括剛剛添加到測試套件中的測試用例
    CU_basic_run_tests();

    // 清理測試註冊表，釋放內存
    CU_cleanup_registry();

    // 返回執行結果，如果所有測試通過則返回 0，否則返回非 0 值
    return CU_get_error();

}
