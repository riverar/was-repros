#include "pch.h"
#include "Class.h"
#if __has_include("Class.g.cpp")
#include "Class.g.cpp"
#endif

#include <shobjidl.h>
#include <winrt/Windows.Storage.Pickers.h>

#pragma comment(lib, "user32.lib")

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::component::implementation
{
    int32_t Class::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Class::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction Class::OpenFileDialogAsync(int32_t hwnd)
    {
        winrt::Windows::Storage::Pickers::FileOpenPicker f{};
        f.as<IInitializeWithWindow>()->Initialize(reinterpret_cast<HWND>(hwnd));
        f.FileTypeFilter().Append(L".jpg");
        co_await f.PickSingleFileAsync();
    }
}
