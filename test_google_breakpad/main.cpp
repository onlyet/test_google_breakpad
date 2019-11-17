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
    //MessageBox(NULL, TEXT("��Ǹ�ǻۿ��ñ����ˣ�����ϵ����֧����Ա"), TEXT("������ʾ"), 0);
    cout << "������" << endl;
#endif // _WIN32

    return succeeded;
}

int main()
{
    // ע���쳣������
    //QString dumpDir = BaseUtil::modulePath() + "/dumps/";
    //QDir dir(dumpDir);
    //if (!dir.exists())
    //{
    //    if (!dir.mkpath(dumpDir))
    //    {
    //        MsgBox::showMessage(QStringLiteral("�����쳣����ģ��ʧ��: �޷������洢Ŀ¼"));
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
        //MsgBox::showMessage(QStringLiteral("�����쳣����ģ��ʧ��!"));
        cout << "nullptr == crashHandler" << endl;
    }

    int* p = nullptr;
    *p = 5;

    return 0;
}