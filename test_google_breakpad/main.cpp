#include <exception_handler.h>
#include <iostream>

using namespace std;

bool dumpProcessor(const wchar_t* path,
    const wchar_t* minidumpID,
    void* context,
    EXCEPTION_POINTERS* exinfo,
    MDRawAssertionInfo* assertion,
    bool succeeded)
{

#ifdef _WIN32
    //MessageBox(NULL, TEXT("抱歉智慧课堂崩溃了，请联系技术支持人员"), TEXT("崩溃提示"), 0);
    cout << "崩溃了" << endl;
#endif // _WIN32

    return succeeded;
}

int main()
{
    // 注册异常捕获函数
    //QString dumpDir = BaseUtil::modulePath() + "/dumps/";
    //QDir dir(dumpDir);
    //if (!dir.exists())
    //{
    //    if (!dir.mkpath(dumpDir))
    //    {
    //        MsgBox::showMessage(QStringLiteral("加载异常处理模块失败: 无法创建存储目录"));
    //    }
    //}
    google_breakpad::ExceptionHandler *crashHandler =
        new google_breakpad::ExceptionHandler(L"C:/Users/ET/Desktop/",
            NULL,
            dumpProcessor,
            NULL,
            google_breakpad::ExceptionHandler::HandlerType::HANDLER_ALL);
    if (nullptr == crashHandler)
    {
        //MsgBox::showMessage(QStringLiteral("加载异常处理模块失败!"));
        cout << "nullptr == crashHandler" << endl;
    }

    int* p = nullptr;
    *p = 5;

    return 0;
}