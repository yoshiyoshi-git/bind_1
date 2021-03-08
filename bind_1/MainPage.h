#pragma once

#include "MainPage.g.h"
#include "StringViewModel.h"
#include "StringVecViewModel.h"

namespace winrt::bind_1::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void button1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

        
        bind_1::StringViewModel SViewModel();
        bind_1::StringVecViewModel SVecViewModel();



    private :
        bind_1::StringViewModel m_SViewModel{ nullptr };
        bind_1::StringVecViewModel m_SVecViewModel{ nullptr };
    public:
        void list_buttton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::bind_1::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
