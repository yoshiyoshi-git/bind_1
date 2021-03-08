#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::bind_1::implementation
{
    MainPage::MainPage()
    {
        //ここ追加
        m_SViewModel = winrt::make<bind_1::implementation::StringViewModel>();
        m_SVecViewModel = winrt::make<bind_1::implementation::StringVecViewModel>();
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}


void winrt::bind_1::implementation::MainPage::button1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    SViewModel().DataString(L"Clicked");
}


bind_1::StringViewModel winrt::bind_1::implementation::MainPage::SViewModel()
{
    return m_SViewModel;
}

bind_1::StringVecViewModel winrt::bind_1::implementation::MainPage::SVecViewModel()
{
    return m_SVecViewModel;
}


void winrt::bind_1::implementation::MainPage::list_buttton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{

    SVecViewModel().SVModelVec().Append(winrt::make<winrt::bind_1::implementation::StringViewModel>(L"list_inc"));
}
