#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <winrt/component.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <Microsoft.UI.Xaml.Window.h> // for INativeWindow

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::app::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        
        winrt::app::MainWindow window = *this;
        HWND hwnd{};
        window.as<IWindowNative>()->get_WindowHandle(&hwnd);
        
        component::Class c{};
        co_await c.OpenFileDialogAsync(reinterpret_cast<int32_t>(hwnd));
    }
}
