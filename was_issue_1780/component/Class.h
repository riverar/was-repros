#pragma once

#include "Class.g.h"

namespace winrt::component::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
        winrt::Windows::Foundation::IAsyncAction OpenFileDialogAsync(int32_t hwnd);
    };
}

namespace winrt::component::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
