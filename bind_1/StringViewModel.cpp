#include "pch.h"
#include "StringViewModel.h"
#if __has_include("StringViewModel.g.cpp")
#include "StringViewModel.g.cpp"
#endif

#include <string>
#include <sstream>
namespace winrt::bind_1::implementation
{
    static int g_Num = 0;

    //ここ以降追加
    StringViewModel::StringViewModel() : m_DataString(L"First String")
    {
    }
    StringViewModel::StringViewModel(const winrt::hstring value)
    {
        m_DataString = value;
    }

    void StringViewModel::DataString(winrt::hstring const& value)
    {
        //何回呼ばれたかも表示（蛇足部分）
        g_Num++;
        std::wstring strvalue;
        std::wostringstream woss;
        woss << g_Num;
        strvalue = value + L" " + woss.str();

        m_DataString = strvalue;

        //ここ追加（View Modelの変更通知）
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"DataString" });
    }
    winrt::hstring StringViewModel::DataString()
    {
        return m_DataString;
    }

    //ここ追加（View Modelの変更通知）
    winrt::event_token StringViewModel::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    //ここ追加（View Modelの変更通知）
    void StringViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
