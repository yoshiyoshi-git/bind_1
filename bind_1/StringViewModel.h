#pragma once

#include "StringViewModel.g.h"

namespace winrt::bind_1::implementation
{
    struct StringViewModel : StringViewModelT<StringViewModel>
    {
        StringViewModel();

        //ここ追加
        StringViewModel(const winrt::hstring value);

        //ここ追加
        void DataString(winrt::hstring const& value);
        winrt::hstring DataString();

        //ここ追加（View Modelの変更通知）
        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        //ここ追加
        winrt::hstring m_DataString;

        //ここ追加（View Modelの変更通知）
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::bind_1::factory_implementation
{
    struct StringViewModel : StringViewModelT<StringViewModel, implementation::StringViewModel>
    {
    };
}
